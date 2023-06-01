#pragma once

#ifdef HZ_PLATFORM_WINDOW
	
extern Hazel::Application* Hazel::CreateApplication();

int main(int argc,char** argv)
{
	auto app = Hazel::CreateApplication();
	app->run();
	delete app;
}

#endif // HZ_PLATFORM_WINDOW


