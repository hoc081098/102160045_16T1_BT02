//
// Created by Peter Hoc on 10/18/2018.
//

#ifndef BAITAPOOP02_FRACTION_H
#define BAITAPOOP02_FRACTION_H

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cmath>

using namespace std;

class Fraction {
 private:
  int numerator;    // tu so
  int denominator;  // mau so

  void initialize(int numerator, int denominator);

  void increment();

  void decrement();

  static int gcd(int a, int b);

  static int int_pow(int base, std::size_t exp);

 public:
  explicit Fraction(int numerator = 0, int denominator = 1);

  explicit Fraction(const std::string &s); // take string parameter of the form of "numerator/denominator" or "numerator"

  int get_numerator() const;

  void set_numerator(int numerator);

  int get_denominator() const;

  void set_denominator(int denominator);

  Fraction &operator+=(const Fraction &rhs);

  Fraction &operator-=(const Fraction &rhs);

  Fraction &operator*=(const Fraction &rhs);

  Fraction &operator/=(const Fraction &rhs);

  friend Fraction operator+(Fraction lhs, const Fraction &rhs);

  friend Fraction operator+(Fraction lhs, const int &rhs);

  friend Fraction operator-(Fraction lhs, const Fraction &rhs);

  friend Fraction operator-(Fraction lhs, const int &rhs);

  friend Fraction operator*(Fraction lhs, const Fraction &rhs);

  friend Fraction operator*(Fraction lhs, const int &rhs);

  friend Fraction operator/(Fraction lhs, const Fraction &rhs);

  friend Fraction operator/(Fraction lhs, const int &rhs);

  bool operator<(const Fraction &rhs) const;

  bool operator>(const Fraction &rhs) const;

  bool operator<=(const Fraction &rhs) const;

  bool operator>=(const Fraction &rhs) const;

  bool operator==(const Fraction &rhs) const;

  bool operator!=(const Fraction &rhs) const;

  Fraction operator-() const;

  Fraction &operator++();

  const Fraction operator++(int);

  Fraction &operator--();

  const Fraction operator--(int);

  friend ostream &operator<<(ostream &os, const Fraction &fraction);

  friend istream &operator>>(istream &is, Fraction &fraction);

  static void *operator new(std::size_t sz);

  static void *operator new[](std::size_t sz);

  static void operator delete(void *ptr, std::size_t sz);

  static void operator delete[](void *ptr, std::size_t sz);

  int &operator[](std::size_t idx);

  const int &operator[](std::size_t idx) const;

  void operator()();

  void operator,(const Fraction &other);

  Fraction operator^(int n) const;

  Fraction &operator^=(int n);

  Fraction operator<<(std::size_t pos) const;

  Fraction &operator<<=(std::size_t pos);

  Fraction operator>>(std::size_t pos) const;

  Fraction &operator>>=(std::size_t pos);
};


#endif //BAITAPOOP02_FRACTION_H
