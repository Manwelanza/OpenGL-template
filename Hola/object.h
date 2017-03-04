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

public:
	PVec3 posicion;
	GLdouble *rotaciones;
	Malla *malla;
	Textura *textura;
	bool activo;
};

#endif