#include "../inc/internal/Polynomial.h"

Polynomial::Polynomial()
{
	m_valid = false;
}

Polynomial::~Polynomial()
{
    //dtor
}

vector<Monomial> Polynomial::getPolyn() const
{
   return m_polyn;
}

Monomial& Polynomial::operator[](const unsigned int index)
{
	if (index >= m_polyn.size()) { 
		std::cerr << "Error: Polynomial Index out of bound: index " << index << " >= " << m_polyn.size() << std::endl;
	}
	return m_polyn[index];
}

bool Polynomial::getValid() const
{
	return m_valid;
}

const Monomial& Polynomial::operator[](const unsigned int index) const
{
	if (index >= m_polyn.size()) {
		std::cerr << "Error: Polynomial Index out of bound.";
	}
	return m_polyn[index];
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
	if (poly.m_valid == true)
		return os << poly[0].getCoef() << poly[0].getTerm();
	else 
		return os << "ERROR: Invalid Polnomial entered.\n";
}

istream& operator>>(istream& is, Polynomial& poly)
{
	Monomial m1;
	int num_lft_parenth(0), num_rht_parenth(0);
	bool open_parenth(false); 
	string s; 
	/* Monomials must have either a coefficient, some function of x, or both.
	*	They must be distinct and cannot blend with other monomials.
	**/
	// Building the first monomial // 
	/* Analyze the first character to be valid.*/
	is >> s;
	if (isdigit(s[0]) || s[0] == 'x') {
		Monomial m1(s);
		poly.m_polyn.push_back(m1);
		if (m1.getValidMono())
			poly.m_valid = true;
	}
	else {
		poly.m_valid = false;
		std::cerr << "ERROR: Invalid startpoint to input expression: \"" << s[0] << "\"" <<  std::endl;
		return is;
	}


	
	while (is >> s && poly.m_valid != false) {}
	return is;
}