#pragma once
#include "GLRequire.h"

struct Planet
{
	float AroundPos;	// 公转角度值
	float SelfPos;		// 自转角度值

	float AroundSpeed;	//公转速度
	float SelfSpeed;	//自转速度

	float AroundRadius;	// 行星的围绕半径
	float SelfRadius;	// 行星的半径

	struct Planet * father; // 中心天体的指针

	struct PlanetTexture* texture; // 行星的纹理

	// 行星的构造函数
	Planet();

	// 行星的构造函数
	Planet(const char * texname, float as, float ss, float ar, float sr, struct Planet* father, GLuint texture_id);

	// 获取天体的坐标信息
	void GetPosition(bool needRadius);

	// 行星的绘制函数
	void DrawPlanet(bool needRadius, int Speed);
};


