
#include "GameObject.h"
#include "Mesh.h"
#include "Transform.h"
#include "Material.h"
#include "Camera.h"


//Constructor
GameObject::GameObject(){
	m_Transform = NULL;
	m_Mesh = NULL;
	m_Material = NULL;
	m_Camera = NULL;
	m_Name = "GameObject";
}

GameObject::~GameObject(){

}


const std::string &GameObject::getName()
{
	return m_Name;
}

//void GameObject::setName(const std::string& name)
//{
//	m_Name = name;
//}


void GameObject::init()
{
	for (auto iter = m_Components.begin(); iter != m_Components.end(); iter++)
	{
		(*iter)->init();
	}
}

void GameObject::destroy()
{
	auto iter = m_Components.begin();
	while (iter != m_Components.end())
	{
		(*iter)->destroy();
		if ((*iter))
		{
			delete (*iter);
			(*iter) = NULL;
			iter = m_Components.erase(iter);
		}
		else
		{
			iter++;
		}
	}
	m_Components.clear();
}

void GameObject::addComponent(Component *component){

}


#pragma region Getters/Setters

//Setters

void GameObject::setTransform(Transform *transform)
{
	m_Transform = transform;
	addComponent(transform);
}

void GameObject::setMaterial(Material *material)
{
	m_Material = material;
	addComponent(material);
}

void GameObject::setCamera(Camera *camera)
{
	m_Camera = camera;
	addComponent(camera);
}

void GameObject::setMesh(Mesh *mesh)
{
	m_Mesh = mesh;
	addComponent(mesh);
}

//Getters 

Transform *GameObject::getTransform()
{
	return m_Transform;
}

Mesh *GameObject::getMesh()
{
	return m_Mesh;
}

Material *GameObject::getMaterial()
{
	return m_Material;
}

Camera *GameObject::getCamera()
{
	return m_Camera;
}

#pragma endregion