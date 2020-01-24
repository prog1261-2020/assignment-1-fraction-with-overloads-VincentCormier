/*Name: Vincent Cormier
Date: 2020-01-18
Purpose: Today we redefine operators to suite our Fraction class!*/
#include "pch.h"
#include "Fraction.h"

//Constructors for fractions, either with no value, one value(forced numerator) and 2 values
Fraction::Fraction()
{
	numerator_ = 1;
	denominator_ = 1;
	reduce();
}

Fraction::Fraction(int n)
{
	numerator_ = n;
	denominator_ = 1;
	reduce();
}

Fraction::Fraction(int n, int d)
{
	numerator_ = n;
	if (d < 0) {
		n *= -1;
		d *= -1;
		denominator_ = d;
		numerator_ = n;
	}
	else if (d == 0) {
		denominator_ = 1;
	}
	else {
		denominator_ = d;
	}
	reduce();
}


//finds lowest common denominator 
void Fraction::reduce() {
	if (numerator_ != 0 && denominator_ != 0) {
		int d = abs(lcd(numerator_, denominator_));
		numerator_ /= d;
		denominator_ /= d;
	}
}
int Fraction::lcd(int x, int y) {     
	if (y == 0)         
		return x;     
	else         
		return lcd(y, x % y); 
}


Fraction Fraction::operator+(const Fraction& rhs) const
{
	Fraction f;
	f.denominator_ = (denominator_ * rhs.denominator_);
	f.numerator_ = ((denominator_ * rhs.numerator_) + (rhs.denominator_ * numerator_));
	f.reduce();
	return f;
}

Fraction operator+(const int& lhs, const Fraction& rhs)
{
	Fraction f;
	f.denominator_ = (1 * rhs.denominator_);
	f.numerator_ = ((lhs * rhs.numerator_) + (rhs.denominator_ * 1));
	f.reduce();
	return f;
}

Fraction operator+(const Fraction& lhs, const int& rhs)
{
	Fraction f;
	f.denominator_ = (1 * lhs.denominator_);
	f.numerator_ = ((rhs * lhs.numerator_) + (lhs.denominator_ * 1));
	f.reduce();
	return f;
}

Fraction& Fraction::operator+=(Fraction& rhs)
{
	*this = *this + rhs;
	reduce();
	return *this;
}

Fraction& operator+=(Fraction& lhs, const int& rhs)
{
	Fraction total;
	total = rhs + lhs;
	total.reduce();
	lhs = total;
	return total;
}

Fraction& operator+=(int& lhs, const Fraction& rhs)
{
	Fraction total;
	total = lhs + rhs;
	total.reduce();
	return total;
}

Fraction Fraction::operator-(const Fraction& rhs) const
{
	Fraction f;
	f.denominator_ = (denominator_ * rhs.denominator_);
	f.numerator_ = ((rhs.denominator_ * numerator_) - (denominator_ * rhs.numerator_));
	f.reduce();
	return f;
}

Fraction operator-(const Fraction& lhs, const int& rhs)
{
	Fraction f;
	f.denominator_ = (1 * lhs.denominator_);
	f.numerator_ = ((1 * lhs.numerator_) - (lhs.denominator_ * rhs));
	f.reduce();
	return f;
}

Fraction operator-(const int& lhs, const Fraction& rhs)
{
	Fraction f;
	f.denominator_ = (1 * rhs.denominator_);
	f.numerator_ = ((lhs * rhs.denominator_) - (rhs.numerator_ * 1));
	f.reduce();
	return f;
}

Fraction& Fraction::operator-=(Fraction& rhs)
{
	*this = *this - rhs;
	reduce();
	return *this;
}

Fraction& operator-=(int& lhs, const Fraction& rhs)
{
	Fraction total;
	total = lhs - rhs;
	total.reduce();
	return total;
}

Fraction& operator-=(Fraction& lhs, const int& rhs)
{
	Fraction total;
	total = lhs - rhs;
	total.reduce();
	lhs = total;
	return total;
}

Fraction Fraction::operator*(const Fraction& rhs) const
{
	Fraction f;
	f.numerator_ = numerator_ * rhs.numerator_;
	f.denominator_ = denominator_ * rhs.denominator_;
	f.reduce();
	return f;
}

Fraction operator*(const Fraction& lhs, const int& rhs)
{
	Fraction f;
	f.numerator_ = lhs.numerator_ * rhs;
	f.denominator_ = lhs.denominator_;
	f.reduce();
	return f;
}

Fraction operator*(const int& lhs, const Fraction& rhs)
{
	Fraction f;
	f.numerator_ = lhs * rhs.numerator_;
	f.denominator_ = rhs.denominator_;
	f.reduce();
	return f;
}

Fraction& Fraction::operator*=(Fraction& rhs)
{
	Fraction total;
	total = *this * rhs;
	total.reduce();
	*this = total;
	return total;
}

Fraction& operator*=(Fraction& lhs, const int& rhs)
{
	Fraction total;
	total = lhs * rhs;
	total.reduce();
	lhs = total;
	return total;
}

Fraction& operator*=(int& lhs, const Fraction& rhs)
{
	Fraction total;
	total = lhs * rhs;
	total.reduce();
	return total;
}

