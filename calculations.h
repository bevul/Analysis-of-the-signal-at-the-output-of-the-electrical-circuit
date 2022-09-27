#ifndef CALCULATIONS_H_INCLUDED
#define CALCULATIONS _H_INCLUDED
#include "in_out.h"

void form_t (int n, double tn, double tk, double* t);
void form_uvx (int n, double*t, double* uvx, data_uvx s);
void form_uvix (int n, double*t, double*uvx, double* uvix, data_uvix f);

double parameter  (int n, double* arr, double* t);
void parameter_with_accuracy_uvx (double p, double eps, double par, int n, data_uvx s);
void parameter_with_accuracy_uvix (double p, double eps, double par, int n, data_uvx s, data_uvix f);
#endif // CALCULATIONS _H_INCLUDED
