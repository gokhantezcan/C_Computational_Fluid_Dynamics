#include <stdio.h>
#include <stdlib.h>
#include <math.h>
# define M_PI           3.14159265358979323846  /* pi */
double x[101];
double u[101];

double phi (double xp, double nup, double tp)
{
    return exp(-(pow(xp - 4 * tp,2)) / (4 * nup * (tp + 1))) + exp(-(pow(xp - 4 * tp - 2 * M_PI,2)) / (4 * nup * (tp + 1)));
}


double phiprime (double xpp, double nupp, double tpp)
{
    return (-(exp(-((pow(-4* tpp + xpp,2)) / (4 * nupp * (tpp + 1)))) / (4 * nupp * (tpp + 1))) * (-8 * tpp + 2 * xpp))  -
            (1 / (4 * nupp * (tpp + 1))) * (-8 * tpp + 2 * xpp - 4 * M_PI) * (exp(-(pow(-4 * tpp + xpp - 2 * M_PI,2)) / (4 * nupp * (tpp + 1))));
}

double u_func(double tu, double xu, double nuu)
{
    return -2 * nuu * (phiprime(xu, nuu, tu) / phi(xu, nuu, tu)) + 4;
}

void x_coordinates()
{
    x[0] = 0.0;
    for(int i = 1; i <= 100; i++)
    {
        x[i] = x[i - 1] + (2 * M_PI) / 100;
    }
}

void u_initialize()
{
    for(int i = 0; i < 101; i++)
    {
        u[i] = u_func(0, x[i], 0.07);
    }
}

int main()
{

    int nx = 101;
    int nt = 100;
    double dx = 2 * M_PI / (nx - 1);
    double nu = .07;
    double dt = dx * nu;

    x_coordinates();

    u_initialize();

    double un[101];

    for(int i = 0; i < nt; i++)
    {
        for(int i = 0; i < 101; i++)
        {
            un[i] = u[i];
        }

        for(int j = 1; j < nx - 1; j++)
        {
            u[j] = un[j] - un[j] * dt / dx * (un[j] - un[j - 1]) + nu * dt / pow(dx,2) *
               (un[j + 1] - 2.0 * un[j] + un[j - 1]);
        }

        u[0] = un[0] - un[0] * dt / dx * (un[0] - un[99]) + nu * dt / pow(dx,2) *
            (un[1] - 2 * un[0] + un[99]);
        u[100] = u[0];
    }


    for(int i = 0; i < 101; i++)
    {
        printf("%f ", u[i]);
    }
    return 0;
}
