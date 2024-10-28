#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

void main() {
    setlocale(LC_ALL, "Portuguese");
    int ano1, ano2, mes1, mes2, dia1, dia2;

    struct tm temp1 = {0};
    struct tm temp2 = {0};

    printf("===========================================\n\t\tBem vindo\n===========================================\n");
    printf("Esta é uma calculadora para calcular a diferença entre dois dias diferentes");

    //Ano inicial
    printf("Tempo inicial\n");
    printf("Digite o ano: ");
    scanf("%d",&ano1);
    printf("Digite o número do mês: ");
    scanf("%d",&mes1);
    printf("Digite o dia: ");
    scanf("%d",&dia1);

    //Ano final
    printf("\n\nTempo final\n");
    printf("Digite o ano: ");
    scanf("%d",&ano2);
    printf("Digite o número do mês: ");
    scanf("%d",&mes2);
    printf("Digite o dia: ");
    scanf("%d",&dia2);
    

    //Recebimento de dados
    temp1.tm_year = ano1 - 1900;
    temp1.tm_mon  = mes1 - 1;
    temp1.tm_mday = dia1;
    temp2.tm_year = ano2 - 1900;
    temp2.tm_mon  = mes2 - 1;
    temp2.tm_mday = dia2;

    //Transformação em segundos
    time_t segundos1 = mktime(&temp1);
    time_t segundos2 = mktime(&temp2);

    //Difereciação 
    double diferenca = difftime(segundos1, segundos2);
    diferenca *= -1;

    //Transformação
    int ano   = diferenca / 31536000;   // Segundos em um ano
    int mes   = diferenca / 2592000;    // Segundos em um mes 
    int dias  = diferenca / 86400;      // Segundos em um dia
    int horas = diferenca / 3600;       // Segundos em uma hora
    int min   = diferenca / 60;         // Segundos em minuto
    int s     = diferenca;              // Segundos

    //Mostra o resultado
    printf("\nSua diferença em:\n\n");
    printf("[%-8d] Anos\n",ano);
    printf("[%-8d] Meses\n",mes);
    printf("[%-8d] Dias\n",dias);
    printf("[%-8d] Horas\n",horas);
    printf("[%-8d] Minutos\n",min);
    printf("[%-8d] Segundos\n",s);

    system("pause");
}