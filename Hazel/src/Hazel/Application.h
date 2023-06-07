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

	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	Application* CreateApplication();
}

