#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>


void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";
const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
"}\n\0";



/*--------------------forma tonta-------------------*/

   /*
   float vertices[] = {
       // first triangle
        0.5f,  0.5f, 0.0f,  // top right
        0.5f, -0.5f, 0.0f,  // bottom right
       -0.5f,  0.5f, 0.0f,  // top left
       // second triangle
        0.5f, -0.5f, 0.0f,  // bottom right
       -0.5f, -0.5f, 0.0f,  // bottom left
       -0.5f,  0.5f, 0.0f   // top left
   };
   unsigned int indices[] = {  // note that we start from 0!
   0, 1, 2,   // first triangle
   3, 4, 5    // second triangle
   };*/
   // ------------------- forma buena ------------------------ //

float vertices_star[6][3] = {
    {0.0f,  -0.8f, 0.0f},  // star1
    { -0.5f, 0.5f, 0.0f},  // star1
    {0.5f, 0.5f, 0.0f},  // star1
    {0.0f, 0.8f, 0.0f},   // star2
    {-0.5f, -0.3f, 0.0f}, // star2
    {0.5f, -0.3f, 0.0f}  // star2
};
unsigned int indices_star[] = {  // note that we start from 0!
    0, 1, 2,  // first Triangle
    3, 4, 5   // second Triangle
};
float vertices_cuad[4][3] = {
    {-0.5f,0.5f,0.0f},
    {0.5f,0.5f,0.0f},
    {0.5f,-0.5f,0.0f},
    {-0.5f,-0.5f,0.0f}
};
unsigned int indices_cuad[] = {
    0,1,2,
    0,2,3
};

float vertices_hex[7][3] = {
    {-0.25f,0.5f,0.0f}, //v1
    {0.25f,0.5f,0.0f},  //v2
    {-0.5f,0.0f,0.0f},  //v3
    {0.0f,0.0f,0.0f},  //v4
    {0.5f,0.0f,0.0f}, //v5
    {-0.25f,-0.5,0.0f},  //v6
    {0.25f,-0.5f,0.0f}   //v7
};
unsigned int indices_hex[] = {
    0,1,3,
    0,2,3,
    3,1,4,
    2,3,5,
    3,4,6,
    3,5,6
};

unsigned int VBO, VAO, EBO;

int main()
{
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    /*
    float vertices[4][3] = {
    { -0.5f, -0.5f, 0.0f}, // left  
    {0.5f, -0.5f, 0.0f}, // right 
    {0.0f,  0.5f, 0.0f},  // 
    {0.3f,  0.6f, 0.0f}  //        
    };*/
    

    float f = 0.25;
    float s1[3][3] = {
        {0.25f, 0.0f, 0.0f},  // left
        {0.0f, 0.25f, 0.0f},  //right
        {0.0f, 0.0f, 0.25f}  // top
    };

    // build and compile our shader program
    // ------------------------------------
    // vertex shader
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    // check for shader compile errors
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    // fragment shader
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    // check for shader compile errors
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    // link shaders
    unsigned int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    // check for linking errors
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    
   
    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------
    
    
    
    glGenBuffers(1, &EBO);
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);
    // 2. copy our vertices array in a vertex buffer for OpenGL to use
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices_hex), vertices_hex, GL_STATIC_DRAW);
    // 3. copy our index array in a element buffer for OpenGL to use
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices_hex), indices_hex, GL_STATIC_DRAW);
    // 4. then set the vertex attributes pointers
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);


    // uncomment this call to draw in wireframe polygons.
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        
        processInput(window);

        // render
        // ------
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // draw our first triangle
        glUseProgram(shaderProgram);
        glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
        //glDrawArrays(GL_TRIANGLES, 0, 4);
        glDrawElements(GL_TRIANGLES,6*3 , GL_UNSIGNED_INT, 0);
        glBindVertexArray(0); // no need to unbind it every time 

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(shaderProgram);

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS){
        /*
        float v[6][3] = { // 6 x 3 dimension
            {0.0f,  -0.4f, 0.0f},  // star1
            { -0.25f, 0.25f, 0.0f},  // star1
            {0.25f, 0.25f, 0.0f},  // star1
            {0.0f, 0.4f, 0.0f},   // star2
            {-0.25f, -0.15f, 0.0f}, // star2
            {0.25f, -0.15f, 0.0f}  // star2
        };*/
        float s1[6][6] = {
            {0.5f,0.0f,0.0f,0.0f,0.0f,0.0f},
            {0.0f,0.5f,0.0f,0.0f,0.0f,0.0f},
            {0.0f,0.0f,0.5f,0.0f,0.0f,0.0f},
            {0.0f,0.0f,0.0f,0.5f,0.0f,0.0f},
            {0.0f,0.0f,0.0f,0.0f,0.5f,0.0f},
            {0.0f,0.0f,0.0f,0.0f,0.0f,0.5f}
        };
        float result[6][3] = {
            {0.0f,0.0f,0.0f},
            {0.0f,0.0f,0.0f},
            {0.0f,0.0f,0.0f},
            {0.0f,0.0f,0.0f},
            {0.0f,0.0f,0.0f},
            {0.0f,0.0f,0.0f}
        };
        float identity[6][6] = {
            {1.0f,0.0f,0.0f,0.0f,0.0f,0.0f},
            {0.0f,1.0f,0.0f,0.0f,0.0f,0.0f},
            {0.0f,0.0f,1.0f,0.0f,0.0f,0.0f},
            {0.0f,0.0f,0.0f,1.0f,0.0f,0.0f},
            {0.0f,0.0f,0.0f,0.0f,1.0f,0.0f},
            {0.0f,0.0f,0.0f,0.0f,0.0f,1.0f}
        };
        // no se modifica result arreglar bug
        int s;
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                s = 0;
                for (int c = 0; c < 3; c++) {
                    s += s1[i][c] * vertices_star[c][j];
                    result[i][j] = s;
                }
            }
        }

        
        glBufferData(GL_ARRAY_BUFFER, sizeof(result), result, GL_STATIC_DRAW);
        
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices_star), indices_star, GL_STATIC_DRAW);
        
        
    }
        
    
    
        
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    ;
}
