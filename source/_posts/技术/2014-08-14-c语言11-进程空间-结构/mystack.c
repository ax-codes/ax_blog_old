#include <stdio.h>

//FILO  LIFO

#define N   100

struct Stack
{
    char space[N];
    int top;
};

struct Stack  st = {{0},0};

int isFull()  //Âú·µÕæ
{
    if(st.top == 100)
        return 1;
    else
        return 0;
}

int isEmpty()     //¿Õ·µÕæ
{
    if(st.top == 0)
        return 1;
    else
        return 0;
}

void push(char ch)
{
    st.space[st.top] = ch;
    st.top++;
}

int pop()
{
    st.top--;
    return st.space[st.top];
}

int main(void)
{
    char ch = 'a';
    for(int i=0; i<26; i++)
    {
        if(!isFull())
            push(ch++);
    }

    while(!isEmpty())
        putchar(pop());

    return 0;
}

