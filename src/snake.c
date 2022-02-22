#include"snake.h"
#include"Touch.h"
#include"display.h"
#include"AT070TN92_LCD.h"
/********
 * 函数名：Init_Game，初始化蛇的信息
 * 参数：无
 * 返回值：无
 * **********/
extern snake_body *snake;
extern int action;
extern lcd_info lcd;
unsigned char number[][word_num_wid*word_num_height];
extern int sorce;
void Init_Snake()
{
	snake = (snake_body *)malloc(sizeof(snake_body));
    snake->Head = NULL;
    snake->Tail = NULL;
    snake->length = 0;
    coordinates *body = (coordinates *)malloc(sizeof(coordinates));
    body->x = rand()%game_width;
    body->y = rand()%game_height;
    for (int  i = 0; i < 3; i++)
    {
        add_body(body);
        body->x++;
    }
	return ;
}
/***************
 * 函数名：Init_food
 * 功能：初始化食物信息
 * 参数：无
 * 返回值：无
 * ******************/


/***********
 * 函数名：add_body
 * 功能：为蛇添加节点（当蛇吃到食物时需要调用此函数）
 * 参数：@snake_body **snake,指向蛇的头节点的指针
 *           @coordinates *body,执行食物的指针
 * 返回值：无
 * *****************/
void add_body(coordinates *body)
{
    
    coordinates *new_node = (coordinates *)malloc(sizeof(coordinates));  
    new_node->x = body->x;
    new_node->y = body->y;
    new_node->next_node = NULL;
    if( snake->Tail == NULL || snake->Head == NULL)
    {
        snake->Tail = new_node;
        snake->Head = new_node;
        snake->length++;
        return ;
    }    
    snake->Head->next_node = new_node;
    snake->Head = new_node;
    snake->length++;
    return ;
}
void delete_body(coordinates *body)
{

}
void delete_tail()
{
    coordinates *tail = snake->Tail;
    snake->Tail = snake->Tail->next_node;
    snake->length--;
    for (int i = tail->x*10; i < tail->x*10+10; i++)
    {
        for (int j = tail->y*10; j < tail->y*10+10;j++)
        Draw_point(&lcd,i,j,Threme);//蓝色为蛇
    }
    free(tail);
    return;
}
/********************
 * 函数名：fun
 * 功能：在蛇移动时，用来将原本蛇的各节点坐标由头至至尾，前一个节点的值赋给后一个，头节点用新的节点赋值）
 * 参数：@p，蛇的头节点
 * 返回值：无
 * *************************/
void fun_judge(int x, int y)
{
    x*=10;
    y*=10;
    if (lcd.adr[x+y*800] == Threme)
    {

        delete_tail();
    }
    else if (lcd.adr[x+y*800] == Blue)
    {
        snake_move();
		display();
        printf("游戏结束！\n");
        exit(1);
    }
    else if (lcd.adr[x+y*800] == Food)
    {
        int a=0,b=0,c=0;
        sorce+=2;
        a=sorce;
        while (a%10)
        {
            Draw_word(number[a%10],799-40-c*word_num_wid,0,word_num_wid,word_num_height);
            c++;
            a/=10;
        }
        c=0;
        b=snake->length;
        while (b%10)
        {
            Draw_word(number[b%10],799-40-c*word_num_wid,0+80,word_num_wid,word_num_height);
            c++;
            b/=10;
        }
        Create_Food();
    }    
}

/************
 * 函数名：snake_move
 * 功能：控制及执行蛇的下一步动作
 * 参数：*************/
void snake_move()
{   
    int x,y;
    x=snake->Head->x;
    y=snake->Head->y;
    coordinates body;
    switch (action)
    {
        case RIGHT:
                x++;
                if (x>game_width-1)
                {
                    x = 0;
                }
                body.x = x;
                body.y = y;
                add_body(&body);
                fun_judge(x,y);
                break;
        case LEFT:
                x--;
                if (x<0)
                {
                    x = game_width-1;
                }
                body.x = x;
                body.y = y;
                add_body(&body);
                fun_judge(x,y); 
                break;

        case UP:
                y--;
                if (y<0)
                {
                    y = game_height-1;
                }
                body.x = x;
                body.y = y;
                add_body(&body);
                fun_judge(x,y);
                break;
        case DOWN:
                y++;
                if (y>game_height-1)
                {
                    y = 0;
                }
                body.x = x;
                body.y = y;
                add_body(&body);
                fun_judge(x,y);             
                break;
        default:
                break;
    }
    return ;    
}
void Create_Food()
{
	int x= 0,y=0;
LOOP:   
    x = rand()%game_width;
    y = rand()%game_height;
    if (lcd.adr[x*10+800*y*10] == Food)
    {
        goto LOOP;
    }
    
	for (int a = x*10; a < x*10+10; a++)
	{
		for (int b = y*10; b < y*10+10; b++)
		{
			Draw_point(&lcd,a,b,Food);
		}
	}
    printf("food.x=%d food.y=%d\n",x,y);
    return;
}
void Init_Food()
{
	for (int i = 0; i < 10; i++)
	{
		Create_Food();
	}
	return;
}