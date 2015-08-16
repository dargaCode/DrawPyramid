#include <stdio.h>
#include <cs50.h>

// prototypes
int GetHeight();
void DrawPyramid();

int main(void)
{
    int height = GetHeight(0, 23);
    // printf("HEIGHT! %i\n", height);
    DrawPyramid(height);   
}   

/*
 * Return validated user input for pyramid height. 
 */
int GetHeight(int minHeight, int maxHeight)
{
    int height;
    do
    {
        printf("Please enter pyramid height (%i - %i): ",
            minHeight,
            maxHeight);
        height = GetInt();
    }
    while (height < minHeight || height > maxHeight);
    return height;
}

/*
 * Draw the pyramid.
 */
void DrawPyramid(int height)
{
    int width = height * 2 - 1;
    int center = height - 1;
    // draw row
    for (int i = 0; i < height; i++)
    {
        int draw_dist = i;
        // draw columns
        for (int j = 0; j < width; j++)
        {
            int dist = abs(center - j);
            if (dist <= draw_dist)
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
                    }
        // next row
        printf("\n");
    }
}
