//#pragma once

#ifndef _H_triAnimado_H_
#define _H_triAnimado_H_

#include "object.h"
#include "tipos.h"
#include "mallaTri.h"
#include <GL/freeglut.h>
#include <iostream>

/**
	* Clase que ejecutara la siguiente animación:
		* El objeto dara una vuelta circular con el radio que haya en la variable "radio"
		* La velocidad de esa rotación circular será la que este en la variable "circular"
		* Además, el objeto rotara sobre si mismo también
*/
class TriAnimado:
	public MallaTri
{
public:
	TriAnimado();
	TriAnimado(int vertex_number, GLdouble radius, GLdouble turn_radius);
	~TriAnimado();

	void play();
	void step();
	void draw();
	void rotate(GLdouble angle);

protected:
	Object *objeto;
	GLdouble velocidad;
	GLdouble radio;
	GLdouble turn_radius;
	GLdouble rotation_angle = 0;
};

#endif