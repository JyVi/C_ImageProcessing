#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "../BasicStructHeader.h"

void ReScale(Image image, double factor, size_t newWidth, size_t newHeight)
{
    size_t oldWidth = image.width;
    size_t oldHeight = image.height;
    size_t oldSize = image.size;
    size_t newSize = newWidth * newHeight;
    Uint8* oldGreyPixels = image.GreyPixels;
    Uint8* newGreyPixels = (Uint8*)malloc(newSize * sizeof(Uint8));

    // bicubic interpolation
    for (size_t y = 0; y < newHeight; y++)
    {
        for (size_t x = 0; x < newWidth; x++)
        {
            // original pixel coordinates
            double xImage = y / factor;
            double yImage = x / factor;

            // coordinates of the 4 surrounding pixels
            int x0 = floor(xImage);
            int x1 = x0 + 1;
            int y0 = floor(yImage);
            int y1 = y0 + 1;

        }
        
    }

    image.width = newWidth;
    image.height = newHeight;
    image.size = newSize;
    free(image.GreyPixels);
    image.GreyPixels = newGreyPixels;
}
