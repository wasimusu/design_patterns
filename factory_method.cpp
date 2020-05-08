/*
 * This demonstrates some of the key concepsts of factory method design pattern.
 * This design pattern is used to create an object without exposing creation
 * logic to the client. It uses polymorphism to achieve that effect.
 * */

#include <bits/stdc++.h>

using namespace std;

/**
 * Shape is a pure abstract which can't be instantiated
 * */
class Shape {
protected:
    int area;
    int perimeter;
public:
    Shape() {
        area = 0;
        perimeter = 0;
    };

    virtual void computeArea() = 0;

    virtual void computePerimeter() = 0;

    int getArea() const {
        return area;
    }

    int getPerimeter() const {
        return perimeter;
    }

};

class Ellipse : public Shape {
protected:
    int major_radius_, minor_radius_;
public:
    Ellipse(const int major_radius, const int minor_radius) : major_radius_(major_radius),
                                                              minor_radius_(minor_radius) {}

    void computeArea() override {
        area = M_PI * major_radius_ * minor_radius_;
    }

    void computePerimeter() override {
        // This is mathematically incorrect for ecclipse. Works for circle.
        perimeter = M_PI * (major_radius_ + minor_radius_);
    }

};

class Circle : public Ellipse {
public:
    Circle(const int radius) : Ellipse(radius, radius) {}

};


class Rectangle : public Shape {
protected:
    int length_, width_;
public:
    Rectangle(const int length, const int width) : length_(length), width_(width) {}

    void computeArea() override {
        area = length_ * width_;
    }

    void computePerimeter() override {
        perimeter = 2 * (length_ + width_);
    }
};

class Square : public Rectangle {
public:
    Square(const int length) : Rectangle(length, length) {}
};

class ShapeFactory {
public:
    ShapeFactory() = default;

    Shape *get_shape(const int type) {
        switch (type) {
            case 0:
                return new Rectangle(3, 4);
                break;
            case 1:
                return new Square(4);
                break;
            case 2:
                return new Ellipse(5, 6);
                break;
            case 3:
                return new Circle(6);
                break;
            default:
                throw invalid_argument("Shape options [0, 3]");
        }
    }

};

using namespace std;


int main() {
    ShapeFactory shapeFactory;

    // Display some random shapes
    Shape *shape_ptr;
    for (int i = 0; i < 10; i++) {
        int shape_type = rand() % 4;
        shape_ptr = shapeFactory.get_shape(shape_type);
        shape_ptr->computeArea();
        shape_ptr->computePerimeter();
        cout << "Area: " << shape_ptr->getArea() << "\tPerimeter: "
             << shape_ptr->getPerimeter() << "\t"
             << typeid(*shape_ptr).name() << endl;
    }


    return 0;
}