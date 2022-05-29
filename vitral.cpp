#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>


void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

// settings
const unsigned int SCR_WIDTH = 600;
const unsigned int SCR_HEIGHT =1200;

const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"layout (location = 1) in vec3 aColor;\n"
"out vec3 ourColor;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos, 1.0);\n"
"   ourColor = aColor;\n"
"}\0";

const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"in vec3 ourColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(ourColor, 1.0f);\n"
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
float vertices_vitral[102][3] = {
    //capa                 // colors
    {0.5f, -0.8f,0.0f}, {1.0f, 0.9f, 0.80f,},
    {0.25f ,-0.7f, 0.0f}, {0.94f, 1.0f, 0.85f},
    {0.45f, -0.7f, 0.0f}, {0.90f, 1.0f, 0.90f},
    {-0.2f, -0.7f, 0.0f}, {0.88f, 0.9f, 1.0f},
    {0.5f, -0.5f, 0.0f}, {0.9f, 1.0f, 0.88f},
    {-0.4f, -0.55f, 0.0f}, {0.9f, 0.88f, 1.0f},
    {0.4f, -0.4f, 0.0f}, {0.99f, 1.0f, 0.87f},
    {0.12f, -0.23f, 0.0f}, {0.89f, 1.0f, 0.9f},
    {-0.1f, -0.1f, 0.0f}, {0.8f, 1.0f, 0.89f},
    {-0.6f, 0.25f, 0.0f}, {0.9f, 0.88f, 1.0f},
    {-0.25f, 0.1f, 0.0f}, {0.9f, 0.89f, 1.0f},
    {-0.65f, 0.05f, 0.0f}, {0.9f, 1.0f, 0.8f},
    {-0.6f, 0.4f, 0.0f}, {1.0f, 0.89f, 0.88f},
    {-0.23f, 0.6f, 0.0f}, {0.9f, 0.88f, 1.0f},
    {-0.2f, 0.9f, 0.0f}, {0.88f, 0.87f, 1.0f},
    {-0.1f, 0.8f, 0.0f}, {1.0f, 0.88f, 0.89f},
    {0.1f, 0.85f, 0.0f}, {1.0f, 0.87f, 0.90f},
    {0.3f, 0.83f, 0.0f},{0.87f, 0.89f, 1.0f},
    {0.6f, 0.85f, 0.0f}, {0.87f, 0.87f, 1.0f},

    {0.11f, -0.05f, 0.0f},{0.0f, 0.54f, 0.94f,},
    {0.10f, 0.09f, 0.0f},{0.0f, 0.55f, 0.84f,},
    {0.09f, 0.3f, 0.0f},{0.0f, 0.49f, 0.85f,},
    {0.11f, 0.65f, 0.0f},{0.0f, 0.53f, 0.9f,},
    {0.5f, 0.8f, 0.0f},{0.0f, 0.50f, 0.89f,},
    {0.65f, 0.7f, 0.0f},{0.0f, 0.55f, 0.9f},
    // rostro               // colors
    {0.45f, -0.35f, 0.0f}, {1.0f, 0.62f, 0.17},
    {0.6f, -0.3f, 0.0f}, {1.0f, 0.62f, 0.17},
    {0.73f, -0.1f, 0.0f}, {1.0f, 0.62f, 0.17},
    {0.75f, -0.03f, 0.0f}, {1.0f, 0.62f, 0.17},
    {0.77f, 0.0f, 0.0f}, {1.0f, 0.62f, 0.17},
    {0.45f, 0.03f, 0.0f}, {1.0f, 0.62f, 0.17},
    {0.76f, 0.09f, 0.0f}, {1.0f, 0.62f, 0.17},
    {0.80f, 0.1f, 0.0f}, {1.0f, 0.62f, 0.17},
    {0.82f, 0.2f, 0.0f}, {1.0f, 0.62f, 0.17},
    {0.85f, 0.25f, 0.0f}, {1.0f, 0.62f, 0.17},
    {0.88f, 0.28f, 0.0f}, {1.0f, 0.62f, 0.17},
    {0.82f, 0.3f, 0.0f}, {1.0f, 0.62f, 0.17},
    {0.73f, 0.4f, 0.0f}, {1.0f, 0.62f, 0.17},
    {0.71f, 0.55f, 0.0f}, {1.0f, 0.62f, 0.17},
    {0.74f, 0.6f, 0.0f}, {1.0f, 0.62f, 0.17},
    //fondo               // colors
    {0.0f, -1.0f, 0.0f}, {1.0f, 0.0f, 0.0f},
    {-1.0f, -1.0f, 0.0f}, {0.0f, 1.0f, 0.0f},
    {-1.0f, -0.5f, 0.0f}, {0.0f, 0.0f, 1.0f},
    {-1.0f, 0.0f, 0.0f}, {1.0f, 0.0f, 0.0f},
    {-1.0f, 0.5f, 0.0f}, {0.0f, 1.0f, 0.0f},
    {-1.0f, 1.0f, 0.0f}, {0.0f, 0.0f, 1.0f},
    {1.0f, 1.0f, 0.0f}, {1.0f, 0.0f, 0.0f},
    {1.0f, 0.5f, 0.0f}, {0.0f, 1.0f, 0.0f},
    {1.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 1.0f},
    {1.0f, -0.5f, 0.0f}, {0.0f, 1.0f, 0.0f},
    {1.0f, -1.0f, 0.0f}, {1.0f, 0.0f, 0.0f}
    
    

    
};

