class Circle
{
private:
	Point mCenter;
	float mRadius;

public:
    Circle(const Point& acenter, float aradius);
    
    //!Circle with radius = 1 and center = (0,0)
    Circle ();

    Circle(const Circle& circle);
    
    Point getCenter () const;
    float getRadius () const;
    
    void setCenter (Point center);
    void setRadius (float radius);
    
    float getArea() const;
    
    float getDistance(const Point& p) const;
    
    bool isColliding(const Circle& c) const;
    
    //!Move the circle to the vector p
    void move(const Point& p);
}; 
