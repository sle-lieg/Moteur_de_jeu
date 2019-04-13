#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>

namespace SL {

template <class T, int len>
class Vector_base {
public:
	T&			operator[](int index);
	const T&	operator[](int index) const;

	friend std::ostream& operator<<(std::ostream &out, Vector_base<T, len> &v) {
		out << std::string("[");

		for (int i = 0; i < len; i++) {
			out << v[i];
			if (i < len - 1)
				out << std::string(";");
		}
		out <<  std::string("]");
		return out;
	}

protected:
	T		_coords[len];
};

template <class T>
class Vector2 : public Vector_base<T, 2> {
public:
	Vector2(T x=0, T y=0);
	Vector2(const Vector2<T> &rh);

	void	operator=(const Vector2 &rh);
	Vector2	operator+(const Vector2 &value) const;
	Vector2	operator-(const Vector2 &value) const;
	Vector2	operator*(const int k) const;

	bool		operator==(const Vector2 &rh);
	Vector2&	operator+=(const Vector2 &rh);
	Vector2&	operator-=(const Vector2 &rh);
	Vector2&	operator*=(const int k);

	friend Vector2	operator*(const int k, const Vector2 &lh) {
		Vector2<T>	v{lh};

		return (v *= k);
	};

	friend std::ostream& operator<<(std::ostream& out, const Vector2 &v) {
		out << "[" << v[0] << ";" << v[1] << "]";

		return out;
	}
};

template <class T>
class Vector3 : public Vector_base<T, 3> {
public:
	Vector3(T x=0, T y=0, T z=0);
	Vector3(const Vector3<T> &rh);

	void	operator=(const Vector3 &rh);
	Vector3	operator+(const Vector3 &value) const;
	Vector3	operator-(const Vector3 &value) const;
	Vector3	operator*(const int k) const;

	bool		operator==(const Vector3 &rh);
	Vector3&	operator+=(const Vector3 &rh);
	Vector3&	operator-=(const Vector3 &rh);
	Vector3&	operator*=(const int k);

	friend Vector3	operator*(const int k, const Vector3 &lh) {
		Vector3<T>	v{lh};

		return (v *= k);
	};
};

template <class T>
class Vector4 : public Vector_base<T, 4> {
public:
	Vector4(T x=0, T y=0, T z=0, T w=0);
	Vector4(const Vector4<T> &rh);

	void	operator=(const Vector4 &rh);
	Vector4	operator+(const Vector4 &value) const;
	Vector4	operator-(const Vector4 &value) const;
	Vector4	operator*(const int k) const;

	bool		operator==(const Vector4 &rh);
	Vector4&	operator+=(const Vector4 &rh);
	Vector4&	operator-=(const Vector4 &rh);
	Vector4&	operator*=(const int k);

	friend Vector4	operator*(const int k, const Vector4 &lh) {
		Vector4<T>	v{lh};

		return (v *= k);
	};
};


}

#endif