#include <string>

class MyVector
{
private:
    int size;
    int capacity;
    double* buffer;

    void reserve(int);

public:
    MyVector();
    MyVector(int);
    ~MyVector();
    MyVector(const MyVector&);
    MyVector(MyVector&&);
    MyVector(std::initializer_list<double>);

    double operator[](int) const;
    double& operator[](int);
    const double& at(int) const;
    double& at(int);
    void push_back(double);
    double pop_back();
    MyVector& operator=(const MyVector&);
    MyVector& operator=(MyVector&&);
};

/*
 * index out of range exception
 * */
class out_of_range
{
public:
    std::string get_message()
    {
        return "index out of range\n";
    }
};

/*
 * empty vector exception
 * */
class empty_vector
{
public:
    std::string get_message()
    {
        return "empty vector\n";
    }
};