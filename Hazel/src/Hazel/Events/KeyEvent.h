#pragma once

#include <sstream>
#include "Event.h"

namespace Hazel
{
	class HZ_API KeyEvent :public Event
	{
	public:
		inline int GetKeyCode() const { return m_KeyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryKeybord)
	protected:
		KeyEvent(int keyCode) :m_KeyCode(keyCode) {}

		int m_KeyCode;

	};

	class HZ_API keyPressedEvent :public KeyEvent
	{
	public:
		keyPressedEvent(int keyCode, int repeatCount) :KeyEvent(keyCode), m_RepeatCount(repeatCount) {}

		inline int GetRepeatCount() const { return m_RepeatCount; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "keyPressedEvent: " << m_KeyCode << " (" << m_RepeatCount << "repeats)";
			return ss.str();
		}
		EVENT_CLASS_TYPE(keyPressed)
	private:
		int m_RepeatCount;
	};

	class HZ_API KeyReleasedEvent :public KeyEvent
	{
		KeyReleasedEvent(int keyCode) :KeyEvent(keyCode) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};

}