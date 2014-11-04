#ifndef Transform_h
#define Transform_h





#include <glm\glm\glm.hpp>
using glm::vec3; //check online or ask brian why we include this
using glm::vec4;

#include <glm/glm/gtc/matrix_transform.hpp>
//#include <glm/glm/gtc/type_ptr.hpp>

#include "Component.h"

class Transform : public Component{

public:
	//Constructors/Destructor
	Transform();
	~Transform();

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