#ifndef SNAKE_H
#define SNAKE_H

#include <windows.h>
#include <vector>
#define WIDTH 50
#define HEIGHT 25

using namespace std;

class Snake
{
    private:
        COORD pos;
        int len;
        int vel;
        char direction;
        vector<COORD> body;

    public:
        Snake(COORD pos, int vel); // constructor
        void change_dir(char dir); // change direction of snake
        void move_snake(); // move snake in current direction
        COORD get_pos(); // get current position of snake
        char get_dir();

        bool eaten(COORD food_pos);

        vector<COORD> get_body();

        void grow();
        bool collided();
};

#endif // SNAKE_H
