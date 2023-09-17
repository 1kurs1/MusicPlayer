#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main(int, char**){
    if(!glfwInit()) return -1;

    GLFWwindow* window = glfwCreateWindow(800, 640, "MusicPlayer", NULL, NULL);
    glfwMakeContextCurrent(window);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        std::cout << "couldn't load OpenGL!" << '\n';
        glfwTerminate();
        return -1;
    }

    glClearColor(0.10f, 0.10f, 0.10f, 1.0f);

    while(!glfwWindowShouldClose(window)){
        glfwPollEvents();
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return EXIT_SUCCESS;
}