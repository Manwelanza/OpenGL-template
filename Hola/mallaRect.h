//#pragma once

#ifndef _H_mallaRect_H_
#define _H_mallaRect_H_

#include "malla.h"
#include "tipos.h"
#include <GL/freeglut.h>

class MallaRect :
	public Malla
{
public:
	MallaRect();
	MallaRect(GLdouble width, GLdouble height, PVec3 color = PVec3());
	MallaRect(GLdouble width, GLdouble height, PVec3 colores [4]);
	virtual ~MallaRect();
	void draw();
	bool load(char arch[]);

protected:
	void init(GLdouble width, GLdouble height, PVec3 colores[4]);
	void activar();
	void desactivar();

protected:
	PVec3 *colores;
};

#endif //_H_mallaRect_H_