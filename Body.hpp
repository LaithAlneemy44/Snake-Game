#include "raylib.h"

class Body {
    public:
        Body(Vector2 position, const int size, Color color);
        void update(const Vector2 new_position);
        void draw();
        Vector2 getPosition();
        
    private:
        Vector2 position;
        const int size;
        const Color color;
};