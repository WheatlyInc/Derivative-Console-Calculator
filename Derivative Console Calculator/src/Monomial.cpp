#include "../inc/internal/Monomial.h"

/** 
 *	Post:
 *		Makes an empty monomial object. Not considered a valid monomial. 
 *		Can be changed with class member functions, however. 
 **/
Monomial::Monomial()
{
	m_coefficient = 0;
	m_term = "";
	m_valid_mono = false;
}

/**
 * Pre:
 *		Takes in some multi-char input and validates it into a monomial object.
 *
 * Post:
 *		Translates the input into an organized, readable object if validated 
 *		successfully.
 **/
Monomial::Monomial(string s)
{
	m_coefficient = 0;
	m_term = "";
	m_valid_mono = false;
	string str_coef; 
	if (s.empty()) {
		std::cerr << "Error: Monomial not defined: Empty string passed in.\n";
		return;
	}
	int i(0);
	if (isdigit(s[0])) {
		for (i; i < s.size() && (isdigit(s[i]) || s[i] == '.'); i++) {
			str_coef += s[i];
		}
		omitTrailZeros(str_coef);
		m_coefficient = stod(str_coef);
		if (s[i] == 'x') {
			m_term += 'x';
			++i;
			if (s[i] == '^' && i < s.size()) {
				m_term += '^';
				int exp_Oper_Index(m_term.size() - 1);
				++i;
				if (i < s.size() && isdigit(s[i])) {
					bool exp_index_still_num = true;
					// This copies the str_number that represents the exponent
					string exp_str;
					for (i; i < s.size() && (isdigit(s[i]) || s[i] == '.'); i++) {
						exp_str += s[i];
					}
					omitTrailZeros(exp_str);

					m_term += exp_str; 
					if (exp_str == "1") {
						m_term = "x";
						if (++i == s.size())
							m_valid_mono = true;
						else
							m_valid_mono = false;
					}
					if (exp_str == "0") {
						m_term = "";
						m_valid_mono = true; 
					}
					else if (isNum(exp_str)) {
						m_valid_mono = true;
					}
					else {
						m_valid_mono = false;
					}
				}
				
			}
			else if (i == s.size()) {
				// x has exp of "1"
				m_valid_mono = true;
			}
		}
	}
	else if (s[0] == 'x') {
		m_coefficient = 1;
		m_term += s.substr(1);
		m_valid_mono = true;
	}
}

/**
 * Pre:
 *		Used by friend and class member functions. Assumes validated parameters
**/
void Monomial::setValidMono(bool b)
{
	m_valid_mono = b;
}

/**
 * Pre:
 *		Used by the Monomial Class to remove trailing zeros from an input string. 
 *		Expects ONLY one "double" in the form of a string. The "double" may or may not have a decimal value.
 * Post: 
 *		Will remove every zero that follows a period. If there is no period, the function makes no changes.
**/
void Monomial::omitTrailZeros(string& str_Num)
{
	auto found = str_Num.find(".");
	if (found == string::npos)
		return;
	str_Num.erase(str_Num.find_last_not_of('0') + 1, std::string::npos);
	if (str_Num[str_Num.size() - 1] == '.')
		str_Num.pop_back();
}

double Monomial::getCoef() const
{
	return m_coefficient;
}

string Monomial::getTerm() const
{
	return m_term;
}

/**
 * Pre:
 *		Takes in a string to check if it is entirely a number in string format
 * Post:
 *		Will return true if s is some number in string format, false otherwise
**/
bool Monomial::isNum(const string s) const
{
	bool b = true;
	for (int i(0); i < s.size() && b; i++)
		if (!isdigit(s[i]))
			b = false;
	return b;
}

/**
 * Post:
 *		Used by friend and class member functions. Returns true for a valid monomial, 
 *		false for an invalid monomial.
**/
bool Monomial::getValidMono() const
{
	return m_valid_mono;
}

/**
 * Post:
 *		Returns true if both compared monomials are valid and have the same coefficients and terms.
 * TO IMPLEMENT:
 *		The ability to compare expressions like 0x^2 and 0x^0
**/
bool Monomial::operator==(const Monomial m) const
{
	return (this->getCoef() == m.getCoef()) && (this->getTerm() == m.getTerm() && getValidMono() && m.getValidMono());
}

bool Monomial::operator!=(const Monomial m) const
{
	return !(*this == m);
}

/**
 * TOBE IMPLEMENTED
 *	Pre:
 * Pro:
 **/
ostream& operator<<(ostream& os, const Monomial& mono)
{

	if (mono.getValidMono()) {
		if (mono.getCoef() == 1) {
			if (mono.getTerm() == "")
				return os << '1';
			else
				return os << mono.getTerm();
		}
		else {
			if (mono.getTerm() == "")
				return os << mono.getCoef();
			else
				return os << mono.getCoef() << mono.getTerm();
		}
	}
	else {
		return os << "ERROR: Invalid Monomial\n";
	}

}

/**
 * DEPRECATED
 *
istream& operator>>(istream& is, Monomial&)
{
	// TODO: insert return statement here
}
**/