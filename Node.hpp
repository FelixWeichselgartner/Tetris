#pragma once
#include <QPainter>

class Node
{
private:
    char figure;
    QColor color;
    int spawn_number;
    int turn_left;
    int turn_right;

public:
    Node()
    {
        this->figure = ' ';
        this->color = QColor(0, 0, 0, 0);
        this->spawn_number = this->turn_left = this->turn_right = 0;
    }
    Node(char figure, QColor color, int spawn_number, int turn_left, int turn_right)
    {
        this->figure = figure;
        this->color = color;
        this->spawn_number = spawn_number;
        this->turn_left = turn_left;
        this->turn_right = turn_right;
    }

    bool is_solid() { return this->figure == 'X'; }
    bool is_moveable() { return this->figure == 'O'; }
    bool is_empty() { return this->figure == ' '; }
    int get_figure() { return this->figure; }
    void set_figure(char figure) { this->figure = figure; }
    QColor get_color() { return this->color; }
    void set_color(QColor color) { this->color = color; }
    int get_spawn_number() { return this->spawn_number; }
    void set_spawn_number(int spawn_number) { this->spawn_number = spawn_number; }
    int get_turn_left() { return this->turn_left; }
    void set_turn_left(int turn_left) { this->turn_left = turn_left; }
    int get_turn_right() { return this->turn_right; }
    void set_turn_right(int turn_right) { this->turn_right = turn_right; }
};
