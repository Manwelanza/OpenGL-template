#pragma once
#include "malla.h"
class Cube :
	public Malla
{
public:
	Cube();
	Cube(GLdouble width, Color4 color_ = Color4(0,0,0,1));
	virtual ~Cube();
	void draw();
	bool load(char arch[]);

protected:
	void activar();
	void desactivar();
private:
	Color4 color;
};