Fraction Fraction::operator/(const Fraction& rhs) const
{
	Fraction f;
	f.numerator_ = numerator_ * rhs.denominator_;
	f.denominator_ = denominator_ * rhs.numerator_;
	f.reduce();
	return f;
}

Fraction operator/(const Fraction& lhs, const int& rhs) 
{
	Fraction f;
	f.numerator_ = lhs.numerator_ * 1;
	f.denominator_ = lhs.denominator_ * rhs;
	f.reduce();
	return f;
}

Fraction operator/(const int& lhs, const Fraction& rhs)
{
	Fraction f;
	f.numerator_ = lhs * rhs.denominator_;
	f.denominator_ = 1 * rhs.numerator_;
	f.reduce();
	return f;
}

Fraction& Fraction::operator/=(Fraction& rhs)
{
	Fraction f;
	f.numerator_ = numerator_ * rhs.denominator_;
	f.denominator_ = denominator_ * rhs.numerator_;
	f.reduce();
	*this = f;
	return f;
}

Fraction operator/=(Fraction& lhs, const int& rhs)
{
	Fraction f;
	f.numerator_ = lhs.numerator_ * 1;
	f.denominator_ = lhs.denominator_ * rhs;
	f.reduce();
	lhs = f;
	return f;
}

Fraction operator/=(int& lhs, const Fraction& rhs)
{
	Fraction f;
	f.numerator_ = lhs * rhs.denominator_;
	f.denominator_ = 1 * rhs.numerator_;
	f.reduce();
	return f;
}

bool Fraction::operator==(const Fraction& rhs) const
{
	if (numerator_ == rhs.numerator_ && denominator_ == rhs.denominator_) {
		return true;
	}
	else {
		return false;
	}
}

bool Fraction::operator!=(const Fraction& rhs) const
{
	if (numerator_ == rhs.numerator_ && denominator_ == rhs.denominator_) {
		return false;
	}
	else {
		return true;
	}
}

bool Fraction::operator<(const Fraction& rhs) const
{
	int check1 = numerator_ * rhs.denominator_;
	int check2 = denominator_ * rhs.numerator_;
	if (check1 < check2) {
		return true;
	}
	else {
		return false;
	}
}



bool operator<(const int& lhs, const Fraction& rhs)
{
	int check1 = lhs * rhs.denominator_;
	int check2 = rhs.numerator_;
	if (check1 < check2) {
		return true;
	}
	else {
		return false;
	}
}

bool operator<(const Fraction& lhs, const int& rhs)
{
	int check1 = lhs.numerator_;
	int check2 = rhs * lhs.denominator_;
	if (check1 < check2) {
		return true;
	}
	else {
		return false;
	}
}

bool Fraction::operator<=(const Fraction& rhs) const
{
	int check1 = numerator_ * rhs.denominator_;
	int check2 = denominator_ * rhs.numerator_;
	if (check1 < check2 || check1 == check2) {
		return true;
	}
	else {
		return false;
	}
}

bool operator<=(const Fraction& lhs, const int& rhs)
{
	int check1 = lhs.numerator_ ;
	int check2 = lhs.denominator_ * rhs;
	if (check1 < check2 || check1 == check2) {
		return true;
	}
	else {
		return false;
	}
}

bool operator<=(const int& lhs, const Fraction& rhs)
{
	int check1 = lhs * rhs.denominator_;
	int check2 = rhs.numerator_;
	if (check1 < check2 || check1 == check2) {
		return true;
	}
	else {
		return false;
	}
}


bool Fraction::operator>(const Fraction& rhs) const
{
	int check1 = numerator_ * rhs.denominator_;
	int check2 = denominator_ * rhs.numerator_;
	if (check1 > check2) {
		return true;
	}
	else {
		return false;
	}
}

bool operator>(const Fraction& lhs, const int& rhs)
{
	int check1 = lhs.numerator_;
	int check2 = rhs * lhs.denominator_;
	if (check1 > check2) {
		return true;
	}
	else {
		return false;
	}
}

bool operator>(const int& lhs, const Fraction& rhs)
{
	int check1 = lhs * rhs.denominator_;
	int check2 = rhs.numerator_;
	if (check1 > check2) {
		return true;
	}
	else {
		return false;
	}
}

bool Fraction::operator>=(const Fraction& rhs) const
{
	int check1 = numerator_ * rhs.denominator_;
	int check2 = denominator_ * rhs.numerator_;
	if (check1 > check2 || check1 == check2) {
		return true;
	}
	else {
		return false;
	}
}

bool operator>=(const Fraction& lhs, const int& rhs)
{
	int check1 = lhs.numerator_;
	int check2 = lhs.denominator_ * rhs;
	if (check1 > check2 || check1 == check2) {
		return true;
	}
	else {
		return false;
	}
}

bool operator>=(const int& lhs, const Fraction& rhs)
{
	int check1 = lhs * rhs.denominator_;
	int check2 = rhs.numerator_;
	if (check1 > check2 || check1 == check2) {
		return true;
	}
	else {
		return false;
	}
}

std::ostream& operator<<(std::ostream& os, const Fraction& rhs)
{
	os << rhs.numerator_ << "/" << rhs.denominator_;
	return os;
}

std::istream& operator>>(std::istream& is, Fraction& rhs)
{
	char f;
	is >> rhs.numerator_ >> f >> rhs.denominator_;
	return is;
}
