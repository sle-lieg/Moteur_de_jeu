#include "Vector.hpp"

namespace SL {


template <typename T, int len>
T& Vector_base<T, len>::operator[] (int index) {
	assert((index >= 0 && index < len) && "Vector<T, len> operator[] argument invalid.");

	return _coords[index];
}

template <typename T, int len>
const T& Vector_base<T, len>::operator[] (int index) const {
	assert((index >= 0 && index < len) && "Vector<T, len> operator[] argument invalid.");

	return _coords[index];
}

}
