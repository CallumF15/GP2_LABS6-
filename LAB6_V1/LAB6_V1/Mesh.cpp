#include "Mesh.h"
#include "Vertex.h"



Mesh::Mesh(){
	//Constructor
}

Mesh::~Mesh(){
	//Destructor
}

void Mesh::init(){
	glGenVertexArrays(1, &m_VAO);
	glBindVertexArray(m_VAO);
	//Create buffer
	glGenBuffers(1, &m_VBO);
	// Make the new VBO active
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
	////Copy Vertex Data to VBO
	//glBufferData(GL_ARRAY_BUFFER, 4 * sizeof(Vertex), m_VBO, GL_STATIC_DRAW);

	//create buffer
	glGenBuffers(1, &m_EBO);
	//Make the EBO active
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
	////Copy Index data to the EBO
	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(int), indices, GL_STATIC_DRAW);

	//Tell the shader that 0 is the position element
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), NULL);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void**)sizeof(vec3));
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void**)(sizeof(vec3) + sizeof(vec2)));
}

void Mesh::destroy()
{
	glDeleteBuffers(1, &m_VBO);
	glDeleteBuffers(1, &m_EBO);
	glDeleteVertexArrays(1, &m_VAO);
}

void Mesh::bind()
{
	glBindVertexArray(m_VAO);
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
}

void Mesh::copyVertexData(int count, int stride, void** data){
	m_VertexCount = count;
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
	glBufferData(GL_ARRAY_BUFFER, count * stride, data, GL_STATIC_DRAW);
}

void Mesh::copyIndexData(int count, int stride, void** data){
	m_IndexCount = count;
	//Make the EBO active
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
	////Copy Index data to the EBO
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * stride, data, GL_STATIC_DRAW);
}

int Mesh::getIndexCount()
{
	return m_IndexCount;
}

int Mesh::getVertexCount(){
	return m_VertexCount;
}