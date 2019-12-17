#include "pch.h"
#include "GLFontMaker.h"


GLFontMaker::GLFontMaker()
{
	lists = glGenLists(MAX_CHAR);
	wglUseFontBitmaps(wglGetCurrentDC(), 0, MAX_CHAR, lists);
	width = GL_WINDOW_WIDTH;
	height = GL_WINDOW_HEIGHT;
}



void GLFontMaker::SelectFont(int size, int charset, const char * face)
{
	HFONT hFont = CreateFontA(size, 0, 0, 0, FW_MEDIUM, 0, 0, 0,
		charset, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
		DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, face);
	HFONT hOldFont = (HFONT)SelectObject(wglGetCurrentDC(), hFont);
	DeleteObject(hOldFont);
}

void GLFontMaker::PrintText(float pos_x, float pos_y, float pos_z, const char * str)
{
	glEnable(GL_COLOR_MATERIAL);
	glColor3f(0.0f, 0.0f, 0.6f);
	glRasterPos3f(pos_x, pos_y, pos_z);
	for (; *str != '\0'; ++str) 
	{
		glCallList(lists + *str);
	}
	glDisable(GL_COLOR_MATERIAL);
}

void GLFontMaker::PrintTextScreen(struct GLCamera camera, float pos_x, float pos_y, const char * str)
{
	glPushMatrix();
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-10, 10, -10, 10);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glEnable(GL_COLOR_MATERIAL);
	// 此处进行屏幕的绘制
	glColor3f(1.0, 1.0, 1.0);
	glRasterPos2f(-10 + pos_x, 10 - pos_y);
	for (; *str != '\0'; ++str)
	{
		glCallList(lists + *str);
	}
	glDisable(GL_COLOR_MATERIAL);
	// 此处结束屏幕的绘制
	glPopMatrix();
}
