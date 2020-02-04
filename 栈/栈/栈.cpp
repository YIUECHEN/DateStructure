#include<stdlib.h>
#include<assert.h>
typedef struct Stack{
	int array[100];
    int top;
}Stack;
void StackInit(Stack* s)
{
     s->top =0;
}
void StackDestory(Stack* s)
{
     free(s);
}
 
void StackPush(Stack* s, int val)
{
     s->array[s->top++];
}

int StackPop(Stack* s)
{
    assert(s->top>0);

	return s->array[--s->top];
	//return s->array[s->top-1];
}

int StackEmpty(Stack* s)
{
    return s->top==0?1:0;
}

int StackSize(Stack* s)
{
	return s->top;
}
 



