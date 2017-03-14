//#pragma once

#ifndef _H_triMovil_H_
#define _H_triMovil_H_

#include "object.h"
#include "tipos.h"
#include "mallaTri.h"
#include <GL/freeglut.h>

/**
* Clase que podr� ser movida por la pantalla y ser� utilizada
* para recortar un trozo de la textura del fondo, que posteriormente
* se utilizar� para texturizar otros objetos.
*/
class TriMovil :
	public MallaTri
{
public:
	TriMovil();
	TriMovil(GLdouble radius);
	~TriMovil();

	void draw();
	void rotate(GLdouble angle);
	void move(PVec3 movement);
	PVec3* getPoints();
	CTex2* getCoordTexts(int width, int height);

protected:
	Object *objeto;
	GLdouble rotation = 0;
	PVec3 position = PVec3(0, 0, 0);
};

#endif