#include "Apple.hpp"
#include <iostream>
using namespace std;

Apple::Apple(const Vector2 centre, const int size, const int grid_size) : centre(centre), size(size), speed(size + 2), grid_size(grid_size), color(RED) {
    move();
}


void Apple::move() {
    const int range = (grid_size - 1) / 2;
    const int dx = GetRandomValue(range * -1, range) * speed;
    const int dy = GetRandomValue(range * -1, range) * speed;
    
    position = {centre.x + dx, centre.y + dy};
}

void Apple::draw() {
    DrawRectangleV(position, {size, size}, color);
}

Vector2 Apple::getPosition() {
    return position;
}