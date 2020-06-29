//
//  context_switch.c
//
//  Created by Sarthak Chopra on 6/28/20.
//  Copyright © 2020 Sarthak Chopra. All rights reserved.
//

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/time.h>
#include <sched.h>

int main(int argc, char *argv[]) {
    // measure context switch
    int nloops = 1000000;
    struct timeval start, end;
    cpu_set_t set;
    CPU_ZERO(&set);
    CPU_SET(0, &set);

    int first_pipefd[2], second_pipefd[2];
    if (pipe(first_pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }
    if (pipe(second_pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }
    pid_t cpid = fork();

    if (cpid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    // child
    } else if (cpid == 0) {
        if (sched_setaffinity(getpid(), sizeof(cpu_set_t), &set) == -1) {
            exit(EXIT_FAILURE);
        }

        for (size_t i = 0; i < nloops; i++) {
            read(first_pipefd[0], NULL, 0);
            write(second_pipefd[1], NULL, 0);
        }
    // parent
    } else {
        if (sched_setaffinity(getpid(), sizeof(cpu_set_t), &set) == -1) {
            exit(EXIT_FAILURE);
        }
        gettimeofday(&start, NULL);
        
        for (size_t i = 0; i < nloops; i++) {
            write(first_pipefd[1], NULL, 0);
            read(second_pipefd[0], NULL, 0);
        }
        gettimeofday(&end, NULL);
        printf("context switch: %f microseconds\n", (float) (end.tv_sec * 1000000 + end.tv_usec - start.tv_sec * 1000000 - start.tv_usec) / nloops);
    }
    return 0;
}
