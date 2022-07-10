#ifndef RUBICK_H
#define RUBICK_H


#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <shader_m.h>
#include <vector>

#define NCUBES 27

class Cube
{
public:
    glm::vec3 position;
    glm::vec2* texture;
    unsigned int VBO,VAO,VBOc ;
    glm::vec3* root;

    Cube(glm::vec3 pos, glm::vec2 tex, int id) {
        position = pos;
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        glGenBuffers(1, &VBOc);
       
        texture = new glm::vec2[]{
            //red
            glm::vec2(0.25f, 0.25f),
            glm::vec2(0.25f, 0.25f),
            glm::vec2(0.25f, 0.25f),
            glm::vec2(0.25f, 0.25f),
            glm::vec2(0.25f, 0.25f),
            glm::vec2(0.25f, 0.25f),
            // yellow
            glm::vec2(0.35f, 0.35f),
            glm::vec2(0.35f, 0.35f),
            glm::vec2(0.35f, 0.35f),
            glm::vec2(0.35f, 0.35f),
            glm::vec2(0.35f, 0.35f),
            glm::vec2(0.35f, 0.35f),
            // pink
            glm::vec2(0.15f, 0.15f),
            glm::vec2(0.15f, 0.15f),
            glm::vec2(0.15f, 0.15f),
            glm::vec2(0.15f, 0.15f),
            glm::vec2(0.15f, 0.15f),
            glm::vec2(0.15f, 0.15f),
            // black
            glm::vec2(0.4f, 0.9f),
            glm::vec2(0.4f, 0.9f),
            glm::vec2(0.4f, 0.9f),
            glm::vec2(0.4f, 0.9f),
            glm::vec2(0.4f, 0.9f),
            glm::vec2(0.4f, 0.9f),
            // white
            glm::vec2(0.9f, 0.9f),
            glm::vec2(0.9f, 0.9f),
            glm::vec2(0.9f, 0.9f),
            glm::vec2(0.9f, 0.9f),
            glm::vec2(0.9f, 0.9f),
            glm::vec2(0.9f, 0.9f),
            // blue
            glm::vec2(0.5f, 0.9f),
            glm::vec2(0.5f, 0.9f),
            glm::vec2(0.5f, 0.9f),
            glm::vec2(0.5f, 0.9f),
            glm::vec2(0.5f, 0.9f),
            glm::vec2(0.5f, 0.9f)

        };
       
        root = new glm::vec3[]{
            //red
            glm::vec3( - 0.5f + position.x, -0.5f + position.y, -0.5f + position.z),
            glm::vec3(0.5f + position.x, -0.5f + position.y, -0.5f + position.z),
             glm::vec3(0.5f + position.x,  0.5f + position.y, -0.5f + position.z),
             glm::vec3(0.5f + position.x,  0.5f + position.y, -0.5f + position.z),
            glm::vec3(-0.5f + position.x,  0.5f + position.y, -0.5f + position.z),
            glm::vec3(-0.5f + position.x, -0.5f + position.y, -0.5f + position.z),
            // yellow
            glm::vec3(-0.5f + position.x, -0.5f + position.y,  0.5f + position.z),
             glm::vec3(0.5f + position.x, -0.5f + position.y,  0.5f + position.z),
             glm::vec3(0.5f + position.x,  0.5f + position.y,  0.5f + position.z),
             glm::vec3(0.5f + position.x,  0.5f + position.y,  0.5f + position.z),
            glm::vec3(-0.5f + position.x,  0.5f + position.y,  0.5f + position.z),
            glm::vec3(-0.5f + position.x, -0.5f + position.y,  0.5f + position.z),
            //pink
            glm::vec3(-0.5f + position.x,  0.5f + position.y,  0.5f + position.z),
            glm::vec3(-0.5f + position.x,  0.5f + position.y, -0.5f + position.z),
            glm::vec3(-0.5f + position.x, -0.5f + position.y, -0.5f + position.z),
            glm::vec3(-0.5f + position.x, -0.5f + position.y, -0.5f + position.z),
            glm::vec3(-0.5f + position.x, -0.5f + position.y,  0.5f + position.z),
            glm::vec3(-0.5f + position.x,  0.5f + position.y,  0.5f + position.z),
            // black
             glm::vec3(0.5f + position.x,  0.5f + position.y,  0.5f + position.z),
             glm::vec3(0.5f + position.x,  0.5f + position.y, -0.5f + position.z),
             glm::vec3(0.5f + position.x, -0.5f + position.y, -0.5f + position.z),
             glm::vec3(0.5f + position.x, -0.5f + position.y, -0.5f + position.z),
             glm::vec3(0.5f + position.x, -0.5f + position.y,  0.5f + position.z),
             glm::vec3(0.5f + position.x,  0.5f + position.y,  0.5f + position.z),
             //white
            glm::vec3(-0.5f + position.x, -0.5f + position.y, -0.5f + position.z),
             glm::vec3(0.5f + position.x, -0.5f + position.y, -0.5f + position.z),
             glm::vec3(0.5f + position.x, -0.5f + position.y,  0.5f + position.z),
             glm::vec3(0.5f + position.x, -0.5f + position.y,  0.5f + position.z),
            glm::vec3(-0.5f + position.x, -0.5f + position.y,  0.5f + position.z),
            glm::vec3(-0.5f + position.x, -0.5f + position.y, -0.5f + position.z),
            // blue
            glm::vec3(-0.5f + position.x,  0.5f + position.y, -0.5f + position.z),
             glm::vec3(0.5f + position.x,  0.5f + position.y, -0.5f + position.z),
             glm::vec3(0.5f + position.x,  0.5f + position.y,  0.5f + position.z),
             glm::vec3(0.5f + position.x,  0.5f + position.y,  0.5f + position.z),
            glm::vec3(-0.5f + position.x,  0.5f + position.y,  0.5f + position.z),
            glm::vec3(-0.5f + position.x,  0.5f + position.y, -0.5f + position.z)
        };
    };

