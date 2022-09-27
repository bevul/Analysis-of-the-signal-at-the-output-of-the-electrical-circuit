#ifndef IN_OUT_H_INCLUDED
#define IN_OUT_H_INCLUDED

struct data_from_uvx
{
    double a;
    double b;
    double tn;
    double t1;
    double t2;
    double tk;
};

typedef struct data_from_uvx data_uvx;

struct data_from_uvix
{
    double uvx0;
    double u0;
    double uvx1;
    double u1;
    double uvx2;
    double u2;
    double uvx3;
    double u3;
};

typedef struct data_from_uvix data_uvix;

void caption (FILE* f);
void data_menu (void);
void data_from_file_uvx (FILE* out_uvx, data_uvx* s);
void data_from_file_uvix (FILE* out_uvix, data_uvix* f);
void user_data_uvx (data_uvx *s);
void user_data_uvix (data_uvix *f);
void menu (void);
void form_table (int n, double* t, double* uvx, double* uvix);
void filling_file (FILE* f, int n, double* arr);


#endif // IN_OUT_H_INCLUDED
