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
      m_polyn.push_back(move(deriveMonomial(poly[i])));
      if (!poly[i].getValidMono()) {
          m_valid = false;
          return;
      }
   }
   m_valid = true;
}

/**
  * Pre:
 *		Requires a valid monomial
 * Post:
 *		Will produce the derived form of the inputed monomial. Will call several check functions
 *      to determine how to solve certain problems.
**/
Monomial deriveMonomial(const Monomial& mono)
{
   double exp(0);
   Monomial *m = nullptr;
   double _coef = mono.getCoef();
   string _term = mono.getTerm();
   string new_coef; 
   string new_term;

   // Derive a constant
   if (_term.empty())
       return *(new Monomial("0"));

   /* Parsing _term */
   for (int k(0); k < _term.size(); k++) {
      if (_term[k] == 'x') {
         ++k;
         if (_term[k] == '^') {
            int exp_Oper_Index = k;
            ++k;
            if (isdigit(_term[k]) || _term[k] == minus) {
               // Change coefficient
               string str_exponent;
               readDoubleFromStr(_term, str_exponent, k);
               exp = stod(str_exponent);
               new_coef = to_string(exp * _coef);
               // Change term
               new_term = "x^" + to_string(--exp);
               m = new Monomial(new_coef + new_term);
            }
         }
         else if (k == _term.size()) 
             m = new Monomial(to_string(_coef));
      }
   }
   if (m == nullptr) {
       std::cerr << "Warning: Monomial->nullptr was called" << std::endl;
       m = new Monomial();
   }
       
   return *m;
}
