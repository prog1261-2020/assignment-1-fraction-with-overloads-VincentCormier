/*Name: Vincent Cormier
Date: 2020-01-18
Purpose: Today we redefine operators to suite our Fraction class!*/

#pragma once
#include <iostream>
#include <cstdlib>
#include <cmath>

class Fraction
{
public:
	Fraction();
	Fraction(int n);
	Fraction(int n, int d);

	int lcd(int x, int y);
	void reduce();

	Fraction operator+(const Fraction& rhs) const;
	friend Fraction operator+(const int& lhs, const Fraction& rhs);
	friend Fraction operator+(const Fraction& lhs, const int& rhs);
	
	Fraction& operator+=(Fraction& rhs);
	friend Fraction& operator+=(Fraction& lhs, const int& rhs);
	friend Fraction& operator+=(int& lhs, const Fraction& rhs);
	
	Fraction operator-(const Fraction& rhs) const;
	friend Fraction operator-(const Fraction& lhs, const int& rhs);
	friend Fraction operator-(const int& lhs, const Fraction& rhs);
	
	Fraction& operator-=(Fraction& rhs);
	friend Fraction& operator-=(int& lhs, const Fraction& rhs);
	friend Fraction& operator-=(Fraction& lhs, const int& rhs);
	
	Fraction operator*(const Fraction& rhs) const;
	friend Fraction operator*(const Fraction& lhs, const int& rhs);
	friend Fraction operator*(const int& lhs, const Fraction& rhs);

	Fraction& operator*=(Fraction& rhs);
	friend Fraction& operator*=(Fraction& lhs, const int& rhs);
	friend Fraction& operator*=(int& lhs, const Fraction& rhs);

	Fraction operator/(const Fraction& rhs) const;
	friend Fraction operator/(const Fraction& lhs, const int& rhs);
	friend Fraction operator/(const int& lhs, const Fraction& rhs);

	Fraction& operator/=(Fraction& rhs) ;
	friend Fraction operator/=(Fraction& lhs, const int& rhs);
	friend Fraction operator/=(int& lhs, const Fraction& rhs);

	bool operator==(const Fraction& rhs) const;
	bool operator!=(const Fraction& rhs) const;

	bool operator<(const Fraction& rhs) const;
	friend bool operator<(const int& lhs, const Fraction& rhs);
	friend bool operator<(const Fraction& lhs, const int& rhs);

	bool operator<=(const Fraction& rhs) const;
	friend bool operator<=(const Fraction& lhs, const int& rhs);
	friend bool operator<=(const int& lhs, const Fraction& rhs);

	bool operator>(const Fraction& rhs) const;
	friend bool operator>(const Fraction& lhs, const int& rhs);
	friend bool operator>(const int& lhs, const Fraction& rhs);

	bool operator>=(const Fraction& rhs) const;
	friend bool operator>=(const Fraction& lhs, const int& rhs);
	friend bool operator>=(const int& lhs, const Fraction& rhs);

	friend std::ostream& operator<<(std::ostream& os, const Fraction& rhs);
	friend std::istream& operator>>(std::istream& is, Fraction& rhs);

private:
	int numerator_;
	int denominator_;
};

