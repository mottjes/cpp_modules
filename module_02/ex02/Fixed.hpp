#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>
#include <string>

class   Fixed
{
private:
	int					_fixedPointValue;
	static const int	_fractionalBits = 8;

public:
    Fixed();
	Fixed(const Fixed &other);
	Fixed(const int nbr);
	Fixed(const	float nbr);
	Fixed& operator=(const Fixed &rhs);
	bool operator<(const Fixed &rhs) const;
	bool operator>(const Fixed &rhs) const;
	bool operator<=(const Fixed &rhs) const;
	bool operator>=(const Fixed &rhs) const;
	bool operator==(const Fixed &rhs) const;
	bool operator!=(const Fixed &rhs) const;
	Fixed operator+(const Fixed &rhs) const;
	Fixed operator-(const Fixed &rhs) const;
	Fixed operator*(const Fixed &rhs) const;
	Fixed operator/(const Fixed &rhs) const;
	Fixed& operator++();
	Fixed& operator--();
	Fixed operator++(int);
	Fixed operator--(int);
	~Fixed();

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;

	static Fixed &min(Fixed &a , Fixed &b);
	static Fixed &max(Fixed &a , Fixed &b);
	static const Fixed &min(const Fixed &a , const Fixed &b);
	static const Fixed &max(const Fixed &a , const Fixed &b);

};

std::ostream &operator<<(std::ostream &output, Fixed const &nbr);

#endif
