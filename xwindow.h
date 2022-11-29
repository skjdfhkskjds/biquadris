#ifndef _WINDOW_
#define _WINDOW_
#include <X11/Xlib.h>
#include <iostream>
#include <string>
#include <memory>

class XWindow
{
	Display *d;
	Window w;
	int s;
	GC gc;
	unsigned long colours[10];

public:
	XWindow(int width = 500, int height = 500); // Constructor; displays the window.
	~XWindow();									// Destructor; destroys the window.
	XWindow(const XWindow &) = delete;
	XWindow &operator=(const XWindow &) = delete;

	// Available colours.
	enum
	{
		White = 0,
		Black,
		Red,
		Green,
		Blue,
		Cyan,
		Yellow,
		Magenta,
		Orange,
		Brown
	};

	// Draws a rectangle
	void fillRectangle(int x, int y, int width, int height, int colour = Black);

	// Draws a string
	void drawString(int x, int y, std::string msg);
};

#endif
