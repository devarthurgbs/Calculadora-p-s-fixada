#include <stdio.h>
#include <string.h>

#include "expressao.h"

int main() {
    Expressao exp;

    // Exemplo de uso
    strcpy(exp.posFixa, "2 3 4 * +");
    exp.Valor = getValor(exp.posFixa);
    printf("Valor da express�o em nota��o p�s-fixada '%s': %f\n", exp.posFixa, exp.Valor);

    // A convers�o de infixa para p�s-fixa deve ser testada aqui
    // strcpy(exp.inFixa, "(3 + 4) * 5");
    // char *posFixa = getFormaInFixa(exp.inFixa);
    // printf("Express�o em nota��o p�s-fixada: %s\n", posFixa);

    return 0;
}
