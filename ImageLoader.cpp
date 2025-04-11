#define _CRT_SECURE_NO_WARNINGS
#include "ImageLoader.h"
#include <fstream>
#include <exception>
#include <iostream>

GLuint ImageLoader::cargarBMP(const char* imagepath) {
	//open
	FILE* file = fopen(imagepath, "rb");
	if (!file) { std::cerr << "Image could not be opened\n"; delete file; return 0; }

	// If not 54 bytes read : problem
	if (fread(header, 1, 54, file) != 54) { 
		std::cerr<< "Not a correct BMP file\n";
		return 0;
	}
	//
	if (header[0] != 'B' || header[1] != 'M') {
		std::cerr << "Not a correct BMP file\n";
		return 0;
	}

	// Read ints from the byte array
	dataPos = *(int*)&(header[0x0A]);
	imageSize = *(int*)&(header[0x22]);
	width = *(int*)&(header[0x12]);
	height = *(int*)&(header[0x16]);

	// Some BMP files are misformatted, guess missing information
	if (imageSize == 0)    imageSize = width * height * 3; // 3 : one byte for each Red, Green and Blue component
	if (dataPos == 0)      dataPos = 54; // The BMP header is done that way

	// Create a buffer
	data = new unsigned char[imageSize];
	// Read the actual data from the file into the buffer
	fread(data, 1, imageSize, file);
	//Everything is in memory now, the file can be closed
	fclose(file);
}

