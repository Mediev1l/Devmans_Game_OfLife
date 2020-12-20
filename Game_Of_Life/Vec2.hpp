#pragma once

template<typename T>
struct Vec2
{
public:
	T _x;
	T _y;

	Vec2();
	Vec2(T x, T y);
	Vec2(const Vec2& cpy);
	Vec2(Vec2&& move);

	Vec2<T> operator = (const Vec2& cpy);
	Vec2<T> operator = (Vec2 && move);

	void setX(T x);
	void setY(T y);

	T getX();
	T getY();
};

typedef Vec2<char> Vec2c;
typedef Vec2<int> Vec2i;
typedef Vec2<float> Vec2f;
typedef Vec2<double> Vec2d;

template<typename T>
inline Vec2<T>::Vec2()
	: _x(0)
	, _y(0)
{
}

template<typename T>
inline Vec2<T>::Vec2(T x, T y)
	: _x(x)
	, _y(y)
{
}

template<typename T>
inline Vec2<T>::Vec2(const Vec2& cpy)
{
	this->_x = cpy._x;
	this->_y = cpy._y;
}

template<typename T>
inline Vec2<T>::Vec2(Vec2&& move)
{
	this->_x = move._x;
	this->_y = move._y;

	move._x = 0;
	move._y = 0;
}

template<typename T>
inline Vec2<T> Vec2<T>::operator=(const Vec2& cpy)
{
	if (this != &cpy)
	{
		this->_x = cpy._x;
		this->_y = cpy._y;
	}

	return *this;
}

template<typename T>
inline Vec2<T> Vec2<T>::operator=(Vec2&& move)
{
	if (this != &move)
	{
		this->_x = move._x;
		this->_y = move._y;

		move._x = 0;
		move._y = 0;
	}

	return *this;
}

template<typename T>
inline void Vec2<T>::setX(T x)
{
	this->_x = x;
}

template<typename T>
inline void Vec2<T>::setY(T y)
{
	this->_y = y;
}

template<typename T>
inline T Vec2<T>::getX()
{
	return _x;
}

template<typename T>
inline T Vec2<T>::getY()
{
	return _y;
}
