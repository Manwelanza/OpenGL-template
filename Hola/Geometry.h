//#pragma once

#ifndef _H_Geometry_H_
#define _H_Geometry_H_

#include <GL/freeglut.h>
#include <cmath>
#include "tipos.h"
#include "piramideTri.h"
#include "mallaTri.h"

class Geometry
{
public:
	~Geometry();
	static bool isInitiated();
	static Geometry* Instance();
	// Lines
	void drawLine(PVec3 origin, PVec3 destination, PVec3 color = *new PVec3());
	void drawLines(int lines, PVec3 points[], PVec3 color = *new PVec3());
	void drawLines(int lines, PVec3 points[], PVec3 colors []);
	//Triangles
	void drawTriangle(int vertex_number, GLdouble radius);
	MallaTri createTriangle(int vertex_number, GLdouble radius);
	void drawPyramid(int vertex_number, GLdouble radius, GLdouble height);
	PiramideTri createPyramid(int vertex_number, GLdouble radius, GLdouble height);

private:
	Geometry(PVec3 eje_ = *new PVec3());
	Geometry(Geometry const&){};
	Geometry& operator=(Geometry const&){};

public:
	PVec3 eje;
private:
	static Geometry* _instance;
};

#endif //_H_Geometry_H_