#include <iostream>
using namespace std;

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point a, b;
    Rect getRect();
    void printRect(Rect);
    Rect rotateLeft(Point);
} Rect;

Point getPoint() {

}


int main() {

}
