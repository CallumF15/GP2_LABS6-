#ifndef Camera_h
#define Camera_h


#include "Component.h"

#include <glm\glm\glm.hpp>
#include <glm/glm/gtc/matrix_transform.hpp>

class Camera : public Component{



public:
	Camera();
	~Camera();

	void setPosition(float x, float y, float z);
	void setLookAt(float x, float y, float z);
	void setUp(float x, float y, float z);
	void setFOV(float fov);
	void setAspectRatio(float aspectratio);
	void setNearClip(float nearclip);
	void setFarClip(float farclip);

	glm::mat4 getViewMatrix();
	glm::mat4 getProjectionMatrix();

	void update();

private:
	glm::vec3 m_Position;
	glm::vec3 m_LookAt;
	glm::vec3 m_Up;
	float m_FOV;
	float m_AspectRatio;
	float m_NearClip;
	float m_FarClip;
	glm::mat4 m_ViewMatrix;
	glm::mat4 m_ProjectionMatrix;
protected:



};


#endif
