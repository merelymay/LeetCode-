#include "vector"
#include "iostream"
using namespace std;

class A {
public:
    A(){
        cout << "construct" << endl;
        ptr_ = new int(100);
    }

    A(const A &a) {
        cout << "copy construct" << endl;
        ptr_ = new int();
        memcpy(ptr_, a.ptr_, sizeof(int));
    }

    ~A() {
        cout << "deconstruct" << endl;
        if (ptr_) {
            delete ptr_;
        }
    }

    A& operator=(const A &a) {
        cout << "operator =" << endl;
        return *this;
    }

    int * getVal(){
        return ptr_;
    }

    A(A &&a) {
        cout << "move construct" << endl;
        ptr_ = a.ptr_;
        a.ptr_ = nullptr;
    }
private:
    int *ptr_;
};

int main() {
    vector<A> vec;
    vec.push_back(move(A()));
    return 0;
}
