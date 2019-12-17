#pragma once
#include "GLRequire.h"

struct GLFontMaker
{
	GLuint lists; // 显示列表编号
	GLsizei width; // 窗口宽度
	GLsizei height; // 窗口高度

	// 构造函数
	GLFontMaker();
	
	// 选择字体样式 
	void SelectFont(int size, int charset, const char* face);

	// 输出文字
	void PrintText(float pos_x, float pos_y, float pos_z, const char * str);

	// 屏幕文字
	void PrintTextScreen(struct GLCamera camera, float pos_x, float pos_y, const char * str);
};

