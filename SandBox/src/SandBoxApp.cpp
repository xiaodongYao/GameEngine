#include <Hazel.h>

class ExampleLayer :public Hazel::Layer
{
public:
	ExampleLayer() :Layer("Example")
	{
	}

	void OnUpdate() override
	{
		if (Hazel::Input::IsKeyPressed(HZ_KEY_TAB))
		{
			HZ_TRACE("Tab key is pressed (poll)");
		}
	}

	void OnEvent(Hazel::Event& event) override
	{
		if (event.GetEventType() == Hazel::EventType::keyPressed)
		{
			Hazel::KeyPressedEvent& e = (Hazel::KeyPressedEvent&)event;
			if (e.GetKeyCode() == HZ_KEY_TAB)
			{
				HZ_TRACE("Tab key is pressed (event)");
			}
			HZ_TRACE("{0}", (char)e.GetKeyCode());
		}
	}

};



class SendBox :public Hazel::Application
{
public:
	SendBox()
	{
		PushLayer(new ExampleLayer());
		//PushOverLay(new Hazel::ImGuiLayer());
	};

	~SendBox() {};


};

Hazel::Application* Hazel::CreateApplication()
{
	return new SendBox();
}


