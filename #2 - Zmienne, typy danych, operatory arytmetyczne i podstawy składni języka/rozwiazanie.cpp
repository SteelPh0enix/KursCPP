#include <iostream>

int main() {
	long long x, y;
	std::cout << "Podaj liczby x i y: ";
	std::cin >> x >> y;
	
	std::cout << "x + y = " << x + y << std::endl
		  << "x - y = " << x - y << std::endl
		  << "x * y = " << x * y << std::endl
		  << "x / y = " << x / y << std::endl;
	return 0;
}
