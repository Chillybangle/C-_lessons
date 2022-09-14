#include "point.h" 
#include "circle.h"
#include <iostream>
#include <cmath>

Circle::Circle(const Point& acenter, float aradius)
{
    mCenter = acenter;
    mRadius = aradius;
}

Circle::Circle ()
{
    mCenter = Point{0, 0};
    mRadius = 1;
}

Circle::Circle(const Circle& circle)
{
    mCenter = circle.mCenter;
    mRadius = circle.mRadius;
}

Point Circle::getCenter () const
{
    return mCenter;
}
float Circle::getRadius () const
{
    return mRadius;
}
    
void Circle::setCenter (Point center)
{
    mCenter = center;
}
void Circle::setRadius (float radius)
{
    if (radius < 0.0)
        mRadius = 0.0;
    else
        mRadius = radius;
}

float Circle::getArea() const
{
    return 3.14 * mRadius * mRadius;
}

float Circle::getDistance(const Point& p) const
{
    float cent_p_dist = mCenter.distance (p);
    return std::abs(cent_p_dist - mRadius);
}

bool Circle::isColliding(const Circle& c) const
{
    if (mCenter.distance(c.mCenter) > (mRadius + c.mRadius))
        return false;
    else
        return true;
}

void Circle::move(const Point& p)
{
    mCenter = mCenter + p;
}
