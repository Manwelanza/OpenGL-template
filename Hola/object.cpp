#include "object.h"


Object::Object()
{
	posicion = PVec3();
	rotaciones = new GLdouble[3];
	rotaciones[0] = 0;
	rotaciones[1] = 0;
	rotaciones[2] = 0;
	malla = NULL;
	//textura = NULL;
	activo = true;
}


Object::~Object()
{
	if (rotaciones) {
		delete[] rotaciones;
		rotaciones = NULL;
	}
}

void Object::init(){
	/*if (textura) {
		textura->init();
	}*/
}

void Object::draw() {
	if (activo) {
		glRotated(rotaciones[0], 1, 0, 0);
		glRotated(rotaciones[1], 0, 1, 0);
		glRotated(rotaciones[2], 0, 0, 1);
		glTranslated(posicion.x, posicion.y, posicion.z);
		if (malla) {
			malla->draw();
		}
		glTranslated(-posicion.x, -posicion.y, -posicion.z);
		glRotated(-rotaciones[2], 0, 0, 1);
		glRotated(-rotaciones[1], 0, 1, 0);
		glRotated(-rotaciones[0], 1, 0, 0);
	}
}

void Object::resize(int width, int height) {
	malla->resize(width, height);
}

void Object::rotation(PVec3 angles) {
	rotaciones[0] += angles.x;
	rotaciones[1] += angles.y;
	rotaciones[2] += angles.z;
}

void Object::move(PVec3 movement) {
	posicion.x += movement.x;
	posicion.y += movement.y;
	posicion.z += movement.z;
}


