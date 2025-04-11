#pragma once
#include <glad/glad.h>


class ImageLoader
{
public:
	ImageLoader() {
		//constructidor
		cargarBMP("./lena.bmp");
	}
	~ImageLoader() {
		//destructarador
	}
	//heimer jungla
	GLuint cargarBMP(const char* imagepath);
	GLuint image{};

	unsigned char header[54]{}; // Each BMP file begins by a 54-bytes header
	unsigned int dataPos{};     // Position in the file where the actual data begins
	unsigned int width, height{};
	unsigned int imageSize{};   // = width*height*3
	// Actual RGB data
	unsigned char* data{};
};

