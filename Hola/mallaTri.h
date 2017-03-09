//#pragma once

#ifndef _H_mallaTri_H_
#define _H_mallaTri_H_

#include "malla.h"
#include "tipos.h"
#include <GL/freeglut.h>

class MallaTri :
	public Malla
{
public:
	MallaTri();
	MallaTri(int vertex_number, GLdouble radius);
	virtual ~MallaTri();
	void draw();
	void setTexture(Textura *textura_);
	bool load(char arch[]);

protected:
	void activarTextura();
	void desactivarTextura();
};

#endif //_H_mallaTri_H_