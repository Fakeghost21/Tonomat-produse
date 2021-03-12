#include "Util.h"

string convertDoubleToString(double x)
{
	string s = to_string(x);
	int decimalSepPos = s.find('.');
	if (decimalSepPos != string::npos)
	{
		int len = s.length() - 1;
		while (s[len] == '0')
		{
			len--;
		}
		if (len == decimalSepPos)
		{
			s = s.substr(0, len);
		}
		else
		{
			s = s.substr(0, len + 1);
		}
	}
	return s;
}
