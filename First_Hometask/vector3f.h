#include <iostream>
#include <math.h>

struct Vector3f
{
    float x;
    float y;
    float z;
};

Vector3f operator+ (const Vector3f& a, const Vector3f& b)
{
    Vector3f result = {a.x + b.x, a.y + b.y, a.z + b.z};
    return result;
}

Vector3f operator- (const Vector3f& a, const Vector3f& b)
{
    Vector3f result = {a.x - b.x, a.y - b.y, a.z - b.z};
    return result;
}

Vector3f operator* (const Vector3f& a, float b)
{
    Vector3f result = {a.x * b, a.y * b, a.z * b};
    return result;
}

Vector3f operator* (float b, const Vector3f& a)
{
    Vector3f result = {a.x * b, a.y * b, a.z * b};
    return result;
}

Vector3f operator/ (const Vector3f& a, float b)
{
    Vector3f result = {a.x / b, a.y / b, a.z / b};
    return result;
}

float operator* (const Vector3f& a, const Vector3f& b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

Vector3f operator- (Vector3f& a)
{
    a = {-a.x, -a.y, -a.z};
    return a;
}

Vector3f operator+ (Vector3f a) 
{
    return a;
}

bool operator== (const Vector3f& a, const Vector3f& b)
{
    if (a.x == b.x && b.y == a.y && a.z == b.z)
        return true;
    else
        return false;
}

bool operator!= (const Vector3f& a, const Vector3f& b)
{
    if (a.x != b.x || a.y != b.y || a.z != b.z)
        return true;
    else
        return false;
}

void operator+= (Vector3f& a, const Vector3f& b)
{
    a.x += b.x;
    a.y += b.y;
    a.z += b.z;
}

void operator-= (Vector3f& a, const Vector3f& b)
{
    a.x -= b.x;
    a.y -= b.y;
    a.z -= b.z;
}

void operator*= (Vector3f& a, const Vector3f& b)
{
    a.x *= b.x;
    a.y *= b.y;
    a.z *= b.z;
}

void operator/= (Vector3f& a, const Vector3f& b)
{
    a.x /= b.x;
    a.y /= b.y;
    a.z /= b.z;
}

void operator*= (Vector3f& a, int b)
{
    a.x *= b;
    a.y *= b;
    a.z *= b;
}

void operator/= (Vector3f& a, int b)
{
    a.x /= b;
    a.y /= b;
    a.z /= b;
}

std::ostream& operator<< (std::ostream& out, const Vector3f& a)
{
    out << '(' << a.x << ", " << a.y << ", " << a.z << ')';
    return out;
}

std::istream& operator>> (std::istream& in, Vector3f& a)
{
    in >> a.x >> a.y >> a.z;
    return in;
}

float squaredNorm (const Vector3f& a)
{
    float result = a.x * a.x + a.y * a.y + a.z * a.z;
    return result;
}

float norm (const Vector3f& a)
{
    float norm = sqrt (a.x * a.x + a.y * a.y + a.z * a.z);
    return norm;
}

void normalize (Vector3f& a)
{
    float coef = norm (a);
    a = {a.x / coef, a.y / coef, a.z / coef};
}
