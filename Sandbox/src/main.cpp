
#include <RMEngine.h>

class Sandbox : public rm::Application
{
public:
	Sandbox(){}
	~Sandbox(){}
};

rm::Application* rm::CreateApplication()
{
	return new Sandbox();
}
