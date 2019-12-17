#pragma once
#include "GLRequire.h"

struct GLSkyBox
{
	float POS_X; // 中心 x 坐标
	float POS_Y; // 中心 y 坐标
	float POS_Z; // 中心 z 坐标
	GLuint texture_id[6]; // 天空盒 6 面纹理对象 id
	float size; // 天空盒大小

	// 天空盒构造函数
	GLSkyBox();

	// 天空盒构造函数
	GLSkyBox(float pos_x, float pos_y, float pos_z, const char *texture_file[6], GLuint texture_id[6], float size);

	// 天空盒更新坐标
	void UpdatePosition(float pos_x, float pos_y, float pos_z);

	// 天空盒绘制场景
	void DrawScence();
};

