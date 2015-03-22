#ifndef __Point2d_H__
#define __Point2d_H__

class Point2d {

public:

	float x, y;

	// Point2d() {};
	// virtual ~Point2d() {};

	Point2d operator+ (const Point2d &p) const;
	Point2d operator- (const Point2d &p) const;
	const Point2d& operator+= (const Point2d &p);
	const Point2d& operator-= (const Point2d &p);
	bool operator== (const Point2d &p) const;
	bool operator!= (const Point2d &p) const;

	bool isBothZero() const;
	void setZero();
	float distanceTo(const Point2d &p) const;

};

#endif // !__Point2d_H__
