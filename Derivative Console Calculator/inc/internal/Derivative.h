#ifndef DERIVATIVE_H
#define DERIVATIVE_H

/***********************************************************
/* The Derivative class will find the derivative of a
/*  single term from its inherited class Polynomial
/***********************************************************/


#include <iostream>
#include <vector>
#include "Polynomial.h"


/**
* This class is the superclass to the class Polynomial. It uses the same 
* structure of Polynomials to find the differentiated version of an existing 
* Polynomial, and to represent and print that version.
*/
class Derivative : public Polynomial
{
    public:
        Derivative(const Polynomial&);
};


Monomial deriveMonomial(const Monomial&);


#endif // DERIVATIVE_H