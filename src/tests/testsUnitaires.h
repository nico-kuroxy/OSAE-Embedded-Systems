/**
 * \file testUnitaires.h
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

int testUnitaireMediane();

int testUnitaireMoyenne();

int testUnitaireMémorisation();

int testUnitaireSoustraction();

int testUnitaireDécompte();

int testUnitaireTraitement();

#endif /* TEST_UNIT_H_ */
