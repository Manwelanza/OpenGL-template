//#pragma once

#ifndef _H_textura_H_
#define _H_textura_H_

#include "tipos.h"
#include <GL/freeglut.h>
#include "PixMap24RGB.h"

class Textura {
public:
	Textura() : w(0), h(0), id(0) {};
	~Textura() { glDeleteTextures(1, &id); };
	void init() {
		//pedimos hueco para una textura (podr�amos pedir m�s)
		//hasta que no tenemos el identificador, lo que hagamos no tiene efecto
		glGenTextures(1, &id);
		activar(); 
		//obligatoriamente establecer uno de los filtros
		//en este caso, media lineal de los colores de alrededor
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	};
	void activar() { 
		glBindTexture(GL_TEXTURE_2D, id); 
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE); 
	};
	void desactivar() { glBindTexture(GL_TEXTURE_2D, 0); };
	bool load(const std::string & BMP_Name); // cargar y transferir a openGL
	void save(const std::string & BMP_Name, int aw, int ah); // obtener de openGL y guardar

	bool load(const std::string & BMP_Name, GLubyte alpha);
	bool load(const std::string & BMP_Name, PixMap24RGB::rgb_color colorKey, GLubyte alpha);

	PixMap24RGB* loadPixMap(const std::string & BMP_Name);
public:
	uint w, h; // dimensiones de la imagen
	GLuint id; // identificador interno de la textura

private:
	
};


#endif