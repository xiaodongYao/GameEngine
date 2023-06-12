#include <Hazel.h>

class ExampleLayer :public Hazel::Layer
{
public:
	ExampleLayer() :Layer("Example")
	{
	}

	void OnUpdate() override
	{
		//HZ_INFO("ExampleLayer::update");
	}

	void OnEvent(Hazel::Event& event) override
	{
		HZ_TRACE("{0}", event);
	}

};



class SendBox :public Hazel::Application
{
public:
	SendBox() 
	{
		PushLayer(new ExampleLayer());
		PushOverLay(new Hazel::ImGuiLayer());
	};

	~SendBox() {};


};

Hazel::Application* Hazel::CreateApplication()
{
	return new SendBox();
}


