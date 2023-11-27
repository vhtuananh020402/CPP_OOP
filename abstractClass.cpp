#include <iostream>

using namespace std;

class Shape {
    private: 
        double height;
        double width;

    public:
        Shape() {};
        Shape(double height, double width) {
            this->height    = height;
            this->width     = width;
        }
        
        virtual double getArea() {
            return (double)height * (double)width;
        }

};


class Triangle : public Shape {
    
};


class Rectangle {

};

int main(){
    
}