#ifndef DERIVATIVE_H
#define DERIVATIVE_H

/***********************************************************
/* The Derivative class will find the derivative of a
/*  single term from its inherited class Polynomial
/***********************************************************/

#include <iostream>
#include <vector>
#include "Polynomial.h"


using namespace std;


class Derivative
{
    public:
        Derivative();
        Derivative(double);
        Derivative(double, string);
        virtual ~Derivative();

    private:
       Polynomial poly;
};



#endif // DERIVATIVE_H
