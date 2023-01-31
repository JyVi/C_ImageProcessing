#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "../BasicStructHeader.h"

void ReScale(Image image, double factor, size_t newWidth, size_t newHeight);
size_t GetPowerOfTwo(size_t size);
void ZeroPad(void* array, size_t size, size_t newSize);
