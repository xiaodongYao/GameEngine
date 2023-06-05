#pragma once

#ifdef HZ_PLATFORM_WINDOW

extern Hazel::Application* Hazel::CreateApplication();

int main(int argc, char** argv)
{
	Hazel::Log::Init();

	HZ_CORE_WARN("Initialize Log");
	int a = 5;
	HZ_INFO("hello hazel! {0}", a);

	auto app = Hazel::CreateApplication();
	app->run();
	delete app;
}

#endif // HZ_PLATFORM_WINDOW


