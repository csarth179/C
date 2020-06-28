//
//  string_array.c
//
//  Created by Sarthak Chopra on 6/25/20.
//  Copyright © 2020 Sarthak Chopra. All rights reserved.
//

#include<stdio.h>
#include<string.h>

int factorial(int);
 
int main()
{
    int i = 1;
 
    char *sports[] =
    {               "golf",
                    "hockey",
                    "football",
                    "cricket",
                    "shooting"
    };
    
    for(i = 0; i < 5; i++) {
        printf("String = %s\n", sports[i]);
        printf("Address of string literal = %u\n", sports[i]);
    }
    return 0;
}
