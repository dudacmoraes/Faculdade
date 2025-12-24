#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>

int main() {

    char letra;
    char input[5];
    int numero;
    bool valido_produto = false;
    int menu_pagamento;
    int notas;
    int moedas;
    bool valido_pagamento = false;

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

    while (1) {
        valido_produto = false;
        valido_pagamento = false;
        double preco = 0.0;
        double total_pago = 0.0;

        while (!valido_produto) {
        printf("\nEscolha seu produto: ");
        fgets(input, sizeof(input), stdin);

        if (sscanf(input, " %c%d", &letra, &numero) != 2) {
            printf("Entrada invalida!");
            continue;
        }
        if (letra >= 'a' && letra <= 'e') {
            letra = toupper(letra);
        }
        if (letra < 'A' || letra > 'E' || numero < 1 || numero > 3) {
            printf("Entrada invalida!");
            continue;
        }
        printf("Voce escolheu: ");

        switch (letra) {
        case 'A':
        case 'a':
            if (numero == 1) {
                preco = 7.00;
                printf("Ruffles R$%.2f", preco);
                valido_produto = true;
            } else if (numero == 2) {
                preco = 8.00;
                printf("Lays R$%.2f", preco);
                valido_produto = true;
            } else if (numero == 3) {
                preco = 10.00;
                printf("Pringles R$%.2f", preco);
                valido_produto = true;
            }
            break;
        case 'B':
        case 'b':
            if (numero == 1) {
                preco = 3.00;
                printf("Snickers - R$%.2f", preco);
                valido_produto = true;
            } else if (numero == 2) {
                preco = 2.00;
                printf("5Star R$%.2f", preco);
                valido_produto = true;
            } else if (numero == 3) {
                preco = 5.00;
                printf("M&Ms R$%.2f", preco);
                valido_produto = true;
            }
            break;
        case 'C':
        case 'c':
            if (numero == 1) {
                preco = 5.00;
                printf("Oreo R$%.2f", preco);
                valido_produto = true;
            } else if (numero == 2) {
                preco = 7.00;
                printf("Bis R$%.2f", preco);
                valido_produto = true;
            } else if (numero == 3) {
                preco = 4.00;
                printf("KitKat R$%.2f", preco);
                valido_produto = true;
            }
            break;
        case 'D':
        case 'd':
            if (numero == 1) {
                preco = 3.00;
                printf("Coca-Cola: %.2f", preco);
                valido_produto = true;
            } else if (numero == 2) {
                preco = 2.00;
                printf("Kuat R$%.2f", preco);
                valido_produto = true;
            } else if (numero == 3) {
                preco = 3.00;
                printf("Sprite R$%.2f", preco);
                valido_produto = true;
            }
            break;
        case 'E':
        case 'e':
            if (numero == 1) {
                preco = 3.00;
                printf("Pepsi R$%.2f", preco);
                valido_produto = true;
            } else if (numero == 2) {
                preco = 4.00;
                printf("Guarana Antartica R$%.2f", preco);
                valido_produto = true;
            } else if (numero == 3) {
                preco = 2.00;
                printf("Soda R$%.2f", preco);
                valido_produto = true;
            }
            break;
        default:
            valido_produto = false;
            break;
        }
        if (!valido_produto) {
            printf("Entrada invalida!");
        }
    }
    if (preco == 0.0) {
    printf("Opcao invalida");
    }

    printf("\n----------\n");
    printf("PAGAMENTO\n");
    printf("----------\n");

    printf("Valor: %.2f\n", preco);

    while (!valido_pagamento) {
        printf("\n[1] Inserir nota\n[2] Inserir moeda\n[3] Escolher outro produto");
        printf("\nSua escolha: ");
        scanf("%d", &menu_pagamento);
        while (getchar() != '\n');

        if (menu_pagamento < 1 || menu_pagamento > 3) {
            printf("Entrada invalida!");
            continue;
        }
        switch (menu_pagamento) {
            case 1:
                printf("\n[1] R$2,00\n[2] R$5,00\n[3] R$10,00\n[4] R$20,00\n[5] R$50,00\n[6] R$100,00\n[0] Voltar ao menu");
                printf("\nSelecione: ");
                scanf("%d", &notas);
                while (getchar() != '\n');

                if (notas == 0) {
                    break;
                }
                switch (notas) {
                    case 1:
                        total_pago += 2.0;
                        break;
                    case 2:
                        total_pago += 5.0;
                        break;
                    case 3:
                        total_pago += 10.0;
                        break;
                    case 4:
                        total_pago += 20.0;
                        break;
                    case 5:
                        total_pago += 50.0;
                        break;
                    case 6:
                        total_pago += 100.0;
                        break;
                    default:
                        printf("Entrada invalida!");
                        break;
                }
                if (total_pago >= preco) {
                    printf("Pagamento concluido!");
                    if (total_pago > preco) {
                        printf("Seu troco: R$%.2f", total_pago - preco);
                    }
                    return 0;
                } else {
                    printf("Dinheiro insuficiente! Faltam R$%.2f", preco - total_pago);
                }
                break;
            case 2:
                printf("\n[1] R$0,01\n[2] R$0,05\n[3] R$0,10\n[4] R$0,25\n[5] R$0,50\n[6] R$1,00\n[0] Voltar ao menu");
                printf("\nSelecione: ");
                scanf("%d", &moedas);
                while (getchar() != '\n');

                if (moedas == 0) {
                    break;
                }
                switch (moedas) {
                    case 1:
                        total_pago += 0.01;
                        break;
                    case 2:
                        total_pago += 0.05;
                        break;
                    case 3:
                        total_pago += 0.10;
                        break;
                    case 4:
                        total_pago += 0.25;
                        break;
                    case 5:
                        total_pago += 0.50;
                        break;
                    case 6:
                        total_pago += 1.0;
                        break;
                    default:
                        printf("Entrada invalida!");
                        break;
                }
                if (total_pago >= preco) {
                    printf("Pagamento concluido!");
                    if (total_pago > preco) {
                        printf("Seu troco: R$%.2f", total_pago - preco);
                    }
                    return 0;
                } else {
                    printf("Dinheiro insuficiente! Faltam R$%.2f", preco - total_pago);
                }
                break;
            case 3:
                valido_pagamento = true;
                break;
            default:
                printf("Entrada invalida!");
                break;
            }
        }
    }
}
