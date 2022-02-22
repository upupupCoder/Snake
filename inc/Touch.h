#ifndef TOUCH_H_
#define TOUCH_H_
#include"input-event-codes.h"
#include<pthread.h>
#include<input.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
typedef struct 
{
    int x;
    int y;
}Point;
enum direction 
{
    UP = 1,
    DOWN = 2,
    LEFT = 3,
    RIGHT = 4,
};
#endif
void *Control_snake();