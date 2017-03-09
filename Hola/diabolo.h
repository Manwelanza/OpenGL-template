//#pragma once

#ifndef _H_diabolo_H_
#define _H_diabolo_H_

#include "piramideTri.h"
#include "tipos.h"
#include <GL/freeglut.h>

class Diabolo :
	public PiramideTri
{
public:
	Diabolo();
	Diabolo(int vertex_number, GLdouble radius, GLdouble height);
	virtual ~Diabolo();
	void draw();
	bool load(char arch[]);
	
protected:
	GLdouble pyramid_degree_offset;
};

#endif
