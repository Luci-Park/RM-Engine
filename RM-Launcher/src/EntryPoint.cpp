#include <RMEngine.h>

extern rm::Application* rm::CreateApplication();

int main(int argc, char** argv)
{
	auto app = rm::CreateApplication();
	app->Run();
	delete app;
	return 0;
}