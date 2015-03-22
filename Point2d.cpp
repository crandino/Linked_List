#include <math.h>
#include "point2d.h"

Point2d Point2d::operator+ (const Point2d &p) const
{
	Point2d tmp;
	tmp.x = x + p.x;
	tmp.y = y + p.y;
	return tmp;
}

Point2d Point2d::operator- (const Point2d &p) const
{
	Point2d tmp;
	tmp.x = x - p.x;
	tmp.y = y - p.y;
	return tmp;
}

const Point2d& Point2d::operator+= (const Point2d &p)
{
	x += p.x;
	y += p.y;
	return (*this);
}

const Point2d& Point2d::operator-= (const Point2d &p)
{
	x -= p.x;
	y -= p.y;
	return (*this);
}

bool Point2d::operator== (const Point2d &p) const
{
	return (x == p.x && y == p.y);
}

bool Point2d::operator!= (const Point2d &p) const
{
	return (x != p.x || y != p.y);
}

bool Point2d::isBothZero() const
{
	return (x == 0.0f && y == 0.0f);
}

void Point2d::setZero()
{
	x = y = 0.0f;
}

float Point2d::distanceTo(const Point2d &p) const
{
	return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));
}