#ifdef _MSC_VER
#pragma once
#endif // _MSC_VER

#ifndef __SEQLIST__HPP__
#define __SEQLIST__HPP__

#include "Common.hpp"

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef struct  PolyNode
{
	int exp;
	float coe;

	struct PolyNode *next;
	struct PolyNode *prev;
} *p_node;

typedef struct
{
	p_node head;

}PolyList;

Status initPoly(PolyList &L,float coe[],int exp[],int len)
{
	L.head = (PolyNode*)malloc(sizeof(PolyNode));
	L.head->next = L.head;
	L.head->prev = L.head;

	p_node tp = L.head;

	for (int i = 0; i < len; ++i) {
		p_node p = (PolyNode *)malloc(sizeof(PolyNode));
		p->coe = coe[i];
		p->exp = exp[i];

		tp->next = p;
		p->prev = tp;

		p->next = L.head;
		L.head->prev = p;

		tp = p;
	}


	return OK;
}

bool isEmpty(PolyList L) {
	return L.head->next == L.head && L.head->prev == L.head;
}

Status printPolyn(PolyList P)
{
	if (!isEmpty(P)) {
		p_node p = P.head;
		while (p->next != P.head) {
			p = p->next;

			if (p->coe > 0 && p->prev != P.head)
				std::cout << "+";
			std::cout << p->coe << ( (p->exp > 0) ?"x^":"");
			if (p->exp > 0) {
				std::cout << p->exp;
			}
		}
	}
	std::cout << std::endl;
	return OK;
}

Status destroyPolyn(PolyList &P) {
	if (P.head) {
		p_node p = P.head->next;
		while (!isEmpty(P))
		{
			
			p->prev->next = p->next;
			p->next->prev = p->prev;

			free(p);
			p = P.head->next;
		}

		free(P.head);
		P.head = NULL;
	}
	return OK;
}

Status addPolyn(PolyList &pa, PolyList &pb)
{

}




#endif
