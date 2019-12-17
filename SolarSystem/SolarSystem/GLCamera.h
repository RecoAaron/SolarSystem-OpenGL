#pragma once
#include "GLRequire.h"

// 摄像机的封装类
struct GLCamera
{
	float EYE_X; // 摄像机的 x 坐标
	float EYE_Y; // 摄像机的 y 坐标
	float EYE_Z; // 摄像机的 z 坐标

	float VIEW_POS; // 摄像机旋转量

	// 摄像机的构造函数
	GLCamera(float eye_x, float eye_y, float eye_z, float view_pos);

	// 摄像机移动
	void GLMove(float offset_right, float offset_up, float offset_forward);

	// 摄像机旋转
	void GLRotate(float offset_view_pos);
};

