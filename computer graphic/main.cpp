// ����GLEW�� ���徲̬����
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
// ���̻ص�����ԭ������
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

// ���������
const int WINDOW_WIDTH = 800, WINDOW_HEIGHT = 600;


float vertices[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
};

int main(int argc, char** argv)
{

    if (!glfwInit())    // ��ʼ��glfw��
    {
        std::cout << "Error::GLFW could not initialize GLFW!" << std::endl;
        return -1;
    }

    // ����OpenGL 3.3 core profile
    std::cout << "Start OpenGL core profile version 3.3" << std::endl;
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    // ��������
    GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT,
        "Demo of createContext", NULL, NULL);
    if (!window)
    {
        std::cout << "Error::GLFW could not create winddow!" << std::endl;
        glfwTerminate();
        return -1;
    }
    // �����Ĵ��ڵ�contextָ��Ϊ��ǰcontext
    glfwMakeContextCurrent(window);

    // ע�ᴰ�ڼ����¼��ص�����
    glfwSetKeyCallback(window, key_callback);

    // ��ʼ��GLEW ��ȡOpenGL����
    glewExperimental = GL_TRUE; // ��glew��ȡ������չ����
    GLenum status = glewInit();
    if (status != GLEW_OK)
    {
        std::cout << "Error::GLEW glew version:" << glewGetString(GLEW_VERSION)
            << " error string:" << glewGetErrorString(status) << std::endl;
        glfwTerminate();
        return -1;
    }

    // �����ӿڲ���
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
    
    
    // ��ʼ��Ϸ��ѭ��
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents(); // ����������� ���̵��¼�

        // �����ɫ������ ����Ϊָ����ɫ
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window); // ��������
    }
    glfwTerminate(); // �ͷ���Դ
    return 0;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, GL_TRUE); // �رմ���
    }
}
