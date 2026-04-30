#include "Point.h"

class Point {

private:
    int x;
    int y;
    
public:
    Point(int x_axis, int y_axis) : x(x_axis), y(y_axis) {};

    int X() {
        return x;
    }
    int Y() {
        return y;
    }
};