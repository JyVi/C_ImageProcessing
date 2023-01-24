#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "../BasicStructHeader.h"

Uint8 Greyscale(SDL_Surface* surface)
{
    Uint8* GreyPixels = malloc (surface->w * surface->h * sizeof(Uint8));
    SDL_LockSurface(surface);
    Uint32* Pixels = (Uint32*)surface->pixels;
    for (size_t i = 0; i < surface->w * surface->h; i++)
    {
        Uint8 r, g, b;
        SDL_GetRGB(Pixels[i], surface->format, &r, &g, &b);
        GreyPixels[i] = 0.2126*r + 0.7152*g + 0.0722*b;
    }
    SDL_UnlockSurface(surface);
    return GreyPixels;
}
