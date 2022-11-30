#ifndef INC_07_RAY_TRACER_CHALLENGE_TUPLE_H
#define INC_07_RAY_TRACER_CHALLENGE_TUPLE_H

#include <tuple>
#include <cmath>

class Tuple {
private:
    double x,y,z,w;
public:
    bool IsPoint()  const { return w == 1.0; }

    bool IsVector() const { return w == 0.0; }

    Tuple(double x, double y, double z, double w): x(x), y(y), z(z), w(w) {}

    double X() const { return x; }

    double Y() const { return y; }

    double Z() const { return z; }

    double W() const { return w; }

    double Magnitude() const {
        return std::sqrt(x*x + y*y + z*z + w*w);
    }

    Tuple Normalized() const {
        auto magnitude = Magnitude();
        return {x/magnitude,y/magnitude,z/magnitude,w/magnitude};
    }

    bool operator==(const Tuple &other) const {
        return x == other.x && y == other.y && z == other.z && w == other.w;
    }

    bool operator!=(const Tuple &other) const {
        return x != other.x || y != other.y || z != other.z || w != other.w;
    }

    Tuple operator+(const Tuple &other) const {
        return {x + other.x, y + other.y, z + other.z, w + other.w};
    }

    Tuple operator-(const Tuple &other) const {
        return {x - other.x, y - other.y, z - other.z, w - other.w};
    }

    Tuple operator-() const {
        return {-x, -y, -z, -w};
    }

    Tuple operator*(const double& scalar) const {
        return {x*scalar, y*scalar,z*scalar,w*scalar};
    }

    double operator*(const Tuple& other) const {
        return x*other.x + y*other.y + z*other.z + w*other.w;
    }
};

Tuple Point(double x, double y, double z) { return {x, y, z, 1.0}; }

Tuple Vector(double x, double y, double z) { return {x, y, z, 0.0}; }


#endif //INC_07_RAY_TRACER_CHALLENGE_TUPLE_H
