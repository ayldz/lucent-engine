#include <iostream>

#include <GLFW/glfw3.h>

#include "window.h"

int main()
{
	lucent::Window window{ "Lucent Engine",960,768 };
	window.Update();

	return 0;
}