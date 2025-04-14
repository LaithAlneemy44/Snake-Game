#include "Utils.hpp"

bool Utils::Vector2Comparator::operator()(const Vector2& u, const Vector2& v) const {
    return Utils::operator<(u, v);
}

Vector2 Utils::getCentre(const int screen_size, const int snake_size) {
    float centre = (screen_size - snake_size) / 2;
    return {centre, centre};
} 

bool Utils::opposite(const int a, const int b) {
    if (a == KEY_W && b == KEY_S || a == KEY_S && b == KEY_W) {
        return true;
    }
    
    if (a == KEY_A && b == KEY_D || a == KEY_D && b == KEY_A) {
        return true;
    }
    
    return false;
}

bool Utils::operator==(const Vector2& u, const Vector2& v) {
    return u.x == v.x && u.y == v.y;
}

bool Utils::operator<(const Vector2& u, const Vector2& v) {
    if (u.x != v.x) {
        return u.x < v.x; 
    }
    return u.y < v.y;     
}

