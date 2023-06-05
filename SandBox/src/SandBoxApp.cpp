#include <Hazel.h>

class SendBox :public Hazel::Application
{
public:
	SendBox() {};

	~SendBox() {};


};

Hazel::Application* Hazel::CreateApplication()
{
	return new SendBox();
}


