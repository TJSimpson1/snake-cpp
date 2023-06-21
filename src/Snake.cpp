#include "Snake.h"

#include <iterator>

Snake::Snake(COORD pos, int vel)
{
    this->pos = pos;
    this->vel = vel;
    len = 1;
    direction = 'n';

    body.push_back(pos);
}

void Snake::change_dir(char dir) { direction = dir; }

list<COORD> Snake::get_body() { return body; }

void Snake::move_snake()
{
    switch(direction)
    {
        case 'u': pos.Y -= vel; break;
        case 'd': pos.Y += vel; break;
        case 'l': pos.X -= vel; break;
        case 'r': pos.X += vel; break;
    }

    if(pos.X > WIDTH - 2) pos.X = 1;
    if(pos.X < 1) pos.X = WIDTH - 2;
    if(pos.Y > HEIGHT - 2) pos.Y = 1;
    if(pos.Y < 1) pos.Y = HEIGHT - 2;

    body.push_back(pos);
    if(body.size() > len) body.erase(body.begin());
}

COORD Snake::get_pos() { return pos; }

bool Snake::eaten(COORD food_pos)
{
    if(food_pos.X == pos.X && food_pos.Y == pos.Y) return true;
    return false;
}

void Snake::grow() { len++; }

bool Snake::collided()
{
    //if(pos.X < 1 || pos.X > WIDTH-2 || pos.Y < 1 || pos.Y > HEIGHT-2) return true;
    auto it = body.begin();
    for(int i = 0; i < len-1; i++)
    {
        if(pos.X == (*it).X && pos.Y == (*it).Y) return true;
        ++it;
    }
    return false;
}

char Snake::get_dir()
{
    return direction;
}
