#include "Juego.h"


Juego::Juego(int ancho, int alto, String titulo) {
	ventana = new RenderWindow(VideoMode(ancho, alto, 32), titulo);

}

void Juego::dibujar()
{
	ventana->clear();

	ventana->display();
}

void Juego::gameloop()
{
	while (ventana->isOpen()) {
		dibujar();
	}
}
