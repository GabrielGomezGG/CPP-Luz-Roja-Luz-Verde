#include "Juego.h"

int main() {
	/*
	RenderWindow* ventana;
	ventana = new RenderWindow(VideoMode(500, 500, 32), "SFML");

	ventana->display();*/

	Juego *juego = new Juego(500, 500, "JDC");
	juego->gameloop();

	

	return 0;
}