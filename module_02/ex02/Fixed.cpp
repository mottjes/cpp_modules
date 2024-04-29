#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0)
{
	std::cout << "Default Constructor called" << std::endl;
}

Fixed::Fixed(const int nbr) :_fixedPointValue(nbr << _fractionalBits)
{
	std::cout << "Int Constructor called" << std::endl;
}

Fixed::Fixed(const float nbr) :_fixedPointValue(roundf(nbr * (1 << this->_fractionalBits)))
{
	std::cout << "Float Constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &rhs)
{
	std::cout << "Copy Constructor called" << std::endl;
	this->setRawBits(rhs.getRawBits());
}

Fixed& Fixed::operator=(const Fixed &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_fixedPointValue = rhs.getRawBits();
	return *this;
}

bool Fixed::operator<(const Fixed &rhs) const
{
	return this->_fixedPointValue < rhs._fixedPointValue;
}

bool Fixed::operator>(const Fixed &rhs) const
{
	return this->_fixedPointValue > rhs._fixedPointValue;
}

bool Fixed::operator<=(const Fixed &rhs) const
{
	return this->_fixedPointValue <= rhs._fixedPointValue;
}

bool Fixed::operator>=(const Fixed &rhs) const
{
	return this->_fixedPointValue >= rhs._fixedPointValue;
}

bool Fixed::operator==(const Fixed &rhs) const
{
	return this->_fixedPointValue == rhs._fixedPointValue;
}

bool Fixed::operator!=(const Fixed &rhs) const
{
	return this->_fixedPointValue != rhs._fixedPointValue;
}

Fixed Fixed::operator+(const Fixed &rhs) const
{
	Fixed ret = (this->toFloat() + rhs.toFloat());
	return ret;
}

Fixed Fixed::operator-(const Fixed &rhs) const
{
	Fixed ret = (this->toFloat() - rhs.toFloat());
	return ret;
}

Fixed Fixed::operator*(const Fixed &rhs) const
{
	Fixed ret = (this->toFloat() * rhs.toFloat());
	return ret;
}

Fixed Fixed::operator/(const Fixed &rhs) const
{
	Fixed ret = (this->toFloat() / rhs.toFloat());
	return ret;
}

Fixed& Fixed::operator++()
{
	this->_fixedPointValue++;
	return *this;
}

Fixed& Fixed::operator--()
{
	this->_fixedPointValue--;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	this->_fixedPointValue++;
	return tmp;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	this->_fixedPointValue--;
	return tmp;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	return	this->_fixedPointValue;
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixedPointValue = raw;
}

float	Fixed::toFloat(void) const
{
	return	((float)this->getRawBits() / (1 << this->_fractionalBits));
}

int		Fixed::toInt(void) const
{
	return (this->getRawBits() >> this->_fractionalBits);
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return a;
	return b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return a;
	return b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return a;
	return b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return a;
	return b;
}

std::ostream &operator<<(std::ostream &os, Fixed const &nbr)
{
	return os << nbr.toFloat();
}
