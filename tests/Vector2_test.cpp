#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Vec2_test

#include <boost/test/unit_test.hpp>
#include "Vector.hpp"
#include "templates.cpp"


template <typename T>
SL::Vector2<T> make_vector2(T x, T y) {
	SL::Vector2<T> v{x, y};

	return v;
}

constexpr int v1_x = 5;
constexpr int v1_y = 10;
constexpr int v2_x = -5;
constexpr int v2_y = -10;
constexpr float v3_x = 5.5;
constexpr float v3_y = 10.5;
constexpr float v4_x = -5.5;
constexpr float v4_y = -10.5;
constexpr double v5_x = 0.000001;
constexpr double v5_y = 10.13546;
constexpr double v6_x = -0.00001;
constexpr double v6_y = -10.13546;

static SL::Vector2<int> v1{v1_x, v1_y};
static SL::Vector2<int> v2{v2_x, v2_y};

static SL::Vector2<float> v3{v3_x, v3_y};
static SL::Vector2<float> v4{v4_x, v4_y};

static SL::Vector2<double> v5{v5_x, v5_y};
static SL::Vector2<double> v6{v6_x, v6_y};


BOOST_AUTO_TEST_CASE(Vector2_constructor) {

	BOOST_CHECK_EQUAL(v1[0], v1_x);
	BOOST_CHECK_EQUAL(v1[1], v1_y);

	BOOST_CHECK_EQUAL(v2[0], v2_x);
	BOOST_CHECK_EQUAL(v2[1], v2_y);

	BOOST_CHECK_EQUAL(v3[0], v3_x);
	BOOST_CHECK_EQUAL(v3[1], v3_y);

	BOOST_CHECK_EQUAL(v4[0], v4_x);
	BOOST_CHECK_EQUAL(v4[1], v4_y);

	BOOST_CHECK_EQUAL(v5[0], v5_x);
	BOOST_CHECK_EQUAL(v5[1], v5_y);

	BOOST_CHECK_EQUAL(v6[0], v6_x);
	BOOST_CHECK_EQUAL(v6[1], v6_y);
}

BOOST_AUTO_TEST_CASE(Vector2_operator_plus) {
	SL::Vector2<int> _v1{};

	_v1 = v1 + v2;
	BOOST_CHECK_EQUAL(_v1[0], v1_x + v2_x);
	BOOST_CHECK_EQUAL(_v1[1], v1_y + v2_y);

	_v1 = _v1 + make_vector2<int>(10, 10);
	BOOST_CHECK_EQUAL(_v1[0], v1_x + v2_x + 10);
	BOOST_CHECK_EQUAL(_v1[1], v1_y + v2_y + 10);

	_v1 += v2;
	BOOST_CHECK_EQUAL(_v1[0], v1_x + v2_x + 10 + v2_x);
	BOOST_CHECK_EQUAL(_v1[1], v1_y + v2_y + 10 + v2_y);
}

BOOST_AUTO_TEST_CASE(Vector2_operator_min) {
	SL::Vector2<int> _v1{};

	_v1 = v1 - v2;
	BOOST_CHECK_EQUAL(_v1[0], v1_x - v2_x);
	BOOST_CHECK_EQUAL(_v1[1], v1_y - v2_y);

	_v1 = _v1 - make_vector2<int>(10, 10);
	BOOST_CHECK_EQUAL(_v1[0], v1_x - v2_x - 10);
	BOOST_CHECK_EQUAL(_v1[1], v1_y - v2_y - 10);

	_v1 -= v2;
	BOOST_CHECK_EQUAL(_v1[0], v1_x - v2_x - 10 - v2_x);
	BOOST_CHECK_EQUAL(_v1[1], v1_y - v2_y - 10 - v2_y);
}

BOOST_AUTO_TEST_CASE(Vector2_operator_mult) {
	SL::Vector2<int> _v1{};

	_v1 = v1 * 3;
	BOOST_CHECK_EQUAL(_v1[0], v1_x * 3);
	BOOST_CHECK_EQUAL(_v1[1], v1_y * 3);

	_v1 *= 2;
	BOOST_CHECK_EQUAL(_v1[0], v1_x * 6);
	BOOST_CHECK_EQUAL(_v1[1], v1_y * 6);
}

BOOST_AUTO_TEST_CASE(Vector2_operator_bool) {
	bool b1 = (v1 == v1);
	BOOST_CHECK_EQUAL(b1, true);

	bool b2 = (v1 == v2);
	BOOST_CHECK_EQUAL(b2, false);

	bool b3 = (v1 == SL::Vector2<int>{v1_x, v1_y});
	BOOST_CHECK_EQUAL(b3, true);
}

BOOST_AUTO_TEST_CASE(Vector2_operator_out) {

	std::cout << v1 << " " << v2 << std::endl;
	std::cout << v3 << " " << v4 << std::endl;
	std::cout << std::fixed << v5 << " " << v6 << std::endl;
}