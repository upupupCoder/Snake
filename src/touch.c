#include"Touch.h"
#include"math.h"
extern int action;
void *Control_snake()
{
    struct input_event ev;
    int fd = open("/dev/input/event0",O_RDONLY);
    if (fd == -1)
    {
        perror("Open Touch Lcd failed!\n");
        exit(1);
    }
    Point start,end;
    start.x = -1;
    start.y = -1;
    int flag = 0;
    int value;
    while (1)
    {
        if(read(fd,&ev,sizeof(ev))!=sizeof(ev))
        {
            perror("Read failed!\n");
            exit(1);
        }
        if (ev.type == EV_ABS && ev.code == ABS_X)
        {
            if (start.x == -1)
            {
                start.x = ev.value*0.78125;
            }
            end.x = ev.value*0.78125;
        }
        if (ev.type == EV_ABS && ev.code == ABS_Y)
        {
            if (start.y == -1)
            {
                start.y = ev.value*0.8;
            }
            end.y = ev.value*0.8;
        }
        if(ev.type == EV_KEY && ev.code == BTN_TOUCH && ev.value == 0)
        {
            double dis;
            dis = sqrt(abs(end.x-start.x)*abs(end.x-start.x)+abs(end.y-start.y)*abs(end.y-start.y)); 
            if (dis < 10.0)
            {
                if (500<end.x&&end.x<600&&280<end.y&&end.y<380)
                {
                    if (action != RIGHT)
                    {
                        action = LEFT;
                    }
                }
                if (600<end.x&&end.x<700&&380<end.y&&end.y<480)
                {
                    if (action != UP)
                    {
                        action = DOWN;
                    }
                }
                if (700<end.x&&end.x<800&&280<end.y&&end.y<380)
                {
                    if (action!=LEFT)
                    {
                        action = RIGHT;
                    }
                }
                if (600<end.x&&end.x<700&&180<end.y&&end.y<280)
                {
                    if (action!=DOWN)
                    {
                        action = UP;
                    }
                }
            }
            else
            {
/*                 printf("触摸事件！\n");
                printf("start.x=%d,start.y=%d\n",start.x,start.y);
                printf("end.x=%d,end.y=%d\n",end.x,end.y);                
                printf("distance=%f\n",dis); */                
            } 
            start.x = -1;
            start.y = -1;       
        }
    }
    close(fd);
    return NULL;
}