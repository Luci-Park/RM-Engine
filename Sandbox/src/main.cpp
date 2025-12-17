
#include "pch.h"
#include <RMEngine.h>

class Sandbox : public rm::Application
{
public:
	Sandbox()
	{
	}
	~Sandbox(){}
	virtual void Run() override
	{
		Application::Run();
		while (true);
	}
};

rm::Application* rm::CreateApplication()
{
	return new Sandbox();
}
