#pragma once

#ifdef HZ_PLATFORM_WINDOWS

extern Hazel::Application* Hazel::CreateApplication();

int main(int argc, char** argv) {
	Hazel::Log::Init();

	Hazel::Log::GetCoreLogger()->warn("Initializing Log!");
	Hazel::Log::GetClientLogger()->info("Hello Log!");

	HZ_CORE_WARN("[Macro] Initializing Log!");
	int a = 12;
	HZ_INFO("[Macro] Hello Log! Var = {0}, a");


	auto app = Hazel::CreateApplication();
	app->Run();
	delete app;
}

#endif