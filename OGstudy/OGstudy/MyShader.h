#pragma once
#include"glad\glad.h"
class MyShader
{
public:
	int ID;
	MyShader(const GLchar* vertexPath,const GLchar* fragmentPath);
	void use();

	~MyShader();
};

