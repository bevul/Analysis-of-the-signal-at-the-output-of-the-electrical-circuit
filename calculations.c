#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "calculations.h"

void form_t (int n, double tn, double tk, double* t)//Form time table
{
    int i;
    double dt=(tk-tn)/(n-1);
    for (i=0;i<n;i++)
        t[i]=tn+i*dt;
}

void form_uvx (int n, double*t, double* uvx, data_uvx s)//Form Uvx table
{
    int i;
    for(i=0; i<n; i++)
        if (t[i]<=s.t1)
            uvx[i]=s.a*(t[i]-s.tn);
            else if (t[i]<=s.t2) uvx[i]=s.a*(s.t1-s.tn);
                else
                    uvx[i]=s.a*(s.t1-s.tn)-s.b*(t[i]-s.t2);
}

void form_uvix (int n, double*t, double*uvx, double* uvix, data_uvix f)//Form Uvix table
{
    int i;
    for (i=0; i<n; i++)
        if (uvx[i]<=f.uvx1)
            uvix[i]=0.5+uvx[i]+5;
                else if (f.uvx2<uvx[i]) uvix[i]=13/6*(uvx[i]-10)+10;
                    else uvix[i]=0.25*(uvx[i]-40)+75;


            //uvix[i]=(uvx[i]-f.uvx0)*(f.u1-f.u0)/(f.uvx1 - f.uvx0) + f.u0;
             //else if (uvx[i]<f.uvx2) uvix[i]=(uvx[i]-f.uvx1)*(f.u2-f.u1)/(f.uvx2 - f.uvx1) + f.u1;
                //else uvix[i]=(uvx[i]-f.uvx2)*(f.u3-f.u2)/(f.uvx3 - f.uvx2) + f.u2;
}

/* Calculation of the parameter */

double max_u (int n, double* arr)
{
    double max_arr=arr[0];
    int i;
    for(i=0;i<n;i++)
        if (arr[i]>=max_arr)
            {
                max_arr=arr[i];
            }
    return max_arr;
}
double parameter  (int n, double* arr, double* t)
{
    double max_arr=max_u(n, arr);

    int i;
    int st_t=0, end_t=0;
    for(i=0;i<n;i++)
        if (arr[i]==max_arr)
            {
                st_t=t[i];
                break;
            }
    for(i=n;i>0;i--)
        if (arr[i]==max_arr)
            {
                end_t=t[i];
                break;
            }
    double max_t=0;
    max_t=fabs(end_t-st_t);

    return max_t;
}

/* Calculation of the parameter with uncertainty of measurement */
//Something wrong with calculation. Should be revisited later. (((

/*
void parameter_with_accuracy_uvx (double p, double eps, double par, int n, data_uvx s)
{
    printf("Uvx:\n");
    double par_uvx;
    while (p>eps)
    {
        double ttmp[n];
        double uvxtmp[n];
        form_t(n, s.tn, s.tk, ttmp);
        form_uvx(n, ttmp, uvxtmp,s);
        par_uvx = parameter(n, uvxtmp, ttmp);
        p = fabs(par-par_uvx)/par_uvx;
        printf("n = %d, parameter = %.4lf, accuracy= %.4lf\n", n, par_uvx, p);
        par=par_uvx;
        n=2*n;
    }
}

void parameter_with_accuracy_uvix (double p, double eps, double par, int n, data_uvx s, data_uvix f)
{
    printf("\nUvix:\n");
    double par_uvix=0;
    while (p>eps)
    {
        double ttmp[n];
        double uvxtmp[n];
        double uvixtmp[n];
        form_t(n, s.tn, s.tk, ttmp);
        form_uvx(n, ttmp, uvxtmp, s);
        form_uvix(n, ttmp, uvxtmp, uvixtmp, f);
        par_uvix = parameter(n, uvixtmp, ttmp);
        p= fabs(par-par_uvix)/par_uvix;
        printf("n= %d, parameter = %.4lf, accuracy= %.4lf\n", n, par_uvix, p);
        par=par_uvix;
        n=2*n;
    }
}
*/
