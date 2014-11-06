#include "Camera.h"
#include "GameObject.h"
#include "Transform.h"

Camera::Camera(){
	//constructor
}

Camera::~Camera(){
	m_Type = "Camera";

}

void Camera::update(){
	//get the position from the transform
	glm::vec3 position = m_Parent->getTransform()->getPosition();

	m_ProjectionMatrix = glm::perspective(m_FOV, m_AspectRatio, m_NearClip, m_FarClip);
	m_ViewMatrix = glm::lookAt(position, m_LookAt, m_Up);
}

#pragma region Getters/Setters

//Setters
void Camera::setPosition(float x, float y, float z){
	m_Position = glm::vec3(x, y, z);
}

void Camera::setLookAt(float x, float y, float z){
	m_LookAt = glm::vec3(x, y, z);
}

void Camera::setUp(float x, float y, float z){
	m_Up = glm::vec3(x, y, z);
}

void Camera::setFOV(float fov){
	m_FOV = fov;
}

void Camera::setAspectRatio(float aspectratio)
{
	m_AspectRatio = aspectratio;
}

void Camera::setNearClip(float nearclip)
{
	m_NearClip = nearclip;
}

void Camera::setFarClip(float farclip)
{
	m_FarClip = farclip;
}

//Getters
glm::mat4 Camera::getViewMatrix(){
	return m_ViewMatrix;
}

glm::mat4 Camera::getProjectionMatrix(){
	return m_ProjectionMatrix;
}

#pragma endregion 



