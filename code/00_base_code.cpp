#define GLFW_INCLUDE_VULKAN // GLFW 会 include 自己的定义，也会 #include <vulkan/vulkan.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <stdexcept>
#include <cstdlib>

const uint32_t WIDTH = 800;
const uint32_t HEIGHT = 600;

class HelloTriangleApplication {
public:
    void run() {
        initWindow();
        initVulkan();
        mainLoop();
        cleanup();
    }

private:
    GLFWwindow* window;

    void initWindow() {
        glfwInit(); // 初始化 GLFW library

        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API); // 不要创建 OpenGL 的上下文
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE); // 禁用调整窗口大小

        window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", nullptr, nullptr);
    }

    void initVulkan() {
        // vkCreateXXX
        // vkAllocateXXX
    }

    void mainLoop() {
        while (!glfwWindowShouldClose(window)) {
            glfwPollEvents(); // 检查 Event
        }
    }

    void cleanup() {
        // vkDestroyXXX
        // vkFreeXXX

        glfwDestroyWindow(window);
        glfwTerminate();
    }
};

int main() {
    HelloTriangleApplication app{};

    try {
        app.run();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
