#include <stdio.h>
#include <string.h>

void calculoDadosCarta(unsigned long int populacao, float area, float pib, int pontosTuristicos, float *densidadePopulacional, float *pibPerCapita, float *superPoder);
void exibirDadosCarta(char estado, char codigo[], char nomeCidade[], unsigned long int populacao, float area, float pib, int pontosTuristicos, float densidadePopulacional, float pibPerCapita, float superPoder);
void compararCartas(char nomeCidade1[], char nomeCidade2[], char atributo1Nome[], char atributo2Nome[], float atributo1Carta1, float atributo1Carta2, float atributo2Carta1, float atributo2Carta2);

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
    int atributo1, atributo2;
    char atributo1Nome[50], atributo2Nome[50];
    float atributo1Carta1, atributo1Carta2, atributo2Carta1, atributo2Carta2;

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
    printf("Informe o primeiro atributo a ser comparado:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Populacional\n");
    printf("6 - PIB per Capita\n");
    printf("7 - Super Poder\n");
    printf("Escolha o primeiro atributo (1-7): ");
    scanf("%d", &atributo1);
    switch (atributo1) {
        case 1:
            strcpy(atributo1Nome, "População");
            atributo1Carta1 = (float)populacao1;
            atributo1Carta2 = (float)populacao2;
            break;
        case 2:
            strcpy(atributo1Nome, "Área");
            atributo1Carta1 = area1;
            atributo1Carta2 = area2;
            break;
        case 3:
            strcpy(atributo1Nome, "PIB");
            atributo1Carta1 = pib1;
            atributo1Carta2 = pib2;
            break;
        case 4:
            strcpy(atributo1Nome, "Pontos Turísticos");
            atributo1Carta1 = (float)pontosTuristicos1;
            atributo1Carta2 = (float)pontosTuristicos2;
            break;
        case 5:
            strcpy(atributo1Nome, "Densidade Populacional");
            atributo1Carta1 = densidadePopulacional1;
            atributo1Carta2 = densidadePopulacional2;
            break;
        case 6:
            strcpy(atributo1Nome, "PIB per Capita");
            atributo1Carta1 = pibPerCapita1;
            atributo1Carta2 = pibPerCapita2;
            break;
        case 7:
            strcpy(atributo1Nome, "Super Poder");
            atributo1Carta1 = superPoder1;
            atributo1Carta2 = superPoder2;
            break;
        default:
            printf("Atributo inválido!\n");
            return 1;
    }
    printf("Informe o segundo atributo a ser comparado:\n");
    if (atributo1 != 1) printf("1 - População\n");
    if (atributo1 != 2) printf("2 - Área\n");
    if (atributo1 != 3) printf("3 - PIB\n");
    if (atributo1 != 4) printf("4 - Pontos Turísticos\n");
    if (atributo1 != 5) printf("5 - Densidade Populacional\n");
    if (atributo1 != 6) printf("6 - PIB per Capita\n");
    if (atributo1 != 7) printf("7 - Super Poder\n");
    printf("Escolha o segundo atributo: ");
    scanf("%d", &atributo2);
    if (atributo1 == atributo2) {
        printf("Atributo inválido! O segundo atributo não pode ser o mesmo que o primeiro.\n");
        return 1;
    }
    switch (atributo2) {
        case 1:
            strcpy(atributo2Nome, "População");
            atributo2Carta1 = (float)populacao1;
            atributo2Carta2 = (float)populacao2;
            break;
        case 2:
            strcpy(atributo2Nome, "Área");
            atributo2Carta1 = area1;
            atributo2Carta2 = area2;
            break;
        case 3:
            strcpy(atributo2Nome, "PIB");
            atributo2Carta1 = pib1;
            atributo2Carta2 = pib2;
            break;
        case 4:
            strcpy(atributo2Nome, "Pontos Turísticos");
            atributo2Carta1 = (float)pontosTuristicos1;
            atributo2Carta2 = (float)pontosTuristicos2;
            break;
        case 5:
            strcpy(atributo2Nome, "Densidade Populacional");
            atributo2Carta1 = densidadePopulacional1;
            atributo2Carta2 = densidadePopulacional2;
            break;
        case 6:
            strcpy(atributo2Nome, "PIB per Capita");
            atributo2Carta1 = pibPerCapita1;
            atributo2Carta2 = pibPerCapita2;
            break;
        case 7:
            strcpy(atributo2Nome, "Super Poder");
            atributo2Carta1 = superPoder1;
            atributo2Carta2 = superPoder2;
            break;
        default:
            printf("Atributo inválido!\n");
            return 1;
    }
    // Comparação dos atributos
    compararCartas(nomeCidade1, nomeCidade2, atributo1Nome, atributo2Nome, atributo1Carta1, atributo1Carta2, atributo2Carta1, atributo2Carta2);
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

