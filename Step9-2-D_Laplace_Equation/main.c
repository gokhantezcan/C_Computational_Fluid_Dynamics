#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nx = 31, ny = 31, c = 1;
    float dx = 2 / (nx - 1);
    float dy = 2 / (ny - 1);

    float p[ny][nx];
    for(int j=0; j < ny; j++)
    {
        for(int i = 0; i < nx; i++)
        {
            p[j][i] = 0.0;
        }
    }

    float y[ny];
    y[0] = 0.0;
    for(int j = 1; j < ny ; j++)
    {
        y[j] = y[j-1] + 0.0333;
    }

    for(int j = 0; j < ny; j++)
    {
        p[j][0] = 0.0;
    }

    for(int j = 0; j < ny; j++)
    {
        p[j][30] = y[j];
    }

    for(int i = 0; i < nx; i++)
    {
        p[0][i] = p[1][i];
    }

    for(int i = 0; i < nx; i++)
    {
        p[30][i] = p[29][i];
    }

    float pn[ny][nx];
    for(int j=0; j < ny; j++)
    {
        for(int i = 0; i < nx; i++)
        {
            pn[j][i] = 0.0;
        }
    }

    int counter = 0;
    while(counter < 100000)
    {
        for(int j = 0; j < ny; j++)
        {
            for(int i = 0; i < nx; i++)
            {
                pn[j][i] = p[j][i];
            }
        }

        // denklem cozduruluyor.
        for(int j = 1; j <= ny-1; j++)
        {
            for(int i = 1; i <= nx-1; i++)
            {
                p[j][i] = (((0.0044) * (pn[j][i+1] + pn[j][i-1])) + ((0.0044) * (pn[j+1][i] + pn[j-1][i]))) / (0.0176);
            }
        }

        // sinir sartlari uygulaniyor.
        for(int j = 0; j < ny; j++)
    {
        p[j][0] = 0.0;
    }

    for(int j = 0; j < ny; j++)
    {
        p[j][30] = y[j];
    }

    for(int i = 0; i < nx; i++)
    {
        p[0][i] = p[1][i];
    }

    for(int i = 0; i < nx; i++)
    {
        p[30][i] = p[29][i];
    }

        counter++;
    }


    printf("%f", p[23][29]);
    return 0;
}
