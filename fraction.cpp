//
// Created by Peter Hoc on 10/18/2018.
//

#include <iostream>
#include "fraction.h"

bool Fraction::operator==(const Fraction &rhs) const {
  return numerator == rhs.numerator && denominator == rhs.denominator;
}

bool Fraction::operator!=(const Fraction &rhs) const {
  return !(rhs == *this);
}

bool Fraction::operator<(const Fraction &rhs) const {
  // array / b < c / d <=> array * d < b * c
  return numerator * rhs.denominator < denominator * rhs.numerator;
}

bool Fraction::operator>(const Fraction &rhs) const {
  return rhs < *this;
}

bool Fraction::operator<=(const Fraction &rhs) const {
  return !(rhs < *this);
}

bool Fraction::operator>=(const Fraction &rhs) const {
  return !(*this < rhs);
}

Fraction &Fraction::operator+=(const Fraction &rhs) {
  int new_numerator = numerator * rhs.denominator + rhs.numerator * denominator;
  int new_denominator = denominator * rhs.denominator;
  initialize(new_numerator, new_denominator);
  return *this;
}

Fraction &Fraction::operator-=(const Fraction &rhs) {
  int new_numerator = numerator * rhs.denominator - rhs.numerator * denominator;
  int new_denominator = denominator * rhs.denominator;
  initialize(new_numerator, new_denominator);
  return *this;
}

Fraction &Fraction::operator*=(const Fraction &rhs) {
  int new_numerator = numerator * rhs.numerator;
  int new_denominator = denominator * rhs.denominator;
  initialize(new_numerator, new_denominator);
  return *this;
}

Fraction &Fraction::operator/=(const Fraction &rhs) {
  int new_numerator = numerator * rhs.denominator;
  int new_denominator = denominator * rhs.numerator;
  initialize(new_numerator, new_denominator);
  return *this;
}

Fraction operator+(Fraction lhs, const Fraction &rhs) {
  return lhs += rhs;
}

Fraction operator-(Fraction lhs, const Fraction &rhs) {
  return lhs -= rhs;
}

Fraction operator*(Fraction lhs, const Fraction &rhs) {
  return lhs *= rhs;
}

Fraction operator/(Fraction lhs, const Fraction &rhs) {
  return lhs /= rhs;
}

Fraction::Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator) {
  initialize(numerator, denominator);
}

void Fraction::initialize(int numerator, int denominator) {
  if (denominator == 0) {
    throw logic_error("Denominator can not be zero");
  }
  if (denominator < 0) {
    numerator *= -1;
    denominator *= -1;
  }
  int gcd = Fraction::gcd(abs(numerator), abs(denominator));
  this->numerator = numerator / gcd;
  this->denominator = denominator / gcd;
}

int Fraction::gcd(int a, int b) {
  while (b != 0) {
    int r = a % b;
    a = b, b = r;
  }
  return a;
}

ostream &operator<<(ostream &os, const Fraction &fraction) {
  return os << fraction.numerator << '/' << fraction.denominator;
}

istream &operator>>(istream &is, Fraction &fraction) {
  cout << "Numerator: ";
  int numerator;
  is >> numerator;

  int denominator;
  do {
    cout << "Denominator: ";
    is >> denominator;
    if (denominator == 0) {
      cout << "Denominator can not be zero!" << '\n';
    }
  } while (denominator == 0);

  fraction.initialize(numerator, denominator);

  return is;
}

Fraction Fraction::operator-() const {
  return Fraction(-numerator, denominator);
}

void Fraction::increment() {
  *this += Fraction(1);
}

void Fraction::decrement() {
  *this -= Fraction(1);
}

Fraction &Fraction::operator++() {
  increment();
  return *this;
}

const Fraction Fraction::operator++(int) {
  Fraction tmp(*this);
  operator++();
  return tmp;
}

