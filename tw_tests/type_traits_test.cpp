#include "type_traits.hpp"

#include <iostream>

class A
{
public:
	A()
	{
		std::cout << "A()" << std::endl;
	}

	A(const A &other)
	{
		std::cout<<
	}
	~A()
	{
		std::cout << "~A()" << std::endl;
	}

private:

};

int main(void)
{

	system("pause");
	return 0;
}