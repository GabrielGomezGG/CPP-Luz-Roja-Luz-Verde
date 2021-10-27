#include "Jugador.h"

Jugador::Jugador(int numero, String _nombre) {
	numeroJugador = numero;
	nombre = _nombre;
	isCorriendo = false;
	distanciaRecorrida = 0;
	contador_a_correr = 0;

	posicion = new Vector2f(0,200);

	imagen = new Texture();
	imagen->loadFromFile("02.png");

	s_actual = new Sprite(*imagen);
	s_actual->setPosition(*posicion);
	s_actual->setScale(0.2, 0.2);


	f_cantidad = new Vector2i(4, 3);
	f_size = new Vector2i(s_actual->getTexture()->getSize().x / f_cantidad->x, s_actual->getTexture()->getSize().y / f_cantidad->y);
	f_actual = new Vector2i(0, 0);

	a_correr = new vector<Vector2i>;
	a_correr->push_back(Vector2i(f_size->x * 2, f_size->y * 0));
	a_correr->push_back(Vector2i(f_size->x * 1, f_size->y * 0));

	a_quieto = new vector<Vector2i>;
	a_quieto->push_back(Vector2i(f_size->x * 0, f_size->y * 0));

	tr_correr = new IntRect(a_correr->at(0), *f_size);
	tr_quieto = new IntRect(a_quieto->at(0), *f_size);

	s_actual->setTextureRect(*tr_quieto);
}

void Jugador::correr()
{
	isCorriendo = true;
	distanciaRecorrida += 1;
	posicion->x += 5;
	setPos(posicion->x, posicion->y);

	setAnimacion();
	//contador_a_correr++;
	
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
	return *s_actual;
}

bool Jugador::getCorrer()
{
	return isCorriendo;
}

void Jugador::setPos(float x, float y)
{
	*posicion = Vector2f(x, y);
	s_actual->setPosition(*posicion);
}

void Jugador::setCorrer()
{
	isCorriendo = false;
	s_actual->setTextureRect(*tr_quieto);
}

void Jugador::setAnimacion()
{
	if (contador_a_correr < a_correr->size()) {
		cout << a_correr->size() << " "<< contador_a_correr<< endl;

		tr_correr = new IntRect(a_correr->at(contador_a_correr), *f_size);
		s_actual->setTextureRect(*tr_correr);

		contador_a_correr++;
	}
	else
	{
		contador_a_correr = 0;
	}
}




