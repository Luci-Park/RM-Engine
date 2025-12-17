
#include "pch.h"
#include <RMEngine.h>
/**
 * @file main.cpp
 * @author sumin.park
 * @brief Main sandbox area.
 * @version 0.1
 * @date 12/16/2025 3:47:59 PM
 *
 * @copyright Copyright (c) 2025 - RM Engine
 *
 */

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
