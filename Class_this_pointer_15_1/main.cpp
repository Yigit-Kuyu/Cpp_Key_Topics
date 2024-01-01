#include <iostream>

/*
Most of the time, you won’t need to explicitly reference the this pointer.
However, if you have a member function that has a parameter with the same name as a data member, you can disambiguate them by using thi

*/


// We use -> to select a member from a pointer to an object. this->m_id is the equivalent of (*this).m_id


struct Something
{
    int data{}; // not using m_ prefix because this is a struct

    void setData(int data)
    {
        this->data = data; // this->data is the member, data is the local parameter
    }
};

int main()
{
    Something m{};
    m.setData(3);

    std::cout << "Hello world! "<< m.data << std::endl;
    return 0;
}



// Related page: https://www.learncpp.com/cpp-tutorial/the-hidden-this-pointer-and-member-function-chaining/
