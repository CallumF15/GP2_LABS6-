//Header guard - ensures class is compiled once & only once.
#ifndef Component_h
#define Component_h


#include <string>




class Component{

public:
	Component();
	virtual ~Component(); //Destructor - Destroys the objects	virtual void init();	virtual void update();	virtual void render();	virtual void destroy();	const std::string &getType();	void toggleActive();	bool isActive();

protected:
	std::string m_Type;
	bool m_Active;

private:



};#endif