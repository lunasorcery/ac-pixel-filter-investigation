#include <cstdio>
#include "xbrz1.8/xbrz.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb/stb_image_write.h"

int main(int argc, char const* const* argv)
{
	int const kScale = 4;

	if (argc <= 1)
		return 1;

	int w,h,comp;
	uint8_t* srcData = stbi_load(argv[1], &w, &h, &comp, 4);
	{
		uint8_t* dstData = new uint8_t[w*h*4*kScale*kScale];
		{
			xbrz::ScalerCfg cfg;
			xbrz::scale(kScale, (uint32_t*)srcData, (uint32_t*)dstData, w, h, xbrz::ColorFormat::ARGB, cfg, 0, h);
			stbi_write_png("out.png", w*kScale, h*kScale, 4, dstData, w*kScale*4);
		}
		delete[] dstData;
	}
	stbi_image_free(srcData);
}
