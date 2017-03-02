//#pragma once
#ifndef _H_tipos_H_
#define _H_tipos_H_

#include <GL/freeglut.h>
#include <cmath>
#include <iostream>
//-------------------------------------------------------------------------

#define uint unsigned int

/**
 * Clase que representa un vector o punto en el espacio tridimensional
*/
class PVec3 {
public:
	//constructor y destructor
	PVec3(GLdouble ax = 0.0, GLdouble ay = 0.0, GLdouble az = 0.0) : x(ax), y(ay), z(az) {};
	~PVec3() {};
	//ajustar coordenadas
	void set(GLdouble px, GLdouble py, GLdouble pz){ x = px; y = py; z = pz; };
	//agrega un valor a las coordeandas del vector
	void add(PVec3 v){ x = x + v.x; y = y + v.y; z = z + v.z; };
	//multiplica las coordenadas por un valor
	void dot(GLdouble e){ x = x*e; y = y*e; z = z*e; };
	//normaliza el vector
	void normalize(){ GLdouble M = magnitude(); x = x / M; y = y / M; z = z / M; };

	//clona el vector, devolviendo uno nuevo
	PVec3 clone() {
		return PVec3(x, y, z);
	}
	//devuelve un nuevo vector normalizado
	PVec3 get_normalized_vector() {
		PVec3 res = (*this).clone();
		res.normalize();
		return res;
	}

	//producto escalar de 2 vectores
	GLdouble dot(PVec3 v){ return x*v.x + y*v.y + z*v.z; }; //  para calcular el coseno del ángulo (= 0 -> perpendiculares)
	//magnitud del vector (longitud)
	GLdouble magnitude(){ return sqrt(x*x + y*y + z*z); };
	//producto vectorial de dos vectores
	PVec3 cross(PVec3 v){ return PVec3(y*v.z - z*v.y, z*v.x - x*v.z, x*v.y - y*v.x); }; // para calcular el vector normal (perpendicular)


	//resta de vectores
	PVec3 operator-(const PVec3& other) {
		return PVec3(x - other.x, y - other.y, z - other.z);
	}
	//resta de escalar al vector
	PVec3 operator-(const GLdouble& magnitude) {
		return PVec3(x - magnitude, y - magnitude, z - magnitude);
	}
	//suma de vectores
	PVec3 operator+(const PVec3& other) {
		return PVec3(x + other.x, y + other.y, z + other.z);
	}
	//suma de escalar al vector
	PVec3 operator+(const GLdouble& magnitude) {
		return PVec3(x + magnitude, y + magnitude, z + magnitude);
	}
	//multiplicación por escalar
	PVec3 operator*(const GLdouble& magnitude) {
		return PVec3(x * magnitude, y * magnitude, z * magnitude);
	}
	//división por escalar
	PVec3 operator/(const GLdouble& magnitude) {
		return PVec3(x / magnitude, y / magnitude, z / magnitude);
	}

	//resta de vectores igualando
	PVec3 operator-=(const PVec3& other) {
		x -= other.x;
		y -= other.y;
		z -= other.z;
		return *this;
	}
	//suma de vectores igualando
	PVec3 operator+=(const PVec3& other) {
		x += other.x;
		y += other.y;
		z += other.z;
		return *this;
	}
	//resta de vectores igualando
	PVec3 operator-=(const GLdouble& magnitude) {
		x -= magnitude;
		y -= magnitude;
		z -= magnitude;
		return *this;
	}
	//suma de vectores igualando
	PVec3 operator+=(const GLdouble& magnitude) {
		x += magnitude;
		y += magnitude;
		z += magnitude;
		return *this;
	}
	//producto por escalar igualando
	PVec3 operator*=(const GLdouble& magnitude) {
		x *= magnitude;
		y *= magnitude;
		z *= magnitude;
		return *this;
	}
	//division por escalar igualando
	PVec3 operator/=(const GLdouble& magnitude) {
		x /= magnitude;
		y /= magnitude;
		z /= magnitude;
		return *this;
	}


