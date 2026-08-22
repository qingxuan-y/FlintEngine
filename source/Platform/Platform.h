#pragma once
#include <string>

//平台抽象，暂未实现
namespace FlintEngine::Platform {
	class Platform {
	public:
		static void Initialize() {

		}
		static void Shutdown() {

		}
		static std::string GetPlatformName() {
			return "Unknown(stub)";
		}
	};
}