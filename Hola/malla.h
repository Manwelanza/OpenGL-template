//#pragma once

#ifndef _H_malla_H_
#define _H_malla_H_

#include "tipos.h"
#include <GL/freeglut.h>

#define PI 3.14159265359

class Malla
{
public:
	Malla();
	virtual ~Malla();
	virtual void draw() = 0;
	
protected:
	virtual void activar();
	virtual void desactivar();

protected:
	PVec3 *vertices;
	PVec3 *normales;
	GLuint numDat;
	CTex2 *coordText;
};

#endif //_H_malla_H_