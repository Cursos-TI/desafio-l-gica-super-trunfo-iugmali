#include <stdio.h>
#include <string.h>

void calculoDadosCarta(unsigned long int populacao, float area, float pib, int pontosTuristicos, float *densidadePopulacional, float *pibPerCapita, float *superPoder);
void exibirDadosCarta(char estado, char codigo[], char nomeCidade[], unsigned long int populacao, float area, float pib, int pontosTuristicos, float densidadePopulacional, float pibPerCapita, float superPoder);
void compararCartas(unsigned long int populacao1, unsigned long int populacao2, float area1, float area2, float pib1, float pib2, int pontosTuristicos1, int pontosTuristicos2, float densidadePopulacional1, float densidadePopulacional2, float pibPerCapita1, float pibPerCapita2, float superPoder1, float superPoder2);

int main() {
    // Variáveis para armazenar os dados das duas cartas
    char estado1, estado2;
    char codigo1[4], codigo2[4];
    char nomeCidade1[50], nomeCidade2[50];
    unsigned long int populacao1, populacao2;
    float area1, area2;
    float pib1, pib2;
    int pontosTuristicos1, pontosTuristicos2;
    float densidadePopulacional1, densidadePopulacional2;
    float pibPerCapita1, pibPerCapita2;
    float superPoder1, superPoder2;

    // Inicialização dos dados da primeira carta
    estado1 = 'A';
    strcpy(codigo1, "A01");
    strcpy(nomeCidade1, "São Gonçalo");
    populacao1 = 896744;
    area1 = 248.16;
    pib1 = 20.3;
    pontosTuristicos1 = 0;

    // Inicialização dos dados da segunda carta
    estado2 = 'A';
    strcpy(codigo2, "A02");
    strcpy(nomeCidade2, "Niterói");
    populacao2 = 481758;
    area2 = 133.76;
    pib2 = 66.3;
    pontosTuristicos2 = 5;

    // Cálculo dos dados da primeira carta
    calculoDadosCarta(populacao1, area1, pib1, pontosTuristicos1, &densidadePopulacional1, &pibPerCapita1, &superPoder1);

    // Cálculo dos dados da segunda carta
    calculoDadosCarta(populacao2, area2, pib2, pontosTuristicos2, &densidadePopulacional2, &pibPerCapita2, &superPoder2);

    // Exibição dos dados da primeira carta
    printf("\nCarta 1:\n");
    exibirDadosCarta(estado1, codigo1, nomeCidade1, populacao1, area1, pib1, pontosTuristicos1, densidadePopulacional1, pibPerCapita1, superPoder1);

    // Exibição dos dados da segunda carta
    printf("\nCarta 2:\n");
    exibirDadosCarta(estado2, codigo2, nomeCidade2, populacao2, area2, pib2, pontosTuristicos2, densidadePopulacional2, pibPerCapita2, superPoder2);

    // Comparação das cartas
    printf("\nComparação das Cartas:\n");
    compararCartas(populacao1, populacao2, area1, area2, pib1, pib2, pontosTuristicos1, pontosTuristicos2, densidadePopulacional1, densidadePopulacional2, pibPerCapita1, pibPerCapita2, superPoder1, superPoder2);
    return 0;
}

void calculoDadosCarta(unsigned long int populacao, float area, float pib, int pontosTuristicos, float *densidadePopulacional, float *pibPerCapita, float *superPoder) {
    // Cálculo da densidade populacional e PIB per capita
    *densidadePopulacional = (float)populacao / area;
    *pibPerCapita = pib * 1000000000.00 / (float)populacao;
    // Cálculo do Super Poder
    *superPoder = (float)populacao + area + pib + (float)pontosTuristicos + (*pibPerCapita) + (1 / (*densidadePopulacional));
}

void exibirDadosCarta(char estado, char codigo[], char nomeCidade[], unsigned long int populacao, float area, float pib, int pontosTuristicos, float densidadePopulacional, float pibPerCapita, float superPoder) {
    // Função para exibir os dados de uma carta
    printf("Estado: %c\n", estado);
    printf("Código: %s\n", codigo);
    printf("Nome da Cidade: %s\n", nomeCidade);
    printf("População: %lu\n", populacao);
    printf("Área: %.2f km²\n", area);
    printf("PIB: %.2f bilhões de reais\n", pib);
    printf("Número de Pontos Turísticos: %d\n", pontosTuristicos);
    printf("Densidade Populacional: %.2f habitantes/km²\n", densidadePopulacional);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita);
    printf("Super Poder: %.2f\n", superPoder);
}

