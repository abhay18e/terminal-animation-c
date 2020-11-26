#include "stdio.h"
#include <stdlib.h> // for  system("cls") to clear screen
#define HEIGHT 30
#define WIDTH 140

char outline_symbol = 'o';
int canvas[HEIGHT][WIDTH];
int clear_canvas(int cnv[HEIGHT][WIDTH]);
int paint_canvas(int cnv[HEIGHT][WIDTH]);
int create_line(int x1, int y1, int x2, int y2, int cnv[HEIGHT][WIDTH]);
int create_rectangle(int top_left_x, int top_left_y, int height, int width, int cnv[HEIGHT][WIDTH], int fill);
int translate_x(int cnv[HEIGHT][WIDTH]);
int translate_y(int cnv[HEIGHT][WIDTH]);

int main()
{

    clear_canvas(canvas);

    create_rectangle(0, 0, 5, 5, canvas, 0);
    create_rectangle(5, 5, 5, 5, canvas, 1);
    create_rectangle(0, 10, 5, 5, canvas, 0);
    create_rectangle(5, 15, 5, 5, canvas, 1);

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

int translate_y(int cnv[HEIGHT][WIDTH])
{
    for (int col = 0; col < WIDTH; col++)
    {
        for (int row = HEIGHT - 1; row > 0; row--)
        {
            cnv[row][col] = cnv[row - 1][col];
            cnv[row - 1][col] = 0;
        }
    }
    return 0;
}

int create_rectangle(int top_left_x, int top_left_y, int height, int width, int cnv[HEIGHT][WIDTH], int fill)
{
    if (fill)
    {
        for (int y = top_left_y; y < top_left_y + height; y++)
        {
            create_line(top_left_x, y, top_left_x + width, y, cnv); // top side of rectangle
        }
    }
    else
    {
        create_line(top_left_x, top_left_y, top_left_x, top_left_y + height, cnv);                  // left side of rectangle
        create_line(top_left_x + width, top_left_y, top_left_x + width, top_left_y + height, cnv);  // right side of rectangle
        create_line(top_left_x, top_left_y, top_left_x + width, top_left_y, cnv);                   // top side of rectangle
        create_line(top_left_x, top_left_y + height, top_left_x + width, top_left_y + height, cnv); // bottom side of rectangle
    }

    return 0;
}