unsigned int indices_vitral[] = {
    // capa
    0, 1, 2,
     1, 2, 3,
     2,  3,  4,
     3,  4,  5,
     4,  5,  6,
     5,  6,  7,
     5, 7, 8,
     5, 9, 8,
     8,  9,  10,
     9,  10,  11,
     10,  11,  12,
     10, 12, 13,
     12,  13,  14,
     13, 14, 15,
     14, 15, 16,
     15, 16, 17,
     16, 17, 18,
     7, 8, 19,
     8, 10, 19,
     10, 19, 20,
     10, 20, 21,
     10, 13, 21,
     13, 21, 22,
    13, 15, 22,
    15, 17, 22,
    17, 22, 23,
    18, 23, 24,
    17, 23, 18,
    // rostro
    6, 7, 25,
    7, 25, 26,
    7, 26, 27,
    7, 19, 27,
    19, 27, 28,
    19, 20, 28,
    20, 28, 29,
    20, 29, 30,
    20, 21, 30,
    21, 30, 33,
    30, 32, 33,
    33, 34, 35,
    33, 35, 36,
    21, 33, 36,
    21, 36, 37,
    21, 22, 37,
    22, 37, 38,
    22, 38, 39,
    22, 39, 24,
    22, 23, 24,
    29, 30, 31,
    // fondo
    0,1,40,
    1, 3, 40,
    0, 3, 40,
    3, 41, 42,
    3, 5, 42,
    5, 9, 42,
    9, 42, 43,
    9, 11, 43,
    11, 12, 43,
    12, 43, 44,
    12, 14, 44,
    14, 44, 45,
    14, 16, 46,
    16, 18, 46,
    18, 24, 46,
    24, 39, 46,
    39, 46, 47,
    38, 39, 47,
    37, 38, 47,
    36, 37, 47,
    35, 36, 47,
    35, 47, 48,
    34, 35, 48,
    32, 34, 48,
    32, 32, 48,
    29, 31, 48,
    28, 29, 48,
    27, 28, 48,
    27, 48, 49,
    26, 27, 49,
    6, 25, 26,
    6, 26, 49,
    4, 6, 49,
    2, 4, 49,
    0, 2, 49,
    0,49,50,
    14, 45, 46,
    40, 0, 50,
    0, 40, 41,
    3, 40, 41,
    31, 32, 48,
    32, 33, 34

};



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

float identity[6][6] = {
    {1.0f,0.0f,0.0f,0.0f,0.0f,0.0f},
    {0.0f,1.0f,0.0f,0.0f,0.0f,0.0f},
    {0.0f,0.0f,1.0f,0.0f,0.0f,0.0f},
    {0.0f,0.0f,0.0f,1.0f,0.0f,0.0f},
    {0.0f,0.0f,0.0f,0.0f,1.0f,0.0f},
    {0.0f,0.0f,0.0f,0.0f,0.0f,1.0f}
};

float s1[6][6] = {
            {1.5f,0.0f,0.0f,0.0f,0.0f,0.0f},
            {0.0f,1.5f,0.0f,0.0f,0.0f,0.0f},
            {0.0f,0.0f,1.5f,0.0f,0.0f,0.0f},
            {0.0f,0.0f,0.0f,1.5f,0.0f,0.0f},
            {0.0f,0.0f,0.0f,0.0f,1.5f,0.0f},
            {0.0f,0.0f,0.0f,0.0f,0.0f,1.5f}
};
float s2[6][6] = {
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
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices_vitral), vertices_vitral, GL_STATIC_DRAW);
    // 3. copy our index array in a element buffer for OpenGL to use
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices_vitral), indices_vitral, GL_STATIC_DRAW);
    // 4. then set the vertex attributes pointers
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);


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
        glDrawElements(GL_TRIANGLES, sizeof(indices_vitral), GL_UNSIGNED_INT, 0);
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
    if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS) {

        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices_star), vertices_star, GL_STATIC_DRAW);

        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices_star), indices_star, GL_STATIC_DRAW);
    }
    if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS){
        
        // no se modifica result arreglar bug
        int k = 6;
        int n = 3;
        int m = 6;

        for (int i = 0; i < k; ++i)
            for (int j = 0; j < n; ++j) {
                float s = 0.0f;
                for (int z = 0; z < m; ++z)
                    s += s2[i][z] * vertices_star[z][j];
                result[i][j] = s;
            }
               
        glBufferData(GL_ARRAY_BUFFER, sizeof(result), result, GL_STATIC_DRAW);
        // 3. copy our index array in a element buffer for OpenGL to use
        
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices_star), indices_star, GL_STATIC_DRAW);
     
    }
        
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {

        // no se modifica result arreglar bug
        int k = 6;
        int n = 3;
        int m = 6;

        for (int i = 0; i < k; ++i)
            for (int j = 0; j < n; ++j) {
                float s = 0.0f;
                for (int z = 0; z < m; ++z)
                    s += s1[i][z] * vertices_star[z][j];
                result[i][j] = s;
            }

        glBufferData(GL_ARRAY_BUFFER, sizeof(result), result, GL_STATIC_DRAW);
        // 3. copy our index array in a element buffer for OpenGL to use

        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices_star), indices_star, GL_STATIC_DRAW);

    }
    if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS) {

        // no se modifica result arreglar bug


        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices_star), vertices_star, GL_STATIC_DRAW);
        // 3. copy our index array in a element buffer for OpenGL to use

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
