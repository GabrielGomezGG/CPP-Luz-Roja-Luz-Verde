#include "Jugador.h"

Jugador::Jugador(int numero, String _nombre) {
	numeroJugador = numero;
	nombre = _nombre;
	isCorriendo = false;
	distanciaRecorrida = 0;

	posicion = new Vector2f(100,200);

	imagen = new Texture();
	imagen->loadFromFile("mega.png");

	s_correr = new Sprite(*imagen);
	s_correr->setPosition(*posicion);
	s_correr->setScale(0.1, 0.1);
}

void Jugador::correr()
{
	isCorriendo = true;
	distanciaRecorrida += 1;
	posicion->x += 1;
	setPos(posicion->x, posicion->y);

	
}

int Jugador::getDistancia()
{
	return distanciaRecorrida;
}

Vector2f Jugador::getPosicion()
{
	return *posicion;
}

Sprite Jugador::getSprite()
{
	return *s_correr;
}

void Jugador::setPos(float x, float y)
{
	*posicion = Vector2f(x, y);
	s_correr->setPosition(*posicion);
}