void compararCartas(char nomeCidade1[], char nomeCidade2[], char atributo1Nome[], char atributo2Nome[], float atributo1Carta1, float atributo1Carta2, float atributo2Carta1, float atributo2Carta2) {
    // Comparação do primeiro atributo
    printf("\nAtributo \"%s\": %s: %.0f, %s: %.0f\n", atributo1Nome, nomeCidade1, atributo1Carta1, nomeCidade2, atributo1Carta2);
    if (strcmp(atributo1Nome, "Densidade Populacional") == 0) {
        if (atributo1Carta1 < atributo1Carta2) {
            printf("%s ganha no atributo \"%s\"!\n", nomeCidade1, atributo1Nome);
        } else if (atributo1Carta1 > atributo1Carta2) {
            printf("%s ganha no atributo \"%s\"!\n", nomeCidade2, atributo1Nome);
        } else {
            printf("Empate no atributo\"%s\"!\n", atributo1Nome);
        }
    } else {
        if (atributo1Carta1 > atributo1Carta2) {
            printf("%s ganha no atributo \"%s\"!\n", nomeCidade1, atributo1Nome);
        } else if (atributo1Carta1 < atributo1Carta2) {
            printf("%s ganha no atributo \"%s\"!\n", nomeCidade2, atributo1Nome);
        } else {
            printf("Empate no atributo\"%s\"!\n", atributo1Nome);
        }
    }
    // Comparação do segundo atributo
    printf("\nAtributo \"%s\": %s: %.0f, %s: %.0f\n", atributo2Nome, nomeCidade1, atributo2Carta1, nomeCidade2, atributo2Carta2);
    if (strcmp(atributo2Nome, "Densidade Populacional") == 0) {
        if (atributo2Carta1 < atributo2Carta2) {
            printf("%s ganha no atributo \"%s\"!\n", nomeCidade1, atributo2Nome);
        } else if (atributo2Carta1 > atributo2Carta2) {
            printf("%s ganha no atributo \"%s\"!\n", nomeCidade2, atributo2Nome);
        } else {
            printf("Empate no atributo\"%s\"!\n", atributo2Nome);
        }
    } else {
        if (atributo2Carta1 > atributo2Carta2) {
            printf("%s ganha no atributo \"%s\"!\n", nomeCidade1, atributo2Nome);
        } else if (atributo2Carta1 < atributo2Carta2) {
            printf("%s ganha no atributo \"%s\"!\n", nomeCidade2, atributo2Nome);
        } else {
            printf("Empate no atributo\"%s\"!\n", atributo2Nome);
        }
    }
    // Comparação da soma dos atributos
    printf("\nSoma dos atributos:\n");
    if (strcmp(atributo1Nome, "Densidade Populacional") == 0 || strcmp(atributo2Nome, "Densidade Populacional") == 0) {
        printf("A soma dos atributos é inversamente proporcional à densidade populacional.\n");
    }
    if (strcmp(atributo1Nome, "Densidade Populacional") == 0) {
        atributo1Carta1 = 1 / atributo1Carta1;
        atributo1Carta2 = 1 / atributo1Carta2;
    }
    if (strcmp(atributo2Nome, "Densidade Populacional") == 0) {
        atributo2Carta1 = 1 / atributo2Carta1;
        atributo2Carta2 = 1 / atributo2Carta2;
    }
    printf("%s: %.0f + %.0f = %.0f\n", nomeCidade1, atributo1Carta1, atributo2Carta1, atributo1Carta1 + atributo2Carta1);
    printf("%s: %.0f + %.0f = %.0f\n", nomeCidade2, atributo1Carta2, atributo2Carta2, atributo1Carta2 + atributo2Carta2);
    if ((atributo1Carta1 + atributo2Carta1) > (atributo1Carta2 + atributo2Carta2)) {
        printf("%s ganha na soma dos atributos!\n", nomeCidade1);
    } else if ((atributo1Carta1 + atributo2Carta1) < (atributo1Carta2 + atributo2Carta2)) {
        printf("%s ganha na soma dos atributos!\n", nomeCidade2);
    } else {
        printf("Empate na soma dos atributos!\n");
    }
}