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

int testStart();
/**
 * \fn testStart();
 * \brief Fonction permettant d'afficher les informations relatives au début de la phase de test avec gdb.

* \return int, 0 si le processus s'est déroulé correctement. */

int testEnd();
/**
 * \fn testEnd();
 * \brief Fonction permettant d'afficher les informations relatives à la fin de la phase de test avec gdb.

* \return int, 0 si le processus s'est déroulé correctement. */

int testBasic();
/**
 * \fn testBasic();
 * \brief Fonction permettant d'afficher les performances et les informations relatives aux tests CPU de manière générale.

* \return int, 0 si le processus s'est déroulé correctement. */


int testTriCPU();
/**
 * \fn testTriCPU();
 * \brief Test CPU permettant d'évaluer les performances des algorithmes de tri par l'intermédiaire de gdb.
 *
 * On teste ces aglorithmes sur les listes issues des données fournies, mais également sur des listes déjà triées dans
 * l'ordre croissant ou décroissant, sur des listes contenant les mêmes valeurs, et sur des listes contenant des séries de
 * valeurs identiques successives triées dans un ordre décroissant.
 *
* \return int, 0 si le processus s'est déroulé correctement. */

int testAlgoCPU();
/**
 * \fn testAlgoCPU();
 * \brief Test CPU permettant d'évaluer les performances de nos algorithmes par l'intermédiaire de gdb.
 *
 * On teste chacune de nos méthodes individuellement ainsi que leur intégration globale.
 *
* \return int, 0 si le processus s'est déroulé correctement. */

#endif /* TEST_CPU_H_ */
