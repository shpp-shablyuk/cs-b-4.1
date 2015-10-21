/*
 * File: Sierpinski.cpp
 * ----------------------
 */

#include <iostream>
#include "gwindow.h"
#include <cmath>
using namespace std;

const double SIZE = 200;
const int ORDER = 5;

GPoint drawFractalLine(GWindow & gw, GPoint pt, double r, double theta, int order);

int main() {
    GWindow gw;

    double cx = gw.getWidth() / 2;
    double cy = gw.getHeight() / 2;
    GPoint pt(cx - SIZE / 2, cy + sqrt(3.0) * SIZE / 4);
    pt = drawFractalLine(gw, pt, SIZE, 60, ORDER);
    pt = drawFractalLine(gw, pt, SIZE, -60, ORDER);
    pt = drawFractalLine(gw, pt, SIZE, 180, ORDER);

	return 0;
}

GPoint drawFractalLine(GWindow & gw, GPoint pt, double r, double theta, int order) {
//    pause(50);
    if (order == 0) {
        return gw.drawPolarLine(pt, r, theta);
    } else {
        r = r / 2;
        pt = drawFractalLine(gw, pt, r, theta, order - 1);
        drawFractalLine(gw, pt, r, theta - 120, order - 1);
        return drawFractalLine(gw, pt, r, theta, order - 1);
    }
}
