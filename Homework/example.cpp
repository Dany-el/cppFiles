#include <iostream>

using std::string, std::cout, std::cin;

class Point{
    int x;
    int y;
public:
    int getX(){
        return x;
    }
    int getY(){
        return y;
    }
    Point(int X,int Y){
        x = X;
        y = Y;
    }
    void print(){
        cout<<"x -> "<<x<<"\ty -> "<<y <<'\n';        
    }
    ~Point(){
    }
};

int main(){
    
    Point* tmp = new Point(5,10);
    tmp->print();

    delete tmp;

    return 0;
}