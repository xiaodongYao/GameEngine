#pragma once
#include "Window.h"
#include "Hazel/LayerStack.h"
#include "Hazel/Events/Event.h"
#include "Hazel/ImGui/ImGuiLayer.h"

#include "Renderer/Shader.h"
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
		inline static Application& Get() { return *s_Intance; }
		inline Window& GetWindow() { return *m_Window; }
	private:
		bool OnWindowClose(Event& e);
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;

		LayerStack m_LayerStack;

		unsigned int m_VertexArray, m_VertexBuffer, m_IndexBuffer;

		std::unique_ptr<Shader> m_Shader;
	private:
		static Application* s_Intance;
	};

	Application* CreateApplication();
}

