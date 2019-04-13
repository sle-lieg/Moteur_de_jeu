#include "Vector.hpp"

namespace SL {

template <typename T>
Vector3<T>::Vector3(T x, T y, T z) : Vector_base<T, 3>{}
{
	std::cout << "Vector3 constructor" << std::endl;
	this->_coords[0] = x;
	this->_coords[1] = y;
	this->_coords[2] = z;
}

template <typename T>
Vector3<T>::Vector3(const Vector3<T> &rh)
{
	*this = rh;
}

template <typename T>
void Vector3<T>::operator=(const Vector3<T> &rh) {
	if (&rh != this) {
		this->_coords[0] = rh[0];
		this->_coords[1] = rh[1];
		this->_coords[2] = rh[2];
	}
}

template <typename T>
Vector3<T> Vector3<T>::operator+(const Vector3<T> &rh) const {

	Vector3<T> v{*this};

	return (v += rh);
}

template <typename T>
Vector3<T> Vector3<T>::operator-(const Vector3<T> &rh) const {

	Vector3<T> v{*this};

	return (v -= rh);
}

template <typename T>
Vector3<T> Vector3<T>::operator*(const int k) const {

	Vector3<T> v{*this};

	return (v *= k);
}

template <typename T>
bool Vector3<T>::operator==(const Vector3<T> &rh) {
	return (
		this->_coords[0] == rh._coords[0] &&
		this->_coords[1] == rh._coords[1] &&
		this->_coords[2] == rh._coords[2]
	);
}

template <typename T>
Vector3<T>&	Vector3<T>::operator+=(const Vector3<T> &rh) {
	this->_coords[0] += rh._coords[0];
	this->_coords[1] += rh._coords[1];
	this->_coords[2] += rh._coords[2];

	return (*this);
}

template <typename T>
Vector3<T>&	Vector3<T>::operator-=(const Vector3<T> &rh) {
	this->_coords[0] -= rh._coords[0];
	this->_coords[1] -= rh._coords[1];
	this->_coords[2] -= rh._coords[2];

	return (*this);
}

template <typename T>
Vector3<T>&	Vector3<T>::operator*=(const int k) {
	this->_coords[0] *= k;
	this->_coords[1] *= k;
	this->_coords[2] *= k;

	return (*this);
}

}