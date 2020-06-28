//
//  cpu.c
//
//  Created by Sarthak Chopra on 6/25/20.
//  Copyright © 2020 Sarthak Chopra. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "common.h"

int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "usage: cpu <string>\n");
        exit(1);
    }
    
    char *str = argv[1];

    while (1) {
        printf("%s\n", str);
        Spin(1);
    }
    return 0;
}
