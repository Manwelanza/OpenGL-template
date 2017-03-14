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
	void setTexture(Textura *textura_);
	void setCoordText(CTex2* coordText_);
	
protected:
	void activar();
	void desactivar();
	void activarTextura();
	void desactivarTextura();

protected:
	PVec3 *vertices;
	PVec3 *normales;
	GLuint numDat;
	CTex2 *coordText;
	Textura *textura;
};

#endif //_H_malla_H_