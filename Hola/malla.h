//#pragma once

#ifndef _H_malla_H_
#define _H_malla_H_

#include "tipos.h"
#include "textura.h"
#include <GL/freeglut.h>

class Malla
{
public:
	Malla();
	virtual ~Malla();
	virtual void draw(){};
	virtual void resize(int width, int height) {};
	virtual void setTexture(Textura *textura_) {};
	
protected:
	void activar();
	void desactivar();

protected:
	PVec3 *vertices;
	PVec3 *normales;
	GLuint numDat;
	CTex2 *coordText;
	Textura *textura;
};

#endif //_H_malla_H_