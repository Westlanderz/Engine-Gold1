    #include "../includes/WindowManager.hpp"

    #include "../includes/core/Coordinator.hpp"
    #include <bitset>
    #include <iostream>


    extern Coordinator coordinator;

    // TODO: Return error to caller
    void WindowManager::Init(std::string const& windowTitle, unsigned int windowWidth, unsigned int windowHeight, unsigned int, unsigned int) {
    	glfwInit();

    	window = glfwCreateWindow(windowWidth, windowHeight, windowTitle.c_str(), NULL, NULL);

    	glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
    	glfwWindowHint(GLFW_FOCUSED, GLFW_TRUE);
    	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    	// Create OpenGL Context
    	glfwMakeContextCurrent(window);
    	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    	glfwSwapInterval(2);

    	// Configure OpenGL
    	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    	glEnable(GL_DEPTH_TEST);
    }


    void WindowManager::Update()
    {
    	glfwSwapBuffers(window);
    }


    void WindowManager::Shutdown()
    {
    	glfwDestroyWindow(window);
    	glfwTerminate();
    }

    void WindowManager::ProcessEvents()
    {
    	glfwPollEvents();

    	bool buttonStateChanged = true;

    	if(glfwGetKey(window, GLFW_KEY_ESCAPE)) {
    		coordinator.sendEvent(Events::Window::QUIT);
    	} else if(glfwGetKey(window, GLFW_KEY_W)) {
    		buttons.set(static_cast<std::size_t>(InputButtons::W));
    	} else if(glfwGetKey(window, GLFW_KEY_A)) {
    		buttons.set(static_cast<std::size_t>(InputButtons::A));
    	} else if(glfwGetKey(window, GLFW_KEY_S)) {
    		buttons.set(static_cast<std::size_t>(InputButtons::S));
    	} else if(glfwGetKey(window, GLFW_KEY_D)) {
    		buttons.set(static_cast<std::size_t>(InputButtons::D));
    	} else if(glfwGetKey(window, GLFW_KEY_Q)) {
    		buttons.set(static_cast<std::size_t>(InputButtons::Q));
    	} else if(glfwGetKey(window, GLFW_KEY_E)) {
    		buttons.set(static_cast<std::size_t>(InputButtons::E));
    	} else {
    		buttonStateChanged = false;
    	}

    	if(buttonStateChanged)
    	{
    		Event event(Events::Window::INPUT);
    		event.setParam(Events::Window::Input::INPUT, buttons);
    		coordinator.sendEvent(event);
    	}
    }