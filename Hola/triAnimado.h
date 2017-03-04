//#pragma once

#ifndef _H_triAnimado_H_
#define _H_triAnimado_H_

#include "object.h"
#include "tipos.h"
#include <GL/freeglut.h>
#include <iostream>

/**
	* Clase que ejecutara la siguiente animaci�n:
		* El objeto dara una vuelta circular con el radio que haya en la variable "radio"
		* La velocidad de esa rotaci�n circular ser� la que este en la variable "circular"
		* Adem�s, el objeto rotara sobre si mismo tambi�n
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