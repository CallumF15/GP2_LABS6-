//Header guard - ensures class is compiled once & only once.
#ifndef Component_h
#define Component_h


#include <string>




class Component{

public:
	Component();
	virtual ~Component(); //Destructor - Destroys the objects

protected:
	std::string m_Type;
	bool m_Active;

private:



};