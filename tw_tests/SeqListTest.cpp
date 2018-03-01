
#include "SeqList.hpp"

int main()
{
	PolyList p1;
	float f1[] = { 7.0f,3.0f,9.1f,5.0f };
	int e1[] = { 0,1,8,17 };
	initPoly(p1, f1, e1, sizeof(e1) / sizeof(int));
	printPolyn(p1);

	destroyPolyn(p1);


	system("pause");
	return 0;
}