#include "pch.h"

int main()
{
	std::cout << "integral: " << sizeof(char) << ' ' << sizeof(short) << ' ' 
		<< sizeof(int) << ' '  << sizeof(long) << ' ' << sizeof(long long) << '\n';
	std::cout << "floating point: " << sizeof(float) << ' ' << sizeof(double) << ' ' << sizeof(long double) << '\n';
	std::cout << "char: "<< sizeof(char) << ' ' << sizeof(wchar_t) << ' ' << sizeof(TCHAR) << '\n';
	std::cout << "pointer: " << sizeof(void*) << '\n';
	std::cout << "bool: " << sizeof(bool) << '\n';
}
