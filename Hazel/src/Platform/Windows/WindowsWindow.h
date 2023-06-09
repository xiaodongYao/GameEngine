#pragma once

#include "Hazel/Window.h"
#include "Hazel/Events/ApplicationEvent.h"
#include "Hazel/Renderer/GraphicsContext.h"

#include <GLFW/glfw3.h>
namespace Hazel {
	class WindowsWindow :public Window
	{
	public:
		WindowsWindow(const WindowProps& props);  //construct

		virtual ~WindowsWindow();

		virtual void OnUpdate() override;

		//长宽获取
		inline unsigned int GetWidth() const override { return m_Data.Width; }
		inline unsigned int GetHeight() const override { return m_Data.Height; }
		//窗口属性
		inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
		void SetSync(bool enabled) override;
		bool IsSync() const override;

		inline virtual void* GetNativeWindow() const { return m_Window; }

	private:
		virtual void Init(const WindowProps& props);
		virtual void ShutDown();
	private:
		GLFWwindow* m_Window;
		GraphicsContext* m_Context;

		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;

			EventCallbackFn EventCallback;
		};

		WindowData m_Data;
	};
}