/**
 * @file main.c
 * @author Pedro Ribeiro, Ricardo Fernandes, Carolina Branco (a27960@alunos.ipca.pt a279861@alunos.opca.pt a27983@alunos.ipca.pt)
 * @brief Local de implementação das funções
 * @version 0.1
 * @date 2023-12-27
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>
#include <locale.h>
#include "Dados.h"
#include "Funcoes.h"

/**
 * @brief Inserção de parametros na função main
 * 
 * @param argc número de argumentos
 * @param argv array de argumentos, indica a posição do argumento (começa no 0) 
 * @return int 
 */

int main(int argc, char* argv[]) {

    setlocale(LC_ALL, "Portuguese");
    char separador = ';';
    char fpacientes[N], fdietas[N], fplanos[N];
    int aux = 0;
    Paciente dados[E];
    Dieta dietas[E];
    PlanoNutri nutri[E];

    if (argc < 3 && strcmp(argv[1], "-ajuda")!=0){
        printf ("Número insuficiente de argumentos\n");
        return 0;
    } 
    if (strcmp(argv[1], "-ajuda") == 0) {
        MostraAjuda();
        return 0;
    }
    if (strcmp(argv[1], "-tab") == 0) {
        if(argc < 4){
            printf ("Número insuficiente de argumentos\n");
            return 0;
        }else{
            separador = '\t';
            strcpy(fpacientes, argv[2]);
            strcpy(fdietas, argv[3]);
            if (argc == 5) {
                strcpy (fplanos, argv[4]);
                aux = 1;
            }
        }
    }
    else {
        if(argc < 3){
            printf ("Número insuficiente de argumentos\n");
            return 0;
        }else{
            strcpy(fpacientes, argv[1]);
            strcpy(fdietas, argv[2]);
            if (argc == 4) {
                strcpy (fplanos, argv[3]);
                aux = 1;
            }
        }
    }
    if (aux == 0) {
        char linha[E][1000];
        int i=0;
        while (i < E && fgets(linha[i], 1000, stdin) != NULL) {
            if (linha[i][0] == '\n') {
                printf("Fim da entrada.\n");
                break;
            }
        i++;
        }

        for (int j = 0; j < i; j++) {
            printf("Dados lidos: %s", linha[j]);
        }
        
        FILE *fplanosFILE;

        if (separador == ';') {
            fplanosFILE = fopen("planosstdin.csv", "w");
            strcpy(fplanos,"planosstdin.csv");
        } else if (separador == '\t') {
            fplanosFILE = fopen("tplanosstdin.csv", "w");
            strcpy(fplanos,"tplanosstdin.csv");
        } else {
            printf("Separador não suportado.\n");
            return 1;
        }

        if (fplanosFILE == NULL) {
            perror("Erro ao abrir o ficheiro de planos");
            return 1;
        }

        for (int j = 0; j < i; j++) {
            fputs(linha[j], fplanosFILE);
        }   

        fclose(fplanosFILE);

    }
    
    LeDadosPacientes(separador, fpacientes, dados, E);
    LeDadosDieta(separador, fdietas, dietas, E);
    LeDadosPlanoNutri(separador, fplanos, nutri, E);

    NaoCumpPaciente nCump[E];

    MediaPaciente mediaPc[E];
    
#pragma region TÓPICO 1. a. (main)

    if (ExportaDadosPacientes("ExpPacientes.csv", dados, E)) {
        printf("Dados dos pacientes exportados com sucesso...\n\n");
    }
    else {
        printf("Erro ao exportar os dados dos pacientes...\n\n");
    }

#pragma endregion

#pragma region TÓPICO 1. b. (main)

    if (ExportaDadosDieta("ExpDietas.csv", dietas, E)) {
        printf("Dados das dietas exportados com sucesso...\n\n");
    }
    else {
        printf("Erro ao exportar os dados das dietas...\n\n");
    }

#pragma endregion

#pragma region TÓPICO 1. c. (main)

    if (ExportaDadosPlanoNutri("ExpPlanoNutricional.csv", nutri, E)) {
        printf("Dados dos planos nutricionais exportados com sucesso...\n\n");
    }
    else {
        printf("Erro ao exportar os dados dos planos nutricionais...\n\n");
    }

#pragma endregion

#pragma region TÓPICO 2

    int pacientesUltrapassam = NumPacientesUltrapassamCal(nutri, dietas, E);
    printf("Número de pacientes que ultrapassaram o limite de calorias: %d\n\n", pacientesUltrapassam);

#pragma endregion

#pragma region TÓPICO 3

    IdentificaForaIntervalo(nutri, dietas, dados, nCump, E);
    OrdenaPacientesForaIntervalo(nCump, E);

    // Exibir resultados
    printf("Pacientes fora do intervalo ordenados:\n");
    for (int i = 0; i < E; i++) {
        if (nCump[i].numpaciente < -1) { //em caso do array ter espaços ocupados com lixo
            break;
        }
        else {
            printf("%d - %s, %d\n", nCump[i].numpaciente, nCump[i].nome, nCump[i].telefone);
        }
    }
    printf("\n");

#pragma endregion

#pragma region TÓPICO 4

    ListaPlanoNutricional(nutri, E, 1, 0, "10-05-2023", "12-05-2023");

#pragma endregion 

#pragma region TÓPICO 5

    CalcularMediasRefeicoes(dietas, mediaPc, E, E, "10-05-2023", "12-05-2023");

    for (int i = 0; i < E; i++) {
        printf("Paciente %d:\n", mediaPc[i].numpaciente);
        printf("Média Pequeno Almoço: %.2f\n", mediaPc[i].mediapequenoalmoco);
        printf("Média Almoço: %.2f\n", mediaPc[i].mediaalmoco);
        printf("Média Jantar: %.2f\n\n", mediaPc[i].mediajantar);
    }

#pragma endregion 

#pragma region TÓPICO 6

    GerarTabelaRefeicoes(dados, dietas, nutri, 3, 3, 3);

#pragma endregion



   

}