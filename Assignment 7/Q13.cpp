#include <iostream>
#include <cmath>
using namespace std;

class Cartesian;

class Polar {
    float r, theta; // theta in radians
public:
    Polar(float radius = 0, float angle = 0) : r(radius), theta(angle) {}
    float getR() { return r; }
    float getTheta() { return theta; }
    friend class Cartesian;
};

class Cartesian {
    float x, y;
public:
    Cartesian() {}
    Cartesian(Polar p) {
        x = p.r * cos(p.theta);
        y = p.r * sin(p.theta);
    }
    void show() {
        cout << "x = " << x << ", y = " << y << endl;
    }
};

int main() {
    Polar p(10, 0.785);  // 45 degrees in radians (~π/4)
    Cartesian c = p;
    c.show();
    return 0;
}
