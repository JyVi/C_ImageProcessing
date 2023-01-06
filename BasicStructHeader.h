#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

struct Image 
{
    SDL_Surface* surface;
    SDL_PixelFormat* format;
    size_t width = surface->w;
    size_t height = surface->h;
    size_t size = width * height;
    Uint32* Pixels;
    Uint8* GreyPixels;
}typedef Image;

Image ToImage(SDL_Surface* surface)
{
    Image image;
    image.surface = surface;
    image.format = surface->format;
    SDL_LockSurface(surface);

    Uint32* PreviousPix = (Uint32*)surface->pixels;
    image.Pixels = malloc(surface->w * surface->h * sizeof(Uint32));
    memcpy(image.Pixels, PreviousPix, surface->w * surface->h * sizeof(Uint32));
    image.GreyPixels = malloc(surface->w * surface->h * sizeof(Uint8));

    SDL_UnlockSurface(surface);
    return image;
}

void FreeImage(Image* image)
{
    free(image->Pixels);
    free(image->GreyPixels);
}
