//#pragma once

#ifndef _H_piramideTri_H_
#define _H_piramideTri_H_

#include "malla.h"
#include "tipos.h"
#include <GL/freeglut.h>

class PiramideTri :
	public Malla
{
public:
	PiramideTri();
	PiramideTri(int vertex_number, GLdouble radius, GLdouble height);
	virtual ~PiramideTri();
	void draw();
	bool load(char arch[]);

};

#endif //_H_piramideTri_H_