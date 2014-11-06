#ifndef Material_h
#define Material_h

#include "Component.h"
#include <GL/glew.h>
#include <string>
#include "Shader.h"

class Material : public Component{

public:
	//Constructors/Destructor
	Material();
	~Material();

	//Methods
	void destroy();
	void bind();
	bool loadShader(const std::string& filenameVertexShader, const std::string& filenameFragShader);
	GLint getUniformLocation(const std::string& name);

	//Getters




	//Setters


protected:
private:
	//variables
	GLuint m_ShaderProgram;

};


#endif