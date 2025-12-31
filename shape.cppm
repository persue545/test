// Module partition graphics:shape - define class Point and Shape
// File: shape.cppm   Version: 0.1.0   License: AGPLv3
// Created: Wei Gong   open-src@qq.com   2025-12-21 11:40:58
// Description:
//     Shape is the base class for all graphics classes
//     Every Shape object has a Point object representing its center

//魔改。卡珊德拉asmdl;asmdasm;

export module graphics:shape;

import std;
using std::print;

export class Point
{
public:
    Point(double x = 0.0, double y = 0.0);
    std::string toString();
private:
    double m_x;
    double m_y;
};

export class Shape
{
public:
    Shape(Point o);                       //构造函数声明，通常不会被继承
    Shape(double x, double y);            //重载的构造函数
    virtual ~Shape();

    void move(Point p);                   //普通函数声明，可被继承
    virtual void resize(double ratio) = 0;//泛化子类的"相似操作"为基类"抽象操作"，
                                          //作为子类相似操作的共同接口，可被继承

    virtual void display();               //泛化子类的"共似操作"作为基类"共似接口操作"
                                          //作为子类"共似操作"的共同接口，可被继承
private:
    Point m_origin;                       //属性描述，可被继承
};

Point::Point(double x, double y)
    : m_x (x), m_y (y)
{}

std::string Point::toString()
{
    return std::format("({}, {})", m_x, m_y);
}

Shape::Shape(Point p):m_origin(p){}
Shape::Shape(double x, double y)
    :m_origin(x,y)
{}

Shape::~Shape()
{    print("cleaning in ~Shape()...\n");
}

void Shape::move(Point p)//泛化的方法，被子类继承
{
    print("    moving to a new Point:{} "
          "using Shape::move().\n",p.toString());
    m_origin = p;
}

void Shape::display()
{
    print("origin = {}", m_origin.toString());
}
