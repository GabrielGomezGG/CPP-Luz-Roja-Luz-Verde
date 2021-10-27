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
	Text* tex, *tex_estado_jugador, *tex_estado_munieca,*tex_gameOver,*tex_tiempo;

	//tiempo y relog
	Clock* relog_m,*relog_j, *relog_limite,* relog_m_a;
	Time* tiempo_m, *tiempo_j, *tiempo_limite;
	int tiempo_minutos_trascurridos, tiempo_seg_trascurrido;
	int tiempo_maximo;

	//variables del juego
	int maxDistancia, maxTiempo, lineaInicio, lineaFinal;
	int tiempo_giro;
	Time *tiempo_m_animacion;
	bool game_over;
	

	//Lineas
	RectangleShape *lineaI, *lineaF;

public:
	Juego(int ancho, int alto, String titulo);
	void dibujar();
	void gameloop();
	void procesarEventos();
	void procesarTexto();
	void procesarEventosTiempos();

	void girarMunieca();
	void gameOver();
	
	void AgregarJugador(int numeroJugador, String nombre);
};

