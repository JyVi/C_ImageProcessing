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
#include <sys/stat.h>

SDL_Surface* load_image(const char* path)
{
    SDL_Surface* surface = IMG_Load(path);
    SDL_Surface* newsurface = SDL_ConvertSurfaceFormat(surface, SDL_PIXELFORMAT_RGBA8888, 0);
    SDL_FreeSurface(surface);
    return newsurface;
}

int main(int argc, char** argv[])
{
    int debug = 0;
    int path = 0;
    char* folder = NULL;
    SDL_Surface* surface = NULL;
    if (argc < 2)
        errx(1, "Usage : image-file, -d debug, -p path to create folder");
    if (argc >= 2)
    {
        surface = load_image(argv[1]);
        if (surface == NULL)
            errx(1, "Error while loading the image");
        for (int i = 2; i < argc; i++)
        {
            if (strcmp(argv[i], "-d") == 0 && debug == 0)
                debug = 1;
            if (strcmp(argv[i], "-p") == 0 && path == 0)
            {
                if (i + 1 < argc)
                {
                    path = 1;
                    folder = argv[i + 1];
                    mkdir(folder, 0777);
                }
                else
                    errx(1, "Error while creating the folder");
            }
        }
    }
    Image* image = NewImage();
    image = ToImage(surface);

    // Blurring Filters
    Image* BlurredImage = NewImage();
     

    FreeImage(image);
    return 0;
}
