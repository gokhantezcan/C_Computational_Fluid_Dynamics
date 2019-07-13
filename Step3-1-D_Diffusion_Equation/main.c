#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nx = 41;
    float dx = 0.05;
    int nt = 20;
    float nu = 0.3;
    float sigma = 0.2;
    double dt = 0.00166;

    float u[nx];
    for(int i = 0; i < nx; i++)
    {
        if(i >=10 && i <= 20)
        {
            u[i] = 2.0;
        }
        else{
            u[i] = 1.0;
        }
    }

    float un[nx];
    for(int i = 0; i < nx; i++)
    {
        un[i] = 1.0;
    }

    for(int i = 0; i < nt; i++)
    {
        for(int j = 0; j < nx; j++)
        {
            un[j] = u[j];
        }

        for(int k = 1; k < nx - 1; k++)
        {
            u[k] = un[k] + nu * dt / (dx * dx) * (un[k+1] - 2 * un[k] + un[k-1]);
        }
    }

    for(int i = 0; i < nx; i++)
    printf("%f\n",u[i]);

    return 0;
}
