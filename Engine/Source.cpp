#include <iostream>

#include "window.h"
#include "math.h"
#include "fileUtils.h"

int main(void) 
{
	
	using namespace graphics;
	using namespace window;
	using namespace math;
	using namespace vectors;

	Window window("Hello World!", 960, 640);

	vec4 a(1.0, 10.0, 23.0, 23.0);
	vec4 b(1.0, 10.0, 23.0, 23.0);

	std::string out = utils::read_file("Source.cpp");
	std::cout << out << std::endl;

	while (!window.closed())
	{
		window.clear();

		glColor4f(0.9, 0.0, 0.0, 1.0);
		glBegin(GL_TRIANGLES);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(0.0f, 0.5f);
		glVertex2f(0.5f, -0.5f);
		glEnd();

		window.update();
	}

	window.~Window();
	return 0;
}