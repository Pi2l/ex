#include <glad/glad.h>
#include <GLFW/glfw3.h>
// #include <F.hpp>

#include <iostream>
#include <time.h>
int Width = 640;
int Height = 400;

GLfloat points[] = {
     0.0f, +0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
    -0.5f, -0.5f, 0.0f
};
GLfloat colors[] = {
    0.1f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f,
    0.5f, 0.5f, 1.0f
};

const char* vertexShaderSource =
    "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main(){\n"
    "   gl_Position = vec4(aPos,1.0f)\n"
    "}";

void processInput(GLFWwindow *);
void WindowSizeCallback(GLFWwindow* , int ,int );

int main(void)
{
	// std::cout << F() << '\n';
	std::cout << "saads" << '\n';

    GLFWwindow* window;

    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(points), points, GL_STATIC_DRAW);

    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(Width, Height, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
	
    glfwMakeContextCurrent(window);

	if(!gladLoadGL()){
		std::cout << "!glad\n";
		return -1;
	}
	//std::cout << GLVersion.major() << ' ' << GLVersion.manor() << '\n';

	glClearColor(0,1,1,1);
    glfwSetWindowSizeCallback(window,WindowSizeCallback);
    
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
    processInput(window);
    
        glClear(GL_COLOR_BUFFER_BIT);
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }
    
    glfwTerminate();
    return 0;
}
void processInput(GLFWwindow *window)
{
    srand(time(0));
    int a = rand() % 2;
    int b = rand() % 2;
    int c = rand() % 2;
    if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS){
        // glfwSetWindowShouldClose(window, true);
        glClearColor(a,b,c,1);
        std::cout << a << ' ' << b << ' ' << c << '\n';
    }
}
void WindowSizeCallback(GLFWwindow* wind, int w,int h){
    Width = w;
    Height = h;
    glViewport(0, 0, w, h);
    std::cout << "w: " << w << " h: " << h << '\n';
}