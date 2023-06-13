#include "Hzpch.h"
#include "Application.h"
#include "Events/ApplicationEvent.h"
#include "Log.h"

#include <glad/glad.h>
#include "Input.h"
namespace Hazel {

#define BIND_EVENT_FN(x) std::bind(&Application::x,this,std::placeholders::_1)
	Application* Application::s_Intance = nullptr;

	Application::Application()
	{
		s_Intance = this;
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent)); //set callback function
	}

	Application::~Application()
	{

	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverLay(Layer* overLay)
	{
		m_LayerStack.PushOverlay(overLay);
		overLay->OnAttach();
	}

	void Application::OnEvent(Event& e)
	{
		//事件调度
		EventDispatcher dispatcher(e);

		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

		HZ_CORE_TRACE("{0}", e);

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
		{
			(*--it)->OnEvent(e);
			if (e.Handled)	
				break;
		}
	}


	void Application::run()
	{
		while (m_Running)
		{
			glClearColor(1, 0, 1, 1); //pink

			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* layer : m_LayerStack)
				layer->OnUpdate();

			auto [x, y] = Input::GetMousePosition();
			HZ_CORE_INFO("{0},{1}", x, y);

			m_Window->OnUpdate();
		}
	}

	bool Application::OnWindowClose(Event& e)
	{
		m_Running = false;
		return true;
	}
}
