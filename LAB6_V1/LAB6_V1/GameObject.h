#ifndef GameObject_h
#define GameObject_h

#include <string>
#include <vector>
#include "Component.h"

class GameObject{


public:
	GameObject();
	~GameObject();
	

	void init();
	void update();
	void render();
	void destroy();

	const std::string& getName();
	std::string& setName();

	void addComponent(Component * component);


protected:
	

private:
	std::string m_Name;
	std::vector<Component*> m_Components;

};

#endif