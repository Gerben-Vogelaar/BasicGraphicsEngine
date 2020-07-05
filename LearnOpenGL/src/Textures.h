#ifndef TEXTURE_H
#define TEXTURE_H
#define _CRT_SECURE_NO_WARNINGS


#include <glew.h>
#include <iostream>
#include"stb_image.h"

class Textures
{
public:
	Textures() {
		//TODO: make the texture filtering a seperate method
		// set texture wrapping to GL_REPEAT (default wrapping method)
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		// set texture filtering parameters
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	}

	void addTexture(const char* texture, bool flipOnLoad) {
		glGenTextures(1, &textureList[arrayPointer]);
		glBindTexture(GL_TEXTURE_2D, textureList[arrayPointer]);
		arrayPointer+=1;

		int len = strlen(texture) + 1;
		if (len == NULL || len < 4) {
			std::cout << "FAILED LOADING TEXTURE, WRONG FILE EXTENSION OR WRONG LOCATION" << std::endl;
			return;
		}

		char fileType[4];
		strncpy_s(fileType, texture + len - 4, 3);	
		logTextureSucces(texture, fileType);
				
 		if (flipOnLoad) {
			//stbi_set_flip_vertically_on_load(true);
		}

		int width, height, nrChannels;
		unsigned char* data = stbi_load(texture, &width, &height, &nrChannels, 0);

		if (data) {
			if (strcmp(fileType,"jpg") == 0) {
				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
			}
			else if (strcmp(fileType, "png") == 0) {
				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
			}
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else
		{
			std::cout << "FAILED TO LOAD TEXTURE" << std::endl;
		}
		stbi_image_free(data);
	}

	void activateTextures() {

		for (int i = 0; i < arrayPointer; i++) {
			glActiveTexture(GL_TEXTURE0 + i);
			glBindTexture(GL_TEXTURE_2D, textureList[i]);
		}

		//glActiveTexture(GL_TEXTURE0);
		//glBindTexture(GL_TEXTURE_2D, textureList[0]);
		//glActiveTexture(GL_TEXTURE1);
		//glBindTexture(GL_TEXTURE_2D, textureList[1]);
	}


private:
	unsigned int textureList[16] = {};
	int arrayPointer = 0;
	
	void logTextureSucces(const char* texture, const char* textureType) const{
		for (size_t i = 0; i < strlen(texture); i++) {
			std::cout << texture[i];
		} std::cout << " Succes adding texture of type: ";

		for (size_t i = 0; i < strlen(textureType); i++) {
			std::cout << textureType[i];
		} std::cout << std::endl;
	}

};

#endif
