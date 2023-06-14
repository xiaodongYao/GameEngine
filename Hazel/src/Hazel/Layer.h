#pragma once

#include "Hazel/Events/Event.h"
#include "Events/KeyEvent.h"

namespace Hazel {
	class HZ_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");

		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnImGuiRender() {}
		virtual void OnEvent(Event& event) {}

		inline const std::string& GetName(){ return m_DebugName; }

	private:
		std::string m_DebugName;
	};

}

