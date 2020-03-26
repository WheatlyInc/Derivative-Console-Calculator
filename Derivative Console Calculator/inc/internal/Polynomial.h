#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

/*********************************************
/* The Polynomial Class will output all the
/* derivatives of each of its individual terms.
/*********************************************/

#include <cmath> /* Trig Funcs, */
#include <iostream>
#include <math.h> /* Log Funcs*/
#include <sstream> /* istringstream ostringstream */
#include <string>
#include <set>
#include <vector>

#include "Monomial.h"

using std::isdigit; 
using std::istream;
using std::ostream;
using std::pair;
using std::make_pair;
using std::stringstream;
using std::string;
using std::to_string;
using std::vector;


enum op {};


/**
* This class lets you construct a vector implementation of Monomials, 
* and supports various operators. 
* To call for a specific monomial in a polynomial object, do a
*     poly[0];
* Implementation for inner operations, such as addition and subtraction
* of like-unlike monomials, will come soon.
*/
class Polynomial
{
   public:
        Polynomial();
        ~Polynomial();
        vector<Monomial> getPolyn() const;
        int getSize() const;
        void combineliketerms();
        Monomial& operator[](const unsigned int);
        bool getValid() const;
        const Monomial& operator[](const unsigned int) const;
		  bool operator==(const Polynomial) const;
        bool operator!=(const Polynomial other_p) const;
		  friend ostream& operator<<(ostream& os, const Polynomial&);
		  friend istream& operator>>(istream& is, Polynomial&);

    protected:
		 bool m_valid;
       vector<Monomial> m_polyn;
		 // Another vector to keep track of operators +-*/ ? 

};


#endif // POLYNOMIAL_H