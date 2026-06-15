//
// Created by yobin_he on 2026/6/14.
//

#ifndef NDKOPENGLSTUDY_SHADERUTILS_H
#define NDKOPENGLSTUDY_SHADERUTILS_H

#include <GLES3/gl3.h>

class ShaderUtils {
public:
    static GLuint LoadShader(GLenum shaderType, const char *pSource);

    // * 指针 &引用
    static GLuint CreateProgram(const char *pVertexShaderSource,  // 传入字符串指针
                                const char *pFragShaderSource, //传入字符串指针
                                GLuint &vertexShaderHandle,  // 传入/传出的引用
                                GLuint &fragShaderHandle);  //传出/传出的引用


    static void DeleteProgram(GLuint &program);

    static void CheckError(const char *pGLOperation);

};


#endif //NDKOPENGLSTUDY_SHADERUTILS_H
