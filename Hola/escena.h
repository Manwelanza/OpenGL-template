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
	Ejes ejes;
	Estados modo;
	Geometry* geometry;
	Textura textura;
  
	MallaRect rectangulo;
	Object rect;

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
