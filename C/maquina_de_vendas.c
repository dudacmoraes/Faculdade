#include <stdio.h>

int main() {

    char letra;
    char input[5];
    int numero;
    double preco = 0.0;
    int notas;

    printf("------------------");
    printf("\nMaquina de vendas\n");
    printf("------------------");

    printf("\nA1 - Ruffles (R$7,00)");
    printf("\nA2 - Lays (R$8,00)");
    printf("\nA3 - Pringles (R$10,00)\n");

    printf("\nB1 - Snickers (R$3,00)");
    printf("\nB2 - 5Star (R$2,00)");
    printf("\nB3 - M&Ms (R$5,00)\n");

    printf("\nC1 - Oreo (R$5,00)");
    printf("\nC2 - Bis (R$7,00)");
    printf("\nC3 - KitKat R$4,00\n");

    printf("\nD1 - Coca-Cola R$3,00");
    printf("\nD2 - Kuat R$2,00");
    printf("\nD3 - Sprite R$3,00\n");

    printf("\nE1 - Pepsi R$3,00");
    printf("\nE2 - Guarana Antartica R$4,00");
    printf("\nE3 - Soda R$2,00\n");

    printf("\nEscolha seu produto: ");
    fgets(input, sizeof(input), stdin);

    if (sscanf(input, " %c%d", &letra, &numero) != 2) {
        printf("Entrada invalida");

        return 0;
    }

    printf("Voce escolheu: ");
    switch (letra) {
        case 'A':
        case 'a':
            if (numero == 1) {
                preco = 7.00;
                printf("Ruffles: R$%.2f", preco);
            } else if (numero == 2) {
                preco = 8.00;
                printf("Lays: R$%.2f", preco);
            } else if (numero == 3) {
                preco = 10.00;
                printf("Pringles: R$%.2f", preco);
            }
            break;
        case 'B':
        case 'b':
            if (numero == 1) {
                preco = 3.00;
                printf("Snickers R$%.2f", preco);
            } else if (numero == 2) {
                preco = 2.00;
                printf("5Star R$%.2f", preco);
            } else if (numero == 3) {
                preco = 5.00;
                printf("M&Ms R$%.2f", preco);
            }
            break;
        case 'C':
        case 'c':
            if (numero == 1) {
                preco = 5.00;
                printf("Oreo R$%.2f", preco);
            } else if (numero == 2) {
                preco = 7.00;
                printf("Bis R$%.2f", preco);
            } else if (numero == 3) {
                preco = 4.00;
                printf("KitKat R$%.2f", preco);
            }
            break;
        case 'D':
        case 'd':
            if (numero == 1) {
                preco = 3.00;
                printf("Coca-Cola: %.2f", preco);
            } else if (numero == 2) {
                preco = 2.00;
                printf("Kuat R$%.2f", preco);
            } else if (numero == 3) {
                preco = 3.00;
                printf("Sprite R$%.2f", preco);
            }
            break;
        case 'E':
        case 'e':
            if (numero == 1) {
                preco = 3.00;
                printf("Pepsi R$%.2f", preco);
            } else if (numero == 2) {
                preco = 4.00;
                printf("Guarana Antartica R$%.2f", preco);
            } else if (numero == 3) {
                preco = 2.00;
                printf("Soda R$%.2f", preco);
            }
            break;
        default:
            printf("Opcao invalida!");
            break;
    }
    if (preco == 0.0) {
        printf("Opcao invalida");
        return 0;
    }
    printf("\n----------\n");
    printf("PAGAMENTO\n");
    printf("----------\n");

    printf("Valor: %.2f\n", preco);
    printf("Insira o dinheiro [R$1,00/ R$2,00/ R$5,00/ R$10,00/ R$20,00/ R$50,00/R$100,00]: ");
    scanf("%d", &notas);

    if (notas != 1 && notas != 2 && notas != 5 && notas != 10 && notas != 20 && notas != 50 && notas != 100) {
        printf("Nota invalida");
    } else if (notas < preco) {
        printf("Dinheiro insuficiente");
    } else {
        double troco = notas - preco;
        printf("Seu troco: R$%.2f", troco);
    }
    return 0;
}
