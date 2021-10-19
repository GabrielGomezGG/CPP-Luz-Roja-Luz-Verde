#include "Juego.h"


Juego::Juego(int ancho, int alto, String titulo) {

	//ventana
	ventana = new RenderWindow(VideoMode(ancho, alto, 32), titulo);

	//evento
	evento = new Event();

	//jugadores

	jugador = new Jugador(01, "Algo");

	jugadores = new vector<Jugador>;
	AgregarJugador(01, "Thiago");

	//texto y fuente
	fuente = new Font();
	fuente->loadFromFile("mi.ttf");

	texto = new Text();
	texto->setFont(*fuente);
	texto->setString("AAAAAAAAAAA" + to_string(10));
	texto->setCharacterSize(30);

	//tiempo y relog
	relog = new Clock();

	tiempo = new Time();

	//variables 
	maxDistancia = 300;
	maxTiempo = 3;
}

void Juego::dibujar()
{
	ventana->clear();

	//textos
	ventana->draw(*texto);

	//sprites
	ventana->draw(jugador->getSprite());

	ventana->display();
}

void Juego::gameloop()
{
	while (ventana->isOpen()) {
		procesarEventos();
		procesarTexto();
		dibujar();
	}
}

void Juego::procesarEventos()
{
	while (ventana->pollEvent(*evento)) {

		switch (evento->type) {

		case Event::Closed:
			ventana->close();
			break;

		case Event::KeyReleased:

			if (evento->key.code == sf::Keyboard::J)
			{
				jugador->correr();
				cout << jugador->getPosicion().x << endl;
				cout << jugador->getPosicion().y << endl;
			}
		}
	}
}

void Juego::procesarTexto()
{
	texto->setString(to_string(jugador->getDistancia()) + "/" + to_string(maxDistancia));
}

void Juego::AgregarJugador(int numeroJugador, String nombre)
{

	jugadores->push_back(Jugador(numeroJugador, nombre));

}
