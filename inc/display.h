#include"input-event-codes.h"
#include<pthread.h>
#include<input.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<AT070TN92_LCD.h>

#define word_num_wid 32
#define word_num_height 64
void display();
void Init_window();
void rep_juxing(lcd_info*lcd,int start_x,int start_y,int width,int height,unsigned int out_col,unsigned int src_col);
void fill_juxing(lcd_info*lcd,int start_x,int start_y,int width,int height,unsigned int col);
void fill_zuosanjiao(lcd_info*lcd,int start_x,int start_y,int width,int height,unsigned int col);
void fill_yuosanjiao(lcd_info*lcd,int start_x,int start_y,int width,int height,unsigned int col);
void fill_shangsanjiao(lcd_info*lcd,int start_x,int start_y,int width,int height,unsigned int col);
void fill_xiasanjiao(lcd_info*lcd,int start_x,int start_y,int width,int height,unsigned int col);
void draw_line(lcd_info*lcd,int start_x,int start_y,int end_x,int end_y,int col);
void Draw_word(unsigned char w[],int start_x,int start_y,int width,int height);