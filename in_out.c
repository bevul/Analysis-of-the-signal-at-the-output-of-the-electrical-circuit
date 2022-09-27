#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input_output.h"

/* Caption */

void caption (FILE* zast)
{
    char ch;
    while (!feof(zast))
    {
        fscanf(zast, "%c", &ch);
        printf("%c", ch);
    }
    printf("\n");
}

/* Start menu */

void data_menu (void)
{
    printf ("1. From file.\n"
            "2. Enter the data by yourself.\n");
}

/* File data */

void data_from_file_uvx (FILE* out_uvx, data_uvx* s)
{
    fscanf (out_uvx,"%lf", &s->a);
    fscanf (out_uvx,"%lf", &s->b);
    fscanf (out_uvx,"%lf", &s->t1);
    fscanf (out_uvx,"%lf", &s->t2);
    fscanf (out_uvx,"%lf", &s->tk);
    fscanf (out_uvx,"%lf", &s->tn);
}

void data_from_file_uvix (FILE* out_uvix, data_uvix* f)
{
    fscanf (out_uvix,"%lf", &f->u0);
    fscanf (out_uvix,"%lf", &f->uvx0);
    fscanf (out_uvix,"%lf", &f->u1);
    fscanf (out_uvix,"%lf", &f->uvx1);
    fscanf (out_uvix,"%lf", &f->u2);
    fscanf (out_uvix,"%lf", &f->uvx2);
    fscanf (out_uvix,"%lf", &f->u3);
    fscanf (out_uvix,"%lf", &f->uvx3);
}

/* Data from user */

void user_data_uvx (data_uvx *s)
{
    printf("\nUvx:\n");
    printf ("a= "); scanf ("%lf", &s->a);
    printf ("b= "); scanf ("%lf", &s->b);
    printf ("tn= "); scanf ("%lf", &s->tn);
    printf ("t1= "); scanf ("%lf", &s->t1);
    printf ("t2= "); scanf ("%lf", &s->t2);
    printf ("tk= "); scanf ("%lf", &s->tk);
}

void user_data_uvix (data_uvix *f)
{
    printf ("\nUvix:\n");
    printf ("U0= "); scanf ("%lf", &f->u0);
    printf ("Uvx0= "); scanf ("%lf", &f->uvx0);
    printf ("U1= "); scanf ("%lf", &f->u1);
    printf ("Uvx1= "); scanf ("%lf", &f->uvx1);
    printf ("U2= "); scanf ("%lf", &f->u2);
    printf ("Uvx2= "); scanf ("%lf", &f->uvx2);
    printf ("U3= "); scanf ("%lf", &f->u3);
    printf ("Uvx3= "); scanf ("%lf", &f->uvx3);
}

/* Menu */

void menu (void)
{
    printf("\n1.Calculation of the parameter\n"
           "2.Calculation of the parameter with given accuracy\n"
           "3.Form the table\n"
           "4.Write the control calculation to the file\n"
           "5.Build the chart of Uvx\n"
           "6.Build the chart of Uvix\n"
            );
}

/* Form the table */

void form_table (int n, double* t, double* uvx, double* uvix)
{
    int i;
    printf ("Number      t       Uvx      Uvix\n");
    for (i=0;i<n;i++)
             printf("\n  %3d   %6.3f   %6.3f   %6.3f",i,t[i],uvx[i],uvix[i]);
}

/* Write the control calculation to the file */

void filling_file (FILE* f, int n, double* arr)
{
    int i;
    for(i=0;i<n;i++)
    {
        fprintf(f,"%6.3lf\n",arr[i]);
    }
}
