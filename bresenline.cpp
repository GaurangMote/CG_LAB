#include<GL/glut.h>
#include<GL/gl.h>

void BSA(int x1,int y1,int x2,int y2)
{
   int p;
   int dx=x2-x1;
   int dy=y2-y1;
   int x=x1;
   int y=y1;
   
   if(dx<0)
   {
       dx=-dx;
   }
   
   if(dy<0)
   {
       dy=-dy;
   }
   
   int x_change=1,y_change=1;
   if(x1>x2)
   {
       x_change=-1;
   }
   if(y1>y2)
   {
       y_change=-1;
   }
   
   glVertex2i(x,y);
   glBegin(GL_POINTS);
   
   if(dx>dy)
   {
       p=2*dy-dx;
       for(int i=1;i<dx;i++)
       {
           if(p>0)
           {
               y+=y_change;
               p=p+2*(dy-dx);
           }
           else
           {
               p=p+2*dy;
           }
           x+=x_change;
           glVertex2i(x,y);
       }
   }
   else
   {
       p=2*dx-dy;
       for(int i=1;i<dy;i++)
       {
           if(p>0)
           {
               x+=x_change;
               p=p+2*(dx-dy);
           }
           else
           {
               p=p+2*dx;
           }
           y+=y_change;
           glVertex2i(x,y);
       }
   }
   glEnd();
}

void renderfunction()
{
    glClearColor(0.0,0.0,0.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,1.0,0.0);
    gluOrtho2D(0,850,0,500);
    
    BSA(100,100,500,300); 
    
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(850,500);
    glutInitWindowPosition(600,245);
    glutCreateWindow("BSA basic");
    glutDisplayFunc(renderfunction);
    glutMainLoop();
    return 0;
}  
