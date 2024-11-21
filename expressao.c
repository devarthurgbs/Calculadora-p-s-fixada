#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "expressao.h"

#define MAX 100

typedef struct
{
    float items[MAX];
    int top;
} Stack;

void initStack(Stack *s)
{
    s->top = -1;
}

int isFull(Stack *s)
{
    return s->top == MAX - 1;
}

int isEmpty(Stack *s)
{
    return s->top == -1;
}

void push(Stack *s, float value)
{
    if (!isFull(s))
    {
        s->items[++(s->top)] = value;
    }
}

float pop(Stack *s)
{
    if (!isEmpty(s))
    {
        return s->items[(s->top)--];
    }
    return 0;
}

float evaluatePostfix(char *exp)
{
    Stack s;
    initStack(&s);
    char *token = strtok(exp, " ");

    while (token != NULL)
    {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1])))
        {
            push(&s, atof(token));
        }
        else
        {
            float val1, val2, result;
            switch (token[0])
            {
            case '+':
                val2 = pop(&s);
                val1 = pop(&s);
                result = val1 + val2;
                push(&s, result);
                break;
            case '-':
                val2 = pop(&s);
                val1 = pop(&s);
                result = val1 - val2;
                push(&s, result);
                break;
            case '*':
                val2 = pop(&s);
                val1 = pop(&s);
                result = val1 * val2;
                push(&s, result);
                break;
            case '/':
                val2 = pop(&s);
                val1 = pop(&s);
                result = val1 / val2;
                push(&s, result);
                break;
            case '^':
                val2 = pop(&s);
                val1 = pop(&s);
                result = pow(val1, val2);
                push(&s, result);
                break;
            case 'r': // Raiz quadrada
                val1 = pop(&s);
                result = sqrt(val1);
                push(&s, result);
                break;
            case 's': // Seno
                val1 = pop(&s);
                result = sin(val1);
                push(&s, result);
                break;
            case 'c': // Cosseno
                val1 = pop(&s);
                result = cos(val1);
                push(&s, result);
                break;
            case 't': // Tangente
                val1 = pop(&s);
                result = tan(val1);
                push(&s, result);
                break;
            case 'l': // Logaritmo
                val1 = pop(&s);
                result = log10(val1);
                push(&s, result);
                break;
            default:
                break;
            }
        }
        token = strtok(NULL, " ");
    }
    return pop(&s);
}

float getValor(char *Str)
{
    return evaluatePostfix(Str);
}

char *getFormaInFixa(char *Str)
{
    // Implementa��o simplificada. A convers�o real deve ser feita aqui.
    // Para fins de demonstra��o, retornamos a string original.
    return Str; // Placeholder
}
