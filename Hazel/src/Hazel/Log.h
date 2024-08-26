#pragma once

#include<memory>
#include "Core.h"
#include "spdlog/spdlog.h"

namespace Hazel{
	class HAZEL_API Log
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}


// Core log macros
#define HZ_CORE_ERROR(...)		::Hazel::Log::GetCoreLogger()->error(__VA_ARGS__)	//__VA_ARGS__ 变量的作用就是将宏定义的变量（前面括号里的...）传给实际函数
#define HZ_CORE_WARN(...)		::Hazel::Log::GetCoreLogger()->warn(__VA_ARGS__)	//前面两个冒号的作用是：明确告诉编译器要从全局命名空间开始查找 Hazel 命名空间。
#define HZ_CORE_INFO(...)		::Hazel::Log::GetCoreLogger()->info(__VA_ARGS__)	//这种做法有助于避免命名冲突。
#define HZ_CORE_TRACE(...)		::Hazel::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define HZ_CORE_FATAL(...)		::Hazel::Log::GetCoreLogger()->fatal(__VA_ARGS__)

///Client log macros
#define HZ_ERROR(...)			::Hazel::Log::GetClientLogger()->error(__VA_ARGS__)
#define HZ_WARN(...)			::Hazel::Log::GetClientLogger()->warn(__VA_ARGS__)
#define HZ_INFO(...)			::Hazel::Log::GetClientLogger()->info(__VA_ARGS__)
#define HZ_TRACE(...)			::Hazel::Log::GetClientLogger()->trace(__VA_ARGS__)
#define HZ_FATAL(...)			::Hazel::Log::GetClientLogger()->fatal(__VA_ARGS__)
