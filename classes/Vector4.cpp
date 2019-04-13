#include "Vector.hpp"

namespace SL {

template <typename T>
Vector4<T>::Vector4(T x, T y, T z, T w) : Vector_base<T, 4>{}
{
	this->_coords[0] = x;
	this->_coords[1] = y;
	this->_coords[2] = z;
	this->_coords[3] = w;
}

template <typename T>
Vector4<T>::Vector4(const Vector4<T> &rh)
{
	*this = rh;
}

template <typename T>
void Vector4<T>::operator=(const Vector4<T> &rh) {
	if (&rh != this) {
		this->_coords[0] = rh[0];
		this->_coords[1] = rh[1];
		this->_coords[2] = rh[2];
		this->_coords[3] = rh[3];
	}
}


template <typename T>
Vector4<T> Vector4<T>::operator+(const Vector4<T> &rh) const {

	Vector4<T> v{*this};

	return (v += rh);
}

template <typename T>
Vector4<T> Vector4<T>::operator-(const Vector4<T> &rh) const {

	Vector4<T> v{*this};

	return (v -= rh);
}

template <typename T>
Vector4<T> Vector4<T>::operator*(const int k) const {

	Vector4<T> v{*this};

	return (v *= k);
}

template <typename T>
bool Vector4<T>::operator==(const Vector4<T> &rh) {
	return (this->_coords[0] == rh._coords[0] &&
			this->_coords[1] == rh._coords[1] &&
			this->_coords[2] == rh._coords[2] &&
			this->_coords[3] == rh._coords[3]);
}

template <typename T>
Vector4<T>&	Vector4<T>::operator+=(const Vector4<T> &rh) {
	this->_coords[0] += rh._coords[0];
	this->_coords[1] += rh._coords[1];
	this->_coords[2] += rh._coords[2];
	this->_coords[3] += rh._coords[3];

	return (*this);
}

template <typename T>
Vector4<T>&	Vector4<T>::operator-=(const Vector4<T> &rh) {
	this->_coords[0] -= rh._coords[0];
	this->_coords[1] -= rh._coords[1];
	this->_coords[2] -= rh._coords[2];
	this->_coords[3] -= rh._coords[3];

	return (*this);
}

template <typename T>
Vector4<T>&	Vector4<T>::operator*=(const int k) {
	this->_coords[0] *= k;
	this->_coords[1] *= k;
	this->_coords[2] *= k;
	this->_coords[3] *= k;

	return (*this);
}



}