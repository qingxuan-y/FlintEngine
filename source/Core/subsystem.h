//所有子系统的统一生命周期
#pragma once
#include <string>

namespace FlintEngine::Core {
	class Subsystem {
	public:
		virtual void Initialize() = 0;
		virtual void Update(float deltatime) = 0;
		virtual void Shutdown() = 0;
		virtual const std::string  GetName() const = 0;
		virtual ~Subsystem() = default;
	};
}