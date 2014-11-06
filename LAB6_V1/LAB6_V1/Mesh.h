#ifndef Mesh_h
#define Mesh_h

#include "Component.h"
#include <GL/glew.h>


#include <SDL.h>
#include <SDL_opengl.h>
#include <gl/GLU.h>

class Mesh : public Component{

public:
	//Constructors/Destructor
	Mesh();
	~Mesh();

	//Methods
	void bind();
	void init();
	void destroy();


	void copyVertexData(int count, int stride, void** data);
	void copyIndexData(int count, int stride, void** data);

	//Getters
	int getVertexCount();
	int getIndexCount();


	
	//Setters





protected:

private:
	//variables
	GLuint m_VBO, m_EBO, m_VAO;
	int m_VertexCount, m_IndexCount;


};




#endif