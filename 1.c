#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

float x1,x2,y1,y2;



void display (void){
    float dx,dy,step,x,y,k,Xin,Yin;
    dx = x2-x1;
    dy = y2-y1;
    
    step = abs(dx) > abs(dy)? abs(dx) : abs(dy);
    
    Xin = dx/step;
    Yin = dy/step;
    
    x=x1;
    y=y1;
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
    for(k=1;k<step;k++){
        x = x+Xin;
        y = y+Yin;
        printf("%f,%f\n",x,y);
        glBegin(GL_POINTS);
        glVertex2i(x,y);
        glEnd();
    }
    
    glFlush();

}

void init (void){
	
}
int main (int argc,char** argv){
    printf("enter the value of x1: ");
    scanf("%f",&x1);
    printf("enter the value of y1: ");
    scanf("%f",&y1);
    printf("enter the value of x2: ");
    scanf("%f",&x2);
    printf("enter the value of y2: ");
    scanf("%f",&y2);
    
    glutInit(&argc,argv);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("DDA algo");
   
    glClearColor(0.0,0.0,0.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	gluOrtho2D(-100,100,-100,100);
	
    glutDisplayFunc(display);
    glutMainLoop();
    
    return 0;  
}
