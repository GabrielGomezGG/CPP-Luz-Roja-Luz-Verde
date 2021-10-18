#include "Juego.h"


Juego::Juego(int ancho, int alto, String titulo) {

	//ventana
	ventana = new RenderWindow(VideoMode(ancho, alto, 32), titulo);

	//evento
	evento = new Event();

	//jugadores
	jugadores = new vector<Jugador>;
	AgregarJugador(01, "Thiago");
}

void Juego::dibujar()
{
	ventana->clear();

	ventana->display();
}

void Juego::gameloop()
{
	while (ventana->isOpen()) {
		procesarEventos();
		dibujar();
	}
}

void Juego::procesarEventos()
{
	while (ventana->pollEvent(*evento)) {

		switch (evento->type) {

		case Event::Closed:
			ventana->close();

		}
	}
}

void Juego::AgregarJugador(int numeroJugador, String nombre)
{

	jugadores->push_back(Jugador(numeroJugador, nombre));

}
