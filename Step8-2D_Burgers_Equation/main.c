#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nx = 41, ny = 41, nt = 120, c = 1;
    float dx = 2 / (nx - 1);
    float dy = 2 / (ny - 1);
    float sigma = 0.0009;
    float nu = 0.01;
    float dt = sigma * dx * dy / nu;

    float u[ny][nx], un[ny][nx], v[ny][nx], vn[ny][nx];

    for(int j = 0; j < ny; j++)
    {
        for(int i = 0; i < nx; i++)
        {
            if( (j >= 10 && j <= 20) && ( i >= 10 && i <= 20))
            {
                u[j][i] = 2.0;
                v[j][i] = 2.0;
            }
            else
            {
                u[j][i] = 1.0;
                v[j][i] = 1.0;
            }
        }
    }

    for(int t = 0; t <= nt; t++)
    {
        for(int j = 0; j < ny; j++)
        {
            for(int i = 0; i < nx; i++)
            {
            un[j][i] = u[j][i];
            vn[j][i] = v[j][i];
            }
        }

        for(int j = 1; j < ny - 1; j++)
        {
            for(int i = 1; i < nx -1; i++)
            {
                u[j][i] = un[j][i] - (0.0045) * un[j][i] * (un[j][i] - un[j][i-1]) - (0.0045) * vn[j][i] * (un[j][i] - un[j-1][i]) +
                            (0.0009) * (un[j][i+1] - 2 * un[j][i] + un[j][i-1]) + (0.0009) * (un[j+1][i] - 2 * un[j][i] + un[j+1][i]);

                v[j][i] = vn[j][i] - (0.0045) * un[j][i] * (vn[j][i] - vn[j][i-1]) - (0.0045) * vn[j][i] * (vn[j][i] - vn[j-1][i]) +
                            (0.0009) * (vn[j][i+1] - 2 * vn[j][i] + vn[j][i-1]) + (0.0009) * (vn[j+1][i] - 2 * vn[j][i] + vn[j+1][i]);

                u[0][i] = 1.0;
                u[40][i] = 1.0;
                u[j][0] = 1.0;
                u[j][40] = 1.0;

                v[0][i] = 1.0;
                v[40][i] = 1.0;
                v[j][0] = 1.0;
                v[j][40] = 1.0;
            }
        }
    }

    printf("%f",u[10][14]);
    return 0;
}
