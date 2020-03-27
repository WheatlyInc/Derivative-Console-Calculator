#include "../inc/internal/Monomial.h"

Monomial::Monomial()
{
	m_coefficient = 0;
	m_term = "";
	m_valid_mono = false;
}

Monomial::Monomial(string s)
{
	m_coefficient = 0;
	m_term = "";
	m_valid_mono = false;
	string str_coef; str_coef += (s[0]);
	if (isdigit(s[0])) {
		int i(1);
		for (i; i < s.size() && isdigit(s[i]); i++) {
			str_coef += s[i];
		}
		m_coefficient = stod(str_coef);
		if (s[i] == 'x') {
			m_term += s.substr(i);
			m_valid_mono = true;
		}
	}
	else if (s[0] == 'x') {
		m_coefficient = 1;
		m_term += s.substr(1);
		m_valid_mono = true;
	}
}

void Monomial::setCoef(double coef)
{
	m_coefficient = coef;
}

void Monomial::setTerm(string term)
{
	m_term = term;
}

void Monomial::setValidMono(bool b)
{
	m_valid_mono = b;
}

double Monomial::getCoef() const
{
	return m_coefficient;
}

string Monomial::getTerm() const
{
	return m_term;
}

bool Monomial::getValidMono() const
{
	return m_valid_mono;
}

bool Monomial::operator==(const Monomial m) const
{
	return (this->getCoef() == m.getCoef()) && (this->getTerm() == m.getTerm());
}

bool Monomial::operator!=(const Monomial m) const
{
	return !(*this == m);
}

ostream& operator<<(ostream& os, const Monomial&)
{
	// TODO: insert return statement here
}

istream& operator>>(istream& is, Monomial&)
{
	// TODO: insert return statement here
}
