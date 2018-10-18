//
// Created by Peter Hoc on 10/18/2018.
//

#ifndef BAITAPOOP02_FRACTION_H
#define BAITAPOOP02_FRACTION_H

#include <ostream>

using namespace std;

class Fraction {
public:
  explicit Fraction(int numerator = 0, int denominator = 1);

  Fraction &operator+=(const Fraction &rhs);

  Fraction &operator-=(const Fraction &rhs);

  Fraction &operator*=(const Fraction &rhs);

  Fraction &operator/=(const Fraction &rhs);

  friend Fraction operator+(Fraction lhs, const Fraction &rhs);

  friend Fraction operator-(Fraction lhs, const Fraction &rhs);

  friend Fraction operator*(Fraction lhs, const Fraction &rhs);

  friend Fraction operator/(Fraction lhs, const Fraction &rhs);

  bool operator<(const Fraction &rhs) const;

  bool operator>(const Fraction &rhs) const;

  bool operator<=(const Fraction &rhs) const;

  bool operator>=(const Fraction &rhs) const;

  bool operator==(const Fraction &rhs) const;

  bool operator!=(const Fraction &rhs) const;

  Fraction operator-() const;

  friend ostream &operator<<(ostream &os, const Fraction &fraction);

  friend istream &operator>>(istream &is, Fraction &fraction);

private:
  int numerator; // tu so
  int denominator; // mau so

  void initialize(int numerator, int denominator);

  static int gcd(int a, int b);
};


#endif //BAITAPOOP02_FRACTION_H
