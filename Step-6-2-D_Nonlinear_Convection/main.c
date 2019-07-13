#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nx = 101, ny = 101, nt = 80, c = 1;
    float dx = 2 / (nx -1);
    float dy = 2 / (ny - 1);
    float sigma = 0.2;
    float dt = sigma * dx;

    float u[ny][nx], v[ny][nx], un[ny][nx], vn[ny][nx];

    for(int j = 0; j < ny; j++)
    {
        for(int i = 0; i < nx; i++)
        {
            if((j >= 25 && j <= 50) && (i >= 25 && i <= 50))
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
        for(int z = 0; z < ny; z++)
        {
            for(int y = 0; y < nx; y++)
            {
                un[z][y] = u[z][y];
                vn[z][y] = v[z][y];
            }
        }

        for(int j = 1; j < ny; j++)
        {
            for(int i = 1; i < nx; i++)
            {
                u[j][i] = (un[j][i] - (un[j][i] * (0.2) * (un[j][i] - un[j][i-1])) - (vn[j][i] * (0.2) * (un[j][i] - un[j-1][i])));
                v[j][i] = (vn[j][i] - (un[j][i] * (0.2) * (vn[j][i] - vn[j][i-1])) - (vn[j][i] * (0.2) * (vn[j][i] - vn[j-1][i])));

                u[0][i] = 1.0;
                u[100][i] = 1.0;
                u[j][0] = 1.0;
                u[j][100] = 1.0;

                v[0][i] = 1.0;
                v[100][i] = 1.0;
                v[j][0] = 1.0;
                v[j][100] = 1.0;


            }
        }
    }



    printf("%f",u[73][58]);
    return 0;
}
