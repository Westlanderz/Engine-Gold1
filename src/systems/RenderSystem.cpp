#include "../../includes/systems/RenderSystem.hpp"

#include "../../includes/components/Camera.hpp"
#include "../../includes/components/Renderable.hpp"
#include "../../includes/components/Transform.hpp"
#include "../../includes/core/Coordinator.hpp"
#include "../../includes/graphics/Shader.hpp"
#include <cmath>
#include <iostream>

extern Coordinator coordinator;

void RenderSystem::Init() {
	coordinator.registerComponent<Camera>();
	coordinator.registerComponent<Renderable>();

	Signature signature;
	signature.set(coordinator.getComponentType<Transform>());
	signature.set(coordinator.getComponentType<Renderable>());
	coordinator.setSystemSignature<RenderSystem>(signature);

	coordinator.addEventListener(METHOD_LISTENER(Events::Window::RESIZED, RenderSystem::WindowSizeListener));

	shader = std::make_unique<Shader>("../shader/vertex.glsl", "../shader/fragment.glsl");

	camera = coordinator.createEntity();

	coordinator.addComponent(
		camera,
		Transform{
			.position = Vector3(0.0f, 0.0f, 500.0f),
			.rotation = Vector3(0.0f, 0.0f, 0.0f),
			.scale = Vector3(1.0f, 1.0f, 1.0f)
		});

	coordinator.addComponent(
		camera,
		Camera{
			.projectionTransform = Camera::makeProjectionTransform(45.0f, 0.1f, 1000.0f, 1920, 1080)
		});

	std::vector<Vector3> vertices =
		{
			Vector3(-0.5f, -0.5f, -0.5f),
			Vector3(0.5f, -0.5f, -0.5f),
			Vector3(0.5f, 0.5f, -0.5f),
			Vector3(0.5f, 0.5f, -0.5f),
			Vector3(-0.5f, 0.5f, -0.5f),
			Vector3(-0.5f, -0.5f, -0.5f),
			Vector3(-0.5f, -0.5f, 0.5),
			Vector3(0.5f, -0.5f, 0.5),
			Vector3(0.5f, 0.5f, 0.5),
			Vector3(0.5f, 0.5f, 0.5),
			Vector3(-0.5f, 0.5f, 0.5),
			Vector3(-0.5f, -0.5f, 0.5),
			Vector3(-0.5f, 0.5f, 0.5f),
			Vector3(-0.5f, 0.5f, -0.5f),
			Vector3(-0.5f, -0.5f, -0.5f),
			Vector3(-0.5f, -0.5f, -0.5f),
			Vector3(-0.5f, -0.5f, 0.5f),
			Vector3(-0.5f, 0.5f, 0.5f),
			Vector3(0.5f, 0.5f, 0.5),
			Vector3(0.5f, 0.5f, -0.5),
			Vector3(0.5f, -0.5f, -0.5),
			Vector3(0.5f, -0.5f, -0.5),
			Vector3(0.5f, -0.5f, 0.5),
			Vector3(0.5f, 0.5f, 0.5),
			Vector3(-0.5f, -0.5f, -0.5f),
			Vector3(0.5f, -0.5f, -0.5f),
			Vector3(0.5f, -0.5f, 0.5f),
			Vector3(0.5f, -0.5f, 0.5f),
			Vector3(-0.5f, -0.5f, 0.5f),
			Vector3(-0.5f, -0.5f, -0.5f),
			Vector3(-0.5f, 0.5f, -0.5),
			Vector3(0.5f, 0.5f, -0.5),
			Vector3(0.5f, 0.5f, 0.5),
			Vector3(0.5f, 0.5f, 0.5),
			Vector3(-0.5f, 0.5f, 0.5),
			Vector3(-0.5f, 0.5f, -0.5)
		};

	std::vector<Vector3> normals =
		{
			Vector3(0.0f, 0.0f, -1.0f),
			Vector3(0.0f, 0.0f, -1.0f),
			Vector3(0.0f, 0.0f, -1.0f),
			Vector3(0.0f, 0.0f, -1.0f),
			Vector3(0.0f, 0.0f, -1.0f),
			Vector3(0.0f, 0.0f, -1.0f),
			Vector3(0.0f, 0.0f, 1.0f),
			Vector3(0.0f, 0.0f, 1.0f),
			Vector3(0.0f, 0.0f, 1.0f),
			Vector3(0.0f, 0.0f, 1.0f),
			Vector3(0.0f, 0.0f, 1.0f),
			Vector3(0.0f, 0.0f, 1.0f),
			Vector3(-1.0f, 0.0f, 0.0f),
			Vector3(-1.0f, 0.0f, 0.0f),
			Vector3(-1.0f, 0.0f, 0.0f),
			Vector3(-1.0f, 0.0f, 0.0f),
			Vector3(-1.0f, 0.0f, 0.0f),
			Vector3(-1.0f, 0.0f, 0.0f),
			Vector3(1.0f, 0.0f, 0.0f),
			Vector3(1.0f, 0.0f, 0.0f),
			Vector3(1.0f, 0.0f, 0.0f),
			Vector3(1.0f, 0.0f, 0.0f),
			Vector3(1.0f, 0.0f, 0.0f),
			Vector3(1.0f, 0.0f, 0.0f),
			Vector3(0.0f, -1.0f, 0.0f),
			Vector3(0.0f, -1.0f, 0.0f),
			Vector3(0.0f, -1.0f, 0.0f),
			Vector3(0.0f, -1.0f, 0.0f),
			Vector3(0.0f, -1.0f, 0.0f),
			Vector3(0.0f, -1.0f, 0.0f),
			Vector3(0.0f, 1.0f, 0.0f),
			Vector3(0.0f, 1.0f, 0.0f),
			Vector3(0.0f, 1.0f, 0.0f),
			Vector3(0.0f, 1.0f, 0.0f),
			Vector3(0.0f, 1.0f, 0.0f),
			Vector3(0.0f, 1.0f, 0.0)
		};


	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	// Vertices
	glGenBuffers(1, &vboVertices);
	glBindBuffer(GL_ARRAY_BUFFER, vboVertices);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vector3) * vertices.size(), vertices.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vector3), (void*)nullptr);
	glEnableVertexAttribArray(0);

	// Surface normal
	glGenBuffers(1, &vboNormals);
	glBindBuffer(GL_ARRAY_BUFFER, vboNormals);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vector3) * normals.size(), normals.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vector3), (void*)nullptr);
	glEnableVertexAttribArray(1);

	glBindVertexArray(0);
}


