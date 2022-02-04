/**
 * \file testCPU.h
 * \brief Déclarations des fonctions utilisées pour déterminer le budget CPU du projet de système embarqué.
 * \author Nicolas Erbetti & Hugo Destannes Froment
 * \version 0.1
 * \date 2 février 2022
 *
 * Déclaration des fonctions de tests qui permettent d'évaluer la sollicitation du CPU par nos algorithmes.
 *
 */

#ifndef TEST_CPU_H_
#define TEST_CPU_H_

#include "../algorithmes.h" //Pour les fonctions testées
#include <stdio.h> //Pour les printf

int test(const char *testName, int testId);

int testTri(const char *testName, int testId, int typeTri);

int testTriCPU();

int testAlgoCPU();

#endif /* TEST_CPU_H_ */
