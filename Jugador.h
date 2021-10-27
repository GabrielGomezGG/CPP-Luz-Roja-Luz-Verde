#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include <vector>;

using namespace std;

using namespace sf;

class Jugador
{
private:
	int numeroJugador;
	String nombre;
	bool isCorriendo;
	int distanciaRecorrida;
	int contador_a_correr;

	Vector2f *posicion;
	Vector2i* f_size, * f_cantidad, * f_actual;
	vector<Vector2i>* a_correr, * a_quieto;
	IntRect* tr_correr, * tr_quieto;
	
	Texture* imagen;
	Sprite* s_actual;

public:
	Jugador(int, String);
	void correr();

	//get
	int getDistancia();
	Vector2f getPosicion();
	Sprite getSprite();
	bool getCorrer();

	//set
	void setPos(float x, float y);
	void setCorrer();
	void setAnimacion();
	
};

