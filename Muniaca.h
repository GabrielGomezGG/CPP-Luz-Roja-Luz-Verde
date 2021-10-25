#pragma once

#include "SFML/Graphics.hpp"
#include <iostream>
#include <vector>;

using namespace std;
using namespace sf;

class Muniaca{

private:
	bool isMirando;

	Vector2f* posicion;
	Vector2i *f_size,*f_cantidad, *f_actual;
	vector<Vector2i>* a_ver, * a_nover;
	IntRect *tr_ver, *tr_ocultarse;

	Texture* imagen;
	Sprite *s_actual, *s_ocultarse;

	Clock *relog;
	Time* tiempo_giro;

public:
	Muniaca();
	void mirando();

	void setSprite();

	//Sprite getSprite(int id);
	bool getMirando();
	void setAnimacion(vector<Vector2i> animacion);
	Sprite getSprite();

};

