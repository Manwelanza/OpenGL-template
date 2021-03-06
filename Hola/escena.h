//#pragma once
#ifndef _H_escena_H_
#define _H_escena_H_

#include "tipos.h"
#include "Geometry.h"
#include "textura.h"
#include "object.h"

enum Estados { Recortar, Animar, Collage, EDiabolo, Pruebas };

//-------------------------------------------------------------------------
class Ejes {
public:
  Ejes(GLdouble l);
  ~Ejes(){};
  void draw();
public:
  PVec3 vertices[6];
  PVec3 colores[6];
};

//-------------------------------------------------------------------------

class Escena {
public:
	Escena(int width = 100, int height = 100, Estados modo_ = Recortar);
	~Escena();
	void init();
	void draw();
	void key(unsigned char key, bool& need_redisplay);
	void resize(int width, int height);
	void rotation(PVec3 angles);
	void rotateTri(GLdouble angle);
	void mouseMoved(int x, int y, int dx, int dy, bool& need_redisplay);

private:
	void cambiaEstado(Estados modo_);
	void recortarInit();
	void animarInit();
	void collageInit();
	void eDiaboloInit();
	void pruebasInit();

	void recortarDraw();
	void animarDraw();
	void collageDraw();
	void eDiaboloDraw();
	void pruebasDraw();

	void recortarKey(unsigned char key, bool& need_redisplay);
	void animarKey(unsigned char key, bool& need_redisplay);
	void collageKey(unsigned char key, bool& need_redisplay);
	void eDiaboloKey(unsigned char key, bool& need_redisplay);
	void pruebasKey(unsigned char key, bool& need_redisplay);

public:
	int width;
	int height;
	Ejes ejes;
	Estados modo;
	Geometry* geometry;
	Textura textura;			// background
	Textura textura2;			// zelda image
	Textura textura3;			// world image
	Textura texturaCollage;
  
	MallaRect rectangulo;		// background
	MallaRect rectangulo2;		// zelda image
	MallaRect rectangulo3;		// world image
	Object rect;				// background
	Object rect2;				// zelda image
	Object rect3;				// world image

	MallaTri triangulo;
	Object tri;

	PiramideTri piramide;
	Object piram;

	Diabolo diabolo;
	Object dia;

	TriAnimado triAnimado;
	Object triA;

	TriMovil triMovil;
	Object triM;
};

//-------------------------------------------------------------------------

#endif  // _H_escena_H_
