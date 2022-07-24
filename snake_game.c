#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <unistd.h>

int i,j,hight=20;
int width=20,score,gameover,flag;
int x,y,fruitx,fruity;


void setup()
{
    gameover =0;
    x = hight/2;
    y = width/2;

    lebel1:
    fruitx= rand()%20;
    if(fruitx==0)
    goto lebel1;

    lebel2:
    fruity=rand()%20;
    if(fruity==0)
    goto lebel2;
    score =0;
}

void draw()
{
    for(i=0; i<hight; i++)
    {
        for(j=0; j<width; j++)
        {
            if(i==0 || i==width-1 || j==0 || j==hight-1)
            {
                printf("#");
            }
            else{   
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("score=%d",score);
    printf("\n");
    printf("Press x to quit the game");
}



void input()
{
    if(kbhit())
    {
        switch (getch())
        {
        case 'a' :
            flag= 1;
            break;
        case 's' :
            flag=2;
            break;
        case 'd' :
            flag=3;
            break;
        case 'w' :
            flag=4;
            break;
        case 'x' :
            gameover=1;
            break;             

        }
    }
}

void logic()
{
    usleep(0.01);
    switch (flag)
    {
    case 1:
        y--;
        break;
    case 2:
        x++;
        break;
    case 3:
        y++;
        break;
    case 4:
        x--;
        break;        
    default:
        break;
    }

    if(x<0 || x>hight || y<0 || y>width)
    gameover=1;

    if(x==fruitx || y==fruity)
    {
        lebel3:
        fruitx=rand()%20;
        if(fruitx==0)
        goto lebel3;

        lebel4:
        fruity=rand()%20;
        if(fruity==0)
        goto lebel4;
        score +=10;

    }
}
void main()
{
    int m,n;

    setup();
    while(!gameover)
    {
        draw();
        input();
        logic();
    }
    printf("arvind");
}