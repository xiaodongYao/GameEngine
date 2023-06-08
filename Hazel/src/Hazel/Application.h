#pragma once
#include "Window.h"
#include "Core.h"
#include "Hazel/Events/Event.h"


namespace Hazel {
	class HZ_API Application
	{
	public:
		Application();

		virtual ~Application();

		void run();
		void OnEvent(Event& e);
	private:
		bool OnWindowClose(Event& e);
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	Application* CreateApplication();
}

