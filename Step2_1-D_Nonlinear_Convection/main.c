#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nx = 41;
    float dx = 0.05;
    int nt = 20;
    float dt = 0.025;

    float u[41];
    for(int i = 0; i < 41; i++)
    {
        if( i >= 10 && i <=20)
        {
            u[i] = 2.0;
        }
        else{
            u[i] = 1.0;
        }
    }

    float un[41];
    for(int i = 0; i < 41; i++)
    {
        un[i] = 1.0;
    }

    for(int i = 0; i < nt; i++)
    {
        for(int j = 0; j < 41; j++)
        {
            un[j] = u[j];
        }
        for(int k = 1; k < nx; k++)
        {
            u[k] = un[k] - un[k] * (dt/dx) * (un[k] - un[k-1]);
        }
    }

    for(int i = 0; i < 41; i++)
    printf("%f\n",u[i]);

    return 0;
}
