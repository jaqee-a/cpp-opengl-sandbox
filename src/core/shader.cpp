#include <glad/glad.h>

#include <sandbox/core/shader.h>

#include <cstdint>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

Sandbox::Shader::Shader(const char* vertexFp, const char* fragmentFp) {
    
    std::string vertexSource;
    std::string fragmentSource;

    std::ifstream vShaderFile;
    std::ifstream fShaderFile;


    vShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
    fShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);

    try {
        vShaderFile.open(vertexFp);
        fShaderFile.open(fragmentFp);

        std::stringstream vShaderStream;
        std::stringstream fShaderStream;

        vShaderStream << vShaderFile.rdbuf();
        fShaderStream << fShaderFile.rdbuf();

        vShaderFile.close();
        fShaderFile.close();

        vertexSource = vShaderStream.str();
        fragmentSource = fShaderStream.str();
    }catch(std::ifstream::failure e) {
        std::cerr << "ERROR::SHADER::CANNOT_READ_SHADER_FILE";
        exit(-1);
    }

    const char* vShaderSource = vertexSource.c_str();
    const char* fShaderSource = fragmentSource.c_str();

    uint32_t vertex, fragment;

    int success;
    char infoLog[512];

    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vShaderSource, NULL);
    glCompileShader(vertex);

    glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
    if(!success) {
        glGetShaderInfoLog(vertex, 512, NULL, infoLog);
        std::cerr << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog;
        exit(-1);
    }


    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fShaderSource, NULL);
    glCompileShader(fragment);

    glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
    if(!success) {
        glGetShaderInfoLog(fragment, 512, NULL, infoLog);
        std::cerr << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog;
        exit(-1);
    }

    this->ID = glCreateProgram();
    glAttachShader(this->ID, vertex);
    glAttachShader(this->ID, fragment);

    glLinkProgram(this->ID);
    glad_glGetProgramiv(this->ID, GL_LINK_STATUS, &success);

    if(!success) {
        glGetProgramInfoLog(this->ID, 512, NULL, infoLog);
        std::cerr << "ERROR:SHADER::PROGRAM::LINKING_FAILED\n" << infoLog;
        exit(-1);
    }

    glDeleteShader(vertex);
    glDeleteShader(fragment);

}


void Sandbox::Shader::Use() {
    glUseProgram(this->ID);
}


void Sandbox::Shader::setBool  (const char *name, bool     value) const {
    glUniform1i(glGetUniformLocation(this->ID, name), (int) value);
}
void Sandbox::Shader::setInt   (const char *name, int32_t  value) const {
    glUniform1i(glGetUniformLocation(this->ID, name), value);
}
void Sandbox::Shader::setFloat (const char *name, float_t  value) const {
    glUniform1f(glGetUniformLocation(this->ID, name), value);
}
void Sandbox::Shader::setMat4  (const char *name, float_t *value) const {
    glUniformMatrix4fv(glGetUniformLocation(this->ID, name), 1, GL_FALSE, value);
}


