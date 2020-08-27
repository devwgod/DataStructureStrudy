/* int형 스택 IntStack (소스) */
#include <stdio.h>
#include <stdlib.h>
#include "IntStack.h"

/*--- 스택 초기화 ---*/
//구조체 포인터와 int하나를 받는다, int는 스택의 크기
int Initialize(IntStack* s, int max)
{
	//구조체 포인터 s가 가르키는 구조체 변수의 ptr을 0으로 초기화
	s->ptr = 0;

	//calloc으로 int크기의 메모리를 max개만큼 할당받고 첫 주소럴 s->stk에 초기화
	if ((s->stk = calloc(max, sizeof(int))) == NULL)
	{
		//초기화 실패
		s->max = 0;
		return -1;
	}
	//초기화 성공시 s의 max값을 인수 max로 초기화
	s->max = max;

	//초기화 성공
	return 0;
}

/*--- 스택에 데이터를 푸시---*/
int Push(IntStack* s, int x)
{
	//스택 포인터가 스택의 맥스보다 클 경우 = 스택이 가득찬 경우
	if (s->ptr >= s->max)
		//에러
		return -1;

	//스택의 공간이 남은 경우
	//스택 첫 요소의 포인터[스택 포인터]의 값을 인수 x로 초기화 이후 스택 포인터 1증가
	s->stk[s->ptr++] = x;
	return 0;
}

/*--- 스택에서 데이터를 팝 ---*/
int Pop(IntStack* s, int* x)
{
	//스택 포인터가 0이하일 때 = 스택이 비어 있을 때
	if (s->ptr <= 0)
		//에러
		return -1;

	//x를 직접참조해서 스택 포인터 값에 -1 한 주소 안에 있는 값으로 초기화
	*x = s->stk[--(s->ptr)];
	return 0;
}

/*--- 스택에서 데이터를 피크 ---*/
int Peek(const IntStack* s, int* x)
{
	if (s->ptr <= 0)
		return -1;
	*x = s->stk[s->ptr - 1];
	return 0;
}

/*--- 스택 비우기 ---*/
void Clear(IntStack* s)
{
	s->ptr = 0;
}

/*--- 스택 용량 ---*/
int Capacity(const IntStack* s)
{
	return s->max;
}

/*--- 스택에 쌓여 있는 데이터 수 ---*/
int Size(const IntStack* s)
{
	return s->ptr;
}

/*--- 스택이 비어 있는가? ---*/
int IsEmpty(const IntStack* s)
{
	return s->ptr <= 0;
}

/*--- 스택은 가득 찼는가? ---*/
int IsFull(const IntStack* s)
{
	return s->ptr >= s->max;
}

/*--- 스택에서 검색 ---*/
int Search(const IntStack* s, int x)
{
	int i;

	for (i = s->ptr - 1; i >= 0; i--)	/* 꼭대기(top) → 바닥(bottom)으로 선형 검색 */
		if (s->stk[i] == x)
			return i;		/* 검색 성공 */
	return -1;				/* 검색 실패 */
}

/*--- 모든 데이터 표시 ---*/
void Print(const IntStack* s)
{
	int i;

	for (i = 0; i < s->ptr; i++)		/* 바닥(bottom) → 꼭대기(top)로 스캔 */
		printf("%d ", s->stk[i]);
	putchar('\n');
}

/*--- 스택 종료 ---*/
void Terminate(IntStack* s)
{
	if (s->stk != NULL)
		free(s->stk);		/* 배열을 삭제 */
	s->max = s->ptr = 0;
}
