#include<GL/gl.h>
#include<GL/glut.h>
using namespace std;
GLfloat T=0;
void spin()
{
    T=T+1;
    if(T>360)
    {
        T=0;
    }
    glutPostRedisplay();    
}

void Face(GLfloat A[],GLfloat B[],GLfloat C[],GLfloat D[])
{
    glBegin(GL_POLYGON);
    glVertex3fv(A);
    glVertex3fv(B);
    glVertex3fv(C);
    glVertex3fv(D);
    glEnd();
}

void cube(GLfloat v0[],GLfloat v1[],GLfloat v2[],GLfloat v3[],GLfloat v4[],GLfloat v5[],GLfloat v6[],GLfloat v7[])
{
    glColor3f(1,0,0);
    Face(v0,v1,v2,v3);
    glColor3f(0,1,0);
    Face(v4,v5,v6,v7);
    glColor3f(0,0,1);
    Face(v0,v3,v7,v4);
    glColor3f(1,0,1);
    Face(v1,v2,v6,v5);
    glColor3f(1,1,0);
    Face(v0,v1,v5,v4);
    glColor3f(0,1,1);
    Face(v3,v2,v6,v7);
}

void draw()
{
   GLfloat v[8][3]={
       {-0.5,0.5,0.5},
       {0.5,0.5,0.5},
       {0.5,-0.5,0.5},
       {-0.5,-0.5,0.5},
       {-0.5,0.5,-0.5},
       {0.5,0.5,-0.5},
       {0.5,-0.5,-0.5},
       {-0.5,-0.5,-0.5}
       };
       glEnable(GL_DEPTH_TEST);
       glClearColor(0,0,0,1);
       glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
       glColor3f(1,0,0);
       glLoadIdentity();
       glRotatef(T,1,1,0);
       cube(v[0],v[1],v[2],v[3],v[4],v[5],v[6],v[7]);
       
       glutSwapBuffers();
}

int main(int argc, char** argv){

glutInit(&argc, argv);
glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
glutInitWindowPosition(250,50);
glutInitWindowSize(900,600);
glutCreateWindow("cube");
glutDisplayFunc(draw);
glutIdleFunc(spin);
glutMainLoop();
return 0;
}
