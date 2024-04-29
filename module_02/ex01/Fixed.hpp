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
	Fixed(const Fixed &rhs);
	Fixed(const int nbr);
	Fixed(const	float nbr);
	Fixed& operator=(const Fixed &rhs);
	~Fixed();

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;

};

std::ostream &operator<<(std::ostream &output, Fixed const &nbr);

#endif
