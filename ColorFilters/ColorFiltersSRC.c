#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "../BasicStructHeader.h"
#include "ColorFiltersHeader.h"

Image Greyscale(Image image)
{
    Uint8* GreyPixels = malloc(image.size * sizeof(Uint8));
    for (size_t i = 0; i < image.size; i++)
    {
        Uint8 r, g, b;
        SDL_GetRGB(image.Pixels[i], image.format, &r, &g, &b);
        GreyPixels[i] = 0.2126*r + 0.7152*g + 0.0722*b;
    }
    image.GreyPixels = GreyPixels;
    return image;
}
