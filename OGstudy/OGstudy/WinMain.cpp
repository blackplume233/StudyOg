#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <iostream>
#include"MyShader.h"


//float vertices[] = {
//	-0.5f,-0.5f,1.0f,
//	0.5f,-1.0f,0.0f,
//	0.0f,0.5f,0.0f
//};

float vertices[] = {
	// 位置              // 颜色
	0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // 右下
	-0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // 左下
	0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f    // 顶部
};

const char *vertexShaderSource = "#version 330 core\n"
"layout(location = 0) in vec3 aPos;\n"

"void main()\n"
"{\n"
"gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";

const char *fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"uniform vec4 ourColor;\n"
"void main()\n"
"{\n"
"FragColor = ourColor;\n"
"}\0";

float timeValue;
float greenValue; 
int vertexColorLocation; 
unsigned int VAO;
unsigned int vertexShader;
unsigned int VBO;
unsigned int fragmentShader;
unsigned int shaderProgram;
MyShader* ptr;

void framebuffer_callback(GLFWwindow* window, int width, int heigth);
void processInput(GLFWwindow *window);
void inline SetRush();
void inline Rush();
int inline MainWindows() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	GLFWwindow* window = glfwCreateWindow(800, 600, "MyG", NULL, NULL);
	if (window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Faild to initialize GLAD" << std::endl;
		return -1;
	}
	glViewport(0, 0, 800, 600);
	
	glfwSetFramebufferSizeCallback(window, framebuffer_callback);
	SetRush();
	while (!glfwWindowShouldClose(window))
	{
		processInput(window);
		Rush();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}
int main() {

	//std::cout << "Maximum nr of vertex attributes supported: " << nrAttributes << std::endl;
	MainWindows();
	return 0;
}

void framebuffer_callback(GLFWwindow * window, int width, int heigth)
{
	glViewport(0, 0, width, heigth);
}


void processInput(GLFWwindow *window) {
	if (glfwGetKey(window,GLFW_KEY_ESCAPE)==GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
}

inline void SetRush()
{

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices,GL_STATIC_DRAW);

/**	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);

	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	glUseProgram(shaderProgram);
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);**/
	MyShader sd("source/shader.vs", "source/shader.fs");
	ptr = &sd;
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	sd.use();
	
}

inline void Rush()
{
	timeValue = glfwGetTime();
	greenValue = sin(timeValue);
	ptr->use();
	vertexColorLocation = glGetUniformLocation(ptr->ID, "alpha");
	glUniform1f(vertexColorLocation, greenValue);
	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glDrawArrays(GL_TRIANGLES, 0, 6);
}


