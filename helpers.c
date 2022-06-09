#include "helpers.h"
#include <stdio.h>
#include <cs50.h>
#include <math.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int a = 0; a < width; a++)
        {
            float faverage = 0;
            int iaverage = 0;
            faverage = (image[i][a].rgbtRed + image[i][a].rgbtBlue + image[i][a].rgbtGreen) / 3.0;
            iaverage = round(faverage);
            image[i][a].rgbtRed = iaverage;
            image[i][a].rgbtBlue = iaverage;
            image[i][a].rgbtGreen = iaverage;

        }


    }


    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //int width2 = floor(width/2);

    for (int i = 0; i < height; i++)
    {
        for (int a = 0; a < width / 2; a++)
        {

            RGBTRIPLE temp;

            temp.rgbtRed = image[i][a].rgbtRed;
            temp.rgbtBlue = image[i][a].rgbtBlue;
            temp.rgbtGreen = image[i][a].rgbtGreen;
            image[i][a] = image[i][width - a - 1];

            image[i][width - a - 1] = temp;

        }


    }


    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE image2[height][width];
    //image2 = image;
    float average = 0;
    int average2 = 0;
    for (int i = 0; i < height; i++)
    {
        for (int a = 0; a < width; a++)
        {

            image2[i][a] = image[i][a];

        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int a = 0; a < width; a++)
        {

            if ((a == 0) && (i == height - 1))
            {
                //Bottom Left
                average = (image2[i][a].rgbtRed + image2[i][a + 1].rgbtRed + image2[i - 1][a].rgbtRed + image2[i - 1][a + 1].rgbtRed) / 4.0;
                average2 = round(average);
                image[i][a].rgbtRed = average2;
                average = (image2[i][a].rgbtBlue + image2[i][a + 1].rgbtBlue + image2[i - 1][a].rgbtBlue + image2[i - 1][a + 1].rgbtBlue) / 4.0;
                average2 = round(average);
                image[i][a].rgbtBlue = average2;
                average = (image2[i][a].rgbtGreen + image2[i][a + 1].rgbtGreen + image2[i - 1][a].rgbtGreen + image2[i - 1][a + 1].rgbtGreen) / 4.0;
                average2 = round(average);
                image[i][a].rgbtGreen = average2;
            }
            else if ((a == 0) && (i == 0))
            {
                //Top Left
                average = (image2[i][a].rgbtRed + image2[i][a + 1].rgbtRed + image2[i + 1][a].rgbtRed + image2[i + 1][a + 1].rgbtRed) / 4.0;
                average2 = round(average);
                image[i][a].rgbtRed = average2;
                average = (image2[i][a].rgbtBlue + image2[i][a + 1].rgbtBlue + image2[i + 1][a].rgbtBlue + image2[i + 1][a + 1].rgbtBlue) / 4.0;
                average2 = round(average);
                image[i][a].rgbtBlue = average2;
                average = (image2[i][a].rgbtGreen + image2[i][a + 1].rgbtGreen + image2[i + 1][a].rgbtGreen + image2[i + 1][a + 1].rgbtGreen) / 4.0;
                average2 = round(average);
                image[i][a].rgbtGreen = average2;

            }
            else if ((a == width - 1) && (i == height - 1))
            {
                //Bottom Right
                average = (image2[i][a].rgbtRed + image2[i][a - 1].rgbtRed + image2[i - 1][a].rgbtRed + image2[i - 1][a - 1].rgbtRed) / 4.0;
                average2 = round(average);
                image[i][a].rgbtRed = average2;
                average = (image2[i][a].rgbtBlue + image2[i][a - 1].rgbtBlue + image2[i - 1][a].rgbtBlue + image2[i - 1][a - 1].rgbtBlue) / 4.0;
                average2 = round(average);
                image[i][a].rgbtBlue = average2;
                average = (image2[i][a].rgbtGreen + image2[i][a - 1].rgbtGreen + image2[i - 1][a].rgbtGreen + image2[i - 1][a - 1].rgbtGreen) / 4.0;
                average2 = round(average);
                image[i][a].rgbtGreen = average2;

            }
            else if ((a == width - 1) && (i == 0))
            {
                //Top Right
                average = (image2[i][a].rgbtRed + image2[i][a - 1].rgbtRed + image2[i + 1][a].rgbtRed + image2[i + 1][a - 1].rgbtRed) / 4.0;
                average2 = round(average);
                image[i][a].rgbtRed = average2;
                average = (image2[i][a].rgbtBlue + image2[i][a - 1].rgbtBlue + image2[i + 1][a].rgbtBlue + image2[i + 1][a - 1].rgbtBlue) / 4.0;
                average2 = round(average);
                image[i][a].rgbtBlue = average2;
                average = (image2[i][a].rgbtGreen + image2[i][a - 1].rgbtGreen + image2[i + 1][a].rgbtGreen + image2[i + 1][a - 1].rgbtGreen) / 4.0;
                average2 = round(average);
                image[i][a].rgbtGreen = average2;
            }
            else if (a == 0)
            {
                //Left Edge
                average = (image2[i][a].rgbtRed + image2[i][a + 1].rgbtRed + image2[i + 1][a].rgbtRed + image2[i + 1][a + 1].rgbtRed + image2[i -
                           1][a + 1].rgbtRed + image2[i - 1][a].rgbtRed) / 6.0;
                average2 = round(average);
                image[i][a].rgbtRed = average2;
                average = (image2[i][a].rgbtBlue + image2[i][a + 1].rgbtBlue + image2[i + 1][a].rgbtBlue + image2[i + 1][a + 1].rgbtBlue +
                           image2[i
                                  - 1][a + 1].rgbtBlue + image2[i - 1][a].rgbtBlue) / 6.0;
                average2 = round(average);
                image[i][a].rgbtBlue = average2;
                average = (image2[i][a].rgbtGreen + image2[i][a + 1].rgbtGreen + image2[i + 1][a].rgbtGreen + image2[i + 1][a + 1].rgbtGreen +
                           image2[i - 1][a + 1].rgbtGreen + image2[i - 1][a].rgbtGreen) / 6.0;
                average2 = round(average);
                image[i][a].rgbtGreen = average2;

            }
            else if (a == width - 1)
            {
                //Right Edge
                average = (image2[i][a].rgbtRed + image2[i][a - 1].rgbtRed + image2[i + 1][a].rgbtRed + image2[i + 1][a - 1].rgbtRed + image2[i -
                           1][a - 1].rgbtRed + image2[i - 1][a].rgbtRed) / 6.0;
                average2 = round(average);
                image[i][a].rgbtRed = average2;
                average = (image2[i][a].rgbtBlue + image2[i][a - 1].rgbtBlue + image2[i + 1][a].rgbtBlue + image2[i + 1][a - 1].rgbtBlue +
                           image2[i
                                  - 1][a - 1].rgbtBlue + image2[i - 1][a].rgbtBlue) / 6.0;
                average2 = round(average);
                image[i][a].rgbtBlue = average2;
                average = (image2[i][a].rgbtGreen + image2[i][a - 1].rgbtGreen + image2[i + 1][a].rgbtGreen + image2[i + 1][a - 1].rgbtGreen +
                           image2[i - 1][a - 1].rgbtGreen + image2[i - 1][a].rgbtGreen) / 6.0;
                average2 = round(average);
                image[i][a].rgbtGreen = average2;

            }
            else if (i == height - 1)
            {
                //Bottom Edge
                average = (image2[i][a].rgbtRed + image2[i][a + 1].rgbtRed + image2[i][a - 1].rgbtRed + image2[i - 1][a + 1].rgbtRed + image2[i -
                           1][a - 1].rgbtRed + image2[i - 1][a].rgbtRed) / 6.0;
                average2 = round(average);
                image[i][a].rgbtRed = average2;
                average = (image2[i][a].rgbtBlue + image2[i][a + 1].rgbtBlue + image2[i][a - 1].rgbtBlue + image2[i - 1][a + 1].rgbtBlue +
                           image2[i
                                  - 1][a - 1].rgbtBlue + image2[i - 1][a].rgbtBlue) / 6.0;
                average2 = round(average);
                image[i][a].rgbtBlue = average2;
                average = (image2[i][a].rgbtGreen + image2[i][a + 1].rgbtGreen + image2[i][a - 1].rgbtGreen + image2[i - 1][a + 1].rgbtGreen +
                           image2[i - 1][a - 1].rgbtGreen + image2[i - 1][a].rgbtGreen) / 6.0;
                average2 = round(average);
                image[i][a].rgbtGreen = average2;
            }
            else if (i == 0)
            {
                //Top Edge
                average = (image2[i][a].rgbtRed + image2[i][a + 1].rgbtRed + image2[i][a - 1].rgbtRed + image2[i + 1][a + 1].rgbtRed + image2[i +
                           1][a - 1].rgbtRed + image2[i + 1][a].rgbtRed) / 6.0;
                average2 = round(average);
                image[i][a].rgbtRed = average2;
                average = (image2[i][a].rgbtBlue + image2[i][a + 1].rgbtBlue + image2[i][a - 1].rgbtBlue + image2[i + 1][a + 1].rgbtBlue +
                           image2[i
                                  + 1][a - 1].rgbtBlue + image2[i + 1][a].rgbtBlue) / 6.0;
                average2 = round(average);
                image[i][a].rgbtBlue = average2;
                average = (image2[i][a].rgbtGreen + image2[i][a + 1].rgbtGreen + image2[i][a - 1].rgbtGreen + image2[i + 1][a + 1].rgbtGreen +
                           image2[i + 1][a - 1].rgbtGreen + image2[i + 1][a].rgbtGreen) / 6.0;
                average2 = round(average);
                image[i][a].rgbtGreen = average2;

            }
            else
            {
                //Everything Else
                average = (image2[i][a].rgbtRed + image2[i][a + 1].rgbtRed + image2[i][a - 1].rgbtRed + image2[i + 1][a + 1].rgbtRed + image2[i +
                           1][a - 1].rgbtRed + image2[i + 1][a].rgbtRed + image2[i - 1][a - 1].rgbtRed + image2[i - 1][a + 1].rgbtRed + image2[i -
                                   1][a].rgbtRed) / 9.0;
                average2 = round(average);
                image[i][a].rgbtRed = average2;
                average = (image2[i][a].rgbtBlue + image2[i][a + 1].rgbtBlue + image2[i][a - 1].rgbtBlue + image2[i + 1][a + 1].rgbtBlue +
                           image2[i
                                  + 1][a - 1].rgbtBlue + image2[i + 1][a].rgbtBlue + image2[i - 1][a - 1].rgbtBlue + image2[i - 1][a + 1].rgbtBlue + image2[i -
                                          1][a].rgbtBlue) / 9.0;
                average2 = round(average);
                image[i][a].rgbtBlue = average2;
                average = (image2[i][a].rgbtGreen + image2[i][a + 1].rgbtGreen + image2[i][a - 1].rgbtGreen + image2[i + 1][a + 1].rgbtGreen +
                           image2[i + 1][a - 1].rgbtGreen + image2[i + 1][a].rgbtGreen + image2[i - 1][a - 1].rgbtGreen + image2[i - 1][a + 1].rgbtGreen +
                           image2[i - 1][a].rgbtGreen) / 9.0;
                average2 = round(average);
                image[i][a].rgbtGreen = average2;
            }
        }
    }


    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE image2[height][width];
    //image2 = image;
    float average = 0;
    int average2 = 0;
    float gx = 0;
    float gy = 0;
    float newvalue = 0;
    for (int i = 0; i < height; i++)
    {
        for (int a = 0; a < width; a++)
        {

            image2[i][a] = image[i][a];

        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int a = 0; a < width; a++)
        {
            if ((a == 0) && (i == height - 1))
            {
                //Bottom Left
                gx = (-1.0 * (0)) + (0 * (image2[i - 1][a].rgbtRed)) + (1.0 * (image2[i - 1][a + 1].rgbtRed)) + (-2.0 * (0)) + (0 *
                        (image2[i][a].rgbtRed)) + (2.0 * (image2[i][a + 1].rgbtRed)) + (-1.0 * (0)) + (0 * (0)) + (1.0 * (0));
                gy = (-1.0 * (0)) + (0 * (0)) + (1.0 * (0)) + (-2.0 * (image2[i - 1][a].rgbtRed)) + (0 * (image2[i][a].rgbtRed)) + (2.0 * (0)) +
                     (-1.0 *
                      (image2[i - 1][a + 1].rgbtRed)) + (0 * (image2[i][a + 1].rgbtRed)) + (1.0 * (0));
                newvalue = sqrt((gx * gx) + (gy * gy));
                if (newvalue > 255)
                {
                    newvalue = 255;
                }
                image[i][a].rgbtRed = round(newvalue);
                gx = (-1.0 * (0)) + (0 * (image2[i - 1][a].rgbtBlue)) + (1.0 * (image2[i - 1][a + 1].rgbtBlue)) + (-2.0 * (0)) + (0 *
                        (image2[i][a].rgbtBlue)) + (2.0 * (image2[i][a + 1].rgbtBlue)) + (-1.0 * (0)) + (0 * (0)) + (1.0 * (0));
                gy = (-1.0 * (0)) + (0 * (0)) + (1.0 * (0)) + (-2.0 * (image2[i - 1][a].rgbtBlue)) + (0 * (image2[i][a].rgbtBlue)) + (2.0 * (0)) +
                     (-1.0 *
                      (image2[i - 1][a + 1].rgbtBlue)) + (0 * (image2[i][a + 1].rgbtBlue)) + (1.0 * (0));
                newvalue = sqrt((gx * gx) + (gy * gy));
                if (newvalue > 255)
                {
                    newvalue = 255;
                }
                image[i][a].rgbtBlue = round(newvalue);
                gx = (-1.0 * (0)) + (0 * (image2[i - 1][a].rgbtGreen)) + (1.0 * (image2[i - 1][a + 1].rgbtGreen)) + (-2.0 * (0)) + (0 *
                        (image2[i][a].rgbtGreen)) + (2.0 * (image2[i][a + 1].rgbtGreen)) + (-1.0 * (0)) + (0 * (0)) + (1.0 * (0));
                gy = (-1.0 * (0)) + (0 * (0)) + (1.0 * (0)) + (-2.0 * (image2[i - 1][a].rgbtGreen)) + (0 * (image2[i][a].rgbtGreen)) + (2.0 * (0)) +
                     (-1.0 *
                      (image2[i - 1][a + 1].rgbtGreen)) + (0 * (image2[i][a + 1].rgbtGreen)) + (1.0 * (0));
                newvalue = sqrt((gx * gx) + (gy * gy));
                if (newvalue > 255)
                {
                    newvalue = 255;
                }
                image[i][a].rgbtGreen = round(newvalue);
            }
            else if ((a == 0) && (i == 0))
            {
                //Top Left
                gx = (-1.0 * (0)) + (0 * (0)) + (1.0 * (0)) + (-2.0 * (0)) + (0 * (image2[i][a].rgbtRed)) + (2.0 * (image2[i][a + 1].rgbtRed)) +
                     (-1.0 *
                      (0)) + (0 * (image2[i + 1][a].rgbtRed)) + (1.0 * (image2[i + 1][a + 1].rgbtRed));
                gy = (-1.0 * (0)) + (0 * (0)) + (1.0 * (0)) + (-2.0 * (0)) + (0 * (image2[i][a].rgbtRed)) + (2.0 * (image2[i + 1][a].rgbtRed)) +
                     (-1.0 *
                      (0)) + (0 * (image2[i][a + 1].rgbtRed)) + (1.0 * (image2[i + 1][a + 1].rgbtRed));
                newvalue = sqrt((gx * gx) + (gy * gy));
                if (newvalue > 255)
                {
                    newvalue = 255;
                }
                image[i][a].rgbtRed = round(newvalue);
                gx = (-1.0 * (0)) + (0 * (0)) + (1.0 * (0)) + (-2.0 * (0)) + (0 * (image2[i][a].rgbtBlue)) + (2.0 * (image2[i][a + 1].rgbtBlue)) +
                     (-1.0 *
                      (0)) + (0 * (image2[i + 1][a].rgbtBlue)) + (1.0 * (image2[i + 1][a + 1].rgbtBlue));
                gy = (-1.0 * (0)) + (0 * (0)) + (1.0 * (0)) + (-2.0 * (0)) + (0 * (image2[i][a].rgbtBlue)) + (2.0 * (image2[i + 1][a].rgbtBlue)) +
                     (-1.0 *
                      (0)) + (0 * (image2[i][a + 1].rgbtBlue)) + (1.0 * (image2[i + 1][a + 1].rgbtBlue));
                newvalue = sqrt((gx * gx) + (gy * gy));
                if (newvalue > 255)
                {
                    newvalue = 255;
                }
                image[i][a].rgbtBlue = round(newvalue);
                gx = (-1.0 * (0)) + (0 * (0)) + (1.0 * (0)) + (-2.0 * (0)) + (0 * (image2[i][a].rgbtGreen)) + (2.0 * (image2[i][a + 1].rgbtGreen)) +
                     (-1.0 *
                      (0)) + (0 * (image2[i + 1][a].rgbtGreen)) + (1.0 * (image2[i + 1][a + 1].rgbtGreen));
                gy = (-1.0 * (0)) + (0 * (0)) + (1.0 * (0)) + (-2.0 * (0)) + (0 * (image2[i][a].rgbtGreen)) + (2.0 * (image2[i + 1][a].rgbtGreen)) +
                     (-1.0 * (0)) + (0 * (image2[i][a + 1].rgbtGreen)) + (1.0 * (image2[i + 1][a + 1].rgbtGreen));
                newvalue = sqrt((gx * gx) + (gy * gy));
                if (newvalue > 255)
                {
                    newvalue = 255;
                }
                image[i][a].rgbtGreen = round(newvalue);

            }
            else if ((a == width - 1) && (i == 0))
            {
                //Top Right
                gx = (0.0 * (image2[i][a].rgbtRed) + 0.0 * (0) + -2.0 * (image2[i][a - 1].rgbtRed) + 0.0 * (0) + 0.0 * (0) + 0.0 * (0) + 0.0 *
                      (0) + 0.0 * (image2[i + 1][a].rgbtRed) + -1.0 * (image2[i + 1][a - 1].rgbtRed));
                gy = (0.0 * (image2[i][a].rgbtRed) + 0.0 * (0) + 0.0 * (image2[i][a - 1].rgbtRed) + 0.0 * (0) + 0.0 * (0) + 0.0 * (0) + 0.0 *
                      (0) + 2.0 * (image2[i + 1][a].rgbtRed) + 1.0 * (image2[i + 1][a - 1].rgbtRed));
                newvalue = sqrt((gx * gx) + (gy * gy));
                if (newvalue <= 255)
                {
                    image[i][a].rgbtRed = round(newvalue);
                }
                else
                {
                    image[i][a].rgbtRed = 255;
                }

                gx = (0.0 * (image2[i][a].rgbtGreen) + 0.0 * (0) + -2.0 * (image2[i][a - 1].rgbtGreen) + 0.0 * (0) + 0.0 * (0) + 0.0 * (0) + 0.0 *
                      (0) + 0.0 * (image2[i + 1][a].rgbtGreen) + -1.0 * (image2[i + 1][a - 1].rgbtGreen));
                gy = (0.0 * (image2[i][a].rgbtGreen) + 0.0 * (0) + 0.0 * (image2[i][a - 1].rgbtGreen) + 0.0 * (0) + 0.0 * (0) + 0.0 * (0) + 0.0 *
                      (0) + 2.0 * (image2[i + 1][a].rgbtGreen) + 1.0 * (image2[i + 1][a - 1].rgbtGreen));
                newvalue = sqrt((gx * gx) + (gy * gy));
                if (newvalue <= 255)
                {
                    image[i][a].rgbtGreen = round(newvalue);
                }
                else
                {
                    image[i][a].rgbtGreen = 255;
                }

                gx = (0.0 * (image2[i][a].rgbtBlue) + 0.0 * (0) + -2.0 * (image2[i][a - 1].rgbtBlue) + 0.0 * (0) + 0.0 * (0) + 0.0 * (0) + 0.0 *
                      (0) + 0.0 * (image2[i + 1][a].rgbtBlue) + -1.0 * (image2[i + 1][a - 1].rgbtBlue));
                gy = (0.0 * (image2[i][a].rgbtBlue) + 0.0 * (0) + 0.0 * (image2[i][a - 1].rgbtBlue) + 0.0 * (0) + 0.0 * (0) + 0.0 * (0) + 0.0 *
                      (0) + 2.0 * (image2[i + 1][a].rgbtBlue) + 1.0 * (image2[i + 1][a - 1].rgbtBlue));
                newvalue = sqrt((gx * gx) + (gy * gy));
                if (newvalue <= 255)
                {
                    image[i][a].rgbtBlue = round(newvalue);
                }
                else
                {
                    image[i][a].rgbtBlue = 255;
                }
            }
            else if ((a == width - 1) && (i == height - 1))
            {
                //Bottom Right

                gx = (-1.0 * (image2[i - 1][a - 1].rgbtRed)) + (0 * (image2[i - 1][a].rgbtRed)) + (1.0 * (0)) + (-2.0 *
                        (image2[i][a - 1].rgbtRed)) + (0 * (image2[i][a].rgbtRed)) + (2.0 * (0)) + (-1.0 *
                                (0)) + (0 * (0)) + (1.0 * (0));
                gy = (-1.0 * (image2[i - 1][a - 1].rgbtRed)) + (0 * (image2[i][a - 1].rgbtRed)) + (1.0 * (0)) + (-2.0 *
                        (image2[i - 1][a].rgbtRed)) + (0 *
                                                       (image2[i][a].rgbtRed)) + (2.0 * (0)) + (-1.0 * (0)) + (0 * (0)) + (1.0 * (0));
                newvalue = sqrt((gx * gx) + (gy * gy));
                if (newvalue > 255)
                {
                    newvalue = 255;
                }
                image[i][a].rgbtRed = round(newvalue);
                gx = (-1.0 * (image2[i - 1][a - 1].rgbtBlue)) + (0 * (image2[i - 1][a].rgbtBlue)) + (1.0 * (0)) + (-2.0 *
                        (image2[i][a - 1].rgbtBlue)) + (0 * (image2[i][a].rgbtBlue)) + (2.0 * (0)) + (-1.0 *
                                (0)) + (0 * (0)) + (1.0 * (0));
                gy = (-1.0 * (image2[i - 1][a - 1].rgbtBlue)) + (0 * (image2[i][a - 1].rgbtBlue)) + (1.0 * (0)) + (-2.0 *
                        (image2[i - 1][a].rgbtBlue)) + (0 *
                                                        (image2[i][a].rgbtBlue)) + (2.0 * (0)) + (-1.0 * (0)) + (0 * (0)) + (1.0 * (0));
                newvalue = sqrt((gx * gx) + (gy * gy));
                if (newvalue > 255)
                {
                    newvalue = 255;
                }
                image[i][a].rgbtBlue = round(newvalue);
                gx = (-1.0 * (image2[i - 1][a - 1].rgbtGreen)) + (0 * (image2[i - 1][a].rgbtGreen)) + (1.0 * (0)) + (-2.0 *
                        (image2[i][a - 1].rgbtGreen)) + (0 * (image2[i][a].rgbtGreen)) + (2.0 * (0)) + (-1.0 *
                                (0)) + (0 * (0)) + (1.0 * (0));
                gy = (-1.0 * (image2[i - 1][a - 1].rgbtGreen)) + (0 * (image2[i][a - 1].rgbtGreen)) + (1.0 * (0)) + (-2.0 *
                        (image2[i - 1][a].rgbtGreen)) + (0 *
                                (image2[i][a].rgbtGreen)) + (2.0 * (0)) + (-1.0 * (0)) + (0 * (0)) + (1.0 * (0));
                newvalue = sqrt((gx * gx) + (gy * gy));
                if (newvalue > 255)
                {
                    newvalue = 255;
                }
                image[i][a].rgbtGreen = round(newvalue);
            }
            else if (a == 0 && (1.0 < i < height - 1))
            {
                //Left Edge
                gx = (-1.0 * (0)) + (0 * (image2[i - 1][a].rgbtRed)) + (1.0 * (image2[i - 1][a + 1].rgbtRed)) + (-2.0 * (0)) + (0 *
                        (image2[i][a].rgbtRed)) + (2.0 * (image2[i][a + 1].rgbtRed)) + (-1.0 * (0)) + (0 * (image2[i + 1][a].rgbtRed)) + (1.0 *
                                (image2[i + 1][a + 1].rgbtRed));
                gy = (-1.0 * (0)) + (0 * (0)) + (1.0 * (0)) + (-2.0 * (image2[i - 1][a].rgbtRed)) + (0 * (image2[i][a].rgbtRed)) + (2.0 *
                        (image2[i + 1][a].rgbtRed)) + (-1.0 * (image2[i - 1][a + 1].rgbtRed)) + (0 * (image2[i][a + 1].rgbtRed)) + (1.0 *
                                (image2[i + 1][a + 1].rgbtRed));
                newvalue = sqrt((gx * gx) + (gy * gy));
                if (newvalue > 255)
                {
                    newvalue = 255;
                }
                image[i][a].rgbtRed = round(newvalue);
                gx = (-1.0 * (0)) + (0 * (image2[i - 1][a].rgbtBlue)) + (1.0 * (image2[i - 1][a + 1].rgbtBlue)) + (-2.0 * (0)) + (0 *
                        (image2[i][a].rgbtBlue)) + (2.0 * (image2[i][a + 1].rgbtBlue)) + (-1.0 * (0)) + (0 * (image2[i + 1][a].rgbtBlue)) + (1.0 *
                                (image2[i + 1][a + 1].rgbtBlue));
                gy = (-1.0 * (0)) + (0 * (0)) + (1.0 * (0)) + (-2.0 * (image2[i - 1][a].rgbtBlue)) + (0 * (image2[i][a].rgbtBlue)) + (2.0 *
                        (image2[i + 1][a].rgbtBlue)) + (-1.0 * (image2[i - 1][a + 1].rgbtBlue)) + (0 * (image2[i][a + 1].rgbtBlue)) + (1.0 *
                                (image2[i + 1][a + 1].rgbtBlue));
                newvalue = sqrt((gx * gx) + (gy * gy));
                if (newvalue > 255)
                {
                    newvalue = 255;
                }
                image[i][a].rgbtBlue = round(newvalue);
                gx = (-1.0 * (0)) + (0 * (image2[i - 1][a].rgbtGreen)) + (1.0 * (image2[i - 1][a + 1].rgbtGreen)) + (-2.0 * (0)) + (0 *
                        (image2[i][a].rgbtGreen)) + (2.0 * (image2[i][a + 1].rgbtGreen)) + (-1.0 * (0)) + (0 * (image2[i + 1][a].rgbtGreen)) + (1.0 *
                                (image2[i + 1][a + 1].rgbtGreen));
                gy = (-1.0 * (0)) + (0 * (0)) + (1.0 * (0)) + (-2.0 * (image2[i - 1][a].rgbtGreen)) + (0 * (image2[i][a].rgbtGreen)) + (2.0 *
                        (image2[i + 1][a].rgbtGreen)) + (-1.0 * (image2[i - 1][a + 1].rgbtGreen)) + (0 * (image2[i][a + 1].rgbtGreen)) + (1.0 *
                                (image2[i + 1][a + 1].rgbtGreen));
                newvalue = sqrt((gx * gx) + (gy * gy));
                if (newvalue > 255)
                {
                    newvalue = 255;
                }
                image[i][a].rgbtGreen = round(newvalue);
            }
            else if ((a == width - 1) && (1.0 < i < height - 1))
            {
                //Right Edge
                gx = (-1.0 * (image2[i - 1][a - 1].rgbtRed)) + (0 * (image2[i - 1][a].rgbtRed)) + (1.0 * (0)) + (-2.0 *
                        (image2[i][a - 1].rgbtRed)) +
                     (0 * (image2[i][a].rgbtRed)) + (2.0 * (0)) + (-1.0 * (image2[i + 1][a - 1].rgbtRed)) + (0 * (image2[i + 1][a].rgbtRed)) + (1.0 *
                             (0));
                gy = (-1.0 * (image2[i - 1][a - 1].rgbtRed)) + (0 * (image2[i][a - 1].rgbtRed)) + (1.0 * (image2[i + 1][a - 1].rgbtRed)) + (-2.0 *
                        (image2[i - 1][a].rgbtRed)) + (0 * (image2[i][a].rgbtRed)) + (2.0 * (image2[i + 1][a].rgbtRed)) + (-1.0 * (0)) + (0 * (0)) +
                     (1.0 * (0));
                newvalue = sqrt((gx * gx) + (gy * gy));
                if (newvalue > 255)
                {
                    newvalue = 255;
                }
                image[i][a].rgbtRed = round(newvalue);
                gx = (-1.0 * (image2[i - 1][a - 1].rgbtBlue)) + (0 * (image2[i - 1][a].rgbtBlue)) + (1.0 * (0)) + (-2.0 *
                        (image2[i][a - 1].rgbtBlue)) +
                     (0 * (image2[i][a].rgbtBlue)) + (2.0 * (0)) + (-1.0 * (image2[i + 1][a - 1].rgbtBlue)) + (0 * (image2[i + 1][a].rgbtBlue)) +
                     (1.0 * (0));
                gy = (-1.0 * (image2[i - 1][a - 1].rgbtBlue)) + (0 * (image2[i][a - 1].rgbtBlue)) + (1.0 * (image2[i + 1][a - 1].rgbtBlue)) +
                     (-2.0 *
                      (image2[i - 1][a].rgbtBlue)) + (0 * (image2[i][a].rgbtBlue)) + (2.0 * (image2[i + 1][a].rgbtBlue)) + (-1.0 * (0)) + (0 * (0)) +
                     (1.0 *
                      (0));
                newvalue = sqrt((gx * gx) + (gy * gy));
                if (newvalue > 255)
                {
                    newvalue = 255;
                }
                image[i][a].rgbtBlue = round(newvalue);
                gx = (-1.0 * (image2[i - 1][a - 1].rgbtGreen)) + (0 * (image2[i - 1][a].rgbtGreen)) + (1.0 * (0)) + (-2.0 *
                        (image2[i][a - 1].rgbtGreen)) + (0 * (image2[i][a].rgbtGreen)) + (2.0 * (0)) + (-1.0 * (image2[i + 1][a - 1].rgbtGreen)) + (0 *
                                (image2[i + 1][a].rgbtGreen)) + (1.0 * (0));
                gy = (-1.0 * (image2[i - 1][a - 1].rgbtGreen)) + (0 * (image2[i][a - 1].rgbtGreen)) + (1.0 * (image2[i + 1][a - 1].rgbtGreen)) +
                     (-2.0 *
                      (image2[i - 1][a].rgbtGreen)) + (0 * (image2[i][a].rgbtGreen)) + (2.0 * (image2[i + 1][a].rgbtGreen)) + (-1.0 * (0)) + (0 * (0)) +
                     (1.0 * (0));
                newvalue = sqrt((gx * gx) + (gy * gy));
                if (newvalue > 255)
                {
                    newvalue = 255;
                }
                image[i][a].rgbtGreen = round(newvalue);
            }
            else if ((i == height - 1) && (1.0 < a < width - 1))
            {
                //Bottom Edge
                gx = (-1.0 * (image2[i - 1][a - 1].rgbtRed)) + (0 * (image2[i - 1][a].rgbtRed)) + (1.0 * (image2[i - 1][a + 1].rgbtRed)) + (-2.0 *
                        (image2[i][a - 1].rgbtRed)) + (0 * (image2[i][a].rgbtRed)) + (2.0 * (image2[i][a + 1].rgbtRed)) + (-1.0 * (0)) + (0 * (0)) +
                     (1.0 * (0));
                gy = (-1.0 * (image2[i - 1][a - 1].rgbtRed)) + (0 * (image2[i][a - 1].rgbtRed)) + (1.0 * (0)) + (-2.0 *
                        (image2[i - 1][a].rgbtRed)) +
                     (0 * (image2[i][a].rgbtRed)) + (2.0 * (0)) + (-1.0 * (image2[i - 1][a + 1].rgbtRed)) + (0 * (image2[i][a + 1].rgbtRed)) + (1.0 *
                             (0));
                newvalue = sqrt((gx * gx) + (gy * gy));
                if (newvalue > 255)
                {
                    newvalue = 255;
                }
                image[i][a].rgbtRed = round(newvalue);
                gx = (-1.0 * (image2[i - 1][a - 1].rgbtBlue)) + (0 * (image2[i - 1][a].rgbtBlue)) + (1.0 * (image2[i - 1][a + 1].rgbtBlue)) +
                     (-2.0 *
                      (image2[i][a - 1].rgbtBlue)) + (0 * (image2[i][a].rgbtBlue)) + (2.0 * (image2[i][a + 1].rgbtBlue)) + (-1.0 * (0)) + (0 * (0)) +
                     (1.0 *
                      (0));
                gy = (-1.0 * (image2[i - 1][a - 1].rgbtBlue)) + (0 * (image2[i][a - 1].rgbtBlue)) + (1.0 * (0)) + (-2.0 *
                        (image2[i - 1][a].rgbtBlue)) +
                     (0 * (image2[i][a].rgbtBlue)) + (2.0 * (0)) + (-1.0 * (image2[i - 1][a + 1].rgbtBlue)) + (0 * (image2[i][a + 1].rgbtBlue)) +
                     (1.0 * (0));
                newvalue = sqrt((gx * gx) + (gy * gy));
                if (newvalue > 255)
                {
                    newvalue = 255;
                }
                image[i][a].rgbtBlue = round(newvalue);
                gx = (-1.0 * (image2[i - 1][a - 1].rgbtGreen)) + (0 * (image2[i - 1][a].rgbtGreen)) + (1.0 * (image2[i - 1][a + 1].rgbtGreen)) +
                     (-2.0 *
                      (image2[i][a - 1].rgbtGreen)) + (0 * (image2[i][a].rgbtGreen)) + (2.0 * (image2[i][a + 1].rgbtGreen)) + (-1.0 * (0)) + (0 * (0)) +
                     (1.0 * (0));
                gy = (-1.0 * (image2[i - 1][a - 1].rgbtGreen)) + (0 * (image2[i][a - 1].rgbtGreen)) + (1.0 * (0)) + (-2.0 *
                        (image2[i - 1][a].rgbtGreen)) + (0 * (image2[i][a].rgbtGreen)) + (2.0 * (0)) + (-1.0 * (image2[i - 1][a + 1].rgbtGreen)) + (0 *
                                (image2[i][a + 1].rgbtGreen)) + (1.0 * (0));
                newvalue = sqrt((gx * gx) + (gy * gy));
                if (newvalue > 255)
                {
                    newvalue = 255;
                }
                image[i][a].rgbtGreen = round(newvalue);
            }
            else if ((i == 0) && (1.0 < a < width - 1))
            {
                //Top Edge
                gx = (-1.0 * (0)) + (0 * (0)) + (1.0 * (0)) + (-2.0 * (image2[i][a - 1].rgbtRed)) + (0 * (image2[i][a].rgbtRed)) + (2.0 *
                        (image2[i][a + 1].rgbtRed)) + (-1.0 * (image2[i + 1][a - 1].rgbtRed)) + (0 * (image2[i + 1][a].rgbtRed)) + (1.0 *
                                (image2[i + 1][a + 1].rgbtRed));
                gy = (-1.0 * (0)) + (0 * (image2[i][a - 1].rgbtRed)) + (1.0 * (image2[i + 1][a - 1].rgbtRed)) + (-2.0 * (0)) + (0 *
                        (image2[i][a].rgbtRed)) + (2.0 * (image2[i + 1][a].rgbtRed)) + (-1.0 * (0)) + (0 * (image2[i][a + 1].rgbtRed)) + (1.0 *
                                (image2[i + 1][a + 1].rgbtRed));
                newvalue = sqrt((gx * gx) + (gy * gy));
                if (newvalue > 255)
                {
                    newvalue = 255;
                }
                image[i][a].rgbtRed = round(newvalue);
                gx = (-1.0 * (0)) + (0 * (0)) + (1.0 * (0)) + (-2.0 * (image2[i][a - 1].rgbtBlue)) + (0 * (image2[i][a].rgbtBlue)) + (2.0 *
                        (image2[i][a + 1].rgbtBlue)) + (-1.0 * (image2[i + 1][a - 1].rgbtBlue)) + (0 * (image2[i + 1][a].rgbtBlue)) + (1.0 *
                                (image2[i + 1][a + 1].rgbtBlue));
                gy = (-1.0 * (0)) + (0 * (image2[i][a - 1].rgbtBlue)) + (1.0 * (image2[i + 1][a - 1].rgbtBlue)) + (-2.0 * (0)) + (0 *
                        (image2[i][a].rgbtBlue)) + (2.0 * (image2[i + 1][a].rgbtBlue)) + (-1.0 * (0)) + (0 * (image2[i][a + 1].rgbtBlue)) + (1.0 *
                                (image2[i + 1][a + 1].rgbtBlue));
                newvalue = sqrt((gx * gx) + (gy * gy));
                if (newvalue > 255)
                {
                    newvalue = 255;
                }
                image[i][a].rgbtBlue = round(newvalue);
                gx = (-1.0 * (0)) + (0 * (0)) + (1.0 * (0)) + (-2.0 * (image2[i][a - 1].rgbtGreen)) + (0 * (image2[i][a].rgbtGreen)) + (2.0 *
                        (image2[i][a + 1].rgbtGreen)) + (-1.0 * (image2[i + 1][a - 1].rgbtGreen)) + (0 * (image2[i + 1][a].rgbtGreen)) + (1.0 *
                                (image2[i + 1][a + 1].rgbtGreen));
                gy = (-1.0 * (0)) + (0 * (image2[i][a - 1].rgbtGreen)) + (1.0 * (image2[i + 1][a - 1].rgbtGreen)) + (-2.0 * (0)) + (0 *
                        (image2[i][a].rgbtGreen)) + (2.0 * (image2[i + 1][a].rgbtGreen)) + (-1.0 * (0)) + (0 * (image2[i][a + 1].rgbtGreen)) + (1.0 *
                                (image2[i + 1][a + 1].rgbtGreen));
                newvalue = sqrt((gx * gx) + (gy * gy));
                if (newvalue > 255)
                {
                    newvalue = 255;
                }
                image[i][a].rgbtGreen = round(newvalue);
            }
            else
            {
                //Everything Else
                gx = (0 * (image2[i][a].rgbtRed) + -2 * (image2[i][a - 1].rgbtRed) + 2 * (image2[i][a + 1].rgbtRed) + 0 *
                      (image2[i - 1][a].rgbtRed) + 1 * (image2[i - 1][a + 1].rgbtRed) + -1 * (image2[i - 1][a - 1].rgbtRed) + -1 *
                      (image2[i + 1][a - 1].rgbtRed) + 0 * (image2[i + 1][a].rgbtRed) + 1 * (image2[i + 1][a + 1].rgbtRed));
                gy = (0 * (image2[i][a].rgbtRed) + 0 * (image2[i][a - 1].rgbtRed) + 0 * (image2[i][a + 1].rgbtRed) + -2 *
                      (image2[i - 1][a].rgbtRed) + -1 * (image2[i - 1][a + 1].rgbtRed) + -1 * (image2[i - 1][a - 1].rgbtRed) + 1 *
                      (image2[i + 1][a - 1].rgbtRed) + 2 * (image2[i + 1][a].rgbtRed) + 1 * (image2[i + 1][a + 1].rgbtRed));
                newvalue = sqrt((gx * gx) + (gy * gy));
                if (newvalue <= 255)
                {
                    image[i][a].rgbtRed = round(newvalue);
                }
                else
                {
                    image[i][a].rgbtRed = 255;
                }

                gx = (0 * (image2[i][a].rgbtGreen) + -2 * (image2[i][a - 1].rgbtGreen) + 2 * (image2[i][a + 1].rgbtGreen) + 0 *
                      (image2[i - 1][a].rgbtGreen) + 1 * (image2[i - 1][a + 1].rgbtGreen) + -1 * (image2[i - 1][a - 1].rgbtGreen) + -1 *
                      (image2[i + 1][a - 1].rgbtGreen) + 0 * (image2[i + 1][a].rgbtGreen) + 1 * (image2[i + 1][a + 1].rgbtGreen));
                gy = (0 * (image2[i][a].rgbtGreen) + 0 * (image2[i][a - 1].rgbtGreen) + 0 * (image2[i][a + 1].rgbtGreen) + -2 *
                      (image2[i - 1][a].rgbtGreen) + -1 * (image2[i - 1][a + 1].rgbtGreen) + -1 * (image2[i - 1][a - 1].rgbtGreen) + 1 *
                      (image2[i + 1][a - 1].rgbtGreen) + 2 * (image2[i + 1][a].rgbtGreen) + 1 * (image2[i + 1][a + 1].rgbtGreen));
                newvalue = sqrt((gx * gx) + (gy * gy));

                if (newvalue <= 255)
                {
                    image[i][a].rgbtGreen = round(newvalue);
                }
                else
                {
                    image[i][a].rgbtGreen = 255;
                }

                gx = (0 * (image2[i][a].rgbtBlue) + -2 * (image2[i][a - 1].rgbtBlue) + 2 * (image2[i][a + 1].rgbtBlue) + 0 *
                      (image2[i - 1][a].rgbtBlue) + 1 * (image2[i - 1][a + 1].rgbtBlue) + -1 * (image2[i - 1][a - 1].rgbtBlue) + -1 *
                      (image2[i + 1][a - 1].rgbtBlue) + 0 * (image2[i + 1][a].rgbtBlue) + 1 * (image2[i + 1][a + 1].rgbtBlue));
                gy = (0 * (image2[i][a].rgbtBlue) + 0 * (image2[i][a - 1].rgbtBlue) + 0 * (image2[i][a + 1].rgbtBlue) + -2 *
                      (image2[i - 1][a].rgbtBlue) + -1 * (image2[i - 1][a + 1].rgbtBlue) + -1 * (image2[i - 1][a - 1].rgbtBlue) + 1 *
                      (image2[i + 1][a - 1].rgbtBlue) + 2 * (image2[i + 1][a].rgbtBlue) + 1 * (image2[i + 1][a + 1].rgbtBlue));
                newvalue = sqrt((gx * gx) + (gy * gy));

                if (newvalue <= 255)
                {
                    image[i][a].rgbtBlue = round(newvalue);
                }
                else
                {
                    image[i][a].rgbtBlue = 255;
                }
            }
        }
    }


    return;
}
