#include "../inc/internal/Derivative.h"

Derivative::Derivative(Polynomial& poly)
{

   if (poly.getValid() == false) {
      std::cerr << "ERROR: Call to take derivative on invalid polynomial" << std::endl;
      m_valid = false;
      return;
   }
   for (int i(0); i < poly.getSize(); i++) {
      int exp(0); 
      Monomial m;
      double _coef = poly[i].getCoef();
      string _term = poly[i].getTerm();

      for (int k(0); k < _term.size(); k++) {
         if (_term[k] == 'x') {
            if (_term[++k] == '^') {
               int carrot_index = k;
               if (isdigit(_term[++k])) {
                  // Change coefficient
                  string str_exponent;
                  for (k; k < _term.size() && isdigit(_term[k]); k++)
                     str_exponent += _term[k];
                  exp = stod(str_exponent);
                  m.setCoef(exp * _coef);

                  // Change Exponent
                  exp -= 1;
                  m.setTerm("x^" + to_string(exp));
                  m.setValidMono(true);
                  m_polyn.push_back(m);
               }
            }
         }
      }
   }
   m_valid = true;
}

Derivative::~Derivative()
{
    //dtor
}
