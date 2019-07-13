#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nx = 81;
    int ny = 81;
    int nt = 100;
    float c = 1.0;
    float dx = 2 / (nx - 1);
    float dy = 2 / (ny - 1);
    float sigma = .2;
    float dt = sigma * dx;

    float u[ny][nx];
    float un[ny][nx];

    for(int j = 0; j < ny; j++)
    {
        for(int i = 0; i < nx; i++)
        {
            if((j >=20 && j <= 40) && (i >= 20 && i <= 40))
            {
                u[j][i] = 2.0;
            }
            else
            {
                u[j][i] = 1.0;
            }
        }
    }

    for(int t = 0; t <= nt; t++)
    {
        for(int y = 0; y < ny; y++)
        {
            for(int z = 0; z < nx; z++)
            {
                un[y][z] = u[y][z];
            }
        }

        for(int j = 1; j < ny; j++)
        {
            for(int i = 1; i < nx; i++)
            {
                u[j][i] = (un[j][i] - ((0.2) * (un[j][i] - un[j][i-1]))  -  ((0.2) * (un[j][i] - un[j-1][i])));

                u[0][i] = 1.0;
                u[80][i] = 1.0;
                u[j][0] = 1.0;
                u[j][80] = 1.0;
            }
        }

    }

    return 0;
}
