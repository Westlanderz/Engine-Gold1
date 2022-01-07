#ifndef RENDERSYSTEM_HPP
#define RENDERSYSTEM_HPP

#include "../includes/core/System.hpp"
#include "../includes/graphics/Shader.hpp"
#include <memory>


class Event;


class RenderSystem : public System {
	public:
		void Init();
		void Update(float dt);

	private:
		void WindowSizeListener(Event& event);

		std::unique_ptr<Shader> shader;

		Entity camera;

		GLuint vao{};
		GLuint vboVertices{};
		GLuint vboNormals{};
};

#endif // RENDERSYSTEM_HPP