	//función para proyectar sobre el plano al cual otro vector es normal
	//si A es el vector proyectado, y B el normal al plano,
	//la ecuación es A-(A dot B)*B
	PVec3 project(PVec3 v) {
		return *this - v*v.dot(*this);
	}

	//función para encontrar la reyección sobre el plano al cual v es normal
	//si A es el vector proyectado, y B el normal al plano,
	//la ecuación es A - project(A, B) = (A dot B)*B
	PVec3 reject(PVec3 v) {
		return v*v.dot(*this);
	}

	//función para rotar respecto a un vector
	//asumiendo v=u,v,w normalizado, el resultado es:
	//	x: u(ux+vy+wz)(1-cos(angle)) + xcos(angle) + (-wy+vz)sin(angle)
	//	y: v(ux+vy+wz)(1-cos(angle)) + ycos(angle) + (wx-uz)sin(angle)
	//	z: w(ux+vy+wz)(1-cos(angle)) + zcos(angle) + (-vx+uy)sin(angle)
	//llamando A al vector original y B al eje:
	//	R = B*(A dot B)*(1-cos(angle)) + A*cos(angle) + (A cross B)*sin(angle)
	PVec3 rotate_against_normal_vector(PVec3 v, GLdouble angle) {
		return v*v.dot(*this)*(1 - cos(angle)) + (*this)*cos(angle) + (*this).cross(v)*sin(angle);
	}

private:
	friend std::ostream& operator<<(std::ostream &strm, const PVec3 &pVec3) { return strm << "PVec3(" << pVec3.x << ", " << pVec3.y << ", " << pVec3.z << ")"; }

public:
	GLdouble x, y, z;
};

/**
* Clase que representa coordenadas en una textura bidimensional
*/
class CTex2 {
public:
	//constructor y destructor
	CTex2(GLdouble ss = 0.0, GLdouble tt = 0.0) : s(ss), t(tt) {};
	~CTex2() {};
public:
	GLdouble s, t;
};

/**
* Clase que representa un color en el espacio RGBA
*/
class Color4 {
public:
	//constructor y destructor
	Color4(GLdouble rr = 0.0, GLdouble gg = 0.0, GLdouble bb = 0.0, GLdouble aa = 1.0) : r(rr), g(gg), b(bb), a(aa) {};
	~Color4() {};
public:
	GLdouble r, g, b, a;
};

//-------------------------------------------------------------------------

class Camara {
public:
  Camara(GLdouble aw, GLdouble ah) :eye(0.0, 0.0, 500.0), look(0.0, 0.0, 0.0), up(0.0, 1.0, 0.0),
                                    xRight(aw / 2.0), xLeft(-xRight), yTop(ah / 2.0), yBot(-yTop), nearVal(1), farVal(1000) {};
  ~Camara() {};

  void setPos(PVec3 ay, PVec3 al, PVec3 ap);
  void setPos();

  void setVV(GLdouble aw, GLdouble ah);
  void setVV();
  void setVV(GLdouble xL, GLdouble xR, GLdouble yT, GLdouble yB, GLdouble nV, GLdouble fV) { nearVal = nV; farVal = fV; setVV(xL, xR, yT, yB, nV, fV); };

  void setEZ();
  void set3D();
public:
  PVec3 eye, look, up;
  GLdouble xRight, xLeft, yTop, yBot, nearVal, farVal;
};

//-------------------------------------------------------------------------

class PuertoVista {
public:
  PuertoVista(GLuint ax, GLuint ay, GLsizei aw, GLsizei ah) : x(ax), y(ay), w(aw), h(ah) {};
  ~PuertoVista() {};
  void set(GLuint ax, GLuint ay, GLsizei aw, GLsizei ah){ x = ax; y = ay; w = aw; h = ah; set(); };
  void set();
public:
  GLint x, y;
  GLsizei w, h;
};

//-------------------------------------------------------------------------

#endif //_H_tipos_H_