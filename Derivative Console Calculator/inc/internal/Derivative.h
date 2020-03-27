#ifndef DERIVATIVE_H
#define DERIVATIVE_H

/***********************************************************
/* The Derivative class will find the derivative of a
/*  single term from its inherited class Polynomial
/***********************************************************/

#include <iostream>
#include <vector>
#include "Polynomial.h"





class Derivative : public Polynomial
{
    public:
        Derivative(const Polynomial&);
};


Monomial deriveMonomial(const Monomial&);


#endif // DERIVATIVE_H