#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

/*********************************************
/* The Polynomial Class will output all the
/* derivatives of each of its individual terms.
/*********************************************/

#include <vector>

#include "Monomial.h"

 
using std::vector;


/**
* This class lets you construct a vector implementation of Monomials, 
* and supports various operators. 
* To call for a specific monomial in a polynomial object, do a
*     poly[0];
* Relies on the validation of the monomial class to build correct, usable objects.
* Implementation for inner operations, such as addition and subtraction
* of like-unlike monomials, will come soon.
*/
class Polynomial
{
   public:
      Polynomial();
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