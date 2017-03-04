//#pragma once

#ifndef _H_mallaRect_H_
#define _H_mallaRect_H_

#include "malla.h"
#include "tipos.h"
#include "textura.h"
#include <GL/freeglut.h>

class MallaRect :
	public Malla
{
public:
	MallaRect(GLdouble width, GLdouble height, Color4 color_ = Color4());
	virtual ~MallaRect();
	void draw();
	bool load(char arch[]);
	void setSize(GLdouble width, GLdouble height);
	void setTexture(Textura *texture_);

protected:
	void createPoints(GLdouble width, GLdouble height);
	void activar();
	void desactivar();

protected:
	Color4 color;
	Textura *textura;
};

#endif //_H_mallaRect_H_