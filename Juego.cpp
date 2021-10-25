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

	//munieca 
	munieca = new Muniaca();

	//texto y fuente
	fuente = new Font();
	fuente->loadFromFile("mi.ttf");

	texto = new Text();
	texto->setFont(*fuente);
	texto->setString("AAAAAAAAAAA" + to_string(10));
	texto->setCharacterSize(30);

	//tiempo y relog
	relog_m = new Clock();

	tiempo_m = new Time();

	srand(time(NULL));

	//variables 
	maxDistancia = 300;
	maxTiempo = 3;
	lineaInicio = 100;
	lineaFinal = 100;
	//tiempo_giro = (rand() % 10) + 2;
	tiempo_giro = 1;
	//cout << tiempo_giro << endl;

	

	//lineas
	lineaI = new RectangleShape(Vector2f(5, alto));
	lineaI->setPosition(Vector2f(50, 0));
	lineaI->setFillColor(Color::Green);

	lineaF = new RectangleShape(Vector2f(5, alto));
	lineaF->setPosition(Vector2f(alto-100, 0));
	lineaF->setFillColor(Color::Green);
}

void Juego::dibujar()
{
	ventana->clear();

	//textos
	ventana->draw(*texto);

	//sprites
	ventana->draw(jugador->getSprite());
	ventana->draw(munieca->getSprite());

	//figuras
	ventana->draw(*lineaI);
	ventana->draw(*lineaF);

	ventana->display();
}

void Juego::gameloop()
{
	
	while (ventana->isOpen()) {
		*tiempo_m = relog_m->getElapsedTime();
		procesarEventos();
		procesarTexto();
		dibujar();

		//tiempo_giro = (rand() % 10) + 2;
		// tiempo_giro = (rand() % 100) + 2;
		//cout << tiempo_m->asSeconds() << endl;
		
		if (tiempo_m->asSeconds() >= tiempo_giro) {
			//cout << tiempo_giro << endl;
			girarMunieca();
			relog_m->restart();
			tiempo_giro = (rand() % 4) + 1;
			cout << "proximo tiempo: "<<tiempo_giro << endl;
		}
		
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

			if (evento->key.code == sf::Keyboard::M)
			{
				munieca->mirando();
				if(!munieca->getMirando())lineaF->setFillColor(Color::Red);
				else
				{
					lineaF->setFillColor(Color::Green);
				}
			}
		}
	}
}

void Juego::procesarTexto()
{
	texto->setString(to_string(jugador->getDistancia()) + "/" + to_string(maxDistancia));
}

void Juego::girarMunieca()
{
	munieca->mirando();
	if (!munieca->getMirando())lineaF->setFillColor(Color::Red);
	else
	{
		lineaF->setFillColor(Color::Green);
	}
}

void Juego::AgregarJugador(int numeroJugador, String nombre)
{

	jugadores->push_back(Jugador(numeroJugador, nombre));

}