void RenderSystem::Update(float) {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	shader->activate();
	glBindVertexArray(vao);

	auto& cameraTransform = coordinator.getComponent<Transform>(camera);
	auto& camera_ = coordinator.getComponent<Camera>(camera);

	for(auto const& entity : entities) {
		auto const& transform = coordinator.getComponent<Transform>(entity);
		auto const& renderable = coordinator.getComponent<Renderable>(entity);

		Matrix4x4 view;
		view.m[0][3] = -cameraTransform.position.x;
		view.m[1][3] = -cameraTransform.position.y;
		view.m[2][3] = -cameraTransform.position.z;

		Matrix4x4 rotY;

		float cos_theta_y = cosf(transform.rotation.y);
		float sin_theta_y = sinf(transform.rotation.y);

		rotY.m[0][0] = cos_theta_y;
		rotY.m[2][0] = -sin_theta_y;
		rotY.m[0][2] = sin_theta_y;
		rotY.m[2][2] = cos_theta_y;


		Matrix4x4 rotX;

		float cosThetaX = cosf(transform.rotation.x);
		float sinThetaX = sinf(transform.rotation.x);

		rotX.m[1][1] = cosThetaX;
		rotX.m[2][1] = sinThetaX;
		rotX.m[1][2] = -sinThetaX;
		rotX.m[2][2] = cosThetaX;


		Matrix4x4 rotZ;

		float cosThetaZ = cosf(transform.rotation.z);
		float sinThetaZ = sinf(transform.rotation.z);

		rotZ.m[0][0] = cosThetaZ;
		rotZ.m[1][0] = sinThetaZ;
		rotZ.m[0][1] = -sinThetaZ;
		rotZ.m[1][1] = cosThetaZ;


		Matrix4x4 translate;
		translate.m[0][3] = transform.position.x;
		translate.m[1][3] = transform.position.y;
		translate.m[2][3] = transform.position.z;

		Matrix4x4 scaleMat;
		scaleMat.m[0][0] = transform.scale.x;
		scaleMat.m[1][1] = transform.scale.y;
		scaleMat.m[2][2] = transform.scale.z;

		Matrix4x4 model = translate * scaleMat * rotY;

		Matrix4x4 projection = camera_.projectionTransform;

		shader->setUniform<Matrix4x4>("uModel", model);
		shader->setUniform<Matrix4x4>("uView", view);
		shader->setUniform<Matrix4x4>("uProjection", projection);
		shader->setUniform<Vector3>("uColor", renderable.color);

		glDrawArrays(GL_TRIANGLES, 0, 36);

		std::cout << "Rendering entity " << entity << std::endl;
	}

	glBindVertexArray(0);
}

void RenderSystem::WindowSizeListener(Event& event) {
	auto windowWidth = event.getParam<unsigned int>(Events::Window::Resized::WIDTH);
	auto windowHeight = event.getParam<unsigned int>(Events::Window::Resized::HEIGHT);

	auto& camera_ = coordinator.getComponent<Camera>(camera);
	camera_.projectionTransform = Camera::makeProjectionTransform(45.0f, 0.1f, 1000.0f, windowWidth, windowHeight);
}
