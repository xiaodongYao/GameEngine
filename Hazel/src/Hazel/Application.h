#pragma once
#include "Window.h"
#include "Hazel/LayerStack.h"
#include "Hazel/Events/Event.h"


namespace Hazel {
	class HZ_API Application
	{
	public:
		Application();

		virtual ~Application();

		void run();
		void OnEvent(Event& e);
		
		void PushLayer(Layer* layer);
		void PushOverLay(Layer* layer);
	private:
		bool OnWindowClose(Event& e);
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;

		LayerStack m_LayerStack;
	};

	Application* CreateApplication();
}

