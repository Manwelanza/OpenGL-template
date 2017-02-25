//#pragma once
#ifndef _H_escena_H_
#define _H_escena_H_

#include "tipos.h"
#include "Geometry.h"

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
	Escena() : ejes(200) { geometry = Geometry::Instance(); };
  ~Escena();
  void init();
  void draw();
  void drawDiabolo();
  void rotarPiramide(GLdouble angulo);
public:
  Ejes ejes;
  Geometry* geometry;
};

//-------------------------------------------------------------------------

#endif  // _H_escena_H_
