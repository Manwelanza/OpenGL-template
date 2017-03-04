#include "textura.h"



bool Textura::load(const std::string & BMP_Name) {
	// la textura debe estar inicializada -> escena::init()
	PixMap24RGB pixMap;
	try {
		pixMap.load_bmpBGR(BMP_Name); // cargar
	}
	catch (const std::ios_base::failure e) {
		std::cerr << "Fallo en el catch 1: " << e.what() << std::endl;
	}
	catch (const std::bad_alloc e) {
		std::cerr << "Fallo de memoria: " << e.what() << std::endl;
	}
	catch (...) {
		std::cerr << "Excepción general" << std::endl;
	}
	w = pixMap.width();
	h = pixMap.height();
	glBindTexture(GL_TEXTURE_2D, id); // transferir a openGL
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_RGB,
		GL_UNSIGNED_BYTE, pixMap.map());
	
	return true;
	//TODO
}


void Textura::save(const std::string & BMP_Name) {
	//create_pixmap
	PixMap24RGB pixMap;
	pixMap.create_pixmap(w, h);

	glGetTexImage(GL_TEXTURE_2D, 0, GL_RGB, // obtener de openGL
		GL_UNSIGNED_BYTE, pixMap.data());


	pixMap.save_bmpBGR(BMP_Name);
	// pA array donde guardar los datos (de tipo y tamaño adecuado)
	// TODO y guardar
}