#include <iostream>
#include <vector>
#include <cmath>

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

class Polynomial
{
public:
  // equivalent to x
  static const Polynomial x;
  
  // polynomial coefficients, indexes are the x grades
  std::vector<double> coeffs;

  Polynomial();
  Polynomial(const Polynomial& p);
  Polynomial(const double n);
  Polynomial(const std::vector<double> coeffs);
  Polynomial(const std::initializer_list<double> coeffs);
  ~Polynomial();

  /*
    the max exponent

    if you use method grade() in a for loop, you must use i=0; i<= pol.grade().
    to avoid confussions, use size() method in for loops
  */
  int grade() const;

  /*
    cofficients vector size shortcut

    if you use method grade() in a for loop, you must use i=0; i<= pol.grade(); i++
    to avoid confussions, use size() method in for loops
  */
  int size() const;

  /*
    the symbolic derivative of polynomial using definition
  */
  Polynomial derivative() const;
  
  /* 
    the symbolic integral of polynomial using definition
    don't forget to print the " + c" :)
  */
  Polynomial integral() const;

  /*
    returns the numeric value of the cofficients vector, i is the grade of x you want to get coefficient
  */
  double operator [] (const int i) const;
  
  /*
    able to set and get item from coffeicients vector, 
    every positive value is accepted, but be careful, because it creates items to set it to 0
    recomendet to use with existing values or special cases, better to use const version
  */
  double &operator [] (const int i);
  
  /*
    evaluates the polynomial numeric value at x
  */
  double operator () (const double x) const;

  /*
    calculates the division of polynomials and writes it in the reference params
  */
  void writeDivision(const Polynomial& divisor, Polynomial& resultTarget, Polynomial& residualTarget) const;

  /*
    raises the polynomial
    remember. this operator is not always for this operation, but is useful here
  */
  Polynomial operator ^ (int n) const;
  
  /*
    equivalent to multiply by x^n
  */
  Polynomial operator << (const int n) const;

  /*
    equivalent to divide by x^n
  */
  Polynomial operator >> (const int n) const;

  Polynomial operator = (const Polynomial& p);
  Polynomial operator + (const Polynomial& p) const;
  Polynomial operator - (const Polynomial& p) const;
  Polynomial operator * (const Polynomial& p) const;
  Polynomial operator / (const Polynomial& p) const;
  Polynomial operator % (const Polynomial& p) const;
  
  template<class T> Polynomial operator + (const T& x) const { return *this + Polynomial(x); }
  template<class T> Polynomial operator - (const T& x) const { return *this - Polynomial(x); }
  template<class T> Polynomial operator * (const T& x) const { return *this * Polynomial(x); }
  template<class T> Polynomial operator / (const T& x) const { return *this / Polynomial(x); }
  template<class T> Polynomial operator % (const T& x) const { return *this % Polynomial(x); }

  template<class T> Polynomial operator  = (const T& x) { return *this = Polynomial(x); }
  template<class T> Polynomial operator += (const T& x) { return *this = *this + x; }
  template<class T> Polynomial operator -= (const T& x) { return *this = *this - x; }
  template<class T> Polynomial operator *= (const T& x) { return *this = *this * x; }
  template<class T> Polynomial operator /= (const T& x) { return *this = *this / x; }
  template<class T> Polynomial operator %= (const T& x) { return *this = *this % x; }

  Polynomial operator  ^= (const int n) { return *this = *this  ^ n; }
  Polynomial operator <<= (const int n) { return *this = *this << n; }
  Polynomial operator >>= (const int n) { return *this = *this >> n; }

  /*
    calculates the polynomials division limit using l'hopital rule
  */
  static double limit(const Polynomial& numerator, const Polynomial& denominator, const double x);
};

std::ostream &operator <<(std::ostream &cout, const Polynomial& p);

#endif