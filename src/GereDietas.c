/**
 * @file GereDietas.c
 * @author Pedro Ribeiro, Ricardo Fernandes, Carolina Branco (a27960@alunos.ipca.pt a279861@alunos.opca.pt a27983@alunos.ipca.pt)
 * @brief Leitura, escrita e manipulação de informações relacionadas com dietas e planos nutricionais
 * @version 0.1
 * @date 2023-12-27
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma warning (disable: 4996)
#include "Dados.h"

#pragma region EXTRA

/**
 * @brief Exibe informações de ajuda sobre o programa.
 *
 * Esta função imprime mensagens de ajuda na consola, explicando o funcionamento do programa.
 * Inclui instruções sobre como utilizar o programa.
 */

void MostraAjuda() {
    printf("Para compilar o programa utilize uma das seguintes opções:\n\n");
    printf("-ajuda: É utilizada para fornecer ajuda ao utilizador sobre os comandos a utilizar\n");
    printf("-tab : É utilizada para compilar o programa com ficheiros passados por argumento com os dados separados por tabs\n");
}

#pragma endregion

#pragma region TÓPICO 1 b

/**
 * @brief Exporta os dados das dietas para um arquivo CSV ou TXT.
 *
 * Esta função recebe um nome de um arquivo e um array de structs Dieta,
 * e exporta os dados das dietas para o arquivo.
 *
 * @param fileName é o nome do arquivo que vai ser feita a exportação.
 * @param dietas é o array de structs Dieta contendo os dados a serem exportados.
 * @param maximodietas Número máximo de dietas no array.
 * @return Retorna true se a exportação for bem sucedida, false caso contrário.
 */

bool ExportaDadosDieta(char fileName[], Dieta dietas[], int maximodietas) {
    FILE* fp;
    fp = fopen(fileName, "w"); //Abre o ficheiro para escrita, usado o caracter "w" para apagar o que estiver escrito e escrever depois o pedido
    if (fp == NULL) return false; //Caso não seja possível abrir o ficheiro retorna false
    for (int i = 0; i < maximodietas; i++) {
            // O ciclo for itera sobre o array dietas e vai escrevendo o mesmo no ficheiro, no formato CSV.
            fprintf(fp, "%d;%s;%s;%d;%s;%d\n", dietas[i].numpaciente, dietas[i].datainicio, dietas[i].datafim, dietas[i].tp, dietas[i].alimento, dietas[i].calorias);

        }
    fclose(fp);
    return true;
    //Fecha o ficheiro e devolve true
}

#pragma endregion

#pragma region TÓPICO 1 b

/**
 * @brief Lê os dados das dietas de um arquivo CSV ou TXT.
 *
 * Esta função recebe um nome de arquivo e lê os dados das dietas do arquivo no formato CSV ou TXT.
 * Os dados lidos são armazenados em um array de structs Dieta.
 * 
 * @param separador 
 * @param fileName é o nome do arquivo para leitura.
 * @param dietas é o array de structs Dieta para armazenar os dados lidos.
 * @param maximodietas é p número máximo de dietas no array.
 * @return Retorna true se a leitura for bem sucedida, false caso contrário.
 *
 */

bool LeDadosDieta(char separador, char fileName[], Dieta *dietas, int maximodietas) {
    FILE * fp;
    fp = fopen (fileName,"r");
    if (fp == NULL) {
    return false; // Retorna false se o apontador do ficheiro for nulo
    }
    if (separador == ';') {
        for (int i = 0; i < maximodietas; i++) {
            fscanf(fp, "%d;%99[^;];%99[^;];%d;%99[^;];%d", &dietas[i].numpaciente, dietas[i].datainicio, dietas[i].datafim, &dietas[i].tp, dietas[i].alimento, &dietas[i].calorias);
            //Para verifcar o que foi lido:
            //printf("%d;%s;%s;%d;%s;%d\n", dietas[i].numpaciente, dietas[i].datainicio, dietas[i].datafim, dietas[i].tp, dietas[i].alimento, dietas[i].calorias);

        }
    }
    if (separador == '\t') {
        for (int i = 0; i < maximodietas; i++) {
            fscanf(fp, "%d\t%99[^\t]\t%99[^\t]\t%d\t%99[^\t]\t%d", &dietas[i].numpaciente, dietas[i].datainicio, dietas[i].datafim, &dietas[i].tp, dietas[i].alimento, &dietas[i].calorias);
            //Para verifcar o que foi lido:
            //printf("%d\t%s\t%s\t%d\t%s\t%d\n", dietas[i].numpaciente, dietas[i].datainicio, dietas[i].datafim, dietas[i].tp, dietas[i].alimento, dietas[i].calorias);
        }
    }
    fclose(fp);
    return true;
    }

