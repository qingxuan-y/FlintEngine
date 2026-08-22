//这是一个能跑的日志系统
#pragma once

#include <iostream>
#include <string>

namespace FlintEngine::Core {

class Log {
public:
	static void Info(const std::string& message) {
		std::cout << "[INFO] " << message << std::endl;
	}

	static void Warn(const std::string& message) {
		std::cout << "[WARN] " << message << std::endl;
	}

	static void Error(const std::string& message) {
		std::cerr << "[ERROR] " << message << std::endl;
	}
};

} // namespace FlintEngine::Core
