#include "Juego.h"

int main() {

	RenderWindow* ventana;
	ventana = new RenderWindow(VideoMode(500, 500, 32), "SFML");

	ventana->display();

	cout << "AAAAAAAAAA" << endl;

	system("PAUSE");

	return 0;
}