void compararCartas(unsigned long int populacao1, unsigned long int populacao2, float area1, float area2, float pib1, float pib2, int pontosTuristicos1, int pontosTuristicos2, float densidadePopulacional1, float densidadePopulacional2, float pibPerCapita1, float pibPerCapita2, float superPoder1, float superPoder2) {
    printf("Informe o atributo a ser comparado:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Populacional\n");
    printf("6 - PIB per Capita\n");
    printf("7 - Super Poder\n");
    printf("Escolha uma opção (1-7): ");
    int opcao;
    scanf("%d", &opcao);
    switch (opcao) {
        case 1:
            printf("Resultado da comparação - atributo População:\n");
            printf("Carta 1 - %lu habitantes\n", populacao1);
            printf("Carta 2 - %lu habitantes\n", populacao2);
            if (populacao1 > populacao2) {
                printf("Carta 1 vence em População\n");
            } else if (populacao2 > populacao1) {
                printf("Carta 2 vence em População\n");
            } else {
                printf("Empate em População\n");
            }
            break;
        case 2:
            printf("Resultado da comparação - atributo Área:\n");
            printf("Carta 1 - %.2f km²\n", area1);
            printf("Carta 2 - %.2f km²\n", area2);
            if (area1 > area2) {
                printf("Carta 1 vence em Área\n");
            } else if (area2 > area1) {
                printf("Carta 2 vence em Área\n");
            } else {
                printf("Empate em Área\n");
            }
            break;
        case 3:
            printf("Resultado da comparação - atributo PIB:\n");
            printf("Carta 1 - %.2f bilhões de reais\n", pib1);
            printf("Carta 2 - %.2f bilhões de reais\n", pib2);
            if (pib1 > pib2) {
                printf("Carta 1 vence em PIB\n");
            } else if (pib2 > pib1) {
                printf("Carta 2 vence em PIB\n");
            } else {
                printf("Empate em PIB\n");
            }
            break;
        case 4:
            printf("Resultado da comparação - atributo Pontos Turísticos:\n");
            printf("Carta 1 - %d pontos turísticos\n", pontosTuristicos1);
            printf("Carta 2 - %d pontos turísticos\n", pontosTuristicos2);
            if (pontosTuristicos1 > pontosTuristicos2) {
                printf("Carta 1 vence em Pontos Turísticos\n");
            } else if (pontosTuristicos2 > pontosTuristicos1) {
                printf("Carta 2 vence em Pontos Turísticos\n");
            } else {
                printf("Empate em Pontos Turísticos\n");
            }
            break;
        case 5:
            printf("Resultado da comparação - atributo Densidade Populacional:\n");
            printf("Carta 1 - %.2f habitantes/km²\n", densidadePopulacional1);
            printf("Carta 2 - %.2f habitantes/km²\n", densidadePopulacional2);
            if (densidadePopulacional1 < densidadePopulacional2) {
                printf("Carta 1 vence em Densidade Populacional\n");
            } else if (densidadePopulacional2 < densidadePopulacional1) {
                printf("Carta 2 vence em Densidade Populacional\n");
            } else {
                printf("Empate em Densidade Populacional\n");
            }
            break;
        case 6:
            printf("Resultado da comparação - atributo PIB per Capita:\n");
            printf("Carta 1 - %.2f reais\n", pibPerCapita1);
            printf("Carta 2 - %.2f reais\n", pibPerCapita2);
            if (pibPerCapita1 > pibPerCapita2) {
                printf("Carta 1 vence em PIB per Capita\n");
            } else if (pibPerCapita2 > pibPerCapita1) {
                printf("Carta 2 vence em PIB per Capita\n");
            } else {
                printf("Empate em PIB per Capita\n");
            }
            break;
        case 7:
            printf("Resultado da comparação - atributo Super Poder:\n");
            printf("Carta 1 - %.2f\n", superPoder1);
            printf("Carta 2 - %.2f\n", superPoder2);
            if (superPoder1 > superPoder2) {
                printf("Carta 1 vence em Super Poder\n");
            } else if (superPoder2 > superPoder1) {
                printf("Carta 2 vence em Super Poder\n");
            } else {
                printf("Empate em Super Poder\n");
            }
            break;
        default:
            printf("Opção inválida!\n");
            break;
    }
}