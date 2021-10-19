#pragma once
#include "SFML/Graphics.hpp"

using namespace sf;

class Jugador
{
private:
	int numeroJugador;
	String nombre;
	bool isCorriendo;
	int distanciaRecorrida;

	Vector2f *posicion;
	
	Texture* imagen;
	Sprite* s_correr;

public:
	Jugador(int, String);
	void correr();

	//get
	int getDistancia();
	Vector2f getPosicion();
	Sprite getSprite();

	//set
	void setPos(float x, float y);
	
};

