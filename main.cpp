#include<iostream>
#include"shared_ptr.h"

class Shape
{
    public:
    ~Shape()
    {
        std::cout << "Calling shape destructor" << '\n';
    }
    void draw()
    {
        std::cout << "In Shape::draw()" << '\n';
    }
};
int main()
{
    mystd::shared_ptr<Shape> sh(new Shape());
    sh->draw();
    {
        mystd::shared_ptr<Shape> p(sh);
        p->draw();
        mystd::shared_ptr<Shape> r;
        r = sh;
        r->draw();
        mystd::shared_ptr<Shape> mp(std::move(sh));
        mp->draw();
        mp = mystd::shared_ptr<Shape>(new Shape());
        mp->draw();
    }
    std::cout << "Out of scope but still destructor not called..." << '\n';
    return 0;
}
