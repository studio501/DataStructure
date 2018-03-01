#ifdef _MSC_VER
#pragma once
#endif // _MSC_VER

#ifndef __COMMON__HPP__
#define __COMMON__HPP__

#include <stdlib.h>
#include <iostream>

#define NS_BEGIN(ns) namespace ns{

#define NS_END(ns) };

#define BEGIN_TW NS_BEGIN(tw)
#define END_TW NS_END(tw)

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;


#define DECLEAR_FOR_EACH_PRIMARYTYPE(macro,...)	\
macro(char,__VA_ARGS__);						\
macro(signed char,__VA_ARGS__);					\
macro(unsigned char,__VA_ARGS__);				\
macro(wchar_t,__VA_ARGS__);						\
macro(short,__VA_ARGS__);						\
macro(unsigned short,__VA_ARGS__);				\
macro(int,__VA_ARGS__);							\
macro(unsigned int,__VA_ARGS__);				\
macro(long,__VA_ARGS__);						\
macro(unsigned long,__VA_ARGS__);				\
macro(long long,__VA_ARGS__);					\
macro(unsigned long long,__VA_ARGS__);			\
macro(float,__VA_ARGS__);						\
macro(double,__VA_ARGS__);						\

#endif