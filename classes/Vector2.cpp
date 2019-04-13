#include "Vector.hpp"

namespace SL {

template <typename T>
Vector2<T>::Vector2(T x, T y) : Vector_base<T, 2>{}
{
	this->_coords[0] = x;
	this->_coords[1] = y;
}

template <typename T>
Vector2<T>::Vector2(const Vector2<T> &rh)
{
	*this = rh;
}

template <typename T>
void Vector2<T>::operator=(const Vector2<T> &rh) {
	if (&rh != this) {
		this->_coords[0] = rh[0];
		this->_coords[1] = rh[1];
	}
}

template <typename T>
Vector2<T> Vector2<T>::operator+(const Vector2<T> &rh) const {

	Vector2<T> v{*this};

	return (v += rh);
}

template <typename T>
Vector2<T> Vector2<T>::operator-(const Vector2<T> &rh) const {

	Vector2<T> v{*this};

	return (v -= rh);
}

template <typename T>
Vector2<T> Vector2<T>::operator*(const int k) const {

	Vector2<T> v{*this};

	return (v *= k);
}

template <typename T>
bool Vector2<T>::operator==(const Vector2<T> &rh) {
	return (
		this->_coords[0] == rh._coords[0] &&
		this->_coords[1] == rh._coords[1]
	);
}

template <typename T>
Vector2<T>&	Vector2<T>::operator+=(const Vector2<T> &rh) {
	this->_coords[0] += rh._coords[0];
	this->_coords[1] += rh._coords[1];

	return (*this);
}

template <typename T>
Vector2<T>&	Vector2<T>::operator-=(const Vector2<T> &rh) {
	this->_coords[0] -= rh._coords[0];
	this->_coords[1] -= rh._coords[1];

	return (*this);
}

template <typename T>
Vector2<T>&	Vector2<T>::operator*=(const int k) {
	this->_coords[0] *= k;
	this->_coords[1] *= k;

	return (*this);
}


}