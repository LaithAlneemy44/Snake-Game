#ifndef UTILS_HPP
#define UTILS_HPP

#include "raylib.h"

namespace Utils {
    struct Vector2Comparator {
        bool operator()(const Vector2& u, const Vector2& v) const;
    };
    
    Vector2 getCentre(const int screen_size, const int snake_size);
    bool opposite(const int a, const int b);
    bool operator==(const Vector2& u, const Vector2& v);
    bool operator<(const Vector2& u, const Vector2& v);
}

#endif // UTILS_HPP