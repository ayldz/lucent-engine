#include <iostream>

#include <GLFW/glfw3.h>

#include "application/window.h"

using namespace lucent;


int main()
{

	Window window{"Lucent Engine", 960, 540};
	window.Update();

	return 0;
}