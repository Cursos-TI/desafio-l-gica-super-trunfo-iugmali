#include <stdio.h>

void lerDadosCarta(char *estado, char codigo[], char nomeCidade[], unsigned long int *populacao, float *area, float *pib, int *pontosTuristicos, float *densidadePopulacional, float *pibPerCapita, float *superPoder);
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

    // Leitura dos dados da primeira carta
    printf("Digite os dados da primeira carta:\n");
    lerDadosCarta(&estado1, codigo1, nomeCidade1, &populacao1, &area1, &pib1, &pontosTuristicos1, &densidadePopulacional1, &pibPerCapita1, &superPoder1);

    // Leitura dos dados da segunda carta
    printf("\nDigite os dados da segunda carta:\n");
    lerDadosCarta(&estado2, codigo2, nomeCidade2, &populacao2, &area2, &pib2, &pontosTuristicos2, &densidadePopulacional2, &pibPerCapita2, &superPoder2);

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

void lerDadosCarta(char *estado, char codigo[], char nomeCidade[], unsigned long int *populacao, float *area, float *pib, int *pontosTuristicos, float *densidadePopulacional, float *pibPerCapita, float *superPoder) {
    // Função para ler os dados de uma carta
    printf("Estado (A-H): ");
    scanf(" %c", estado);
    printf("Código da Carta (ex: A01): ");
    scanf("%s", codigo);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", nomeCidade);
    printf("População: ");
    scanf("%lu", populacao);
    printf("Área (em km²): ");
    scanf("%f", area);
    printf("PIB (em bilhões): ");
    scanf("%f", pib);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", pontosTuristicos);
    // Cálculo da densidade populacional e PIB per capita
    *densidadePopulacional = (float)(*populacao) / (*area);
    *pibPerCapita = (*pib) * 1000000000.00 / (float)(*populacao);
    // Cálculo do Super Poder
    *superPoder = (float)(*populacao) + (*area) + (*pib) + (float)(*pontosTuristicos) + (*pibPerCapita) + (1 / (*densidadePopulacional));
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
    int resultadoPopulacao = populacao1 > populacao2;
    int resultadoArea = area1 > area2;
    int resultadoPib = pib1 > pib2;
    int resultadoPontosTuristicos = pontosTuristicos1 > pontosTuristicos2;
    int resultadoDensidadePopulacional = densidadePopulacional1 < densidadePopulacional2;
    int resultadoPibPerCapita = pibPerCapita1 > pibPerCapita2;
    int resultadoSuperPoder = superPoder1 > superPoder2;
    printf("Resultado da comparação - atributo PIB:\n");
    printf("Carta 1 - %.2f bilhões de reais\n", pib1);
    printf("Carta 2 - %.2f bilhões de reais\n", pib2);
    if (resultadoPib) {
        printf("Carta 1 vence em PIB\n");
    } else {
        printf("Carta 2 vence em PIB\n");
    }
}