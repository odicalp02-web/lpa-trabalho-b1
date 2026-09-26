#include <stdio.h>

#define VALOR_TAXA_KM 1.20
#define VALOR_PROTECAO 7.50
#define VALOR_TENTATIVA_EXTRA 4.00

float calcular_valor_base(float distancia);
float calcular_adicional_peso(float subtotal_inicial, float peso);
float calcular_adicional_modalidade(float subtotal_inicial, int modalidade);
float calcular_valor_final(float subtotal_inicial, float adicional_peso, float adicional_modalidade, float custo_protecao, float custo_tentativas);

int main() {
    int opcao_continuar = 1;

    int total_entregas = 0;
    float valor_total_sessao = 0.0;
    float maior_valor = -1.0;
    float menor_valor = -1.0;
    int qtd_economica = 0;
    int qtd_expressa = 0;
    int qtd_prioritaria = 0;

    printf("=== SISTEMA DE SIMULADOR DE ENTREGAS ===\n");

    while (opcao_continuar == 1) {
        float distancia, peso;
        int modalidade, protecao, tentativas;

        do {
            printf("\nInforme a distancia em km (maior que 0): ");
            scanf("%f", &distancia);
            if (distancia <= 0) {
                printf("[ERRO] Distancia invalida. Informe um valor maior que zero.\n");
            }
        } while (distancia <= 0);

        do {
            printf("Informe o peso em kg (maior que 0): ");
            scanf("%f", &peso);
            if (peso <= 0) {
                printf("[ERRO] O peso deve ser maior que zero. Tente novamente.\n");
            }
        } while (peso <= 0);

        do {
            printf("Informe a modalidade (1-Economica, 2-Expressa, 3-Prioritaria): ");
            scanf("%d", &modalidade);
            if (modalidade < 1 || modalidade > 3) {
                printf("[ERRO] Modalidade invalida. Escolha 1, 2 ou 3.\n");
            }
        } while (modalidade < 1 || modalidade > 3);

        do {
            printf("Deseja servico de protecao? (1-Sim / 0-Nao): ");
            scanf("%d", &protecao);
            if (protecao != 0 && protecao != 1) {
                printf("[ERRO] Valor invalido. Digite 1 para Sim ou 0 para Nao.\n");
            }
        } while (protecao != 0 && protecao != 1);

        do {
            printf("Informe a quantidade de tentativas adicionais (>= 0): ");
            scanf("%d", &tentativas);
            if (tentativas < 0) {
                printf("[ERRO] A quantidade nao pode ser negativa. Tente novamente.\n");
            }
        } while (tentativas < 0);

        // Peso e modalidade sao calculados separadamente sobre o mesmo subtotal inicial
        float valor_base = calcular_valor_base(distancia);
        float subtotal_inicial = valor_base + (distancia * VALOR_TAXA_KM);
        float adicional_peso = calcular_adicional_peso(subtotal_inicial, peso);
        float adicional_mod = calcular_adicional_modalidade(subtotal_inicial, modalidade);
        float custo_protecao = (protecao == 1) ? VALOR_PROTECAO : 0.0;
        float custo_tentativas = tentativas * VALOR_TENTATIVA_EXTRA;

        float valor_final = calcular_valor_final(subtotal_inicial, adicional_peso, adicional_mod, custo_protecao, custo_tentativas);

        printf("\n----------------------------------------\n");
        printf("RESULTADO DA ENTREGA ATUAL:\n");
        printf(" Valor-base: R$ %.2f\n", valor_base);
        printf(" Subtotal inicial: R$ %.2f\n", subtotal_inicial);
        printf(" Valor Final da Entrega: R$ %.2f\n", valor_final);
        printf("----------------------------------------\n");

        total_entregas++;
        valor_total_sessao += valor_final;

        if (modalidade == 1) qtd_economica++;
        else if (modalidade == 2) qtd_expressa++;
        else if (modalidade == 3) qtd_prioritaria++;

        if (total_entregas == 1) {
            maior_valor = valor_final;
            menor_valor = valor_final;
        } else {
            if (valor_final > maior_valor) maior_valor = valor_final;
            if (valor_final < menor_valor) menor_valor = valor_final;
        }

        do {
            printf("Deseja processar outra entrega? (1-Sim / 0-Nao): ");
            scanf("%d", &opcao_continuar);
            if (opcao_continuar != 0 && opcao_continuar != 1) {
                printf("[ERRO] Opcao invalida. Digite 1 para continuar ou 0 para encerrar.\n");
            }
        } while (opcao_continuar != 0 && opcao_continuar != 1);
    }

    printf("\n========================================\n");
    printf("         RESUMO FINAL DA SESSAO         \n");
    printf("========================================\n");
    if (total_entregas > 0) {
        float valor_medio = valor_total_sessao / total_entregas;
        printf("Quantidade total de entregas: %d\n", total_entregas);
        printf("Valor total calculado: R$ %.2f\n", valor_total_sessao);
        printf("Valor medio das entregas: R$ %.2f\n", valor_medio);
        printf("Entregas Economicas: %d\n", qtd_economica);
        printf("Entregas Expressas: %d\n", qtd_expressa);
        printf("Entregas Prioritarias: %d\n", qtd_prioritaria);
        printf("Maior valor de entrega: R$ %.2f\n", maior_valor);
        printf("Menor valor de entrega: R$ %.2f\n", menor_valor);
    } else {
        printf("Nenhuma entrega foi processada nesta sessao.\n");
    }
    printf("========================================\n");

    return 0;
}

float calcular_valor_base(float distancia) {
    if (distancia <= 5.0) {
        return 8.00;
    } else if (distancia <= 15.0) {
        return 12.00;
    } else if (distancia <= 30.0) {
        return 18.00;
    } else {
        return 25.00;
    }
}

float calcular_adicional_peso(float subtotal_inicial, float peso) {
    if (peso <= 2.0) {
        return 0.0;
    } else if (peso <= 5.0) {
        return subtotal_inicial * 0.05;
    } else if (peso <= 10.0) {
        return subtotal_inicial * 0.10;
    } else {
        return subtotal_inicial * 0.20;
    }
}

float calcular_adicional_modalidade(float subtotal_inicial, int modalidade) {
    if (modalidade == 1) {
        return 0.0;
    } else if (modalidade == 2) {
        return subtotal_inicial * 0.15;
    } else if (modalidade == 3) {
        return subtotal_inicial * 0.30;
    }
    return 0.0;
}

float calcular_valor_final(float subtotal_inicial, float adicional_peso, float adicional_modalidade, float custo_protecao, float custo_tentativas) {
    return subtotal_inicial + adicional_peso + adicional_modalidade + custo_protecao + custo_tentativas;
}
