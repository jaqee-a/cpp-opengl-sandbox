#pragma once



#include <cstdint>
#include <math.h>
namespace Sandbox {
    
    class Shader {
    public:
        uint32_t ID;

        Shader(const char* vertexFp, const char* fragmentFp);

        ~Shader();


        void Use();

        void setBool  (const char *name, bool     value) const;
        void setInt   (const char *name, int32_t  value) const;
        void setFloat (const char *name, float_t  value) const;
        void setMat4  (const char *name, float_t *value) const;
    };
};
