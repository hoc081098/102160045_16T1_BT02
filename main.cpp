
#include "fractionlist.h"

int main() {
  FractionList list(4);
  std::cout << list << '\n';

  std::cin >> list;
  std::cout << list << '\n';

  std::cout << "list[0] = " << list[0] << '\n';
  std::cout << "list[1] = " << list[1] << '\n';

  std::cout << "list[0] + list[1] = " << list[0] + list[1] << '\n';
  std::cout << "list[0] - list[1] = " << list[0] - list[1] << '\n';
  std::cout << "list[0] * list[1] = " << list[0] * list[1] << '\n';
  std::cout << "list[0] / list[1] = " << list[0] / list[1] << '\n';

  return 0;
}