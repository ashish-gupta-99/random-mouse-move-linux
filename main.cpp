#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

#include <X11/Xlib.h>
#include <X11/Xutil.h>

#define MICRO_SECOND 1e+6

int genRandom(int from)
{
    /* gen random number in range */
    return rand() % from;
}

void mouseMove()
{
    Display *displayMain = XOpenDisplay(0);

    Screen *s DefaultScreenOfDisplay(displayMain);
    int scr = XDefaultScreen(displayMain);

    Window root_window = XRootWindow(displayMain, scr);

    int rx = genRandom(s->width), ry = genRandom(s->height);

    // std::cout << "move " << rx << " " << ry << std::endl;

    if (displayMain == NULL)
    {
        fprintf(stderr, "Errore nell'apertura del Display !!!\n");
        exit(EXIT_FAILURE);
    }

    XWarpPointer(displayMain, None, root_window, 0, 0, 0, 0, rx, ry);

    XFlush(displayMain);
}

int main()
{
    srand(time(0)); // Initialize random number generator.

    std::cout << "Moving randomly, press ctrl+c to stop!\n";

    while (1)
    {
        mouseMove();
        usleep(5 * MICRO_SECOND);
    }
    return 0;
}