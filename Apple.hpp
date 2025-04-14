#ifndef APPLE_HPP
#define APPLE_HPP

#include "raylib.h"

class Apple {
    public:
        Apple(const Vector2 centre, const int size, const int grid_size);
        void move();
        void draw();
        Vector2 getPosition();
    
    private:
        const Vector2 centre;
        Vector2 position;
        const int size;
        const int speed;
        const int grid_size;
        const Color color;
};

#endif // APPLE_HPP