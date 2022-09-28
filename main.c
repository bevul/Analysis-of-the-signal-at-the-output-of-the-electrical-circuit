#include <stdio.h>
#include <stdlib.h>
#include "calculations.h"
#include "in_out.h"

int main()
{
    //FILE *zast=fopen("zast.txt", "r");
    //caption(zast);
    //fclose(zast);

    int input=0;
    int answer=0;

    int n;
    printf("\nControl calculation:\n");
    printf ("\nEnter n (number of elements): ");
    scanf("%d", &n);
    printf("\n");

    double t[n];
    double uvx[n];
    double uvix[n];

    data_uvx s;
    data_uvix f;

    printf ("What type of data do you need to use?\n");
    data_menu();
    printf("Number: ");
    scanf("%d", &input);
    switch (input)
    {
    case 1:
    {
        FILE* out_uvx=fopen("uvx_data.txt", "r");
        data_from_file_uvx(out_uvx, &s);
        fclose(out_uvx);

        FILE* out_uvix=fopen("uvix_data.txt", "r");
        data_from_file_uvix(out_uvix, &f);
        fclose(out_uvix);
        break;
    }
    case 2:
    {
        user_data_uvx(&s);
        user_data_uvix(&f);
        break;
    }
      default:
    {
        printf("\nIncorrect input!\n");
        break;
    }
    }


    form_t(n, s.tn, s.tk, t);
    form_uvx(n, t, uvx, s);
    form_uvix(n, t, uvx, uvix, f);

    do
    {
        menu();
        printf("\nNumber: ");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
        {
            double t_max_uvx=0;
            t_max_uvx=parameter(n, uvx, t);
            printf("\nMax Uvx time=%.2lf\n", t_max_uvx);
            double t_max_uvix=0;
            t_max_uvix=parameter(n, uvix, t);
            printf("Max Uvix time=%.2lf\n", t_max_uvix);
            break;
        }
        case 2:
        {
            /*double p=1;
            double eps=0.024;
            double par=10;
            parameter_with_accuracy_uvx(p, eps, par, n, s);
            parameter_with_accuracy_uvix(p, eps, par, n, s, f);
            break;*/
        }
        case 3:
        {
            form_table(n, t, uvx, uvix);
            break;
        }
        case 4:
        {
            FILE *f1=fopen("t.txt","w");
            filling_file(f1,n,t);
            FILE *f2=fopen("uvx.txt","w");
            filling_file(f2,n,uvx);
            FILE *f3=fopen("uvix.txt", "w");
            filling_file(f3,n,uvix);
            fclose(f1);
            fclose(f2);
            fclose(f3);
            printf("Calculations were written to the files.\n");
            break;
        }

        case 5:
        {
            system("C:\\maxima-5.46.0\\bin\\maxima -b uvx_max.txt");
            break;
        }
        case 6:
        {
            system("C:\\maxima-5.46.0\\bin\\maxima -b uvix_max.txt");
            break;
        }
        default:
        {
            printf("\nIncorrect input!\n");
            break;
        }
        }
        printf("\nDo you want to continue?(1-yes, 2-no) ");
        scanf("%d", &answer);
    }
    while (answer==1);
    return 0;

}

