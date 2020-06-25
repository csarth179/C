//
//  common.h
//  Spin
//
//  Created by Sarthak Chopra on 6/25/20.
//  Copyright © 2020 Sarthak Chopra. All rights reserved.
//

#ifndef __common_h__
#define __common_h__

#include <sys/time.h>
#include <sys/stat.h>
#include <assert.h>

double GetTime() {
    struct timeval t;
    int rc = gettimeofday(&t, NULL);
    assert(rc == 0);
    return (double) t.tv_sec + (double) t.tv_usec/1e6;
}

void Spin(int length) {
    double t = GetTime();
    while ((GetTime() - t) < (double) length);
}

#endif
