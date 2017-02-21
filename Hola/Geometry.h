//#pragma once

#ifndef _H_Geometry_H_
#define _H_Geometry_H_

#include <GL/freeglut.h>
#include <cmath>
#include "tipos.h"

class Geometry
{
public:
	~Geometry();
	static bool isInitiated();
	static Geometry* Instance();
	void drawLine(PVec3 origin, PVec3 destination, PVec3 color = *new PVec3());
	void drawLines(int lines, PVec3 points[], PVec3 color = *new PVec3());
	void drawLines(int lines, PVec3 points[], PVec3 colors []);
	

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