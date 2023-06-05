#include<GL/glut.h>
#include<GL/gl.h>

void displayfunc(int x,int y)
{
   glColor3f(0,1,0);
       glBegin(GL_POINTS);
           glVertex2f(x,y);
       glEnd();     
}

void simpleline(float x1,float y1,float x2,float y2)
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
    
    for(int i=0;i<=steps;i++)
    {
        displayfunc(x1,y1);
        x1+=xinc;
        y1+=yinc;
    }
    
    glFlush();
}

void renderfunction()
{
    glClearColor(0.0,0.0,0.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,1.0,1.0);
    gluOrtho2D(0,850,0,500);
    /*glBegin(GL_TRIANGLES);
        glVertex2f(100,100);
        glVertex2f(50,150);
        glVertex2f(200,50);  
    glEnd();*/
    
    
    
    glFlush();
}

void onMouseClick(int button,int state,int x,int y)
{
    simpleline(100,100,500,400);
    simpleline(500,400,800,250);
}

int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(850,500);
    glutInitWindowPosition(600,245);
    glutCreateWindow("DDA basic");
    glutDisplayFunc(renderfunction);
    glutMouseFunc(onMouseClick);
    glutMainLoop();
    return 0;
}    
