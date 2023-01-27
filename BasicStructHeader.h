#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <math.h>
#include "./ColorFilters/ColorFiltersHeader.h"

struct Image 
{
    size_t width;
    size_t height;
    size_t size;
    Uint32* Pixels;
    Uint8* GreyPixels;
}typedef Image;

Image* NewImage()
{
    Image* image = malloc(sizeof(Image));
    image->width = 0;
    image->height = 0;
    image->size = 0;
    image->Pixels = NULL;
    image->GreyPixels = NULL; 
    return image;
}

Image* ToImage(SDL_Surface* surface)
{
    Image* image = NewImage();
    image->width = surface->w;
    image->height = surface->h;
    image->size = image->width * image->height;
    SDL_LockSurface(surface);

    Uint32* PreviousPix = (Uint32*)surface->pixels;
    image->Pixels = (Uint32*)malloc(image->size * sizeof(Uint32));
    memcpy(image->Pixels, PreviousPix, image->size * sizeof(Uint32));
    image->GreyPixels = Greyscale(surface);

    SDL_UnlockSurface(surface);
    return image;
}

void FreeImage(Image* image)
{
    free(image->Pixels);
    free(image->GreyPixels);
}

void WriteFile(void* data, size_t size, size_t count, FILE* file)
{
    fwrite(data, size, count, file);
}
