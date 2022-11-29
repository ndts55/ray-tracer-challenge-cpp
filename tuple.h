#ifndef INC_07_RAY_TRACER_CHALLENGE_TUPLE_H
#define INC_07_RAY_TRACER_CHALLENGE_TUPLE_H

#include <tuple>

class Tuple {
private:
    std::tuple<double, double, double, double> tuple;
public:
    bool isPoint() { return w() == 1.0; }

    bool isVector() { return w() == 0.0; }

    Tuple(double x, double y, double z, double w) {
        tuple = std::make_tuple(x, y, z, w);
    }

    double x() { return std::get<0>(tuple); }

    double y() { return std::get<1>(tuple); }

    double z() { return std::get<2>(tuple); }

    double w() { return std::get<3>(tuple); }

    bool operator==(const Tuple &other) const {
        return tuple == other.tuple;
    }

    bool operator!=(const Tuple &other) const {
        return tuple != other.tuple;
    }
};

Tuple point(double x, double y, double z) { return {x, y, z, 1.0}; }

Tuple vector(double x, double y, double z) { return {x, y, z, 0.0}; }


#endif //INC_07_RAY_TRACER_CHALLENGE_TUPLE_H
