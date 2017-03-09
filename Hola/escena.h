//#pragma once
#ifndef _H_escena_H_
#define _H_escena_H_

#include "tipos.h"
#include "Geometry.h"
#include "textura.h"
#include "object.h"

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
	Escena(int width = 100, int height = 100);
	~Escena();
	void init();
	void draw();
	void resize(int width, int height);
	void rotation(PVec3 angles);


public:
  Ejes ejes;
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
};

//-------------------------------------------------------------------------

#endif  // _H_escena_H_
