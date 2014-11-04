#ifndef Mesh_h
#define Mesh_h

#include "Component.h"
#include <GL/glew.h>

class Mesh : public Component{

public:
	//Constructors/Destructor
	Mesh();
	~Mesh();

	//Methods
	void update(); //double check this (Section 3 start)

	//Getters
	glm::vec3 &getPosition();
	glm::vec3 &getScale();
	glm::vec3 &getRotation();
	glm::vec3 &getModel();

	//Setters
	void setPosition();
	void setScale();
	void setRotation();
	void setModel();

protected:

private:
	glm::vec3 m_Position;
	glm::vec3 m_Scale;
	glm::vec3 m_Rotation;
	glm::mat4 m_Model;


};




#endif