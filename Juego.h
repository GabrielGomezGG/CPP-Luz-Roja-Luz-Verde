#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include "Jugador.h"
#include <vector>

using namespace sf;
using namespace std;

class Juego
{
private:
	//ventana
	RenderWindow* ventana;

	//evento
	Event *evento;

	//lista de jugadores
	Jugador* jugador;
	vector<Jugador> *jugadores;

	//fuente y texto
	Font *fuente;
	Text *texto;

	//tiempo y relog
	Clock* relog;
	Time* tiempo;

	//variables del juego
	int maxDistancia, maxTiempo;

public:
	Juego(int ancho, int alto, String titulo);
	void dibujar();
	void gameloop();
	void procesarEventos();
	void procesarTexto();
	
	void AgregarJugador(int numeroJugador, String nombre);
};

