#ifdef _MSC_VER
#pragma once
#endif // _MSC_VER

#ifndef __BITTREE__HPP__
#define __BITTREE__HPP__

#include "Common.hpp"
#include <functional>
typedef int ElemType;
typedef ElemType* ElemTypePointer;
#define EmptyData 0xFFFFFFFF
typedef std::function<void(ElemType)> VisiFunc;

typedef struct BiTNode
{
	ElemType data;
	struct BiTNode * lchild, *rchild;
}BiTNode,*BiTree;

ElemTypePointer createBiTree(BiTree &T, ElemTypePointer p, ElemType *pEnd)
{
	if (p == pEnd) {
		return p;
	}
	ElemType t = *(p++);
	if (t == EmptyData) {
		T = NULL;
	}
	else {
		if (!(T = (BiTNode*)malloc(sizeof(BiTNode))))
			exit(OVERFLOW);

		T->data = t;
		p = createBiTree(T->lchild, p, pEnd);
		p = createBiTree(T->rchild, p, pEnd);
	}
	return p;
}

Status inOrederTraverse(BiTree T, VisiFunc v)
{
	if (T) {
		if (inOrederTraverse(T->lchild, v)) {
			v(T->data);
			if (inOrederTraverse(T->rchild, v)) {
				return OK;
			}else{
				return ERROR;
			}
		}else{
			return ERROR;
		}
	}
	return OK;
}

Status preOrderTraverse(BiTree T, VisiFunc v) {
	if (T) {
		v(T->data);
		if (preOrderTraverse(T->lchild,v)) {
			if (preOrderTraverse(T->rchild,v)) {
				return OK;
			}
			else {
				return ERROR;
			}
		}
		else {
			return ERROR;
		}
	}
	return OK;
}

Status postOrderTraverse(BiTree T, VisiFunc v) {
	if (T) {
		if (postOrderTraverse(T->lchild,v)) {
			if (postOrderTraverse(T->rchild,v)) {
				v(T->data);
				return OK;
			}
			else {
				return ERROR;
			}
		}
		else {
			return ERROR;
		}
	}
	return OK;
}

Status inOrderWithStack(BiTree T, VisiFunc v)
{
	return OK;
}


#endif