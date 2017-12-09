#pragma once
#include"MyShader.h"

class myog
{
public:
	float timeValue;
	float greenValue;
	int vertexColorLocation;
	unsigned int VAO;
	unsigned int vertexShader;
	unsigned int VBO;
	unsigned int EBO;
	unsigned int fragmentShader;
	unsigned int shaderProgram;
	MyShader ourShader;
	unsigned int texture;
	unsigned int texture1;
	///face run
	float facex = -1.0f;
	float facexa = -1.0f;

	myog(const GLchar* vertexPath, const GLchar* fragmentPath);
	~myog();

	virtual void inline SetRush();
	virtual void inline Rush();

	void Rush(void(*rush)(myog og));
	void SetRush(void(*setrush)(myog og));
	void inline ReadTexTure(unsigned int & texture, const char* path);
	void inline ReadTexTure(unsigned int & texture, const char* path, GLenum format);
};