    glm::vec3 * get_root() {
        return this->root;
    };
    /*float* get_root() {
        return this->root;
    }*/
    glm::vec2* get_colours() {
        return this->texture;
    }

    void prepare_buffer() {

        glBindVertexArray(this->VAO);
        glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 3 * 6 * 6, this->get_root(), GL_STATIC_DRAW);
        glBindBuffer(GL_ARRAY_BUFFER, this->VBOc);
        glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 2 * 6 * 6, this->get_colours(), GL_STATIC_DRAW);


        // position attribute
        glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
        //glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
        glEnableVertexAttribArray(0);
        // texture coord attribute
        glBindBuffer(GL_ARRAY_BUFFER, this->VBOc);
        //glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, NULL);
        glEnableVertexAttribArray(1);
    };
    void rotation_x(glm::vec3 transformation) {
        glm::mat4 rotate(1.0f);
        
        rotate = glm::rotate(rotate, glm::radians(0.5f), glm::vec3(1.0f, 0.0f, 0.0f));
        for (int i = 0; i < 36; i++) {
            glm::vec4 a(root[i], 1.0f);
            root[i] =  rotate*a;
            
        }
        /*glm::vec4 b(position, 1.0f);
        position = rotate*b;*/
        prepare_buffer();
    };
    void rotation_y(glm::vec3 transformation) {
        glm::mat4 rotate(1.0f);
        rotate = glm::rotate(rotate, glm::radians(0.5f), glm::vec3(0.0f, 1.0f, 0.0f));
        for (int i = 0; i < 36; i++) {
            glm::vec4 a(root[i], 1.0f);
            root[i] = rotate*a;
        }
        //glm::vec4 b(position, 1.0f);
        //////rotate = glm::rotate(rotate, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        //position = rotate * b;
        prepare_buffer();
    };
    void rotation_z(glm::vec3 transformation) {
        glm::mat4 rotate(1.0f);
        rotate = glm::rotate(rotate, glm::radians(0.5f), glm::vec3(0.0f, 0.0f, 1.0f));
        for (int i = 0; i < 36; i++) {
            glm::vec4 a(root[i], 1.0f);
            root[i] = rotate*a;
        }
        /*glm::vec4 b(position, 1.0f);
        position = rotate * b;*/
        prepare_buffer();
    };
};

class Rubick 
{
    glm::vec3* bones;
    std::vector<Cube*> cubes;

