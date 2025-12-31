import graphics;
import std;

using std::print;

int main()
{
    ///
    /// \brief p
    /////
    /// /
    /// /
    /// /
    /// /
    /// /
    /// /
    /// /
    ///
    Point p(1.0, 1.0);

    Shape *ps = new Circle(p, 1.0);
    print("Point p(1.0, 1.0);\n");
    print("Shape *ps = new Circle(p, 1.0);\n");
    ps->display();     // 多态调用Shape的接口操作display()

    delete ps;
    print("-------------------------------\n");

    ps = new Rectangle(p, 1.0, 1.0);
    print("ps = new Rectangle(p, 1.0, 1.0);\n");
    ps->display();     // 多态调用Shape的接口操作display()

    delete ps;
    print("-------------------------------\n");

    return 0;
}
