#include <iostream>
#include <string>
#include <algorithm>

#include "GL/glew.h"
#include "GL/glut.h"


void display()
{
	glutSwapBuffers();
}


int main(int argc, char* argv[])
{
	// initialize the GLUT system
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(50, 50);
	glutInitWindowPosition(0, 0);

	// mainWindow will have the ID 1
	glutCreateWindow("empty");

	glutDisplayFunc(display);
	glutIdleFunc(NULL);
	glutMouseFunc(NULL);
	glutMotionFunc(NULL);
	glutPassiveMotionFunc(NULL);
	glutReshapeFunc(NULL);
	glutKeyboardFunc(NULL);


	GLenum err = glewInit();

	if (GLEW_OK != err)
	{
		std::cerr << "Error: " << glewGetErrorString(err) << std::endl;
		exit(1);
	}

	const char* str = 0;

	std::cout << "  - GPU Driver Info" << std::endl;
	std::cout << "    ------------------" << std::endl;

	str = (const char*)glGetString(GL_VENDOR);
	if (str)
	{
		std::string vendor(str);
		std::string firstWord = vendor.substr(0, vendor.find(" "));

		std::cout << "    Vendor: " << vendor << std::endl;

		if (!firstWord.empty())
		{
			std::transform(firstWord.begin(), firstWord.end(), firstWord.begin(), ::tolower);

			std::cout << "    \t - Relevant: " << firstWord << std::endl;
		}
	}

	str = (const char*)glGetString(GL_RENDERER);
	if (str)
	{
		std::string renderer(str);
		std::cout << "    Renderer: " << renderer << std::endl;
	}

	str = (const char*)glGetString(GL_VERSION);
	if (str)
	{
		std::string version(str);
		std::string lastWord = version.substr(version.find_last_of(" ") + 1);

		std::cout << "    Version: " << version << std::endl;
		std::cout << "    \t - Relevant: " << lastWord << std::endl;
	}


	str = (const char*)glGetString(GL_SHADING_LANGUAGE_VERSION);
	if (str)
	{
		std::string glslVersion(str);

		std::cout << "    GLSL Version: " << glslVersion << std::endl;
	}

	glutMainLoop();

	return 0;
}