    //unsigned int VBO[NCUBES], VAO[NCUBES];   // 27 cubos
public:
    Rubick() {
        bones = new glm::vec3[]{
            /// ejes principales
            glm::vec3(0.0f,         0.0f,  0.0f),
            glm::vec3(0.0f + 1.0f,  0.0f,  0.0f),
            glm::vec3(0.0f - 1.0f,  0.0f,  0.0f),
            glm::vec3(0.0f,  0.0f + 1.0f,  0.0f),
            glm::vec3(0.0f,  0.0f - 1.0f,  0.0f),
            glm::vec3(0.0f,  0.0f,  0.0f + 1.0f),
            glm::vec3(0.0f,  0.0f,  0.0f - 1.0f),
            /// plano x = 0
            glm::vec3(0.0f,  0.0f + 1.0f,  0.0f + 1.0f),
            glm::vec3(0.0f,  0.0f + 1.0f,  0.0f - 1.0f),
            glm::vec3(0.0f,  0.0f - 1.0f,  0.0f + 1.0f),
            glm::vec3(0.0f,  0.0f - 1.0f,  0.0f - 1.0f),
            // plano y = 0
            glm::vec3(0.0f + 1.0f,  0.0f,  0.0f + 1.0f),
            glm::vec3(0.0f + 1.0f,  0.0f,  0.0f - 1.0f),
            glm::vec3(0.0f - 1.0f,  0.0f,  0.0f + 1.0f),
            glm::vec3(0.0f - 1.0f,  0.0f,  0.0f - 1.0f),
            // plano z = 0
            glm::vec3(0.0f + 1.0f,  0.0f + 1.0f,  0.0f),
            glm::vec3(0.0f + 1.0f,  0.0f - 1.0f,  0.0f),
            glm::vec3(0.0f - 1.0f,  0.0f + 1.0f,  0.0f),
            glm::vec3(0.0f - 1.0f,  0.0f - 1.0f,  0.0f),
            // complemento 2 ^^ 3 = 8
            glm::vec3(0.0f + 1.0f,  0.0f + 1.0f,  0.0f + 1.0f),
            glm::vec3(0.0f + 1.0f,  0.0f + 1.0f,  0.0f - 1.0f),
            glm::vec3(0.0f + 1.0f,  0.0f - 1.0f,  0.0f + 1.0f),
            glm::vec3(0.0f + 1.0f,  0.0f - 1.0f,  0.0f - 1.0f),
            glm::vec3(0.0f - 1.0f,  0.0f + 1.0f,  0.0f + 1.0f),
            glm::vec3(0.0f - 1.0f,  0.0f + 1.0f,  0.0f - 1.0f),
            glm::vec3(0.0f - 1.0f,  0.0f - 1.0f,  0.0f + 1.0f),
            glm::vec3(0.0f - 1.0f,  0.0f - 1.0f,  0.0f - 1.0f)

        };
    };

    void init() {

      
        for (int i = 0; i < NCUBES; i++) {

            glm::vec2 text(0.0f, 0.0f);
            Cube* cube = new Cube(bones[i], text, i);
            cubes.push_back(cube);
            //glBindVertexArray(VAO[i]);
            cubes[i]->prepare_buffer();
            
        }
    
    };
    

    void render() {

        for (int i = 0; i < NCUBES; i++) {
            glBindVertexArray(cubes[i]->VAO);
            glDrawArrays(GL_TRIANGLES, 0, 3 * 12);
        }
    };
    void deleteVertexArray() {
        for (int i = 0; i < NCUBES; i++) {
            glDeleteVertexArrays(1, &cubes[i]->VAO);
            glDeleteBuffers(1, &cubes[i]->VBO);
        }
    };

    void rotation(glm::vec3 transformation, glm::mat4 model, Shader ourShader) {



        for (int i = 0; i < NCUBES; i++) {
            if (transformation.x) {
                float p = transformation.x;
                p = roundf(p);
                if (cubes[i]->position.x == p) {
                    cubes[i]->rotation_x(transformation);
                }
            }           
            if (transformation.y) {
                float p = transformation.y;
                p = roundf(p);
                if (cubes[i]->position.y == p) {
                    cubes[i]->rotation_y(transformation);
                }
            }
            if (transformation.z) {
                float p = transformation.z;
                p = roundf(p);
                if (cubes[i]->position.z == p) {
                    cubes[i]->rotation_z(transformation);
                }
            }
        }
    };
};


#endif
