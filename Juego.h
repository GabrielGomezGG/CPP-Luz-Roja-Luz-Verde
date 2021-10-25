#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include "Jugador.h"
#include "Muniaca.h"
#include <vector>
#include <time.h>
#include <stdlib.h>

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

	//MUNIECA
	Muniaca* munieca;

	//fuente y texto
	Font *fuente;
	Text *texto;

	//tiempo y relog
	Clock* relog_m;
	Time* tiempo_m;

	//variables del juego
	int maxDistancia, maxTiempo, lineaInicio, lineaFinal;
	int tiempo_giro;
	

	//Lineas
	RectangleShape *lineaI, *lineaF;

public:
	Juego(int ancho, int alto, String titulo);
	void dibujar();
	void gameloop();
	void procesarEventos();
	void procesarTexto();

	void girarMunieca();
	
	void AgregarJugador(int numeroJugador, String nombre);
};

