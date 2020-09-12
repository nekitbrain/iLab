#include <stdio.h>
#include <math.h>


//-----------------------------------------------------------------------------

const int infinityroots = -1;

int  quadraticsolver(double a, double b, double c, double* x1, double* x2);
void quadraticsolver_test();

//-----------------------------------------------------------------------------

int main()
    {
    quadraticsolver_test();

    double a, b, c;

    printf ("\nThis is QuadraticKiller - solves quadratic equation. (c) kisnikser\n\n"
            "Given the equation ax^2+bx+c=0. Enter a: ");
    scanf  ("%lf", &a);
    printf ("                                Enter b: ");
    scanf  ("%lf", &b);
    printf ("                                Enter c: ");
    scanf  ("%lf", &c);
    printf ("\nYour equation: %lfx^2+%lfx+%lf=0\n\n", a, b, c);

    double x1, x2;

    int nRoots = quadraticsolver(a, b, c, &x1, &x2);

    switch(nRoots)
        {
        case 0:  printf ("No roots.\n");
                 break;

        case 1:  printf ("x = %lf\n", x1);
                 break;

        case 2:  printf ("x1 = %lf\nx2 = %lf\n", x1, x2);
                 break;

        case infinityroots: printf("Any number.\n");
                 break;

        default: printf ("main(): ERROR: nRoots = %d\n", nRoots);
                 break;
        }

    return 0;
    }

//-----------------------------------------------------------------------------

int quadraticsolver(double a, double b, double c, double* x1, double* x2)
    {
    if (a == 0)
        {
        if (b == 0)
            {
            if (c == 0) return infinityroots;

            else        return 0;
            }
        else
            {
            *x1 = -c/b;

                        return 1;
            }
        }
    else
        {
        double D = b*b - 4*a*c;
        if      (D > 0)
            {
            *x1 = (-b-sqrt(D))/(2*a);
            *x2 = (-b+sqrt(D))/(2*a);

                        return 2;
            }
        else if (D == 0)
            {
            *x1 =  -b/(2*a);

                        return 1;
            }
        else            return 0;
        }
    }

//-----------------------------------------------------------------------------

void quadraticsolver_test()
    {
    printf ("\nquadraticsolver_test():\n\n");

    double a, b, c;
    double x1 = 0;
    double x2 = 0;
    int    n  = 0;

    n = quadraticsolver( 0, 0, 0, &x1, &x2);

    if (n == infinityroots)            printf ("Test on %d ok\n", __LINE__);
    else                               printf ("Test on %d BAD: quadraticsolver (0, 0, 1): n = infinityroots expected, but n = %d\n", __LINE__, n);

    n = quadraticsolver( 0, 0, 1, &x1, &x2);

    if (n == 0)                        printf ("Test on %d ok\n", __LINE__);
    else                               printf ("Test on %d BAD: quadraticsolver (0, 0, 1): n = 0 expected, but n = %d\n", __LINE__, n);

    n = quadraticsolver( 0, 1, 1, &x1, &x2);

    if (n == 1 && x1 == -1)            printf ("Test on %d ok\n", __LINE__);
    else                               printf ("Test on %d BAD: quadraticsolver (0, 1, 1): n = 1, x = -1 expected, but n = %d, x = %lf\n", __LINE__, n, x1);

    n = quadraticsolver( 1, 1, 1, &x1, &x2);

    if (n == 0)                        printf ("Test on %d ok\n", __LINE__);
    else                               printf ("Test on %d BAD: quadraticsolver (1, 1, 1): n = 0 expected, but n = %d\n", __LINE__, n);

    n = quadraticsolver(1, -4, 4, &x1, &x2);

    if (n == 1 && x1 == 2)             printf ("Test on %d ok\n", __LINE__);
    else                               printf ("Test on %d BAD: quadraticsolver (1, -4, 4): n = 1, x = 2 expected, but n = %d, x = %lf\n", __LINE__, n, x1);

    n = quadraticsolver(1, -5, 6, &x1, &x2);

    if (n == 2 && x1 == 2 && x2 == 3)  printf ("Test on %d ok\n", __LINE__);
    else                               printf ("Test on %d BAD: quadraticsolver (1, -5, 6): n = 2, x1 == 2, x2 == 3 expected, but n = %d, x1 = %lf, x2 = %lf\n", __LINE__, n, x1, x2);
    }

//-----------------------------------------------------------------------------
