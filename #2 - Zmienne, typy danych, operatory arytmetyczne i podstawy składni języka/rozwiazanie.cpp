#include <iostream>

int main() {
  long long x, y;
  std::cout << "Podaj liczby x i y: ";
  std::cin >> x >> y;

  // Staraj się używać std::endl tylko w ostatniej linijce wypisywanego tekstu.
  std::cout << "x + y = " << x + y << '\n'
            << "x - y = " << x - y << '\n'
            << "x * y = " << x * y << '\n'
            << "x / y = " << x / y << std::endl;
}
