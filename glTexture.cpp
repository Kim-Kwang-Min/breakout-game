
#include "glTexture.h"

/*
SRC(figura):
      0
      |
      |
0----0.5----1
      |
      |
      1

DEST(imagem):
      1
      |
      |
-1----0----1
      |
      |
     -1
*/

GLTexture::GLTexture(const char *filename) {
	tex = SOIL_load_OGL_texture(
		filename,
		SOIL_LOAD_RGBA,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MULTIPLY_ALPHA
	);

	if(!tex) {
		throw std::runtime_error("Can\'t load texture!\n");
	}
}

void GLTexture::drawEntire(double x_orig,double y_orig,
	double x_dest,double y_dest) {
	glBindTexture(GL_TEXTURE_2D,tex);
	glBegin(GL_QUADS);
		glTexCoord2f (0.0f, 0.0f); glVertex2f (x_orig,y_orig);
		glTexCoord2f (1.0f, 0.0f); glVertex2f (x_dest,y_orig);
		glTexCoord2f (1.0f, 1.0f); glVertex2f (x_dest,y_dest);
		glTexCoord2f (0.0f, 1.0f); glVertex2f (x_orig,y_dest);
	glEnd();
}

void GLTexture::drawEntireReverseX(double x_orig,double y_orig,
	double x_dest,double y_dest) {
	glBindTexture(GL_TEXTURE_2D,tex);
	glBegin(GL_QUADS);
		glTexCoord2f (0.0f, 0.0f); glVertex2f (x_dest,y_orig);
		glTexCoord2f (1.0f, 0.0f); glVertex2f (x_orig,y_orig);
		glTexCoord2f (1.0f, 1.0f); glVertex2f (x_orig,y_dest);
		glTexCoord2f (0.0f, 1.0f); glVertex2f (x_dest,y_dest);
	glEnd();
}
