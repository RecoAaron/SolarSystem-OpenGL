#include "pch.h"
#include "Planet.h"


Planet::Planet()
{
	AroundPos = 0;
	SelfPos = 0;
	AroundSpeed = 0;
	SelfSpeed = 0;
	AroundRadius = 0;
	SelfRadius = 0;
	texture = NULL;
	father = NULL;
}

Planet::Planet(const char * texname, float as, float ss, float ar, float sr, struct Planet* father_p, GLuint texture_id)
{
	texture = new PlanetTexture(texname, texture_id);
	father = father_p;
	if (father_p != NULL)
		AroundPos = float(rand() % 360);
	else
		AroundPos = 0;
	AroundSpeed = as;
	AroundRadius = ar;
	SelfPos = 0;
	SelfSpeed = ss;
	SelfRadius = sr;
}

void Planet::GetPosition(bool needRadius)
{
	if (father != NULL)
	{
		// 如果中心天体不是恒心，则先过去中心天体的坐标信息
		father->GetPosition(needRadius);
		// 然后，变换回中心天体的自转
		glRotatef(-father->SelfPos, 0.0f, 1.0f, 0.0f);
		//// 绘制公转轨道
		if (needRadius)
		{
			glPushMatrix();// 保存当前模型视图矩阵
			// 绘制星球轨道
			glBegin(GL_LINE_LOOP);
			for (int i = 0; i < 360; i++)
				glVertex3f(AroundRadius*sin(EDGE_ANGLE*i), 0, AroundRadius*cos(EDGE_ANGLE*i));
			glEnd();
			glPopMatrix();// 重置模型视图矩阵
		}
	}
	// 变换天体的公转角度
	glRotatef(AroundPos, 0.0f, 1.0f, 0.0f);
	// 移动至天体的位置
	glTranslatef(AroundRadius, 0.0f, 0.0f);
	// 变换天体的自转角度
	glRotatef(SelfPos, 0.0f, 1.0f, 0.0f);
}

void Planet::DrawPlanet(bool needRadius, int Speed)
{
	// 获取行星的纹理对象
	texture->GLBindTexture();
	// 进行坐标系变换
	GetPosition(needRadius);
	// 将星球旋转90度，保证纹理位置正确
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	// 设置绘制模式为矩形绘制
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);
	// 创建二次曲面对象
	GLUquadricObj   *uquadric = gluNewQuadric();
	// 设置二次曲面光滑
	gluQuadricNormals(uquadric, GL_SMOOTH);
	// 启动二次曲面纹理
	gluQuadricTexture(uquadric, TRUE);
	// 绘制球体二次曲面
	gluSphere(uquadric, SelfRadius, 100, 100);
	// 删除二次曲面对象
	gluDeleteQuadric(uquadric);
	// 结束绘制
	glEnd();
	
	// 更新行星的位置信息
	float _speed = 0;
	if (Speed == 0)
		_speed = UPDATE_PAUSE;
	if (Speed == 1)
		_speed = UPDATE_LOW;
	if (Speed == 2)
		_speed = UPDATE_MID;
	if (Speed == 3)
		_speed = UPDATE_HIGH;

	AroundPos += (AroundSpeed * _speed);
	SelfPos += (SelfSpeed*_speed);

	if (AroundPos > 360)
		AroundPos = 0;
	if (SelfPos > 360)
		SelfPos = 0;
	// 将坐标系还原
	glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
}
