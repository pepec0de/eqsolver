#include "../include/stringutils.h"

// Func to split a string with a given char
vector<string> stringutils::splitString(string str, char deliminator) {
	vector<string> strVct;
	unsigned int relStart = 0;
	for (unsigned int i = 0; i < str.size(); i++) {
		if (str[i] == deliminator) {
			// Hacemos el substring y despues lo añadimos al vector str
			strVct.push_back(getSubstring(str, relStart, i));
			relStart = i+1;
			// Si el delimitador esta en el ultimo caracter sacamos el vector
			if (relStart >= str.size()) {
				return strVct;
			}
		}
	}
	strVct.push_back(getSubstring(str, relStart, str.size()));
	return strVct;
}

// Func to do substring having an interval
string stringutils::getSubstring(string str, unsigned int start, unsigned int end) {
	string result = "";
	for (unsigned int i = start; i < end; i++) {
        result += str[i];
	}
	return result;
}

// Func to remove last characters of a string (has to be a negative number)
string stringutils::getSubstring(string str, int fromEnd) {
	string result = "";
	if (fromEnd < 0) {
		for (int i = 0; i < (fromEnd + (int)str.size()); i++) {
			result.push_back(str[i]);
		}
	}
	return result;
}

// Converters
string stringutils::tostring(float value) {
    ostringstream strs;
    strs << value;
    return strs.str();
}
