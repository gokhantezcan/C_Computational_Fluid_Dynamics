#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nx = 31, ny = 31, nt = 17;
    float dx = 2 / (nx - 1);
    float dy = 2 / (ny - 1);
    float nu = .05;
    float sigma = .25;
    float dt = sigma * dx * dy /nu;

    float u[ny][nx];
    float un[ny][nx];

    for(int j = 0; j < ny; j++)
    {
        for(int i = 0; i < nx; i++)
        {
            if((j >= 7 && j <= 15) && (i >= 7 && i <= 15))
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
        for(int z = 0; z < ny; z++)
        {
            for(int y = 0; y < nx; y++)
            {
                un[z][y] = u[z][y];
            }
        }

        for(int j = 1; j < ny - 1; j++)
        {
            for(int i = 1; i < nx - 1; i++)
            {
               u[j][i] = un[j][i] + (0.244) * (un[j][i+1] - 2 * un[j][i] + un[j][i-1]) + (0.244) * (un[j+1][i] - 2 * un[j][i] + un[j-1][i]);

                u[0][i] = 1.0;
                u[30][i] = 1.0;
                u[j][0] = 1.0;
                u[j][30] = 1.0;

            }
        }

    }


    return 0;
}
