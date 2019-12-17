#pragma once
// 包含程序中用到的所有的头文件
#include "GL/glew.h"
#include "GL/glut.h"

#include <math.h>
#include <Windows.h>
#include <mmsystem.h>

#include <vector>
#include <iostream>

#include "PngLoader.h"
#include "PlanetTexture.h"
#include "GLCamera.h"
#include "Planet.h"
#include "GLSkyBox.h"
#include "GLFontMaker.h"

#pragma comment(lib,"winmm.lib")


using namespace std;

#define GL_WINDOW_WIDTH			1200 // 窗口的宽度
#define GL_WINDOW_HEIGHT		800 // 窗口的高度

#define GL_DISPLAY_MODE			GLUT_RGBA | GLUT_DOUBLE // 窗口显示模式设置

#define MAX_CHAR				128 // 字符绘制种类

#define EYE_POS_X				0	// 摄像机初始 x 坐标
#define EYE_POS_Y				0	// 摄像机初始 y 坐标290
#define EYE_POS_Z				100 // 摄像机初始 z 坐标340

#define MOVE_SPEED				100 // 移动速度
#define JUMP_SPEED				100 // 上下速度
#define ROTATE_SPEED			2 // 旋转速度

#define UPDATE_PAUSE			0 // 更新暂停
#define UPDATE_LOW				0.3f // 慢速正常
#define UPDATE_MID				1.0f // 正常更新
#define UPDATE_HIGH				2.0f // 加速更新

#define VIEW_ANGLE				45 // 视角角度
#define VIEW_ANGLE_MAX			120 // 视角角度最大值
#define VIEW_ANGLE_MIN			30 // 视角角度最小值

#define VIEW_DOWN				0.0f // 俯看值-1.0
#define VIEW_DOWN_MAX			2.0f // 俯看值最大值
#define VIEW_DOWN_MIN			-2.0f // 俯看值最小值

#define SKYBOX_SIZE				700 // 天空盒大小

#define PLANET_COUNT			11 // 行星数量

#define EDGE_ANGLE				0.017453f  // 2PI/360
