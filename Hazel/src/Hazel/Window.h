#pragma once
#include "hzpch.h"

#include "Hazel/Core.h"
#include "Hazel/Events/Event.h"


namespace Hazel {
	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& title = "Hazel Engine!",
			unsigned int width = 1280,
			unsigned int height = 720) :Title(title), Width(width), Height(height) {}
	};

	//窗口界面的接口
	class HZ_API Window
	{
	public :
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual void OnUpdate() = 0;
		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		//窗口属性
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetSync(bool enabled) = 0;
		virtual bool IsSync() const = 0;

		virtual void* GetNativeWindow() const = 0;//根据平台选择
		static Window* Create(const WindowProps& props = WindowProps());
	};
}