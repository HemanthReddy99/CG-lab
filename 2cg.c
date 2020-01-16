#include<stdio.h>
#include<GL/glut.h>
//#include<math.h>
#define pi 3.14

#define H 600
#define W 720



void plotlinelow(float x1, float y1, float x2, float y2)
{
	float dx = x2 - x1, dy = y2 - y1;
	float yi = 1;
	if(dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	float D = 2 * dy - dx;
	
	glBegin(GL_POINTS);
	float x, y = y1;
	for(x = x1; x < x2; x++)
	{
		glVertex2f(x / W, y / H);
		if(D > 0)
		{
			y = y + yi;
			D = D - 2 * dx;
		}
		D = D + 2 * dy;
	}
	glEnd();
}

void plotlinehigh(float x1, float y1, float x2, float y2)
{
	float dx = x2 - x1, dy = y2 - y1;
	float xi = 1;
	if(dx < 0)
	{
		xi = -1;
		dx = -dx;
	}
	float D = 2 * dx - dy;
	
	glBegin(GL_POINTS);
	float y, x = x1;
	for(y = y1; y < y2; y++)
	{
		glVertex2f(x / W, y / H);
		if(D > 0)
		{
			x = x + xi;
			D = D - 2 * dy;
		}
		D = D + 2 * dx;
	}
	glEnd();
}

void bresenham(float x1, float y1, float x2, float y2)
{
	float dx = x2 - x1, dy = y2 - y1;
	if(abs(dy) < abs(dx))
	{
		dx > 0 ? plotlinelow(x1, y1, x2, y2) : plotlinelow(x2, y2, x1, y1);
	}
	else
	{
		dy > 0 ? plotlinehigh(x1, y1, x2, y2) : plotlinehigh(x2, y2, x1, y1);
	}
}

		

void display()
{
	glPointSize(1.0);
	glColor3f(0.0, 1.0, 0.4);
	glClear(GL_COLOR_BUFFER_BIT);

	

	bresenham(100, 100, -100, 100);
	bresenham(100, 100, 100, -100);
	bresenham(-100, -100, -100, 100);
	bresenham(-100, -100, 100, -100);

	

	bresenham(0, 100, 100, 0);
	bresenham(0, 100, -100, 0);
	bresenham(0, -100, 100, 0);
	bresenham(0, -100, -100, 0);

	
	
	bresenham(50, 50, -50, 50);
	bresenham(50, 50, 50, -50);
	bresenham(-50, -50, -50, 50);
	bresenham(-50, -50, 50, -50);

	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(W, H);
	glutCreateWindow("W");

	glClearColor(0.0, 0.0, 0.0, 1.0);
	
	glutDisplayFunc(display);
	glutMainLoop();
}
