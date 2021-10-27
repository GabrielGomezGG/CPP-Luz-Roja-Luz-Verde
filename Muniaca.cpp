#include "Muniaca.h"


Muniaca::Muniaca(){

	

	imagen = new Texture();
	imagen->loadFromFile("01.png");

	s_actual = new Sprite(*imagen);
	//s_ver->setTextureRect(*tr_ver);

	//s_ocultarse = new Sprite(*imagen);

	relog = new Clock();
	tiempo_giro = new Time();
	

	//variables
	isMirando = false;
	contador_a_correr = 0;

	f_cantidad = new Vector2i(4, 4);
	f_size = new Vector2i(s_actual->getTexture()->getSize().x/f_cantidad->x, s_actual->getTexture()->getSize().y / f_cantidad->y);
	f_actual = new Vector2i(0, 0);
	
	posicion = new Vector2f( 450, 200 );
	s_actual->setPosition(*posicion);
	//s_actual->setOrigin(s_actual->getTexture()->getSize().x / 2, s_actual->getTexture()->getSize().y / 2);

	a_nover = new vector<Vector2i>;
	a_nover->push_back(Vector2i(f_size->x * 0, f_size->y * 2));
	a_nover->push_back(Vector2i(f_size->x * 0, f_size->y * 0));
	a_nover->push_back(Vector2i(f_size->x * 1, f_size->y * 3));

	a_ver = new vector<Vector2i>;
	a_ver->push_back(Vector2i(f_size->x * 1, f_size->y * 3));
	a_ver->push_back(Vector2i(f_size->x * 0, f_size->y * 0));
	a_ver->push_back(Vector2i(f_size->x * 0, f_size->y * 2));

	tr_ver = new IntRect(Vector2i(a_ver->at(0).x, a_ver->at(0).y), *f_size);
	//tr_ocultarse = new IntRect(Vector2i(f_size->x *0, f_size->y *0), *f_size);
	
	setSprite();
	//mirando();

}

void Muniaca::mirando()
{
	if (!isMirando) {
		//tr_ver = new IntRect(Vector2i(f_size->x * 3, f_size->y * 3), *f_size);

		//tr_ver = new IntRect(a_ver->at(0), *f_size);
		setAnimacion(*a_nover);
		isMirando = true;
	}
	else {
		//tr_ver = new IntRect(Vector2i(f_size->x * 0, f_size->y * 2), *f_size);
		setAnimacion(*a_ver);
		isMirando = false;
	}

	//s_actual->setTextureRect(*tr_ver);
}

void Muniaca::setSprite()
{
	/*
	if (!isMirando) {
		tr_ver = new IntRect(Vector2i(f_size->x * 3, f_size->y * 3), *f_size);
	}
	else {
		tr_ver = new IntRect(Vector2i(f_size->x * 3, f_size->y * 3), *f_size);
	}*/

	s_actual->setTextureRect(*tr_ver);

}
/*
Sprite Muniaca::getSprite(int id)
{
	if(id == 0)
		return *s_actual;

	if (id == 1)
		return *s_actual;

	return *s_actual;
}*/


bool Muniaca::getMirando()
{
	return isMirando;
}

void Muniaca::setAnimacion(vector<Vector2i> animacion)
{
	//*tiempo_giro = relog->getElapsedTime();
	for (int i = 0; i < animacion.size(); i++) {
		/*
		cout << "viejo" << endl;
		cout << "x: " << s_actual->getTextureRect().left << " ";
		cout << "y: " << s_actual->getTextureRect().top << " ";
		cout << "ancho: " << s_actual->getTextureRect().width << " ";
		cout << "alto: " << s_actual->getTextureRect().height << endl;
		

		cout << "frame actual: " << i << endl;
		cout << "x"<<animacion.at(i).x << " ";
		cout << "y"<<animacion.at(i).y << endl;
		*/

		//cout << tiempo_giro->asSeconds() << endl;

		//if (tiempo_giro->asSeconds() >= 2) {
			tr_ver = new IntRect(animacion.at(i), *f_size);
			s_actual->setTextureRect(*tr_ver);

			//relog->restart();
		//}
		/*
		cout << "actual" << endl;
		cout << "x: " << s_actual->getTextureRect().left << " ";
		cout << "y: " << s_actual->getTextureRect().top << " ";
		cout << "ancho: " << s_actual->getTextureRect().width << " ";
		cout << "alto: " << s_actual->getTextureRect().height << endl;
		cout << "--------------------------------------------" << endl;
		*/
	}

	
}

void Muniaca::setAnimacion()
{
	if (contador_a_correr < a_ver->size()) {
		//cout << a_ver->size() << " " << contador_a_correr << endl;

		if (isMirando) {
			tr_ver = new IntRect(a_ver->at(contador_a_correr), *f_size);
			s_actual->setTextureRect(*tr_ver);
		}
		if (!isMirando) {
			tr_ocultarse = new IntRect(a_nover->at(contador_a_correr), *f_size);
			s_actual->setTextureRect(*tr_ocultarse);
		}
		contador_a_correr++;
	}
	else
	{
		contador_a_correr = 0;
	}
}

Sprite Muniaca::getSprite()
{
	return *s_actual;
}
