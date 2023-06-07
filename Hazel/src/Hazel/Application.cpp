#include "Hzpch.h"
#include "Application.h"
#include "Events/ApplicationEvent.h"
#include "Log.h"

namespace Hazel {
	Application::Application() 
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application() 
	{
	
	}

	void Application::run()
	{
		while (m_Running)
		{
			m_Window->OnUpdate();
		}
	}
}
