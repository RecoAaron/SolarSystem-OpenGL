#include "pch.h"
#include "PlanetTexture.h"


PlanetTexture::PlanetTexture()
{
	texture = 0;
}

PlanetTexture::PlanetTexture(const char * filename, GLuint texture)
{
	this->texture = texture;
	// 图像的存储数组
	vector<unsigned char> image;
	// 图像的宽度和高度
	unsigned int width, height;
	// 加载图片
	unsigned int error = lodepng::decode(image, width, height, filename);
	if (error != 0)
	{
		// 加载图片出错
		cout << "error " << error << ": " << lodepng_error_text(error) << endl;
		return;
	}
	// 启用OpenGL纹理
	glEnable(GL_TEXTURE_2D);
	// 设置读取数据的对齐方式
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	// 绑定该纹理对象
	glBindTexture(GL_TEXTURE_2D, texture);
	// 设置纹理S，T重复方式
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	// 指定纹理贴图和材质混合的方式
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	// 设置纹理过滤选项
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	// 创建MipMap纹理
	gluBuild2DMipmaps(GL_TEXTURE_2D, 4, width, height, GL_RGBA, GL_UNSIGNED_BYTE, &image[0]);
	// 关闭OpenGL纹理
	glDisable(GL_TEXTURE_2D);
}

void PlanetTexture::GLBindTexture()
{
	glBindTexture(GL_TEXTURE_2D, texture);
}
