#define ASSERT(x) if (!(x)) __debugbreak();
#define GLCall(x) GLClearError();\
	x;\
	ASSERT(GLLogCall(#x, __FILE__, __LINE__))

void GLClearError() 
{
	while (glGetError() != GL_NO_ERROR); 
} 
/*Once all errors are cleared, you can call an openGL function and after that you call this function which whill show all error flags that are set*/ 

bool GLLogCall(const char* function, const char* file, int line) { 
	while (GLenum error = glGetError()) { 
		std::cout << "[OpenGL Error] (" << error << "):" << function << " " << file << ":" << line << std::endl; 
		return false; 
	} 
	return true; 
}