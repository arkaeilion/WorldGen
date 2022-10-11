#ifndef SUSTAIN_IMAGE_H
#define SUSTAIN_IMAGE_H

#include "common.h"

namespace Sustain {

	class Image {
	private:

	public:
		Image();
		~Image();

		bool LoadTextureFromFile(const char* filename, int* out_texture, int* out_width, int* out_height);
		bool Create(const std::string& path);
	};

}

#endif // SUSTAIN_IMAGE_H