#pragma endregion

#pragma region TÓPICO 1 c

/**
 * @brief Exporta os dados do plano nutricional para um arquivo CSV ou TXT.
 *
 * Esta função recebe um nome de arquivo e exporta os dados do plano nutricional
 * para o arquivo no formato CSV ou TXT.
 *
 * @param fileName é o nome do arquivo para exportação.
 * @param plano é o array de structs PlanoNutri contendo os dados a serem exportados.
 * @param maximodietas é o número máximo de planos nutricionais no array.
 * @return Retorna true se a exportação for bem sucedida, false caso contrário.
 */

bool ExportaDadosPlanoNutri(char fileName[], PlanoNutri plano[], int maximodietas) {
    FILE* fp;
    fp = fopen(fileName, "w");
    if (fp == NULL) return false;
    for (int i = 0; i < maximodietas; i++) {
        fprintf(fp, "%d;%s;%s;%d;%d;%d\n", plano[i].numpaciente, plano[i].datainicio, plano[i].datafim, plano[i].tp, plano[i].caloriasMin, plano[i].caloriasMax);
    }
    fclose(fp);
    return true;
}


/**
 * @brief Lê os dados dos planos nutricionais de um arquivo e armazena-os em um array de estruturas PlanoNutri.
 *
 * Esta função recebe um nome de arquivo e lê os dados das dietas do arquivo no formato CSV ou TXT.
 * Os dados lidos são armazenados em um array de structs PlanoNutri.
 *
 * @param fileName é o nome do arquivo a ser lido.
 * @param plano é o array de estruturas PlanoNutri para armazenar os dados lidos.
 * @param maximodietas é o número máximo de dietas a serem lidas do arquivo.
 * @return Retorna true se a leitura for bem sucedida, false caso contrário.
 */

bool LeDadosPlanoNutri(char separador, char fileName[], PlanoNutri *nutri, int maximodados) {
    FILE * fp;
    fp = fopen(fileName,"r");
    if (fp == NULL) {
        return false; // Retorna um dado vazio se o apontador do ficheiro for nulo
    }

    if (separador == ';') {
        for (int i = 0; i < maximodados; i++) {
            fscanf(fp, "%d;%99[^;];%99[^;];%d;%d;%d", &nutri[i].numpaciente, nutri[i].datainicio, nutri[i].datafim, &nutri[i].tp, &nutri[i].caloriasMin, &nutri[i].caloriasMax);
            //Para verifcar o que foi lido:
            //printf("%d;%s;%s;%d;%d;%d\n", nutri[i].numpaciente, nutri[i].datainicio, nutri[i].datafim, nutri[i].tp, nutri[i].caloriasMin, nutri[i].caloriasMax);
        }
    }

    if (separador == '\t') {
        for (int i = 0; i < maximodados; i++) {
            fscanf(fp, "%d\t%99[^\t]\t%99[^\t]\t%d\t%d\t%d", &nutri[i].numpaciente, nutri[i].datainicio, nutri[i].datafim, &nutri[i].tp, &nutri[i].caloriasMin, &nutri[i].caloriasMax);
            //Para verifcar o que foi lido:
            //printf("%d\t%s\t%s\t%d\t%d\t%d\n", nutri[i].numpaciente, nutri[i].datainicio, nutri[i].datafim, nutri[i].tp, nutri[i].caloriasMin, nutri[i].caloriasMax);        
        }
    }
    fclose(fp);
    return true;
}

#pragma endregion

#pragma region TÓPICO 2

