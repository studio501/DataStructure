
#include "BitTree.hpp"

int main()
{
	BiTree T1;
	ElemType arr[] = { 1,2,3,EmptyData,EmptyData,4,5,EmptyData,6,EmptyData,EmptyData,7,EmptyData,EmptyData,EmptyData };
	ElemType *p = &arr[0];
	int arrLen = sizeof(arr) / sizeof(ElemType);
	createBiTree(T1, p, (p + arrLen) );

	inOrederTraverse(T1, [&](ElemType e) {std::cout << e; });
	std::cout << std::endl;

	preOrderTraverse(T1, [&](ElemType e) {std::cout << e; });
	std::cout << std::endl;

	postOrderTraverse(T1, [&](ElemType e) {std::cout << e; });
	std::cout << std::endl;

	system("pause");
	return 0;
}