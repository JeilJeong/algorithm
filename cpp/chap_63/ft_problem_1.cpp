#include <iostream>

using namespace	std;

class GameWindow {
public:
	GameWindow();
	GameWindow(const int, const int);

	int		GetWidth () const;
	int		GetHeight () const;
	void	ResizeWindow (const int, const int);
	
private:
	int		width;
	int		height;
};

GameWindow::GameWindow() : width(800), height(600) { }
GameWindow::GameWindow(const int w, const int h) { ResizeWindow(w, h); }
int		GameWindow::GetWidth (void) const { return (width); }
int		GameWindow::GetHeight (void) const { return (height); }
void	GameWindow::ResizeWindow (const int w, const int h) {
	width = w < 800 ? 800 : w;
	height = h < 600 ? 600 : h;
}

int	main()
{
	GameWindow	mainWindow;
	mainWindow.ResizeWindow(500, 768);
	cout << mainWindow.GetWidth() << 'x' << mainWindow.GetHeight() << endl;
}