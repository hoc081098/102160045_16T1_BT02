
#include <vector>
#include "fraction.h"
#include "fractionlist.h"

int main() {
  try {

    Fraction fraction(1, 2);
    fraction--;
    std::cout << fraction << '\n';
    std::cout << --fraction << '\n';

    Fraction *const fraction1 = new Fraction(1, 2);
    delete fraction1;

    fraction();
    std::cout << fraction[0] << '\n';
    std::cout << fraction[1] << '\n';

    Fraction *const a = new Fraction[2];
    delete[] a;

    fraction, *fraction1;
    fraction + 2;

    Fraction fraction2(1, 2);
    const Fraction &fraction3 = fraction2 << 2;
    std::cout << fraction2 << '\n';
    std::cout << fraction3 << '\n';


    std::cout << "--------" << '\n';
    std::cout << Fraction("2/4") << '\n';
//  std::cout << Fraction("1/0") << '\n';
    std::cout << Fraction("12213") << '\n';
    std::cout << Fraction("13") << '\n';

    std::cout << "--------" << '\n';
    std::cout << (Fraction("-2 / 3") ^ -3) << '\n';
    Fraction fraction4(98, -3);
    fraction4 ^= -3;
    std::cout << fraction4 << '\n';


    FractionList list(2);
    std::cin >> list;
    std::cout << list << '\n';

    std::cout << list[0] << '\n';

    FractionList copy;
    copy = list;
    std::cout << copy << '\n';

    std::cout << list << '\n';
    list[0] = Fraction(7, 8);

    std::cout << copy << '\n';

    std::cout << list << '\n';

    copy = list;
    std::cout << (copy == list) << '\n';

    int a1[]={1, 2, 3, 4};
    int a2[]={1, 2, 3};
    std::cout << "%" << std::equal(a1, a1+3, a2) << '\n';
  } catch (const std::exception &e) {
    std::cout << e.what() << '\n';
  }
  return 0;
}