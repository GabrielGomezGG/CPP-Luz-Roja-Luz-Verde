#pragma once
#include "SFML/Graphics.hpp"
#include "Jugador.h"
#include <vector>

using namespace sf;
using namespace std;

class Juego
{
private:
	RenderWindow* ventana;
	vector<Jugador> *jugadores;

public:
	Juego(int ancho, int alto, String titulo);
	void AgregarJugador();
};
