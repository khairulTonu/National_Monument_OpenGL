#include<windows.h>
#include<windows.h>
#include<GL/glut.h>
#include <stdlib.h>
#include<bits/stdc++.h>


float angle=0.0;
float lx=0.0f,lz=-1.0f,ll=0.0f;;
static int slices = 16;
static int stacks = 16;
static int dx = 0;
static int dy = 0;
static int dz = 8;
float xx=0,zz=0;
float x=1.0f,z=5.0f;
float tableStandWidth = 0.2f;

GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat mat_ambient[] = { 0.5, 0.0, 0.0, 1.0 };
GLfloat mat_diffuse[] = { 1.0, 0.0, 0.0, 1.0 };
GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat mat_shininess[] = {10};

GLfloat no_mat2[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat mat_ambient2[] = { 0.0, 0.5, 0.0, 1.0 };
GLfloat mat_diffuse2[] = { 0.0, 1.0, 0.0, 1.0 };
GLfloat mat_specular2[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat mat_shininess2[] = {10};

GLfloat no_mat3[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat mat_ambient3[] = { 0.0, 0.0, 0.5, 1.0 };
GLfloat mat_diffuse3[] = { 0.0, 0.0, 1.0, 1.0 };
GLfloat mat_specular3[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat mat_shininess3[] = {10};

GLfloat no_mat4[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat mat_ambient4[] = { 0.0, 0.5, 0.5, 1.0 };
GLfloat mat_diffuse4[] = { 0.0, 0.5, 1.0, 1.0 };
GLfloat mat_specular4[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat mat_shininess4[] = {10};

GLfloat no_mat5[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat mat_ambient5[] = { 0.75, 0.5, 0.5, 1.0 };
GLfloat mat_diffuse5[] = { 0.5, 0.5, 1.0, 1.0 };
GLfloat mat_specular5[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat mat_shininess5[] = {10};

GLfloat no_mat6[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat mat_ambient6[] = { 0.75, 1.0, 0.5, 1.0 };
GLfloat mat_diffuse6[] = { 0.25, 1.0, 1.0, 1.0 };
GLfloat mat_specular6[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat mat_shininess6[] = {10};

GLfloat no_light[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat light_ambient[] = {1.0, 1.0, 1.0, 1.0};
GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1 };
GLfloat light_specular[] = { 1, 1, 1, 1 };
GLfloat light_position[] = { 2.0, 25.0, 3.0, 1.0 };

void drawWalls()
{

    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    const double a = t*90.0;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient2);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse2);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular2);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess2);
    //glColor3d(1,0,0);
    //glColor3d(0,0.5,0.5);
    glPushMatrix();
    glTranslated(0,-1,-1);
    glRotated(15,1,0,0);


    //floor
    glPushMatrix();
    glTranslated(0,0,0);
    glScaled(8,0.2,4);
    glutSolidCube(1);
    glPopMatrix();

    //left wall
    glPushMatrix();
    glTranslated(-4,1.9,0);
    glScaled(0.2,4,4);
    glutSolidCube(1);
    glPopMatrix();

    //right wall
    glPushMatrix();
    glTranslated(4,1.9,0);
    glScaled(0.2,4,4);
    glutSolidCube(1);
    glPopMatrix();

    //back wall
    glPushMatrix();
    glTranslated(0,1.9,-1.9);
    glScaled(8,4,0.2);
    glutSolidCube(1);
    glPopMatrix();



    glPopMatrix();



}

void drawTable()
{
    // Table start

    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient2);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse2);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular2);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess2);
    //glColor3d(1,1,0);

    glPushMatrix();
    glTranslated(0,-1,-1);
    glRotated(15,1,0,0);
    //table head
    glPushMatrix();
    glTranslated(0,2,0);
    //glColor3d(1,1,0);
    glScaled(3,0.2,3);
    glutSolidCube(1);
    glPopMatrix();

    //right front leg
    glPushMatrix();
    glTranslated(1.2,1,1.2);
    //glColor3d(1,1,0);
    glScaled(0.2,2,0.2);
    glutSolidCube(1);
    glPopMatrix();

    //left front leg
    glPushMatrix();
    glTranslated(-1.2,1,1.2);
    //glColor3d(1,1,0);
    glScaled(0.2,2,0.2);
    glutSolidCube(1);
    glPopMatrix();

    //left back leg
    glPushMatrix();
    glTranslated(-1.2,1,-1.2);
    //glColor3d(1,1,0);
    glScaled(0.2,2,0.2);
    glutSolidCube(1);
    glPopMatrix();

    //right back leg
    glPushMatrix();
    glTranslated(1.2,1,-1.2);
    //glColor3d(1,1,0);
    glScaled(0.2,2,0.2);
    glutSolidCube(1);
    glPopMatrix();

    glPopMatrix();


}

void myDesign()
{

    float x1 = 0.2, x2, _x1 = -.2, _x2, _z1 = -0.2, _z2, y1 = 3.0, y2, top = 0;
    float r = 1, g = 1, b = 1;

    for(int i = 0; i < 7; i++)
    {
        x2 = x1+0.1;
        _x2 = _x1-0.1;
        _z2 = _z1-0.1;
        y2 = y1+0.1;

        glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient2);
        glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse2);
        glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular2);
        glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess2);



        //glColor3d(.1,0.5,0.9);
        glColor3d(0.5,0.5,0.5);
        glBegin(GL_TRIANGLE_FAN);
        glVertex3f(0, 0, _z1);//v2
        glVertex3f(x1, 0, 0);//v1
        glVertex3f(0, y1, _z1);//v3
        glVertex3f(_x1, 0, 0);//v4
        glEnd();

        glColor3d(1,1,1);
        glBegin(GL_TRIANGLE_FAN);
        glVertex3f(0, 0, _z2);//v2
        glVertex3f(x2, 0, 0);//v1
        glVertex3f(0, y2, _z1-0.1);//v3
        glVertex3f(_x2, 0, 0);//v4
        glEnd();

        glColor3d(1,1,1);
        glBegin(GL_QUADS);
        glVertex3f(x1, 0, 0);
        glVertex3f(x2, 0, 0);
        glVertex3f(0, y2, _z1-0.1);
        glVertex3f(0, y1, _z1);
        glEnd();

        glColor3d(.4,1,0);
        glBegin(GL_QUADS);
        glVertex3f(_x1, 0, 0);
        glVertex3f(_x2, 0, 0);
        glVertex3f(0, y2, _z1-0.1);
        glVertex3f(0, y1, _z1);
        glEnd();
        x1 += 0.3;
        _x1 -= 0.3;
        _z1 -= 0.3;
        y1 -= 0.4;
        top -= 0.2;
    }
}

