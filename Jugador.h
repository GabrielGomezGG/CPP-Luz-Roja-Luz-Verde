#pragma once
#include "SFML/Graphics.hpp"

using namespace sf;

class Jugador
{
private:
	int numeroJugador;
	String nombre;
	bool estado;
public:
	Jugador(int, String);
	void correr();
	void parar();
	void mostrarDatos();
	
};

