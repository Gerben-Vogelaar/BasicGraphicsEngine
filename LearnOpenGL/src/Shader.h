#ifndef SHADER_H
#define SHADER_H

#include <string>

#include <glm/glm/glm.hpp>
#include <glm/glm/gtc/type_ptr.hpp>

class Shader
{
public:
	unsigned int ID;
	// constructor generates the shader on the fly
	Shader(const char* vertexPath, const char* fragmentPath);
	// activate the shader
	void use();
	// utility uniform functions
	void setBool(const std::string &name, bool value) const;
	
	void setInt(const std::string &name, int value) const;
	
	void setFloat(const std::string &name, float value) const;

	void setVec3(const std::string &name, glm::vec3 value) const;
	
	void setMat4(const std::string &name, glm::mat4 model) const;

private:
	// utility function for checking shader compilation/linking errors.
	void checkCompileErrors(unsigned int shader, std::string type);
};
#endif