void draw()
{

    glPushMatrix();
    drawWalls();
    glPopMatrix();

    glPushMatrix();
    drawTable();
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.25, 0.8, 1);
    glScaled(.5,.6,.4);
    myDesign();
    glPopMatrix();

}

void changeSize(int w, int h)
{
    if (h == 0)
        h = 1;
    float ratio =  w * 1.0 / h;

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    glViewport(0, 0, w, h);

    gluPerspective(100.0f, ratio, 0.5f, 100.0f);

    glMatrixMode(GL_MODELVIEW);
}

bool rot = true;
void renderScene()
{

    const double t = glutGet(GLUT_ELAPSED_TIME) / 1900.0;
    double a;

    if(rot)
    {
        a = t*90.0;
    }
    else
    {
        a = t;
    }

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    gluLookAt(	x + 5*sin(ll), 1.0f, z + 5*cos(ll),
                x+lx, 1.0f,  z+lz,
                0.0f, 1.0f,  0.0f);


    glPushMatrix();
    glRotated(0,0.5,1,0);
    //glRotated(a,0,1,0);
    draw();
    glPopMatrix();
    glutSwapBuffers();
}

void processSpecialKeys(int key, int x, int y)
{

    float fraction = 0.3f;

    switch (key)
    {

    case GLUT_KEY_LEFT :
        angle -= 0.05f;
        lx = sin(angle);
        lz = -cos(angle);
        break;
    case GLUT_KEY_RIGHT :
        angle += 0.05f;
        lx = sin(angle);
        lz = -cos(angle);
        break;
    case GLUT_KEY_UP :
        x += lx * fraction;
        z += lz * fraction;
        break;
    case GLUT_KEY_DOWN :
        x -= lx * fraction;
        z -= lz * fraction;
        break;
    case GLUT_KEY_HOME :
        ll += .05;
        break;
    }

    glutPostRedisplay();

}

static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27 :
    case 'q':
        exit(0);
        break;

    case 'z':
        dz++;
        stacks++;
        break;

    case 'x':
        dx++;
        break;

    case 'X':
        dx--;
        break;

    case 'Y':
        dy++;
        break;

    case 'y':
        dy--;
        break;

    case 'a' :
        xx += .01 * .1;
        //zz += .1 * .5;
        gluLookAt(	0.0f, 1.0f, 5.0f,
                    xx+0.0f, 1.0f,  2.0f,
                    0.0f, 1.0f,  0.0f);
        break;
    case 'b' :
        xx -= .01 * .1;
        //zz -= .01 * .5;
        gluLookAt(	0.0f, 1.0f, 5.0f,
                    xx+1.0, 1.0f, 2.0,
                    0.0f, 1.0f,  0.0f);
        break;
    case 'Z':
        if (slices>3 && stacks>3)
        {
            dz--;
            stacks--;
        }
        break;
    }

    glutPostRedisplay();
}




int main(int argc, char **argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(1366,720);
    glutCreateWindow("Saheed Minar");

    // register callbacks
    glutDisplayFunc(renderScene);
    glutReshapeFunc(changeSize);
    glutIdleFunc(renderScene);
    glutSpecialFunc(processSpecialKeys);
    glutKeyboardFunc(key);

    glClearColor(1,1,1,1);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    /*glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);*/

    // enter GLUT event processing cycle
    glutMainLoop();
    return 1;
}


