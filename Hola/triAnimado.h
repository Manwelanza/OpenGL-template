//#pragma once

#ifndef _H_triAnimado_H_
#define _H_triAnimado_H_

#include "object.h"
#include "tipos.h"
#include <GL/freeglut.h>
#include <iostream>

/**
	* Clase que ejecutara la siguiente animación:
		* El objeto dara una vuelta circular con el radio que haya en la variable "radio"
		* La velocidad de esa rotación circular será la que este en la variable "circular"
		* Además, el objeto rotara sobre si mismo también
*/
class TriAnimado
{
public:
	TriAnimado();
	~TriAnimado();

	void play();
	void step();

protected:
	Object *objeto;
	GLdouble velocidad;
	GLdouble radio;
};

#endif