//
// Created by yobin_he on 2026/6/14.
//

#include <malloc.h>
#include "ShaderUtils.h"
#include "LogUtils.h"
#include <GLES2/gl2ext.h>

GLuint ShaderUtils::LoadShader(GLenum shaderType, const char *pSource) {
    GLuint shader = glCreateShader(shaderType);
    if (shader) {
        glShaderSource(shader, 1, &pSource, NULL); //将shader与pSource链接
        glCompileShader(shader); //编译
        GLint compiled = 0;
        glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
        if (!compiled) {
            GLint infoLen = 0;
            glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLen);
            if (infoLen) {
                char *buf = (char *) malloc((size_t) infoLen);
                if (buf) {
                    glGetShaderInfoLog(shader, infoLen, NULL, buf);
                    LOGCATE("GLUtils::LoadShader Could not compile shader %d:\n%s\n", shaderType,
                            buf);
                    free(buf);
                }
                glDeleteShader(shader);
                shader = 0;
            }
        }
    }
    return shader;
}

GLuint ShaderUtils::CreateProgram(const char *pVertexShaderSource, const char *pFragShaderSource,
                                  GLuint &vertexShaderHandle, GLuint &fragShaderHandle) {
    GLuint  program = 0;
    vertexShaderHandle = LoadShader(GL_VERTEX_SHADER,pVertexShaderSource);
    if(!vertexShaderHandle) return program;
    fragShaderHandle = LoadShader(GL_FRAGMENT_SHADER,pFragShaderSource);
    if(!fragShaderHandle) return program;

    program = glCreateProgram();
    if(program){
        glAttachShader(program,vertexShaderHandle);
        CheckError("glAttachShader vertexShaderHandle");
        glAttachShader(program,fragShaderHandle);
        CheckError("glAttachShader fragShaderHandle");
        glLinkProgram(program);

        GLint linkState = GL_FALSE;
        glGetProgramiv(program,GL_LINK_STATUS,&linkState);

        glDetachShader(program,vertexShaderHandle);
        glDeleteShader(vertexShaderHandle);
        vertexShaderHandle = 0;

        glDetachShader(program,fragShaderHandle);
        glDeleteShader(fragShaderHandle);
        fragShaderHandle = 0;

        if(linkState != GL_TRUE){
            GLint  bufLength = 0;
            glGetProgramiv(program,GL_INFO_LOG_LENGTH,&bufLength);
            if (bufLength) {
                char *buf = (char *) malloc((size_t) bufLength);
                if (buf) {
                    glGetProgramInfoLog(program, bufLength, NULL, buf);
                    LOGCATE("ShaderUtils::CreateProgram Could not link program:\n%s\n", buf);
                    free(buf);
                }
            }
            glDeleteProgram(program);
            program = 0;
        }
    }
    LOGCATE("ShaderUtils::CreateProgram program = %d", program);
    return program;
}

void ShaderUtils::DeleteProgram(GLuint &program) {
    LOGCATE("ShaderUtils::DeleteProgram");
    if (program)
    {
        glUseProgram(0);
        glDeleteProgram(program);
        program = 0;
    }
}

void ShaderUtils::CheckError(const char *pGLOperation) {
    for (GLint error = glGetError(); error; error = glGetError()) {
        LOGCATE("ShaderUtils::CheckGLError GL Operation %s() glError (0x%x)\n", pGLOperation,
                error);
    }
}
