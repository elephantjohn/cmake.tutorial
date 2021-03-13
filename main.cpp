#include <iostream>
#include <adder.h>
#include <GLFW/glfw3.h>
#include <OLASConfig.h>

using namespace std;

int main(int argc, char* argv[]) {
	cout << "Wlecome" << endl;
    adder(4.5,6);
   
	cout << argv[0] << " Version" << OLAS_VERSION_MAJOR << "." << OLAS_VERSION_MINOR << endl;

    GLFWwindow* window;

    /* Init GLFW */
    if( !glfwInit() )
       exit( EXIT_FAILURE );
 
    window = glfwCreateWindow( 400, 400, "Boing (classic Amiga demo)", NULL, NULL );
    if (!window)
    {
        glfwTerminate();
        exit( EXIT_FAILURE );
    }
 
    /* Main loop */
    for (;;)
    {
        /* Timing */
        /* Swap buffers */
        glfwSwapBuffers(window);
        glfwPollEvents();
 
        /* Check if we are still running */
        if (glfwWindowShouldClose(window))
            break;
    }
 
    glfwTerminate();

	return 0;
}
