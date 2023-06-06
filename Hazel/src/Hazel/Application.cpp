#include "Application.h"
#include "Events/ApplicationEvent.h"
#include "Log.h"

namespace Hazel {
	Application::Application() {}

	Application::~Application() {}

	void Application::run()
	{
		WindowResizeEvent e(1200,720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			HZ_TRACE(e);
		}

		if (e.IsInCategory(EventCategoryInput))
		{
			HZ_TRACE(e);
		}


		while (true);
	}
}
