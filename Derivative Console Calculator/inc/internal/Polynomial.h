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


using std::istream;
using std::ostream;
using std::pair;
using std::make_pair;
using std::string;
using std::vector;


#define monomial pair<double, string>


class Polynomial
{
    public:
        Polynomial();
        ~Polynomial();
        vector<monomial> getPolyn() const;
		  bool operator==(Polynomial);
		  friend ostream& operator<<(ostream& os, const Polynomial&);
		  friend istream& operator>>(istream& is, Polynomial&);

    private:
        vector<monomial> m_polyn;
};



#endif // POLYNOMIAL_H
