#include "helpers.h"
#include "stdlib.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float gray = ((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            int Gray = gray;
            if (gray - Gray >= 0.5)
            {
                gray = Gray + 1;
                image[i][j].rgbtRed = gray;
                image[i][j].rgbtGreen = gray;
                image[i][j].rgbtBlue = gray;
            }
            else
            {
                image[i][j].rgbtRed = Gray;
                image[i][j].rgbtGreen = Gray;
                image[i][j].rgbtBlue = Gray;
            }
        }
    }
    return;
}

void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float sepiaRed = 0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue;
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            int sepiared = sepiaRed;
            if (sepiaRed - sepiared >= 0.5)
            {
                sepiaRed = sepiared + 1;
            }
            float sepiaGreen = 0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue;
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            int sepiagreen = sepiaGreen;
            if (sepiaGreen - sepiagreen >= 0.5)
            {
                sepiaGreen = sepiagreen + 1;
            }
            float sepiaBlue = 0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue;
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            int sepiablue = sepiaBlue;
            if (sepiaBlue - sepiablue >= 0.5)
            {
                sepiaBlue = sepiablue + 1;
            }

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }

    return;
}

void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int x = width / 2;
            if (width - 1 - j < x)
            {
                break;
            }
            else
            {
                char tmp = image[i][j].rgbtRed;
                image[i][j].rgbtRed = image[i][width - 1 - j].rgbtRed;
                image[i][width - 1 - j].rgbtRed = tmp;

                char tmg = image[i][j].rgbtGreen;
                image[i][j].rgbtGreen = image[i][width - 1 - j].rgbtGreen;
                image[i][width - 1 - j].rgbtGreen = tmg;

                char tmb = image[i][j].rgbtBlue;
                image[i][j].rgbtBlue = image[i][width - 1 - j].rgbtBlue;
                image[i][width - 1 - j].rgbtBlue = tmb;
            }
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    float totalr, totalg, totalb;
    int counter = 0;
    totalr = totalg = totalb = 0;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            for (int colum = i - 1; colum <= i + 1; colum++)
            {
                for (int row = j - 1; row <= j + 1; row++)
                {
                    if (row < width && colum < height && row >= 0 && colum >= 0)
                    {
                        totalr += copy[colum][row].rgbtRed;
                        totalg += copy[colum][row].rgbtGreen;
                        totalb += copy[colum][row].rgbtBlue;
                        counter++;
                    }
                }
            }

            image[i][j].rgbtRed = round(totalr / counter);
            image[i][j].rgbtGreen = round(totalg / counter);
            image[i][j].rgbtBlue = round(totalb / counter);
            counter = 0;
            totalr = totalg = totalb = 0;
        }
    }
    return;
}
