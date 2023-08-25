#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "./BasicStructHeader.h"
#include "../MathsFilters/MathsFiltersHeader.h"
#include <math.h>

// 1D FFT
void FFT1D(double* real, double* imag, size_t size);

// 2D FFT
/*
* @brief Perform the 2D FFT on the input image
* @param real is the real part of the input image
* @param imag is the imaginary part of the input image
* @param width is the width of the input image
* @param height is the height of the input image
*/
void FFT2D(double* real, double* imag, size_t width, size_t height);

// inverse 2D FFT
/*
* @brief Perform the 2D IFFT on the input image
* @param real is the real part of the input image
* @param imag is the imaginary part of the input image
* @param width is the width of the input image
* @param height is the height of the input image
*/
void IFFT2D(double* real, double* imag, size_t width, size_t height);
