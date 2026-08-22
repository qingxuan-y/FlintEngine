#pragma once
#include <vector>
#include <memory>
#include "subsystem.h"

namespace FlintEngine::Core {

	class Application {
	public:
		Application() = default;
		virtual ~Application() = default;
		void Run();
		void RegisterSubsystem(std::unique_ptr<Subsystem>subsystem);

		virtual void OnStart() {}
		virtual void OnUpdate (float deltatime){}
		virtual void OnStop() {}

	private:
		std::vector<std::unique_ptr<Subsystem>> m_Subsystems;
		bool m_Running = false;
	};
}