//
// Created by Peter Hoc on 10/18/2018.
//

#include <iostream>
#include <cstdlib>
#include "fraction.h"

bool Fraction::operator==(const Fraction &rhs) const {
  return numerator == rhs.numerator && denominator == rhs.denominator;
}

bool Fraction::operator!=(const Fraction &rhs) const {
  return !(rhs == *this);
}

bool Fraction::operator<(const Fraction &rhs) const {
  // a / b < c / d <=> a * d < b * c
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
