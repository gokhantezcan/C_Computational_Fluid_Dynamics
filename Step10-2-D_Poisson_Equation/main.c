#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nx = 50, ny = 50, nt = 100;
    int xmin = 0, xmax = 2, ymin = 0, ymax = 1;

    float dx = 0.0408;
    float dy = 0.0204;

    float p[ny][nx], pd[ny][nx], b[ny][nx];

    for(int j = 0; j < ny; j++)
    {
        for(int i = 0; i < nx; i++)
        {
            p[j][i] = 0.0;
            pd[j][i] = 0.0;
            b[j][i] = 0.0;
        }
    }

    b[12][12] = 100.0;
    b[37][37] = -100.0;

    for(int t = 0; t < nt; t++)
    {
        for(int j = 0; j < ny; j++)
        {
            for(int i = 0; i < nx; i++)
            {
                pd[j][i] = p[j][i];
            }
        }

        for(int j = 1; j <= ny-1; j++)
        {
            for(int i = 1; i <= nx-1; i++)
            {
                p[j][i] = (((pd[j][i+1] + pd[j][i-1]) * (0.00041)) + ((pd[j+1][i] + pd[j-1][i]) * (0.0016)) - ((b[j][i]) * (0.000000656))) / (0.00402);
            }
        }

        for(int i  = 0; i < nx; i++)
        {
            p[0][i] = 0.0;
        }
        for(int i = 0; i < nx; i++)
        {
            p[49][i] = 0.0;
        }
        for(int j = 0; j < ny; j++)
        {
            p[j][0] = 0.0;
        }
        for(int j = 0; j < ny; j++)
        {
            p[j][49] = 0.0;
        }
    }

    return 0;
}
