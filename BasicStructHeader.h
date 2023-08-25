#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <math.h>
//#include "./ColorFilters/ColorFiltersHeader.h"

struct Image 
{
    size_t width;
    size_t height;
    size_t size;
    Uint32* Pixels;
    Uint8* GreyPixels;
}typedef Image;

Image* NewImage();
Image* ToImage(SDL_Surface* surface);
void FreeImage(Image* image);
void WriteFile(void* data, size_t size, size_t count, FILE* file);
