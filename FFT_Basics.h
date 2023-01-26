#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "./BasicStructHeader.h"
#include <math.h>

void FFT1D(double* real, double* imag, size_t size)
{
    // bit reverse the 2 input arrays which are of same size
    // reverse in first the order table
    int* bit_reversed = (int*)malloc(sizeof(int) * size);

    for (size_t i = 0; i < size; i++)
    {
        bit_reversed[i] =(bit_reversed[i >> 1] >> 1) | ((i & 1) << (int)(log2(size) - 1));
    }

    for (size_t i = 0; i < size; i ++)
    {
        // why i > bit_reversed[i]  and not i < bit_reversed[i] ?
        // because we want to swap the values only once
        // but why > and not < ?
        // because we want to swap the values only once yeah but why > and not < ?
        // if i want to use < then i will have to swap the values twice
        // and that will be a waste of time
        if (i > bit_reversed[i])
        {
            // swap the values
            double temp_real = real[i];
            double temp_imag = imag[i];

            real[i] = real[bit_reversed[i]];
            imag[i] = imag[bit_reversed[i]];

            real[bit_reversed[i]] = temp_real;
            imag[bit_reversed[i]] = temp_imag;
        }
    }

    // perform the FFT
    /* s is the size of the sub array
    *  w_real and w_imag are the real and imaginary part of the twiddle factor
    *  k is the index of the sub array
    *  w_real_temp and w_imag_temp are the real and imaginary part of the twiddle factor
    *  j is the index of the array
    *  idex is the index of the array
    *  temp_real and temp_imag are the real and imaginary part of the twiddle factor
    *  the algorithm is the same as the one in the 1D FFT
    *  for each sub array of size s
    *  for each element of the sub array
    *  calculate the twiddle factor
    *  for each element of the array
    *  calculate the twiddle factor
    *  calculate the real and imaginary part of the twiddle factor
    *  swap the values
    *  increase the size of the sub array by 2
    */
    for (size_t s = 1; s < size; s *= 2)
    {
        // which explain why i have 2 temp variables
        // double tw_real = cos(M_PI / s);
        // double tw_imag = -sin(M_PI / s);
        for (size_t k = 0; k < s; k++)
        {
            // this is the twiddle factor
            // here i split the real and imaginary part of the numbers
            // dos the 2 multplied by M_PI cancel each other ? no why ? 
            double tw_real_temp = cos(2 * M_PI * k / (2 * s));
            double tw_imag_temp = -sin(2 * M_PI * k / (2 * s));
            for (size_t j = 0; j < size; j += 2*s)
            {
                size_t idex = j+k;
                double temp_real = real[idex + s] * tw_real_temp - imag[idex + s] * tw_imag_temp;
                double temp_image = real[idex + s] * tw_imag_temp + imag[idex + s] * tw_real_temp;

                double temp_real2 = real[idex];
                double temp_imag2 = imag[idex];
                real[idex] = temp_real2 + temp_real;
                imag[idex] = temp_imag2 + temp_image;
                real[idex + s] = temp_real2 - temp_real;
                imag[idex + s] = temp_imag2 - temp_image;
            }
        }
    }

    free(bit_reversed);
}

// 2D FFT
void FFT2D(double* real, double* imag, size_t width, size_t height)
{
    // Perform the 1d FFT on each row
    for (size_t i = 0; i < height; i++)
    {
        for (size_t j = 0; j < width; j++)
        {
            // pointer notation same as real[i * widthj] and imag[i * width]
            FFT1D(real + i * width, imag + i * width, width);
        }
    }
    // transpose the 2D aray
    // swap those values once only
    for (size_t i = 0; i < height; i++)
    {
        // here once because j = i + 1 we swap only the half of the matrix
        for (size_t j = i; j < width; j++)
        {
            double temp_real = real[i * width + j];
            double temp_imag = imag[i * width + j];

            real[i * width + j] = real[j * width + i];
            imag[i * width + j] = imag[j * width + i];

            real[j * width + i] = temp_real;
            imag[j * width + i] = temp_imag;
        }
    }
}

// inverse 2D FFT
void IFFT2D(double* real, double* imag, size_t width, size_t height)
{
    // So the inverse FFT is the same as the FFT but with the imaginary part of the twiddle factor
    // being multiplied by -1
    // twadle factor = cos(2 * M_PI * k / (2 * s)) - sin(2 * M_PI * k / (2 * s)) * i

    // for loop of 2 because we want to perform the FFT twice
    // once on the rows and once on the columns
    // and we need to transpose the matrix after the first FFT
    for (short k = 0; k < 2; k++)
    {
        // first lets transpose the 2D array
        for (size_t i = 0; i < height; i++)
        {
            // here once because j = i + 1 we swap only the half of the matrix 
            for (size_t j = i + 1; j < width; j++)
            {
                double temp_real = real[i * width + j];
                double temp_imag = imag[i * width + j];

                real[i * width + j] = real[j * width + i];
                imag[i * width + j] = imag[j * width + i];

                real[j * width + i] = temp_real;
                imag[j * width + i] = temp_imag;
            }
        }

        // now we will perferm the 1DFFT to each row of the transposed matrix
        for (size_t i = 0; i < height; i++)
        {
            // pointer notation same as real[i * widthj] and imag[i * width]
            FFT1D(real + i * width, imag + i * width, width);
        }
    }

    // normalising the arrays
    size_t size = width * height;
    for (size_t i = 0; i < size; i++)
    {
        real[i] /= size;
        imag[i] /= size;
    }
}
