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
/**
 * \fn test(const char *testName, int testId)
 * \brief Fonction permettant d'afficher les performances et les informations relatives aux tests CPU de manière générale.
 *
 * \param testName tableau de caractère contenant le nom du test effectué
 * \param testId int représentant la classe de test à effectuer (0 pour le test d'initialisation, 1 pour un test général, 2 pour le test de fin).
 *
* \return int, 0 si le processus s'est déroulé correctement. */

int testTri(const char *testName, int testId, int typeTri);
/**
 * \fn testTri(const char *testName, int testId, int typeTri);
 * \brief Fonction permettant d'afficher les performances et les informations relatives aux tests CPU des algoritmes de tri.
 *
 * \param testName tableau de caractère contenant le nom du test effectué
 * \param testId int représentant la classe de test à effectuer (0 pour le test d'initialisation, 1 pour un test général, 2 pour le test de fin).
 * \param typeTri int représentant le type d'algorithme de tri que nous utilisons. Elle nous permet d'afficher le tableau trié défini de manière globale correspondant.
 *
* \return int, 0 si le processus s'est déroulé correctement. */

int testTriCPU();
/**
 * \fn testTriCPU();
 * \brief Test CPU permettant d'évaluer les performances des algorithmes de tri par l'intermédiaire de gdb.
 *
* \return int, 0 si le processus s'est déroulé correctement. */

int testAlgoCPU();
/**
 * \fn testAlgoCPU();
 * \brief Test CPU permettant d'évaluer les performances de nos algorithmes par l'intermédiaire de gdb.
 *
* \return int, 0 si le processus s'est déroulé correctement. */

#endif /* TEST_CPU_H_ */
