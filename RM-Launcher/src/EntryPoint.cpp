/**
 * @file EntryPoint.cpp
 * @author sumin.park
 * @brief The launcher for the engine.
 * @version 0.1
 * @date 12/16/2025 3:47:59 PM
 *
 * @copyright Copyright (c) 2025 - RM Engine
 *
 */

#include "pch.h"
#include <RMEngine.h>

int main(int argc, char** argv)
{
	auto app = rm::CreateApplication();
	app->Run();
	delete app;
	return 0;
}