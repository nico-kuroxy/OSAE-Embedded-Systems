/**
 * \file testsUnitaires.h
 * \brief Déclarations des fonctions utilisées pour les tests unitaires du projet de système embarqué.
 * \author Nicolas Erbetti & Hugo Destannes Froment
 * \version 0.1
 * \date 2 février 2022
 *
 * Déclaration des fonctions développées pour valider le bon fonctionnement des différents algorithmes du projet.
 *
 */

#ifndef TEST_UNIT_H_
#define TEST_UNIT_H_

#include "../algorithmes.h" //Pour les fonctions testées
#include <stdio.h> //Pour les printf

int testUnitaireExtract();
/**
 * \fn testUnitaireExtract();
 * \brief Test unitaire vérifiant le bon fonctionnement de la fonction extract.
 *
* \return int, 0 si le processus s'est déroulé correctement. */

int testUnitaireMediane();
/**
 * \fn testUnitaireMediane()
 * \brief Test unitaire vérifiant le bon fonctionnement de la fonction médiane.
 *
* \return int, 0 si le processus s'est déroulé correctement. */

int testUnitaireMoyenne();
/**
 * \fn testUnitaireMoyenne();
 * \brief Test unitaire vérifiant le bon fonctionnement de la fonction moyenne.
 *
* \return int, 0 si le processus s'est déroulé correctement. */

int testUnitaireMémorisation();
/**
 * \fn testUnitaireMémorisation();
 * \brief Test unitaire vérifiant le bon fonctionnement de la fonction mémorisation.
 *
* \return int, 0 si le processus s'est déroulé correctement. */

int testUnitaireSoustraction();
/**
 * \fn testUnitaireSoustraction();
 * \brief Test unitaire vérifiant le bon fonctionnement de la fonction soustraction.
 *
* \return int, 0 si le processus s'est déroulé correctement. */

int testUnitaireDécompte();
/**
 * \fn testUnitaireDécompte();
 * \brief Test unitaire vérifiant le bon fonctionnement de la fonction décompte.
 *
* \return int, 0 si le processus s'est déroulé correctement. */

int testUnitaireTraitement();
/**
 * \fn testUnitaireTraitement();
 * \brief Test d'intégration vérifiant le bon fonctionnement du processus global avec l'enchaînement des différentes fonctions.
 *
 * On compare la liste du nombre de hotspots attendus avec la liste retournée par le processus global.
 * On considère que le test est réussi si on a plus de 95% de correspondance.
 *
* \return int, 0 si le processus s'est déroulé correctement. */

#endif /* TEST_UNIT_H_ */
