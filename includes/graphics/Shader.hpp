#ifndef SHADER_HPP
#define SHADER_HPP

#include <glad/glad.h>
#include <string>


class Matrix4x4;
class Vector3;


class Shader {
	public:
		Shader(std::string const& vertexPath, std::string const& fragmentPath);

		void activate();

		template<typename T>
		void setUniform(const std::string& name, const T& value) {
			if constexpr (std::is_same_v<T, Matrix4x4>) {
				glUniformMatrix4fv(glGetUniformLocation(id, name.c_str()), 1, GL_TRUE, (GLfloat*)value.m);
			} else if constexpr (std::is_same_v<T, Vector3>) {
				glUniform3fv(glGetUniformLocation(id, name.c_str()), 1, (GLfloat*)&value);
			}
		}

	private:
		GLuint id;
};

#endif // SHADER_HPP
