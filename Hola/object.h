//#pragma once

#ifndef _H_object_H_
#define _H_object_H_

#include "malla.h"
#include "tipos.h"
#include "textura.h"
#include <GL/freeglut.h>
#include <iostream>

class Object
{
public:
	Object();
	virtual ~Object();

	virtual void init();
	virtual void draw();
	virtual void resize (int width, int height);
	virtual void rotation(PVec3 angles);
	virtual void move(PVec3 movement);

public:
	PVec3 posicion;
	GLdouble *rotaciones;
	Malla *malla;
	//Textura *textura;
	bool activo;
};

#endif