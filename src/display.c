#include"display.h"
#include"snake.h"
#include<math.h>
extern snake_body *snake;
extern char action;
extern lcd_info lcd;
extern unsigned char sor_len[];
void display()
{
    coordinates *body = snake->Tail;//显示蛇
    while (body->next_node!=NULL)
    {

        for (int i = body->x*10; i < body->x*10+10; i++)
        {
            for (int j = body->y*10; j < body->y*10+10;j++)
            Draw_point(&lcd,i,j,Blue);//蓝色为蛇
        }
        body=body->next_node;   
    }
    return;
}
void Draw_word(unsigned char w[],int start_x,int start_y,int width,int height)
{
    int x,y;
    for (int i = 0; i < width*height/8; i++)
    {
        for (int j = 7; j >=0; j--)
        {

            x = (i*8)%width+7-j+start_x;
            y = (i*8)/width+start_y;
            if (w[i]&(1<<j))
            {
                Draw_point(&lcd,x,y,0x00000000);
            }
            else
            {
                Draw_point(&lcd,x,y,Threme);
            }
        }  
    }
    return ;
}
void Init_window()
{
    fill_juxing(&lcd,0,HEIGHT-1,WIDTH,HEIGHT,Threme);
    printf("function:%s Line:%d\n",__FUNCTION__,__LINE__);
    fill_juxing(&lcd,500,HEIGHT-1,300,300,White);
    fill_juxing(&lcd,500,380,100,100,Grey);//左边矩形
    fill_juxing(&lcd,700,380,100,100,Grey);//右边矩形
    fill_juxing(&lcd,600,280,100,100,Grey);//上边矩形
    printf("function:%s Line:%d\n",__FUNCTION__,__LINE__);
    fill_juxing(&lcd,600,HEIGHT-1,100,100,Grey);//下边矩形
    fill_zuosanjiao(&lcd,500,380,100,100,Triangle);//左三角形
    fill_yousanjiao(&lcd,700,380,100,100,Triangle);//右三角形
    printf("function:%s Line:%d\n",__FUNCTION__,__LINE__);
    fill_shangsanjiao(&lcd,600,280,100,100,Triangle);//上三角形
    fill_xiasanjiao(&lcd,600,HEIGHT-1,100,100,Triangle);//下三角形
    printf("function:%s Line:%d\n",__FUNCTION__,__LINE__);
    for (int i = 0; i < 5; i++)
    {
        draw_line(&lcd,500+i,HEIGHT-1,500+i,0,Line);
        draw_line(&lcd,500,180-i,WIDTH-1,180-i,Line);

    }
    printf("function:%s Line:%d\n",__FUNCTION__,__LINE__);
    Draw_word(sor_len,504,0,296,175);
    printf("function:%s Line:%d\n",__FUNCTION__,__LINE__);
}
/****
*函数名：rep_juxing
*功能：对某一矩形内的颜色进行替换
*参数：
    lcd:lcd屏幕
    start_x:起始横坐标
    start_y:起始纵坐标
    width：宽度
    height：长度
    src_col:源颜色
    out_col:输出颜色
*返回值：void
******/
void rep_juxing(lcd_info*lcd,int start_x,int start_y,int width,int height,unsigned int out_col,unsigned int src_col)
{

    for (int y = start_y; y >= start_y - height+1; y--)
    {
        for (int x = start_x; x < start_x+width; x++)
        {
            if (lcd->adr[x+y*WIDTH-1] == src_col)
            {
                Draw_point(lcd,x,y,out_col);
            }   
        }
        
    }
    return ;  
}
/****
*函数名：fill_juxing
*功能：对某一矩形进行颜色填充
*参数：
    lcd:lcd屏幕
    start_x:起始横坐标
    start_y:起始纵坐标
    width：宽度
    height：长度
    col:填充颜色
*返回值：void
******/
void fill_juxing(lcd_info*lcd,int start_x,int start_y,int width,int height,unsigned int col)
{
    for (int y = start_y; y >= start_y - height+1; y--)
    {
        for (int x = start_x; x < start_x+width; x++)
        {
                Draw_point(lcd,x,y,col);   
        }
        
    }
    return ;    
}
/****
*函数名：fill_zuosanjiao
*功能：对左三角进行颜色填充
*参数：
    lcd:lcd屏幕
    start_x:起始横坐标
    start_y:起始纵坐标
    width：宽度
    height：长度
    col:填充颜色
*返回值：void
******/
void fill_zuosanjiao(lcd_info*lcd,int start_x,int start_y,int width,int height,unsigned int col)
{
    int abs_x,abs_y;
    for (int y = start_y; y >= start_y - height+1; y--)
    {
        for (int x = start_x; x < start_x+width; x++)
        {
            abs_x = abs(x - start_x);
            abs_y = abs(y - start_y);
            if(abs_y>-height/2.0/width*abs_x+height/2.0&& abs_y<height/2.0/width*abs_x+height/2.0 )
            {
                Draw_point(lcd,x,y,col);
            }
        }
    }
    return;
}
/****
*函数名：fill_yousanjiao
*功能：对右三角进行颜色填充
*参数：
    lcd:lcd屏幕
    start_x:起始横坐标
    start_y:起始纵坐标
    width：宽度
    height：长度
    col:填充颜色
*返回值：void
******/
void fill_yousanjiao(lcd_info*lcd,int start_x,int start_y,int width,int height,unsigned int col)
{
    int abs_x,abs_y;
    for (int y = start_y; y >= start_y - height+1; y--)
    {
        for (int x = start_x; x < start_x+width; x++)
        {
            abs_x = abs(x - start_x);
            abs_y = abs(y - start_y);
            if(abs_y>height/2.0/width*abs_x && abs_y<-height/2.0/width*abs_x+height)
            {
                Draw_point(lcd,x,y,col);            
            }
        }
    }
    return;
}
/****
*函数名：fill_shangsanjiao
*功能：对上三角进行颜色填充
*参数：
    lcd:lcd屏幕
    start_x:起始横坐标
    start_y:起始纵坐标
    width：宽度
    height：长度
    col:填充颜色
*返回值：void
******/
void fill_shangsanjiao(lcd_info*lcd,int start_x,int start_y,int width,int height,unsigned int col)
{
    int abs_x,abs_y;
    for (int y = start_y; y >= start_y - height+1; y--)
    {
        for (int x = start_x; x < start_x+width; x++)
        {
            abs_x = abs(x - start_x);
            abs_y = abs(y - start_y);
            if(abs_y < 2.0*height/width*abs_x && abs_y < -2.0*height/width*abs_x+2.0*height)
            Draw_point(lcd,x,y,col);
        }
    }
    return;
}
/****
*函数名：fill_xiasanjiao
*功能：对左三角进行颜色填充
*参数：
    lcd:lcd屏幕
    start_x:起始横坐标
    start_y:起始纵坐标
    width：宽度
    height：长度
    col:填充颜色
*返回值：void
******/
void fill_xiasanjiao(lcd_info*lcd,int start_x,int start_y,int width,int height,unsigned int col)
{
    int abs_x,abs_y;
    for (int y = start_y; y >= start_y - height+1; y--)
    {
        for (int x = start_x; x < start_x+width; x++)
        {
            abs_x = abs(x - start_x);
            abs_y = abs(y - start_y);
            if(abs_y > -2.0*height/width*abs_x+height && abs_y > 2.0*height/width*abs_x-height)
            Draw_point(lcd,x,y,col);
        }
    }
    return;
}
/*****
*函数名：draw_line
*功能：画一条线段
*参数：
    lcd：lcd屏幕
    start_x,start_y:直线起始坐标
    end_x,end_y:直线终点坐标
    col：线段的颜色
*返回值：void
*********/
void draw_line(lcd_info*lcd,int start_x,int start_y,int end_x,int end_y,int col)
{
    double k,b;
    if (end_y == start_y && end_x == start_x)
    {
        printf("绘制线段时输入参数错误！\n");
        return;
    }
    if (end_y-start_y == 0)
    {
        if (end_x>start_x)
        {
            for (int i = start_x; i < end_x; i++)
            {
                Draw_point(lcd,i,start_y,col);
            }
        }
       else
       {
            for (int i = end_x;  i< start_x; i++)
            {
                Draw_point(lcd,i,start_y,col);
            }           
       }
       return ;
    }
    if (end_x-start_x == 0)
    {
        if (end_y>start_y)
        {
            for (int i = start_y; i < end_y; i++)
            {
                Draw_point(lcd,start_x,i,col);
            }
        }
        else
        {
            for (int i = end_y; i < start_y; i++)
            {
                Draw_point(lcd,start_x,i,col);
            }
        }
        return;  
    }
    k =  (end_y - start_y)/1.0/(end_x - start_x);
    b =  end_y - k*end_x;
    if (end_x > start_x)
    {
        for (int i = start_x,j = 0; i < end_x; i++)
        {
            j = k*start_x+b;
            Draw_point(lcd,i,j,col);
        }
    }
    else 
    {
        for (int i = end_x,j = 0; i < start_x; i++)
        {
            j = k*end_x+b;
            Draw_point(lcd,i,j,col);
        }    
    }
    return;
    
}

