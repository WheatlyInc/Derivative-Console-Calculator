#include "../inc/internal/Derivative.h"

/** Use this function to take the derivative of an exisiting polynomial.
  * Pre:
 *		Takes in a valid polynomial.
 * Post:
 *		Will attempt to derive the entire polynomial expression. Will output any errors or calculation failures.
**/
Derivative::Derivative(const Polynomial& poly)
{
   if (poly.getValid() == false) {
      std::cerr << "ERROR: Call to take derivative on invalid polynomial" << std::endl;
      m_valid = false;
      return;
   }
   for (int i(0); i < poly.getSize(); i++) {
      m_polyn.push_back(deriveMonomial(poly[i]));
   }
   m_valid = true;
}

/**
  * Pre:
 *		Requires a valid monomial
 * Post:
 *		Will produce the derived form of the inputed monomial. Will call several check functions
 *    to determine how to solve certain problems.
**/
Monomial deriveMonomial(const Monomial& mono)
{
   int exp(0);
   Monomial *m = new Monomial();
   double _coef = mono.getCoef();
   string _term = mono.getTerm();

   /* Parsing _term */
   for (int k(0); k < _term.size(); k++) {
      if (_term[k] == 'x') {
         ++k;
         if (_term[k] == '^') {
            int exp_Oper_Index = k;
            ++k;
            if (isdigit(_term[k])) {
               // Change coefficient
               string str_exponent;
               for (k; k < _term.size() && isdigit(_term[k]); k++)
                  str_exponent += _term[k];
               exp = stod(str_exponent);
               m->setCoef(exp * _coef);
               // Change Exponent
               exp -= 1;
               m->setTerm("x^" + to_string(exp));
               m->setValidMono(true);
            }
         }
      }
   }
   return *m;
}