/**
 * @brief Conta o número de pacientes cujo consumo de calorias ultrapassa o limite definido no plano nutricional.
 *
 * Esta função percorre os arrays de planos nutricionais e dietas e conta quantos pacientes ultrapassaram
 * o limite de calorias definido no plano nutricional para a respectiva refeição.
 *
 * @param plano é o array de structs PlanoNutri contendo os dados dos planos nutricionais.
 * @param dietas é o array de structs Dieta contendo os dados das dietas.
 * @param maximopacientes é o número máximo de pacientes nos arrays.
 * @return Retorna o número de pacientes cujo consumo de calorias ultrapassa o limite definido no plano nutricional.
 */

int NumPacientesUltrapassamCal(PlanoNutri plano[], Dieta dietas[], int maximopacientes) {
    int contador = 0;
        for (int i = 0; i < maximopacientes; i++) {  // Itera sobre o array de pacientes
            if (dietas[i].calorias > plano[i].caloriasMax) {
                contador++; // Se o consumo de calorias na dieta atual excede o limite definido no plano é somada 1 unidade à variável contador

        }
    }
return contador;
    // Retorna o número total de pacientes cujo consumo de calorias ultrapassa o limite
}  

#pragma endregion

#pragma region TÓPICO 3

/**
 * @brief Identifica os pacientes cujo consumo de calorias está fora do intervalo definido no plano nutricional.
 *
 * Esta função percorre os arrays de planos nutricionais, dietas e dados dos pacientes,
 * identificando os pacientes cujo consumo de calorias está fora do intervalo definido
 * pelo plano nutricional. Os pacientes identificados são armazenados na struct NaoCumpPaciente.
 *
 * @param plano é o array de structs PlanoNutri contendo os dados dos planos nutricionais.
 * @param dietas é o array de structs Dieta contendo os dados das dietas.
 * @param dados é o array de structs Paciente contendo os dados dos pacientes.
 * @param dadospacientes é o array de structs NaoCumpPaciente que armazenará os dados dos pacientes que não cumprem.
 * @param maxpaciente é o número máximo de pacientes nos arrays.
 */

void IdentificaForaIntervalo(PlanoNutri plano[], Dieta dietas[], Paciente dados[], NaoCumpPaciente dadospacientes[], int maxpaciente) {
    int num = 0;

    for (int i = 0; i < maxpaciente; i++) {
    // Verifica se o consumo de calorias está fora do intervalo definido no plano
    if (dietas[i].calorias > plano[i].caloriasMax || dietas[i].calorias < plano[i].caloriasMin) {
        // Armazena os dados dos pacientes que não cumprem as condições
        dadospacientes[num].numpaciente = dados[i].numpaciente;
        strcpy(dadospacientes[num].nome, dados[i].nome);
        dadospacientes[num].telefone = dados[i].telefone;
        num++;
        }
    }
}


/**
 * @brief Ordena os pacientes fora do intervalo com base no número do paciente.
 *
 * Esta função ordena o array de pacientes fora do intervalo
 * na struct NaoCumpPaciente com base no número do paciente em ordem decrescente.
 *
 * @param dadospacientes é o array de structs NaoCumpPaciente a ser ordenado.
 * @param maxpaciente é o número máximo de pacientes no array.
 */

void OrdenaPacientesForaIntervalo(NaoCumpPaciente dadospacientes[], int maxpaciente) {
    for (int i = 0; i < maxpaciente - 1; i++) {
        for (int j = i + 1; j < maxpaciente; j++) {
            if (dadospacientes[i].numpaciente < dadospacientes[j].numpaciente) {  // Compara o número dos pacientes para determinar a ordem
            NaoCumpPaciente temp = dadospacientes[i];
            dadospacientes[i] = dadospacientes[j];
            dadospacientes[j] = temp;
            // Troca os elementos se estiverem fora de ordem
            }
        }
    }
}

#pragma endregion

#pragma region TÓPICO 4

