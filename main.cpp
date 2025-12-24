import graphics;
import std;

using std::print;
using std::vector;

using std::make_unique;
using std::unique_ptr;

void resizeShapes(vector<unique_ptr<Shape>> &vs, double r)
{ // vs是一个多态指针变量unique_ptr<Shape>的数组，管理了一组Shape的子类堆对象
    for(auto&& s : vs)
        s->resize(r);  // 针对接口类的编程：多态调用-抽象操作可以动态绑定到各个子类的覆盖方法，代码稳定有弹性
}

int main()
{
    Point p(1.0, 1.0);
    print("-------------针对实现类的编程，子类引用变量调用抽象操作，只能绑定到单个子类的覆盖方法------------\n");
    auto pc = make_unique<Circle>(p, 5.0);
    pc->resize(2); // 针对实现类的编程

    auto pr = make_unique<Rectangle>(p, 5.0, 5.0);
    pr->resize(2); // 针对实现类的编程

    print("-------------针对接口类的编程，基类引用变量调用抽象操作，可动态绑定到各个子类的覆盖方法----------\n");
    vector<unique_ptr<Shape>> vs;
    vs.push_back(std::move(pc));
    vs.push_back(std::move(pr));
    resizeShapes(vs, 2);  // 调用resize()，遍历所有Shape指针，触发多态调用

    return 0;
}


// void resizeShapes(vector<uniuqe_ptr<Circle>> &vc, vector<std::unique_ptr<Rectangle>> &vr)
// {
//     for (auto& c : vc){
//         c->resize(2);
//     }

// }
