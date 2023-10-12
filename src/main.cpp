#include "core/stdinclude.hpp"

int main(int, char**){
    if(!glfwInit()) return -1;

    GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "MusicPlayer", NULL, NULL);
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    // Setup ImGUI:
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    //ImVec2 windowSize = {WINDOW_WIDTH, WINDOW_HEIGHT};
    ImGui_ImplOpenGL3_Init();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_NewFrame();

    // Setup style:
    ImGui::StyleColorsDark();

    ImVec4 clearColor = ImVec4(0.15f, 0.15f, 0.15f, 1.00f);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        std::cout << "couldn't load OpenGL!" << '\n';
        glfwTerminate();
        return -1;
    }

    glClearColor(0.10f, 0.10f, 0.10f, 1.0f);

    while(!glfwWindowShouldClose(window)){
        glfwPollEvents();
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();

        ImGui::NewFrame();

        ImGui::SetNextWindowSize(ImVec2(WINDOW_WIDTH, WINDOW_HEIGHT));
        if(ImGui::Begin("Test", NULL, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse)){
            if(ImGui::Button("Load Music", ImVec2(100, 50))){

            }
        }
        ImGui::End();
        ImGui::Render();
        ImGui::EndFrame(); 

        int displayWidth, displayHeight;
        glfwGetFramebufferSize(window, &displayWidth, &displayHeight);
        glViewport(0, 0, displayWidth, displayHeight);
        glClearColor(clearColor.x, clearColor.y, clearColor.z, clearColor.w);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Cleanup:
    glfwTerminate();

    return EXIT_SUCCESS;
}