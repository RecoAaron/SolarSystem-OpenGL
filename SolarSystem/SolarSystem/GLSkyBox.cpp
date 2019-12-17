#include "pch.h"
#include "GLSkyBox.h"


GLSkyBox::GLSkyBox()
{
	POS_X = 0;
	POS_Y = 0;
	POS_Z = 0;
	for (int i = 0; i < 6; i++)
	{
		texture_id[i] = 0;
	}
	size = 0;
}

GLSkyBox::GLSkyBox(float pos_x, float pos_y, float pos_z, const char *texture_file[6], GLuint texture_id[6], float size)
{
	POS_X = pos_x;
	POS_Y = pos_y;
	POS_Z = pos_z;

	this->size = size;

	for (int i = 0; i < 6; i++)
	{
		this->texture_id[i] = texture_id[i];
	}

	glEnable(GL_TEXTURE_2D);
	for (int i = 0; i < 6; i++)
	{
		unsigned int width, height;
		std::vector<unsigned char> star;
		unsigned int error = lodepng::decode(star, width, height, texture_file[i]);
		if (error != 0)
		{
			std::cout << "error " << error << ": " << lodepng_error_text(error) << std::endl;
			return;
		}
		glBindTexture(GL_TEXTURE_2D, texture_id[i]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		gluBuild2DMipmaps(GL_TEXTURE_2D, 4, width, height, GL_RGBA, GL_UNSIGNED_BYTE, &star[0]);
	}
}

void GLSkyBox::UpdatePosition(float pos_x, float pos_y, float pos_z)
{
	POS_X = pos_x;
	POS_Y = pos_y;
	POS_Z = pos_z;
}

void GLSkyBox::DrawScence()
{
	// 绘制前面
	glBindTexture(GL_TEXTURE_2D, texture_id[0]);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex3f(-size, size, -size);
	glTexCoord2f(1, 0); glVertex3f(size, size, -size);
	glTexCoord2f(1, 1); glVertex3f(size, -size, -size);
	glTexCoord2f(0, 1); glVertex3f(-size, -size, -size);
	glEnd();
	// 绘制后面
	glBindTexture(GL_TEXTURE_2D, texture_id[1]);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex3f(size, size, size);
	glTexCoord2f(1, 0); glVertex3f(-size, size, size);
	glTexCoord2f(1, 1); glVertex3f(-size, -size, size);
	glTexCoord2f(0, 1); glVertex3f(size, -size, size);
	glEnd();
	// 绘制左面
	glBindTexture(GL_TEXTURE_2D, texture_id[2]);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex3f(size, size, -size);
	glTexCoord2f(1, 0); glVertex3f(size, size, size);
	glTexCoord2f(1, 1); glVertex3f(size, -size, size);
	glTexCoord2f(0, 1); glVertex3f(size, -size, -size);
	glEnd();
	// 绘制右面
	glBindTexture(GL_TEXTURE_2D, texture_id[3]);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex3f(-size, size, size);
	glTexCoord2f(1, 0); glVertex3f(-size, size, -size);
	glTexCoord2f(1, 1); glVertex3f(-size, -size, -size);
	glTexCoord2f(0, 1); glVertex3f(-size, -size, size);
	glEnd();
	// 绘制上面
	glBindTexture(GL_TEXTURE_2D, texture_id[4]);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex3f(-size, size, size);
	glTexCoord2f(1, 0); glVertex3f(size, size, size);
	glTexCoord2f(1, 1); glVertex3f(size, size, -size);
	glTexCoord2f(0, 1); glVertex3f(-size, size, -size);
	glEnd();
	// 绘制下面
	glBindTexture(GL_TEXTURE_2D, texture_id[5]);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex3f(-size, -size, -size);
	glTexCoord2f(1, 0); glVertex3f(size, -size, -size);
	glTexCoord2f(1, 1); glVertex3f(size, -size, size);
	glTexCoord2f(0, 1); glVertex3f(-size, -size, size);
	glEnd();
}

