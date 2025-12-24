export module graphics:circle;

import :shape;  //子类分区需要导入基类分区
import std;
using std::print;

export class Circle : public Shape
{
public:
    Circle(class Point origin = Point(),
           double r = 0.0);    //构造函数
    virtual ~Circle() override;

    double diameter();         //特有操作

    //抽象操作的覆盖声明，简称覆盖操作
    virtual void resize(double ratio) override;
private:
    double m_radius;           //特有属性
};

Circle::Circle(Point origin, double r):
    Shape(origin), m_radius(r)
{}

Circle::~Circle()
{}

// 抽象操作的Circle覆盖方法
void Circle::resize(double ratio)
{
    print("    ***resizing a Circle: radius = {} "
          "before resize, ", m_radius);
    m_radius *= ratio;
    print("radius = {} after resize.\n", m_radius);
}

double Circle::diameter()        //特定操作的特定方法
{
    return 2 * m_radius;
}
