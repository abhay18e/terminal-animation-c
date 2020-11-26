#include "stdio.h"
#include <stdlib.h> // for  system("cls") to clear screen
#define HEIGHT 30
#define WIDTH 140

char outline_symbol = '*';
int canvas[HEIGHT][WIDTH];
int clear_canvas(int cnv[HEIGHT][WIDTH]);
int paint_canvas(int cnv[HEIGHT][WIDTH]);
int create_line(int x1, int y1, int x2, int y2, int cnv[HEIGHT][WIDTH]);
int translate_x(int cnv[HEIGHT][WIDTH]);

int main()
{

    clear_canvas(canvas);
    create_line(0, 10, 0, 20, canvas);   // left side of rectangle
    create_line(10, 10, 10, 20, canvas); // right side of rectangle
    create_line(0, 10, 10, 10, canvas);  // top side of rectangle
    create_line(0, 20, 11, 20, canvas);  // bottom side of rectangle

    for (int sq = 0; sq < WIDTH; sq++)
    {
        system("cls");
        paint_canvas(canvas);
        translate_x(canvas);
    }

    return 0;
}

int clear_canvas(int cnv[HEIGHT][WIDTH])
{
    for (int row = 0; row < HEIGHT; row++)
    {
        for (int col = 0; col < WIDTH; col++)
        {
            cnv[row][col] = 0;
        }
    }
    return 0;
}

int paint_canvas(int cnv[HEIGHT][WIDTH])
{

    for (int row = 0; row < HEIGHT; row++)
    {
        for (int col = 0; col < WIDTH; col++)
        {
            if (cnv[row][col] == 0)
                printf(" ");
            else
                printf("%c", outline_symbol);
        }
        printf("\n");
    }
    return 0;
}

int create_line(int x1, int y1, int x2, int y2, int cnv[HEIGHT][WIDTH])
{
    //when y1 and y2 are same means horizontal line
    if (y1 == y2)
    {
        for (int x = x1; x < x2; x++)
        {
            cnv[y1][x] = 1;
        }
    } // when x1 and x2 are same means vertical line
    else if (x1 == x2)
    {
        for (int y = y1; y < y2; y++)
        {
            cnv[y][x1] = 1;
        }
    }

    return 0;
}

int translate_x(int cnv[HEIGHT][WIDTH])
{
    for (int row = 0; row < HEIGHT; row++)
    {
        for (int col = WIDTH - 1; col > 0; col--)
        {
            cnv[row][col] = cnv[row][col - 1]; // [][][a][b][][]   b = a
            cnv[row][col - 1] = 0;             // a = 0
        }
    }
    return 0;
}