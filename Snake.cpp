#include "Snake.hpp"
using namespace std;
using namespace Utils;

Snake::Snake(Apple apple, Vector2 position, const int size, const int screen_size) : apple(apple), position(position), size(size), screen_size(screen_size), speed(size + 2), alive(true), color(GREEN), occupied({position}), directions({KEY_W, KEY_A, KEY_S, KEY_D}), q({-1})
{   
    apple_position = apple.getPosition();
}
void Snake::buffer(const int direction) {
    if (directions.count(direction) && !opposite(q.front(), direction)) {
        q.push(direction);
    }
}

void Snake::update() {
    int direction = q.front();
    if (direction == -1) {
        draw();
        return;
    }
    
    Vector2 current_position = position;
    move(direction);
    occupied.insert(position);
    for (auto& cell : body) {
        auto temp = cell.getPosition();
        cell.update(current_position);
        if (position == current_position) {             
            kill();            
        }
        
        current_position = temp;
    }
    
    occupied.erase(current_position);
    if (position == apple_position) {
        eat();     
    }
    
    else if (position.x < size || position.y < size || position.x > screen_size - size - 2 || position.y > screen_size - size - 2) {
        kill();
    }
    
    draw();
}

void Snake::move(const int direction) {
    switch (direction) {
        case (KEY_S):
            position.y += speed;
            break;
            
        case (KEY_W):
            position.y -= speed;
            break;
            
        case (KEY_D):
            position.x += speed;
            break;
            
        case (KEY_A):
            position.x -= speed;
            break;
    }
}

void Snake::turn() {
    q.pop();
    update();
}

void Snake::eat() {
    Vector2 position;
    if (body.empty()) {
        position = this->position;
    }
    
    else {
        position = body.back().getPosition();
    }
    
    body.push_back({position, size, color});
    do {
        apple.move();
        apple_position = apple.getPosition();
    }
    while (occupied.count(apple_position));
}

void Snake::kill() {
    alive = false;
    color = YELLOW;
}

bool Snake::living() {
    return alive;
}

int Snake::getDirection() {
    return q.front();
}

void Snake::draw() {
    DrawRectangleV(position, {size, size}, color);
    for (auto& cell : body) {
        cell.draw();
    }
    
    apple.draw();
    string score = "SCORE: " + to_string(body.size());
    DrawText(score.c_str(), 100, 100, 30, BLUE);
}

bool Snake::turned() {
    return q.size() > 1;
}

void Snake::gameOver() {
    draw();
    DrawText("GAME OVER", 200, 200, 30, RED);
}