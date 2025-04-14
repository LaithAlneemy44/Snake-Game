#include "Body.hpp"

Body::Body(Vector2 position, const int size, Color color) : position(position), size(size), color(color) {

}

void Body::update(const Vector2 new_position) {
    position = new_position;
}

void Body::draw() {
    DrawRectangleV(position, {size, size}, color);
}

Vector2 Body::getPosition() {
    return position;
}
