#include <iostream>
using namespace std;

class Shape{
public:
    virtual void area() = 0;
    virtual void draw() = 0;
};

class Circle : public Shape{
private:
    float radius;

public:
    Circle(float r){
        radius = r;
    }

    void area() override{
        cout << "Area of Circle: " << 3.14 * radius * radius << endl;
    }

    void draw() override{
        cout << "Drawing Circle" << endl;
    }
};

class Rectangle : public Shape{
private:
    float length;
    float width;

public:
    Rectangle(float l, float w){
        length = l;
        width = w;
    }

    void area() override{
        cout << "Area of Rectangle: " << length * width << endl;
    }

    void draw() override{
        cout << "Drawing Rectangle" << endl;
    }
};

int main(){
    Circle circle(5);
    Rectangle rectangle(10, 5);

    Shape* shapes[2];

    shapes[0] = &circle;
    shapes[1] = &rectangle;

    cout << "--- Shape Details ---" << endl;

    for (int i = 0; i < 2; i++){
        shapes[i]->area();
        shapes[i]->draw();
        cout << endl;
    }
    return 0;
}