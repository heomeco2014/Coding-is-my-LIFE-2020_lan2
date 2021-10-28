#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
#include <stack>
#include <string.h>
#include <string>
#include <vector>
using namespace std;

struct point {
    double x, y;
};

struct Triangle {
    point x, y, z;
};

double calcDistanceBetween2Points(point p1, point p2) {
    return sqrt((pow(p2.x - p1.x, 2)) + (pow(p2.y - p1.y, 2)));
}

class CPoint {
    struct Point {
        double x, y, z;
    };

    double calDistance(Point p1, Point p2) {
        return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
    }
};



int main() {
     
}