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
Monomial::Monomial(const string& s)
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
	try {
		if (s[i] == minus) {
			if (isdigit(s[i+1])) {
				readDoubleFromStr(s, str_coef, i);
				m_coefficient = stod(str_coef);
				if (s[i] == 'x') {
					parseBuildTerm(s, i);
				}
			}
			else if (s[i+1] == 'x') {
				m_coefficient = -1;
				parseBuildTerm(s, ++i);
			}
			else
				throw "Invalid character read after '-': In " + s + '\n';
		}
		else if (isdigit(s[i])) {
			readDoubleFromStr(s, str_coef, i);
			m_coefficient = stod(str_coef);
			if (s[i] == 'x') {
				parseBuildTerm(s, i);
			}
			else if (i == s.size()) {
				m_valid_mono = true;
			}
		}
		else if (s[i] == 'x') {
			m_coefficient = 1;
			parseBuildTerm(s, i);
		}
	}
	catch (string error) {
		m_valid_mono = false;
		std::cerr << "ERROR: " << error << std::endl;
	}
	
}

/**
 * Pre:
 *		Is the second parse func to help and be called by the Monomial Constructor. This function expects
 *		the constructor input string(&s), and the current index that the Constructor was on(&i), as parameters.
 *
 * Post:
 *		Translates the input into an organized, readable term if validated
 *		successfully.
 **/
void Monomial::parseBuildTerm(const string& s, int& i)
{	
	string _term = "x";
	++i;
	if (s[i] == '^' && i < s.size()) {
		_term += '^';
		int exp_Oper_Index(i);
		++i;
		if (i < s.size() && (isdigit(s[i]) || s[i] == minus)) {
			bool exp_index_still_num = true;
			// This copies the str_number that represents the exponent
			string exp_str;
			readDoubleFromStr(s, exp_str, i);
			if (exp_str == "1") {
				m_term = "x";
				if (i == s.size())
					m_valid_mono = true;
				else
					m_valid_mono = false;
			}
			else if (exp_str == "0") {
				m_term += "";
				m_valid_mono = true;
			}
			else if (isNum(exp_str)) {
				_term += exp_str;
				m_term += _term;
				m_valid_mono = true;
			}
			else {
				m_valid_mono = false;
			}
		}
	}
	else if (i == s.size()) {
		// x has exp of "1"
		m_term = _term;
		m_valid_mono = true;
	}
	else {
		throw "Ambiguous term after 'x': In " + s + '\n';
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
bool Monomial::isNum(const string& s) const
{
	bool onePeriodRead = false;
	if (s[0] == '.') {
		std::cerr << "Ambiguous '.' at the beggining of num." << std::endl;
		return false;
	}
	int i(0);
	if (s[i] == minus)
		i++;
	for (i; i < s.size(); i++) {
		if (s[i] == '.' && onePeriodRead) 
			return false;
		else if (!isdigit(s[i]) && s[i] != '.')
			return false;
		if (s[i] == '.') {
			if (i == s.size() - 1)
				return false;
			onePeriodRead = true;
		}		
	}
	return true;
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
 *  Pro:
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
		else if (mono.getCoef() == -1) {
			if (mono.getTerm() == "")
				return os << "-1";
			else
				return os << minus << mono.getTerm();
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

/**
 * Pre:
 *		Used by the Monomial Class to remove trailing zeros from an input string.
 *		Expects ONLY one "double" in the form of a string. The "double" may or may not have a decimal value.
 * Post:
 *		Will remove every zero that follows a period. If there is no period, the function makes no changes.
**/
void omitTrailZeros(string& str_Num)
{
	auto found = str_Num.find(".");
	if (found == string::npos)
		return;
	str_Num.erase(str_Num.find_last_not_of('0') + 1, std::string::npos);
	if (str_Num[str_Num.size() - 1] == '.')
		str_Num.pop_back();
}

/**
 * Pre:
 *		Is the first parse func to help and be called by the Monomial Constructor. This function expects
 *		the constructor input string(&s), another string to store the double, and the current index
 *		that the Constructor was on(&i), as parameters.
 *
 * Post:
 *		Translates the input into an organized, readable double if validated
 *		successfully.
 **/
void readDoubleFromStr(const string& s, string& str_double, int& i)
{
	bool onePeriodRead = false;
	if (s[i] == minus) {
		str_double += minus;
		i++;
	}
	if (s[i] == '.')
		throw "The character '.' was found at the beggining of a string expected to represent a double: In " + s +"\n";
	for (i; i < s.size() && (isdigit(s[i]) || s[i] == '.'); i++) {
		if (onePeriodRead && s[i] == '.')
			throw "More than one '.' in number: " + s.substr(0, i + 1) + "\n";
		if (!isdigit(s[i]) && s[i] != '.')
			throw "Invalid character '" + s.substr(i, 0) + "' read when expecting a string representing a double: In " + s + "\n";
		str_double += s[i];
		if (s[i] == '.')
			onePeriodRead = true;
	}
	omitTrailZeros(str_double);
}