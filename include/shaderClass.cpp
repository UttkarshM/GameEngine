#include "shaderClass.h"

std::string get_file_contents(const char* filename){

	std::ifstream inFile;
	inFile.open(filename);

	std::stringstream strStream;
	strStream << inFile.rdbuf();
	std::string str = strStream.str();
	
	return str;
}


Shader::Shader(const char* vertexFile,const char* fragmentFile){

	std::string vertexCode = get_file_contents(vertexFile);
	std::string fragmentCode = get_file_contents(fragmentFile);

	const char* vertexShaderCode = vertexCode.c_str();
  std::cout<<vertexShaderCode<<std::endl;
	
  const char* fragmentShaderCode = fragmentCode.c_str();
  std::cout<<fragmentShaderCode<<std::endl;
  
  ID = glCreateProgram();
	
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);

	glShaderSource(vertexShader, 1, &vertexShaderCode,NULL);
	glCompileShader(vertexShader);
  
  //error handling statements.
  //
  int result;
  glGetShaderiv(vertexShader, GL_COMPILE_STATUS,&result);
  if(result==0){
    std::cout<<"error in vertex shader"<<std::endl;
  }
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(fragmentShader, 1, &fragmentShaderCode,NULL);
	glCompileShader(fragmentShader);

   glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &result);
   if(result==0){
	   std::cout<<"error in fragment shader"<<std::endl;
   }
    glAttachShader(ID, vertexShader);
	  glAttachShader(ID,  fragmentShader);

	glLinkProgram(ID);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}


int Shader::GetUniformNumber(std::string Uname){
  if(UniformsMap.find(Uname) !=UniformsMap.end()){
    return UniformsMap[Uname];
  }
  int location = glGetUniformLocation(ID, Uname.c_str());
  UniformsMap[Uname]=location;
  return location;
}


void Shader::UseUniformNumber(std::string name, float v0, float v1, float v2, float v3){
  glUniform4f(GetUniformNumber(name), v0, v1, v2, v3);
}


void Shader::UseUniform1i(std::string name, int value){
  glUniform1i(GetUniformNumber(name), value);
}


void Shader::UseUniform1f(std::string name, float value){
  glUniform1f(GetUniformNumber(name), value);
}


void Shader::UseUniformMat4f(std::string name, const glm::mat4& matrix){
  //we dont need to transpose it cause glm as glm is column major 
  //we are giving the address of the first element as all the data is stored sequentially
  glUniformMatrix4fv(GetUniformNumber(name), 1, GL_FALSE, &matrix[0][0]);
}


void Shader::activate(){
	glUseProgram(ID);
}


void Shader::Delete(){
	glDeleteProgram(ID);
}