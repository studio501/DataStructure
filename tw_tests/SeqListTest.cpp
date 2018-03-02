
#include "SeqList.hpp"

int main()
{
	PolyList p1;
	float f1[] = { 7.0f,3.0f,9.1f,5.0f };
	int e1[] = { 0,1,8,17 };
	initPoly(p1, f1, e1, sizeof(e1) / sizeof(int));
	printPolyn(p1);

	PolyList p2;
	float f2[] = { 2.0f,4.0f,-9.1f,5.0f,66.0f };
	int e2[] = { 0,1,8,17,19 };

	initPoly(p2, f2, e2, sizeof(e2) / sizeof(int));
	printPolyn(p2);

	PolyList p11;
	clonePoly(p1, p11);
	std::cout << "p1 + p2" << std::endl;
	addPolyn(p11, p2);
	printPolyn(p11);
	destroyPolyn(p11);

	PolyList p12;
	clonePoly(p1, p12);
	std::cout << "p1 * p2" << std::endl;
	mulPolyn(p12, p2);
	printPolyn(p12);
	destroyPolyn(p12);

	PolyList p13;
	clonePoly(p1, p13);
	std::cout << "p1 - p2" << std::endl;
	subPolyn(p13, p2);
	printPolyn(p13);
	destroyPolyn(p13);

	destroyPolyn(p1);
	destroyPolyn(p2);

	system("pause");
	return 0;
}