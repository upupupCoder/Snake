#ifndef _SNAKE_H_
#define _SNAKE_H_
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <linux/input.h>
#include <fcntl.h>
#include <pthread.h>
#include <sys/time.h>
#include <stdbool.h>
#include <termios.h>
#include <sys/select.h>
#include <stdbool.h>
#include <AT070TN92_LCD.h>

#define FOOD_MAX 10
#define game_width 50        
#define game_height 48
typedef char ElemtType;
typedef struct coordinates //坐标信息
{
    int x;
    int y;
    struct coordinates *next_node;
} coordinates;

typedef struct snake_body //蛇的身体信息
{
    coordinates *Head;
    coordinates *Tail;
    int length;
} snake_body;

void Init_Snake();
void add_body(coordinates *body);
void delete_body(coordinates *body);
void delete_tail();
void snake_move();
void Init_Food();
void Create_Food();
#endif // _SNAKE_H_
