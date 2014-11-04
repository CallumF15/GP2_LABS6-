
#include "GameObject.h"


//Constructor
GameObject::GameObject(){

	m_Name = "GameObject";
}

GameObject::~GameObject(){

}


const std::string &GameObject::getName()
{
	return m_Name;
}


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