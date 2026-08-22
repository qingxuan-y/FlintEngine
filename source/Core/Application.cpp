#include "Application.h"
#include "log.h"
#include <chrono>
#include <thread>

namespace FlintEngine::Core {

void Application::Run() {
	Log::Info("FlintEditor opening...");

	// 初始化子系统
	for (auto& subsystem : m_Subsystems) {
		std::string msg = std::string("Initializing ") + subsystem->GetName() + " subsystem";
		Log::Info(msg);
		subsystem->Initialize();


	}

	OnStart();
	m_Running = true;

	// 固定主循环为60Hz，启动主循环
	const float fixedDeltaTime = 1.0f / 60.0f;
	auto lastTime = std::chrono::high_resolution_clock::now();

	Log::Info("主循环已启动");

	int frameCount = 0;
	const int maxFrames = 300;

	while (m_Running && frameCount < maxFrames) {
		auto currentTime = std::chrono::high_resolution_clock::now();
		std::chrono::duration<float> diff = currentTime - lastTime;
		float deltaTime = diff.count();
		lastTime = currentTime;

		// 更新子系统
		for (auto& subsystem : m_Subsystems) {
			subsystem->Update(deltaTime);
		}

		OnUpdate(deltaTime);

		frameCount++;
		if (frameCount % 60 == 0) {
			Log::Info("Tick " + std::to_string(frameCount / 60) + "s");
		}

		// 固定时间步长：睡眠到下一帧
		float sleepTime = fixedDeltaTime - deltaTime;
		if (sleepTime > 0.0f) {
			std::this_thread::sleep_for(std::chrono::duration<float>(sleepTime));
		}
	}

	// 关闭Editor
	Log::Info("Editor closing...");
	OnStop();

	for (auto& subsystem : m_Subsystems) {
		std::string msg = std::string("Shutting down ") + subsystem->GetName() + " subsystem";
		Log::Info(msg);
		subsystem->Shutdown();
	}

	Log::Info("Editor closed cleanly.");
}

void Application::RegisterSubsystem(std::unique_ptr<Subsystem> subsystem) {
	m_Subsystems.push_back(std::move(subsystem));
}

}