const Fraction Fraction::operator--(int) {
  Fraction tmp(*this);
  operator--();
  return tmp;
}

Fraction &Fraction::operator--() {
  decrement();
  return *this;
}

int Fraction::get_numerator() const {
  return numerator;
}

void Fraction::set_numerator(int numerator) {
  initialize(numerator, denominator);
}

int Fraction::get_denominator() const {
  return denominator;
}

void Fraction::set_denominator(int denominator) {
  initialize(numerator, denominator);
}

void *Fraction::operator new(std::size_t sz) {
  std::cout << "custom new for size " << sz << '\n';
  return ::operator new(sz);
}

void *Fraction::operator new[](std::size_t sz) {
  std::cout << "custom new[] for size " << sz << '\n';
  return ::operator new(sz);
}

void Fraction::operator delete(void *ptr, std::size_t sz) {
  std::cout << "custom delete for size " << sz << '\n';
  ::operator delete(ptr);
}

void Fraction::operator delete[](void *ptr, std::size_t sz) {
  std::cout << "custom delete[] for size " << sz << '\n';
  ::operator delete(ptr);
}

int &Fraction::operator[](std::size_t idx) {
  if (idx == 0) return numerator;
  if (idx == 1) return denominator;
  throw std::out_of_range("Index must be in range 0..1");
}

const int &Fraction::operator[](std::size_t idx) const {
  if (idx == 0) return numerator;
  if (idx == 1) return denominator;
  throw std::out_of_range("Index must be in range 0..1");
}

void Fraction::operator()() {
  std::cout << "::operator()" << '\n';
}

void Fraction::operator,(const Fraction &other) {
  std::cout << *this << ", " << other << '\n';
}

Fraction Fraction::operator<<(std::size_t pos) const {
  Fraction temp(*this);
  temp *= Fraction(1 << pos);
  return temp;
}

Fraction &Fraction::operator<<=(std::size_t pos) {
  return *this *= Fraction(1 << pos);
}

Fraction Fraction::operator>>(std::size_t pos) const {
  Fraction temp(*this);
  temp /= Fraction(1 << pos);
  return temp;
}

Fraction operator+(Fraction lhs, const int &rhs) {
  return lhs + Fraction(rhs);
}

Fraction operator-(Fraction lhs, const int &rhs) {
  return lhs - Fraction(rhs);
}

Fraction operator*(Fraction lhs, const int &rhs) {
  return lhs * Fraction(rhs);
}

Fraction operator/(Fraction lhs, const int &rhs) {
  return lhs / Fraction(rhs);
}

Fraction &Fraction::operator>>=(std::size_t pos) {
  return *this /= Fraction(1 << pos);
}

Fraction::Fraction(const std::string &s) : numerator(0), denominator(1) {

  int numerator, denominator;
  char delimiter;

  std::istringstream iss1(s);
  if (iss1 >> numerator && !(iss1 >> delimiter)) {
    initialize(numerator, 1);
    return;
  }

  std::istringstream iss2(s);
  if ((iss2 >> numerator) &&
      (iss2 >> delimiter) &&
      delimiter == '/' &&
      (iss2 >> denominator)) {
    initialize(numerator, denominator);
  } else {
    throw std::invalid_argument("Invalid conversion to Fraction: " + s);
  }
}

Fraction Fraction::operator^(int n) const {
  try {
    if (n >= 0) return Fraction(int_pow(numerator, static_cast<size_t>(n)), int_pow(denominator, static_cast<size_t>(n)));
    return (Fraction(1) / *this) ^ (-n);
  }catch (const std::logic_error& e) {
    throw std::logic_error("Math error");
  }
}

int Fraction::int_pow(int base, std::size_t exp) {
  int result = 1;
  while (exp) {
    if (exp & 1) result *= base;
    exp /= 2;
    base *= base;
  }
  return result;
}

Fraction &Fraction::operator^=(int n) {
  return *this = *this ^ n;
}
