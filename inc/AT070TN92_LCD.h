#ifndef _AT070TN92_LCD_H_
#define _AT070TN92_LCD_H_
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#define WIDTH  800
#define HEIGHT 480
#define DEPTH  4
#define LCD_SIZE (WIDTH*HEIGHT*DEPTH)

enum Game_color 
{
    Threme = 0x001E90FF,
    White = 0x00FFFFFF,
    Triangle = 0x00a1a3a6,
    Grey = 0x00d9d6c3,
    Blue = 0x000000ff,
    Food = 0x007bbfea,
    Line = 0x00ADD8E6
};
typedef struct
{
    int fd;
    size_t* adr;
}lcd_info;
void Init_Lcd(const char*pathname,lcd_info *lcd);
void Clr_Lcd(lcd_info*lcd);
void Cle_Lcd(lcd_info *lcd_info);
void Draw_point(lcd_info*lcd,int x,int y,unsigned int color);
#endif