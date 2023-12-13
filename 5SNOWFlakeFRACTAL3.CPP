#include<iostream>
#include<graphics.h>
//#include<conio.h>
#include<math.h>
void koch(int x1, int y1, int x2, int y2,int it)
{ int x3,x4,y3,y4,x,y;
int slicex=(x2-x1)/3;
int slicey=(y2-y1)/3;
x3=x1+slicex;
y3=y1+slicey;
x4=x2-slicex;
y4=y2-slicey;
float angle=(60*M_PI)/180;
x=x3+(x4-x3)*cos(angle)+(y4-y3)*sin(angle);
y=y3-(x4-x3)*sin(angle)+(y4-y3)*cos(angle);
if(it>0)
{
koch(x1,y1,x3,y3,it-1);
koch(x3,y3,x,y,it-1);
koch(x,y,x4,y4,it-1);
koch(x4,y4,x2,y2,it-1);
 }
else{
line(x1,y1,x3,y3);
line(x3,y3,x,y);
line(x,y,x4,y4);
line(x4,y4,x2,y2);
}
}
int main()
{
int gd=DETECT,gm, x1=100,y1=100, x2=400,y2=400,it=2;
initgraph(&gd,&gm,NULL);
koch(x1,y1,x2,y2,it);
//getch();
delay(4000);

closegraph();
return 0;
}