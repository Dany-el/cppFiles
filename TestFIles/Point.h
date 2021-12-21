#pragma once

class Point{
    int x;
    int y;
public:
    int getX();
    int getY();
    void Print();
    Point(int X,int Y);
    Point();
    ~Point();
};