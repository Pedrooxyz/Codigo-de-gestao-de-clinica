/**
 * @file Dados.h
 * @author Pedro Ribeiro, Ricardo Fernandes, Carolina Branco (a27960@alunos.ipca.pt a279861@alunos.opca.pt a27983@alunos.ipca.pt)
 * @brief Fornece estruturas de dados que podem ser usadas para representar informações sobre pacientes, dietas, planos nutricionais e métricas 
 * relacionadas à ingestão de calorias.
 * @version 0.1
 * @date 2023-12-27
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once

#define N 30
#define M 40
#define L 50
#define E 5 //se alterarem o numero de pacientes basta mudar este valor para a nova quantidade

#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#include <string.h>
#pragma warning (disable: 4996)

//Criação das structs necessárias

typedef enum { PEQUENO_ALMOCO, ALMOCO, JANTAR } Refeicao;

typedef struct Dieta {
	int numpaciente;  /**< Número de paciente*/
	char datainicio[N]; /**< Data de início da dieta*/
	char datafim[N]; /**< Data fim da dieta*/
		// Achamos mais produtivo pôr em vez de uma variável para a data pôr uma data inicio e uma data fim
	Refeicao tp; /**< Tipo da refeição (Pequeno-almoço;Almoço;Jantar)*/
	char alimento[M]; /**< Alimento ingerido pelo paciente*/
	int calorias; /**< Calorias ingeridas pelo paciente*/

}Dieta;

typedef struct Paciente {
	int numpaciente; /**< Número de paciente*/
	char nome[N]; /**< Nome do paciente*/
	int telefone; /**< Número do telefone do paciente*/
}Paciente;

typedef struct PlanoNutri {
	int numpaciente; /**< Número de paciente*/
	char datainicio[N]; /**< Data de início do plano nutricional*/
	char datafim[N]; /**< Data de fim do plano nutricional*/
	Refeicao tp; /**< Tipo da refeição (Pequeno-almoço;Almoço;Jantar)*/
	int caloriasMin; /**< Número mínimo de calorias que o paciente deve consumir*/
	int caloriasMax; /**< Número máximo de calorias que o paciente deve consumir*/
}PlanoNutri;

typedef struct NaoCumpPaciente {
	int numpaciente; /**< Número do paicente*/
	char nome[N]; /**< Nome do paciente*/
	int telefone; /**< Número de telefone do paciente*/
}NaoCumpPaciente;

typedef struct MediaPaciente {
	int numpaciente; /**< Número de paciente*/
	double mediapequenoalmoco; /**< Média de calorias consumidas durante o pequeno-almoço durante um período específico de tempo*/
	double mediaalmoco; /**< Média de calorias consumidas durante o almoço durante um período específico de tempo*/
	double mediajantar; /**< Média de calorias consumidas durante o jantar durante um período específico de tempo*/
}MediaPaciente;

