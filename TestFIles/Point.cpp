#include <iostream>
#include "Point.h"

Point::getX(){
    return x;
}
Point::getY(){
    return y;
}
Point::Point(){
    x = 0;
    y = 0;
}
Point::Point(int X,int Y){
    x = X;
    y = Y;
}
Point::Print(){
    cout<<x << "\t"<<y<<'\n';
}