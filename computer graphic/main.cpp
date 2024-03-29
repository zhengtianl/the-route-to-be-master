// 引入GLEW库 定义静态链接
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include <glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtx/transform2.hpp>
#include<glm/gtx/euler_angles.hpp>
// 键盘回调函数原型声明
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

// 定义程序常量
const int WINDOW_WIDTH = 800, WINDOW_HEIGHT = 600;


float vertices[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
};

int main(int argc, char** argv)
{

    if (!glfwInit())    // 初始化glfw库
    {
        std::cout << "Error::GLFW could not initialize GLFW!" << std::endl;
        return -1;
    }

    // 开启OpenGL 3.3 core profile
    std::cout << "Start OpenGL core profile version 3.3" << std::endl;
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    // 创建窗口
    GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT,
        "Demo of createContext", NULL, NULL);
    if (!window)
    {
        std::cout << "Error::GLFW could not create winddow!" << std::endl;
        glfwTerminate();
        return -1;
    }
    // 创建的窗口的context指定为当前context
    glfwMakeContextCurrent(window);

    // 注册窗口键盘事件回调函数
    glfwSetKeyCallback(window, key_callback);

    // 初始化GLEW 获取OpenGL函数
    glewExperimental = GL_TRUE; // 让glew获取所有拓展函数
    GLenum status = glewInit();
    if (status != GLEW_OK)
    {
        std::cout << "Error::GLEW glew version:" << glewGetString(GLEW_VERSION)
            << " error string:" << glewGetErrorString(status) << std::endl;
        glfwTerminate();
        return -1;
    }

    // 设置视口参数
    glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
    //VERTEX SHADER
    unsigned int VAO;
    glGenBuffers(1, &VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VAO);

    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    //framgent shader
    
    
    // 开始游戏主循环
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents(); // 处理例如鼠标 键盘等事件

        // 清除颜色缓冲区 重置为指定颜色
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window); // 交换缓存
    }
    glfwTerminate(); // 释放资源
    return 0;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, GL_TRUE); // 关闭窗口
    }
}
