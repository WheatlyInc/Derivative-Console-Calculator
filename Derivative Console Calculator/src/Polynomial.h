#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

/*********************************************
/* The Polynomial Class will output all the
/* derivatives of each of its individual terms.
/*********************************************/

#include <iostream>
#include <vector>
#include <set>


#define monomial pair<double, char>

using std::pair;
using std::vector;
using std::ostream;
using std::istream;


class Polynomial
{
    public:
        Polynomial();
        ~Polynomial();

    private:
        vector<monomial> polyn;
};

//ostream& operator<<(ostream& os, Polynomial);
//istream& operator>>(istream& is, Polynomial&);

#endif // POLYNOMIAL_H
