#ifndef EXPRESSAO_H
#define EXPRESSAO_H

typedef struct {
    char posFixa[512]; // Expressão na forma pós-fixa
    char inFixa[512];  // Expressão na forma infixa
    float Valor;       // Valor numérico da expressão
} Expressao;

char *getFormaInFixa(char *str); // Retorna a forma infixa de str (pós-fixa)
float getValor(char *str);        // Calcula o valor de str (na forma pós-fixa)

#endif
