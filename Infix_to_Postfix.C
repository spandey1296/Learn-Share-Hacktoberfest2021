#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

char stack[20];
int top = -1;


void push(char s)
{
	top++;
	stack[top] = s;
}


char pop()
{
	char p;
	p = stack[top];
	top--;
	return p;
}


int ISP(char c)
{
	if(c == '(')
		return 0;
	if(c == '+' || c == '-')
		return 2;
	if(c == '*' || c == '/')
		return 4;
	if(c == '^')
		return 5;
}


int ICP(char c)
{
	if(c == ')')
		return 0;
	if(c == '(')
		return 9;
	if(c == '+' || c == '-')
		return 1;
	if(c == '*' || c == '/')
		return 3;
	if(c