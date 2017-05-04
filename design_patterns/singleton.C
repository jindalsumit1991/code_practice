#include <iostream>

using namespace std;

class A
{
    static A *A_ptr;
    A(){}

    public:
    static A *instance()
    {
        if(!A_ptr)
            A_ptr = new A();
        return A_ptr;
    }

    static A &getInstance()
    {
        static A instance;
        return instance;
    }

    ~A()
    {
        cout << "Destructor called" << endl;
    }

    void print()
    {
        cout << "inside print()" <<endl;
    }

    void reset()
    {
        if(A_ptr)
        {
            delete A_ptr;
            A_ptr = NULL;
        }
    }
};

A* A::A_ptr = 0;

int main()
{
    //A::instance()->print();
    A::getInstance().print();
    //A::instance()->reset();
    return 0;
}
