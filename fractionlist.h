//
// Created by Peter Hoc on 10/22/2018.
//

#ifndef BAITAPOOP02_FRACTIONLIST_H
#define BAITAPOOP02_FRACTIONLIST_H

#include <ostream>
#include "fraction.h"

class FractionList {
 private:
  Fraction *array;
  size_t n;

  static Fraction *allocArray(int n);

  static void freeArray(Fraction *a);

  void freeAndAllocArray(size_t n);

  void checkIndex(size_t idx) const;

 public:
  explicit FractionList(size_t n = 0);

  FractionList(const FractionList &other);

  virtual ~FractionList();

  Fraction &operator[](std::size_t idx);

  const Fraction &operator[](std::size_t idx) const;

  friend istream &operator>>(istream &is, FractionList &list);

  friend ostream &operator<<(ostream &os, const FractionList &list);

  FractionList &operator=(const FractionList &rhs);

  bool operator==(const FractionList &rhs) const;

  bool operator!=(const FractionList &rhs) const;
};


#endif //BAITAPOOP02_FRACTIONLIST_H
