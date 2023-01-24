#include <err.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "./BasicStructHeader.h"
#include "./FFT_Basics.h"
#include "./BlurringFilters/BlurringFiltersHeader.h"
#include "./ColorFilters/ColorFiltersHeader.h"
#include "./DetectionFilters/DetectionFiltersHeader.h"
#include "./MathsFilters/MathsFiltersHeader.h"

SDL_Surface* load_image(const char* path)
{
    SDL_Surface* surface = IMG_Load(path);
    SDL_Surface* newsurface = SDL_ConvertSurfaceFormat(surface, SDL_PIXELFORMAT_RGBA8888, 0);
    SDL_FreeSurface(surface);
    return newsurface;
}

int main(int argc , char** argv)
{
    
    return 0;
}
