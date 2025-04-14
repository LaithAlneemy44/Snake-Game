#ifndef SNAKE_HPP
#define SNAKE_HPP

#include "raylib.h"
#include "Body.hpp"
#include "Apple.hpp"
#include "Utils.hpp"
#include <set>
#include <unordered_set>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;
using namespace Utils;
class Snake {
    public:
        Snake(Apple apple, Vector2 position, const int size, const int screen_size);
        void buffer(const int direction);
        void update();
        void move(const int direction);
        void turn();
        void eat();   
        void kill();
        bool living();
        void draw();
        int getDirection();
        bool turned();
        void gameOver();
        
    private:
        Apple apple;
        Vector2 apple_position;
        Vector2 position;
        const int size;
        const int screen_size;
        const int speed;
        bool alive;
        float factor;
        Color color;
        set<Vector2, Vector2Comparator> occupied;
        const unordered_set<int> directions;
        queue<int> q;
        vector<Body> body;
};

#endif // SNAKE_HPP