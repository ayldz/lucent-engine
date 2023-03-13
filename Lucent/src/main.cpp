#include <iostream>

#include <GLFW/glfw3.h>

#include "window.h"

using namespace lucent;

int main()
{
	Window window{ "Lucent Engine",968,768 };
	window.Update();

	return 0;
}