/**
 * @brief Lista o plano nutricional para um paciente em uma refeição específica durante um determinado período.
 *
 * Esta função imprime na tela o plano nutricional para um paciente em uma refeição específica durante um período definido.
 *
 * @param planos é o array de structs PlanoNutri que contem os dados dos planos nutricionais.
 * @param maxplanos é o número máximo de planos nutricionais no array.
 * @param numpaciente é o número do paciente para o qual o plano nutricional será listado.
 * @param refeicao é o indice da refeição (0 para 'peq. almoço', 1 para 'almoço', 2 para 'jantar').
 * @param dataInicio é a data de início do período desejado no formato "DD/MM/AAAA".
 * @param dataFim é a data de término do período desejado no formato "DD/MM/AAAA".
 */

void ListaPlanoNutricional(PlanoNutri planos[], int maxplanos, int numpaciente, int refeicao, char dataInicio[], char dataFim[]) {

char aux[N];
    if (refeicao == 0) {
        strcpy(aux, "peq. almoço");
    }
    if (refeicao == 1) {
        strcpy(aux, "almoço");
    }
    if (refeicao == 2) {
        strcpy(aux, "jantar");
    }

    //Criação de uma variável e colocação da string correspondente a cada índice para ser imprimido na consola o valor em string

    printf("Plano Nutricional para o Paciente %d na Refeicao '%s' no periodo de %s a %s:\n\n", numpaciente, aux, dataInicio, dataFim);

    for (int i = 0; i < maxplanos; i++) {
        if (planos[i].numpaciente == numpaciente && planos[i].tp == refeicao && strcmp(planos[i].datainicio, dataInicio) <= 0 && strcmp(planos[i].datafim, dataFim) >= 0) {
            printf("O paciente de número: %d\n", planos[i].numpaciente);
            printf("O plano dura de %s a %s\n", planos[i].datainicio, planos[i].datafim);
            printf("Na refeição %s deve ingerir:\n", aux);
            printf("Calorias Mínimas: %d\n", planos[i].caloriasMin);
            printf("Calorias Máximas: %d\n\n", planos[i].caloriasMax);
        }
    }
}

#pragma endregion

#pragma region TÓPICO 5

/**
 * @brief Calcula as médias de calorias consumidas em diferentes refeições para cada paciente.
 *
 * @param dietas Um array de estruturas Dieta contendo informações sobre as dietas.
 * @param dados Um array de estruturas MediaPaciente para armazenar os resultados das médias.
 * @param maxdietas O número máximo de elementos no array de dietas.
 * @param maxpacientes O número máximo de pacientes.
 * @param dataInicio A data de início do período desejado para o cálculo das médias.
 * @param dataFim A data de fim do período desejado para o cálculo das médias.
 */

void CalcularMediasRefeicoes(Dieta dietas[], MediaPaciente dados[], int maxdietas, int maxpacientes, char dataInicio[], char dataFim[]) {

    for (int i = 0; i < maxpacientes; i++) {
            double auxcontadorPequenoAlmoco = 0.0;
            double auxcontadorAlmoco = 0.0;
            double auxcontadorJantar = 0.0;
            int numPequenoAlmoco = 0;
            int numAlmoco = 0;
            int numJantar = 0;

    for (int j = 0; j < maxdietas; j++) {
                if (strcmp(dietas[j].datainicio, dataInicio) <= 0 && strcmp(dietas[j].datafim, dataFim) >= 0 &&
                    dietas[j].numpaciente == i + 1) {

                    switch (dietas[j].tp) {
                        case 0: // Pequeno Almoço
                            auxcontadorPequenoAlmoco += dietas[j].calorias;
                            numPequenoAlmoco++;
                            break;
                        case 1: // Almoço
                            auxcontadorAlmoco += dietas[j].calorias;
                            numAlmoco++;
                            break;
                        case 2: // Jantar
                            auxcontadorJantar += dietas[j].calorias;
                            numJantar++;
                            break;
            }
        }
    }

    dados[i].numpaciente = i + 1;
    dados[i].mediapequenoalmoco = (numPequenoAlmoco > 0) ? auxcontadorPequenoAlmoco / numPequenoAlmoco : 0;
    dados[i].mediaalmoco = (numAlmoco > 0) ? auxcontadorAlmoco / numAlmoco : 0;
    dados[i].mediajantar = (numJantar > 0) ? auxcontadorJantar / numJantar : 0;
        }
    }

#pragma endregion


