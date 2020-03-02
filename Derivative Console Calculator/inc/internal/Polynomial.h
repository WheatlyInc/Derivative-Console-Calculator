#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

/*********************************************
/* The Polynomial Class will output all the
/* derivatives of each of its individual terms.
/*********************************************/

#include <cmath> /* Trig Funcs, */
#include <iostream>
#include <math.h> /* Log Funcs*/
#include <string>
#include <set>
#include <vector>

#include "Monomial.h"

using std::istream;
using std::ostream;
using std::pair;
using std::make_pair;
using std::string;
using std::vector;


class Polynomial
{
    public:
        Polynomial();
        ~Polynomial();
        vector<Monomial> getPolyn() const;
		  bool operator==(const Polynomial) const;
		  friend ostream& operator<<(ostream& os, const Polynomial&);
		  friend istream& operator>>(istream& is, Polynomial&);

    private:
       vector<Monomial> m_polyn;
};


#endif // POLYNOMIAL_H
