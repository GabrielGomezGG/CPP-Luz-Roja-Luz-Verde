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

	tex = new Text();
	tex->setFont(*fuente);
	tex->setString("AAAAAAAAAAA" + to_string(10));
	tex->setCharacterSize(20);

	tex_estado_jugador = new Text();
	tex_estado_jugador->setFont(*fuente);
	tex_estado_jugador->setString("AAAAAAAAAAA" + to_string(10));
	tex_estado_jugador->setCharacterSize(20);
	tex_estado_jugador->setPosition(0, 30);

	tex_estado_munieca = new Text();
	tex_estado_munieca->setFont(*fuente);
	tex_estado_munieca->setString("AAAAAAAAAAA" + to_string(10));
	tex_estado_munieca->setCharacterSize(20);
	tex_estado_munieca->setPosition(0, 60);

	tex_gameOver = new Text();
	tex_gameOver->setFont(*fuente);
	tex_gameOver->setString("AAAAAAAAAAA" + to_string(10));
	tex_gameOver->setCharacterSize(20);
	tex_gameOver->setPosition(0, 90);

	//tiempo y relog
	relog_m = new Clock();

	tiempo_m = new Time();

	relog_j = new Clock();

	tiempo_j = new Time();

	srand(time(NULL));

	//variables 
	maxDistancia = 300;
	maxTiempo = 3;
	lineaInicio = 100;
	lineaFinal = 100;
	//tiempo_giro = (rand() % 10) + 2;
	tiempo_giro = 1;
	//cout << tiempo_giro << endl;

	game_over = false;

	//lineas
	lineaI = new RectangleShape(Vector2f(5, alto));
	lineaI->setPosition(Vector2f(50, 0));
	lineaI->setFillColor(Color::Green);

	lineaF = new RectangleShape(Vector2f(5, alto));
	lineaF->setPosition(Vector2f(alto-100, 0));
	lineaF->setFillColor(Color::Green);
}
void Juego::gameloop()
{
	
	while (ventana->isOpen()) {
		if (!game_over) {
			*tiempo_m = relog_m->getElapsedTime();

			procesarEventos();
			procesarTexto();
			dibujar();
			gameOver();

			//tiempo_giro = (rand() % 10) + 2;
			// tiempo_giro = (rand() % 100) + 2;
			//cout << tiempo_m->asSeconds() << endl;
		
			if (tiempo_m->asSeconds() >= tiempo_giro) {
				//cout << tiempo_giro << endl;
				girarMunieca();
				relog_m->restart();
				tiempo_giro = (rand() % 4) + 1;
				//cout << "proximo tiempo: "<<tiempo_giro << endl;
			}
		
		}
		else{
		//ventana->close();
			game_over = true;
			procesarTexto();
			/*ventana->clear();*/
			dibujar();
			//ventana->display();
		}
	}
	
	
}

void Juego::dibujar()
{
	ventana->clear();

	//textos
	ventana->draw(*tex);
	ventana->draw(*tex_estado_jugador);
	ventana->draw(*tex_estado_munieca);
	ventana->draw(*tex_gameOver);


	//sprites
	ventana->draw(jugador->getSprite());
	ventana->draw(munieca->getSprite());

	//figuras
	ventana->draw(*lineaI);
	ventana->draw(*lineaF);

	ventana->display();
}

void Juego::procesarEventos()
{
	*tiempo_j = relog_j->getElapsedTime();
	cout << tiempo_j->asSeconds() << endl;
	if (tiempo_j->asSeconds() >= 0.2) {
		jugador->setCorrer();
		relog_j->restart();

	}
	while (ventana->pollEvent(*evento)) {

		switch (evento->type) {

		case Event::Closed:
			ventana->close();
			break;

		case Event::KeyReleased:

			if (evento->key.code == sf::Keyboard::J)
			{
				jugador->correr();
				relog_j->restart();
				
				
				
				//cout << jugador->getPosicion().x << endl;
				//cout << jugador->getPosicion().y << endl;
			}

			/*
			
			if (evento->key.code == sf::Keyboard::M)
			{
				munieca->mirando();
				if(!munieca->getMirando())lineaF->setFillColor(Color::Red);
				else
				{
					lineaF->setFillColor(Color::Green);
				}
			}*/
		}
	}
}

void Juego::procesarTexto()
{
	String estadoJugador;
	String estadoMunieca;
	String estadoGameOver;

	if (jugador->getCorrer()) {
		estadoJugador = "Corriendo";
	}
	else
	{
		estadoJugador = "Quieto";
	}

	if (munieca->getMirando()) {
		estadoMunieca = "Ocultando";
	}
	else
	{
		
		estadoMunieca = "Mirando";
	}

	if (game_over) {
		estadoGameOver = "Perdiste";
	}
	else
	{
		estadoGameOver = "GAME OVER : false";
	}

	tex->setString(to_string(jugador->getDistancia()) + "/" + to_string(maxDistancia));
	tex_estado_jugador->setString("Estado del jugador: " + estadoJugador);
	tex_estado_munieca->setString("Estado del Munieca: " + estadoMunieca);
	tex_gameOver->setString( estadoGameOver);
}

void Juego::girarMunieca()
{
	munieca->mirando();
	if (!munieca->getMirando()) {
		lineaF->setFillColor(Color::Red);
	}
	else
	{
		lineaF->setFillColor(Color::Green);
	}
}

void Juego::gameOver()
{
	if (jugador->getCorrer() && !munieca->getMirando()) {
		game_over = true;
	}
	//if (!jugador->getCorrer() && !munieca->getMirando())
	//{	
	//	tex_gameOver->setPosition(ventana->getSize().x /2, ventana->getSize().y /2);
	//	game_over = false;
	//	//tex_gameOver->setOrigin(tex_gameOver->get)
	//	
	//}
	
}

void Juego::AgregarJugador(int numeroJugador, String nombre)
{

	jugadores->push_back(Jugador(numeroJugador, nombre));

}
