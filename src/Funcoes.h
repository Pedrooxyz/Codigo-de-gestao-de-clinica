/**
 * @file Funcoes.h
 * @author Pedro Ribeiro, Ricardo Fernandes, Carolina Branco (a27960@alunos.ipca.pt a279861@alunos.opca.pt a27983@alunos.ipca.pt)
 * @brief Declaração das funções
 * @version 0.1
 * @date 2023-12-27
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once
#include "Dados.h"
#pragma warning (disable: 4996)

void MostraAjuda();

bool ExportaDadosPacientes(char nomeFicheiro[], Paciente pacientes[], int maximoPacientes);
bool LeDadosPacientes(char separador, char fileName[], Paciente *dados,  int maximoplanos);

bool ExportaDadosDieta(char fileName[], Dieta dietas[], int maximodietas);
bool LeDadosDieta(char separador, char fileName[], Dieta *dietas, int maximodietas);

bool ExportaDadosPlanoNutri(char fileName[], PlanoNutri plano[], int maximodietas);
bool LeDadosPlanoNutri(char separador, char fileName[], PlanoNutri *nutri, int maximodados);

int NumPacientesUltrapassamCal(PlanoNutri plano[], Dieta dietas[], int maximopacientes);

void IdentificaForaIntervalo(PlanoNutri plano[], Dieta dietas[], Paciente dados[], NaoCumpPaciente dadospacientes[], int maxpaciente);

void OrdenaPacientesForaIntervalo(NaoCumpPaciente dadospacientes[], int maxpaciente);

void ListaPlanoNutricional(PlanoNutri planos[], int maxplanos, int numpaciente, int refeicao, char dataInicio[], char dataFim[]);

void CalcularMediasRefeicoes(Dieta dietas[], MediaPaciente dados[], int maxdietas, int maxpacientes, char dataInicio[], char dataFim[]);

void GerarTabelaRefeicoes(Paciente pacientes[], Dieta dietas[], PlanoNutri planos[], int maxPacientes, int maxDietas, int maxPlanos);

