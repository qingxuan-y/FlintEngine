#pragma once
#include "Application.h"

//引擎核心
namespace FlintEngine::Core {
	class Engine {
	public:
		static Engine& GetInstance() {
			static Engine instance;
			return instance;
		}

		void SetApplication(std::unique_ptr<Application> app) {
			m_Application = std::move(app);
		}

		void Run() {
			if (m_Application) {
				m_Application->Run();
			}
		}

	private:
		Engine() = default;
		std::unique_ptr<Application> m_Application;
	};
}
