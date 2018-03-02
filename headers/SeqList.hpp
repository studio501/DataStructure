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

Status unattachOneItem(p_node p)
{
	p->prev->next = p->next;
	p->next->prev = p->prev;
	return OK;
}

Status attachOneItem(p_node p, p_node pos)
{
	p->next = pos->next;
	pos->next = p;

	p->prev = p->next->prev;
	p->next->prev = p;

	return OK;
}

Status delOneItem(p_node &pos)
{
	unattachOneItem(pos);
	free(pos);
	pos = NULL;
	return OK;
}

Status locateExp(PolyList L, int exp,p_node &locate_p)
{
	p_node p = L.head;
	while (p->next != L.head)
	{
		p = p->next;
		if (p->exp == exp)
		{
			locate_p = p;
			break;
		}
	}
	return OK;
}

Status clonePoly(PolyList L, PolyList &L_dist)
{
	L_dist.head = (PolyNode*)malloc(sizeof(PolyNode));
	L_dist.head->next = L_dist.head;
	L_dist.head->prev = L_dist.head;

	p_node p = L.head;

	p_node tp = L_dist.head;

	while (p->next != L.head)
	{
		p = p->next;
		p_node pc = (PolyNode*)malloc(sizeof(PolyNode));
		
		pc->coe = p->coe;
		pc->exp = p->exp;

		tp->next = pc;
		pc->prev = tp;

		pc->next = L_dist.head;
		L_dist.head->prev = pc;

		tp = pc;
	}

	return OK;
}

Status multiOneItem(PolyList &L, p_node pItem)
{
	p_node p = L.head;
	while (p->next != L.head)
	{
		p = p->next;
		p->coe *= pItem->coe;
		p->exp += pItem->exp;
	}
	return OK;
}

Status locateExpProximity(PolyList L, int exp, p_node &proPos)
{
	p_node p = L.head;
	while (p->next != L.head)
	{
		p = p->next;
		if (p->exp > exp)
		{
			proPos = p->prev;
			break;
		}

		if (p->next == L.head)
		{
			proPos = p;
		}
	}

	return OK;
}

Status addPolyn(PolyList &pa, PolyList &pbOri)
{
	PolyList pb;
	clonePoly(pbOri,pb);

	p_node paH = pa.head;

	p_node pbH = pb.head;

	while (pbH->next != pbH)
	{
		p_node pb1 = pbH->next;
		unattachOneItem(pb1);

		p_node findp = NULL;
		locateExp(pa, pb1->exp, findp);
		if (findp) {
			findp->coe += pb1->coe;
			if (findp->coe == 0) {
				delOneItem(findp);
			}

			delOneItem(pb1);
		}
		else {
			locateExpProximity(pa, pb1->exp, findp);
			attachOneItem(pb1, findp);
		}
	}
	destroyPolyn(pb);

	return OK;
}

Status subPolyn(PolyList &pa, PolyList &pb)
{
	PolyList temp;
	p_node p = (PolyNode*)malloc(sizeof( PolyNode));
	p->coe = -1;
	p->exp = 0;
	p->prev = p->next = NULL;

	clonePoly(pb, temp);
	multiOneItem(temp, p);

	addPolyn(pa, temp);

	free(p);
	p = NULL;

	destroyPolyn(temp);

	return OK;
}

Status mulPolyn(PolyList &pa, PolyList &pbOri)
{
	PolyList pb;
	clonePoly(pbOri, pb);

	p_node paH = pa.head;
	p_node pbH = pb.head;

	PolyList oritemp;
	clonePoly(pa, oritemp);

	bool isFirst = false;
	while (pbH->next != pbH) {
		p_node pb1 = pbH->next;
		unattachOneItem(pb1);

		if (!isFirst)
		{
			isFirst = true;
			multiOneItem(pa, pb1);
		}
		else
		{
			PolyList temp;
			clonePoly(oritemp, temp);
			multiOneItem(temp, pb1);
			addPolyn(pa, temp);
			destroyPolyn(temp);
		}
	}
	destroyPolyn(oritemp);
	destroyPolyn(pb);

	return OK;
}


#endif
