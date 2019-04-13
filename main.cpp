#include <iostream>
#include "templates.cpp"
#include "Vector.hpp"

using namespace SL;

int main() {
	Vector2<int> v1{5, 10};
	std::cout << v1 << std::endl;

	Vector2<int> v2{2, 3};
	std::cout << v2 << std::endl;
	v2 = v1;
	std::cout << v2 << std::endl;

	Vector2<int> v3{v1};
	std::cout << v3 << std::endl;

	Vector2<int> v4{};
	std::cout << v4 << " " << v2 << std::endl;

	Vector3<float> v5{4.5, 7.23, 19.3456};
	std::cout << v5 << std::endl;
	
	Vector4<double> v6{12.5, 10., 0.00034, 150.5};
	std::cout << v6 << std::endl;

	Vector4<double> v7{ v6 + v6};
	std::cout << v7 << std::endl;

	Vector4<double> v8{ v6 - Vector4<double>{10., 10., 10., 10.} };
	std::cout << v8 << std::endl;

	Vector4<double> v9{};
	v9 = v7 * 2;
	std::cout << v9 << std::endl;

	Vector4<double> v10{};
	v10 = 2 * v7;
	std::cout << v10 << std::endl;

	return (0);
}