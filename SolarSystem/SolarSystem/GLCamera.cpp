#include "pch.h"
#include "GLCamera.h"
#include <math.h>


GLCamera::GLCamera(float eye_x, float eye_y, float eye_z, float view_pos)
{
	this->EYE_X = eye_x;
	this->EYE_Y = eye_y;
	this->EYE_Z = eye_z;

	VIEW_POS = 0;
}

void GLCamera::GLMove(float offset_right, float offset_up, float offset_forward)
{
	EYE_Y = EYE_Y + offset_up;

	EYE_X = EYE_X + offset_forward * float(sin(VIEW_POS));
	EYE_Z = EYE_Z + offset_forward * float(-cos(VIEW_POS));

	EYE_X = EYE_X + offset_right * float(cos(VIEW_POS));
	EYE_Z = EYE_Z + offset_right * float(sin(VIEW_POS));
}

void GLCamera::GLRotate(float offset_view_pos)
{
	VIEW_POS += offset_view_pos;
	if (VIEW_POS < -180)
		VIEW_POS = 180;
	if (VIEW_POS > 180)
		VIEW_POS = -180;
}
