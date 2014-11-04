#include "Transform.h"



void Transform::update()
{
	if (m_Active == true){

		glm::mat4 translate = glm::translate(translate, m_Position);
		glm::mat4 scale = glm::scale(scale, m_Scale);

		glm::mat4 rotationX = glm::rotate(rotationX, m_Rotation.x, vec3(1.0f, 0.0f, 0.0f));
		glm::mat4 rotationY = glm::rotate(rotationY, m_Rotation.y, vec3(0.0f, 1.0f, 0.0f));
		glm::mat4 rotationZ = glm::rotate(rotationZ, m_Rotation.z, vec3(0.0f, 0.0f, 1.0f));

		glm::mat4 rotation = rotationX*rotationY*rotationZ;
		m_Model = translate*rotation*scale;
	}
}