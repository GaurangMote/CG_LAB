#include<GL/glut.h>
#include<GL/gl.h>

void displayfunc(int x,int y,int i)
{
   glColor3f(0,1,0);
       glBegin(GL_POINTS);
           glVertex2f(x,y);
       glEnd();
}

void displaydashfunc(int x,int y,int i)
{
    if(i%4==0 || i%6==0){
	   return;
	}
    glColor3f(0,1,0);
       glBegin(GL_POINTS);
           glVertex2f(x,y);
       glEnd();
}

void displaydotfunc(int x,int y,int i)
{
    if(i%8!=0){
	   return;
	}
    glColor3f(0,1,0);
       glBegin(GL_POINTS);
           glVertex2f(x,y);
       glEnd();
}

void simpleline(float x1,float y1,float x2,float y2,int choice)
{
    float dy,dx;
    dy=y2-y1;
    dx=x2-x1;
    
    int steps;
    
    if(abs(dy)<abs(dx))
    {
        steps=abs(dx);
    }
    else
    {
        steps=abs(dy);
    }
    
    float xinc,yinc;
    
    xinc=dx/(float)steps;
    yinc=dy/(float)steps;
    
    if(choice==1)
    {
        for(int i=0;i<=steps;i++)
        {
            displayfunc(x1,y1,i);
            x1+=xinc;
            y1+=yinc;
        }  
    }
    else if(choice==2)
    {
        for(int i=0;i<=steps;i++)
        {
            displaydashfunc(x1,y1,i);
            x1+=xinc;
            y1+=yinc;
        }
    }
    
    else if(choice==3)
    {
        for(int i=0;i<=steps;i++)
        {
            displaydotfunc(x1,y1,i);
            x1+=xinc;
            y1+=yinc;
        }
    }
    
    
    glFlush();
}

void renderfunction()
{
    glClearColor(0.0,0.0,0.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,1.0,1.0);
    gluOrtho2D(0,1000,0,600);
    /*glBegin(GL_TRIANGLES);
        glVertex2f(100,100);
        glVertex2f(50,150);
        glVertex2f(200,50);  
    glEnd();*/
    
    simpleline(100,100,500,400,1);
    simpleline(200,50,800,50,2);
    
    
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(1000,600);
    glutInitWindowPosition(600,245);
    glutCreateWindow("DDA basic");
    glutDisplayFunc(renderfunction);
    glutMainLoop();
    return 0;
}    
