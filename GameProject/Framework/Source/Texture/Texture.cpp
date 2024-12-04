#include "Texture.h"


#define STB_IMAGE_IMPLEMENTATION
#include "Libraries/stb_image.h"

fw::Texture::Texture()
{
	
	// Example:
// Allocate an array of unsigned chars.
// If we want an 5x3 array with 4 unsigned chars each,
//   we can do this, but it'll be very hard-coded.
	unsigned char* pixels = new unsigned char[5 * 3 * 4];

	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 5; x++)
		{
			int index = (y * 5 + x) * 4;

			// Fill the pixel with a color of your choice.
			pixels[index + 0] = 0;
			pixels[index + 1] = 0;
			pixels[index + 2] = 255;
			pixels[index + 3] = 255;
		}
	}

	glGenTextures(1, &m_TextureID);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, m_TextureID);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 5, 3, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	glBindTexture(GL_TEXTURE_2D, 0);
}

fw::Texture::Texture(const char* filename)
{
	int x, y, n;

	stbi_set_flip_vertically_on_load(true);
	unsigned char* data = stbi_load(filename, &x, &y, &n, 4);

	if (data != nullptr)
	{
		glGenTextures(1, &m_TextureID);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, m_TextureID);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, x, y, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

		//free pointer
		stbi_image_free(data);
	}


}

fw::Texture::~Texture()
{
	glDeleteTextures(1, &m_TextureID);
}

GLuint fw::Texture::GetTextureID()
{
    return m_TextureID;
}
