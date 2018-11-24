//
// Created by Peter Hoc on 10/22/2018.
//

#include "fractionlist.h"

Fraction *FractionList::allocArray(int n) {
  return new Fraction[n];
}

void FractionList::freeArray(Fraction *a) {
  delete[] a;
}

FractionList::FractionList(size_t n) : n(n), array(NULL) {
  if (n < 0) throw std::invalid_argument("N must be greater than or equal to zero");
  freeAndAllocArray(n);
}

FractionList::~FractionList() {
  freeArray(array);
}

istream &operator>>(istream &is, FractionList &list) {
  int n;
  do {
    std::cout << "Input n = ";
    is >> n;
    if (n < 0) std::cout << "N must be greater than or equal to zero. Input again!" << '\n';
  } while (n < 0);

  if (n != list.n) {
    list.freeAndAllocArray(static_cast<size_t>(n));
  }
  for (int i = 0; i < n; ++i) {
    std::cout << "Input fraction " << i << ": " << '\n';
    is >> list[i];
    std::cout << '\n';
  }

  return is;
}

ostream &operator<<(ostream &os, const FractionList &list) {
  os << "FractionList: size = " << list.n << ", array = [\n";
  for (int i = 0; i < list.n; ++i) {
    os << "  [" << i << "] " << list[i];
    if (i < list.n - 1) os << ",\n";
  }
  return os << "\n]";
}

Fraction &FractionList::operator[](std::size_t idx) {
  checkIndex(idx);
  return array[idx];
}

void FractionList::checkIndex(size_t idx) const {
  if (idx < 0 || n <= idx) {
    ostringstream oss;
    oss << "Index must be in range " << 0 << ".." << (n - 1);
    throw out_of_range(oss.str());
  }
}

const Fraction &FractionList::operator[](std::size_t idx) const {
  checkIndex(idx);
  return array[idx];
}

void FractionList::freeAndAllocArray(size_t n) {
  if (n < 0) throw std::invalid_argument("N must be greater than or equal to zero");

  freeArray(array);
  array = allocArray(n);
  this->n = n;
}

FractionList::FractionList(const FractionList &other) {
  n = other.n;
  array = new Fraction[n];
  std::copy(other.array, other.array + n, array);
}

FractionList &FractionList::operator=(const FractionList &rhs) {
  if (this != &rhs) {
    if (n != rhs.n) {
      delete[] array;
      n = 0;
      array = NULL;

      array = new Fraction[rhs.n];
      n = rhs.n;
    }
    std::copy(rhs.array, rhs.array + rhs.n, array);
  }
  return *this;
}

bool FractionList::operator==(const FractionList &rhs) const {
  return n == rhs.n && std::equal(array, array + n, rhs.array);
}

bool FractionList::operator!=(const FractionList &rhs) const {
  return !(rhs == *this);
}
