#include "Material.h"

Material::Material(){
	//Constructor
	m_ShaderProgram = -1;
	m_Type = "Material";
}

Material::~Material()
{
	//Destructor
}

void Material::destroy()
{
	glDeleteProgram(m_ShaderProgram);
}

void Material::bind()
{
	glUseProgram(m_ShaderProgram);
}


bool Material::loadShader(const std::string& filenameVertexShader, const std::string& filenameFragShader)
{
	GLuint vertexShaderProgram = 0;

	vertexShaderProgram = loadShaderFromFile(const_cast<std::string&>(filenameVertexShader), VERTEX_SHADER);

	GLuint fragmentShaderProgram = 0;
	fragmentShaderProgram = loadShaderFromFile(const_cast<std::string&>(filenameFragShader), FRAGMENT_SHADER);

	m_ShaderProgram = glCreateProgram();
	glAttachShader(m_ShaderProgram, vertexShaderProgram);
	glAttachShader(m_ShaderProgram, fragmentShaderProgram);
	glLinkProgram(m_ShaderProgram);
	checkForLinkErrors(m_ShaderProgram);

	//now we can delete the VS & FS Programs
	glDeleteShader(vertexShaderProgram);
	glDeleteShader(fragmentShaderProgram);

	glBindAttribLocation(m_ShaderProgram, 0, "vertexPosition");
	glBindAttribLocation(m_ShaderProgram, 1, "vertexTexCoords");
	glBindAttribLocation(m_ShaderProgram, 2, "vertexColour");

	return true;
}

GLint Material::getUniformLocation(const std::string& name)
{
	return glGetUniformLocation(m_ShaderProgram, name.c_str());
}


