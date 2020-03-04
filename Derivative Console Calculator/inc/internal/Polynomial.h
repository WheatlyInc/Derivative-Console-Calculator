#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

/*********************************************
/* The Polynomial Class will output all the
/* derivatives of each of its individual terms.
/*********************************************/

#include <cctype> /* isdigit*/
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
using std::stod;
using std::stringstream;
using std::string;
using std::to_string;
using std::vector;


class Polynomial
{
    public:
        Polynomial();
        ~Polynomial();
        vector<Monomial> getPolyn() const;
		  bool operator==(const Polynomial) const;
        bool operator!=(const Polynomial other_p) const;
		  friend ostream& operator<<(ostream& os, const Polynomial&);
		  friend istream& operator>>(istream& is, Polynomial&);

    private:
		 bool m_valid_polyn;
       vector<Monomial> m_polyn;
		 // Another vector to keep track of operators +-*/ ? 

};


#endif // POLYNOMIAL_H