#include "../inc/internal/Polynomial.h"

Polynomial::Polynomial()
{
    //ctor
}

Polynomial::~Polynomial()
{
    //dtor
}

vector<Monomial> Polynomial::getPolyn() const
{
   return m_polyn;
}

bool Polynomial::operator==(const Polynomial other_p) const
{
	return this->getPolyn() == other_p.getPolyn();
}

bool Polynomial::operator!=(const Polynomial other_p) const
{
	return !(*this == other_p);
}

ostream& operator<<(ostream& os, const Polynomial& poly)
{
	if (poly.m_valid_polyn == true)
		return os << poly.getPolyn()[0].getCoef() << poly.getPolyn()[0].getTerm();
	else 
		return os << "ERROR: Invalid Polnomial entered.\n";
}

istream& operator>>(istream& is, Polynomial& poly)
{
	int num_lft_parenth(0), num_rht_parenth(0);
	bool open_parenth(false); 
	string s; 
	is >> s;
	
	// Analyze first character to be valid
	if (!isdigit(s[0]) && s[0] != 'x') {
		poly.m_valid_polyn == false;
	}
	else if (isdigit(s[0])) {
		Monomial m1;
		string str_coef; str_coef += (s[0]);
		int i(1);
		for (i; i < s.size() && isdigit(s[i]); i++) {
			str_coef += s[i];
		}
		m1.setCoef(stod(str_coef));
		if (s[i] == 'x') {
			m1.setTerm("x");
			m1.setValidMono(true);
		}
		poly.m_polyn.push_back(m1);
	}

	while (is >> s && poly.m_valid_polyn != false) {

	}
	
	return is;
}