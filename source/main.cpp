#include "core/Engine.h"
#include "core/Application.h"
#include "core/log.h"
#include "platform/Platform.h"

using namespace FlintEngine;

class FlintEngineApp : public Core::Application {
public:
    void OnStart() override {
        Core::Log::Info("FlintEngineApp::OnStart() - engine framework is running!");
    }

    void OnUpdate(float deltaTime) override {
        // 空实现,关于输入、逻辑更新
    }

    void OnStop() override {
        Core::Log::Info("FlintEngineApp::OnStop() - cleaning up...");
    }
};

int main() {
    // 初始化平台抽象
    Platform::Platform::Initialize();
    Core::Log::Info("Platform: " + Platform::Platform::GetPlatformName());

    // 创建Editor实例
    auto app = std::make_unique<FlintEngineApp>();

    // 设置并运行引擎
    Core::Engine::GetInstance().SetApplication(std::move(app));
    Core::Engine::GetInstance().Run();

    // 关闭平台抽象
    Platform::Platform::Shutdown();

    return 0;
}