#pragma once
#include "GLRequire.h"

struct PlanetTexture
{
	GLuint texture; // 纹理对象 id

	// 纹理构造函数
	PlanetTexture();

	// 纹理构造函数
	PlanetTexture(const char * filename, GLuint texture);

	// 绑定当前纹理
	void GLBindTexture();
};

