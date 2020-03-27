#pragma once

class Node
{
private:
    char figure;
    int color;
    int spawn_number;
    int turn_left;
    int turn_right;

public:
    Node()
    {
        this->figure = ' ';
        this->color = this->spawn_number = this->turn_left = this->turn_right = 0;
    }
    Node(char figure, int color, int spawn_number, int turn_left, int turn_right)
    {
        this->figure = figure;
        this->color = color;
        this->spawn_number = spawn_number;
        this->turn_left = turn_left;
        this->turn_right = turn_right;
    }

    int get_figure() { return this->figure; }
    void set_figure(char figure) { this->figure = figure; }
    int get_color() { return this->color; }
    void set_color(int color) { this->color = color; }
    int get_spawn_number() { return this->spawn_number; }
    void set_spawn_number(int spawn_number) { this->spawn_number = spawn_number; }
    int get_turn_left() { return this->turn_left; }
    void set_turn_left(int turn_left) { this->turn_left = turn_left; }
    int get_turn_right() { return this->turn_right; }
    void set_turn_right(int turn_right) { this->turn_right = turn_right; }
};
