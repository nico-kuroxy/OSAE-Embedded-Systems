/**
 * \file testsUnitaires.cpp
 * \brief Corps des fonctions utilisées pour les tests unitaires du projet de système embarqué.
 * \author Nicolas Erbetti & Hugo Destannes Froment
 * \version 0.1
 * \date 2 février 2022
 *
 * Corps des fonctions développées pour valider le bon fonctionnement des différents algorithmes du projet.
 *
 */

#include "testsUnitaires.h"

int testUnitaireExtract(){
	return 0;
}

int testUnitaireMediane(){
	int len_capteurs = 3;
	int len_pixels = 10;
	unsigned short test[10] = {1, 5, 2, 9, 7, 3, 2, 4, 2, 92};
	unsigned short test2[10] = {11, 52, 22, 93, 73, 3, 23, 42, 32, 92};
	unsigned short test3[10] = {4, 4, 1, 8, 71, 34, 22, 2, 22, 12};

	unsigned short values[uiSensorCount][uiSensorSize];
	for (int i = 0; i < len_pixels; i++){
		values[0][i] = test[i];
		values[1][i] = test2[i];
		values[2][i] = test3[i];
	}
	double Vmediane[len_pixels] = {0, 0, 0, 0};
	unsigned short temp[len_pixels] = {0, 0, 0, 0};
	SortEngine engine;

	mediane(engine, values, temp, Vmediane, len_capteurs, len_pixels);
	printf("testUnitaireMediane\n");
	for (int i = 0; i < len_pixels; i++){
		printf("Médiane pixel %d : %f\n\n", i, Vmediane[i]);
	}
	return 0;
}

int testUnitaireMoyenne(){
	int len_capteurs = 3;
	int len_pixels = 4;
	int erreur = 5;
	unsigned short test[4] = {10, 5, 2, 1000};
	unsigned short test2[4] = {11, 63, 21, 8};
	unsigned short test3[4] = {120, 4, 1, 8};
	double Vmediane[4] = {11, 5, 2, 8};

	unsigned short values[uiSensorCount][uiSensorSize]; //On n'initialise pas le tableau "à la main" avec des valeurs par défaut puisque cela prendrait trop de ressources (5000 valeurs)
	for (int i = 0; i < len_pixels; i++){
		values[0][i] = test[i];
		values[1][i] = test2[i];
		values[2][i] = test3[i];
	}
	double Vmoyenne[len_pixels] = {0, 0, 0, 0};

	moyenne(values, Vmediane, Vmoyenne, len_capteurs, len_pixels, erreur);
	printf("testUnitaireMoyenne\n");
	for (int i = 0; i < len_pixels; i++){
		printf("Médiane pixel %d : %f\n", i, Vmediane[i]);
		printf("Moyenne pixel %d : %f\n\n", i, Vmoyenne[i]);
	}
	return 0;
}

int testUnitaireMémorisation(){
	int len_pixels = 4;
	double test[4] = {10, 5, 2, 1000};
	double Vref[len_pixels] = {0, 0, 0, 0};
	mémorisation(Vref, test, len_pixels);
	printf("testUnitaireMémorisation\n");
	for (int i = 0; i < len_pixels; i++){
		printf("Vecteur d'origine case %d : %f\n", i, test[i]);
		printf("Vecteur copié case %d: %f\n\n", i, Vref[i]);
	}
	return 0;
}

int testUnitaireSoustraction(){
	int len_pixels = 4;
	double Vref[4] = {100, 5, 2, 1000};
	double Vmu[4] = {10, 53, 23, 10003};
	double Vs[len_pixels] = {0, 0, 0, 0};
	soustraction(Vref, Vmu, Vs, len_pixels);
	printf("testUnitaireSoustraction\n");
	for (int i = 0; i < len_pixels; i++){
		printf("Vecteur soustrait case %d : %f\n", i, Vs[i]);
	}
	return 0;
}

int testUnitaireDécompte(){
	int len_pixels = 4;
	double Vs[4] = {100, 5, 2, 1000};
	double seuil = 100;
	int k = décompteHotspot(Vs, seuil, len_pixels);
	printf("testUnitaireDécompte\n");
	printf("Décompte : %d\n\n", k);
	return 0;
}

int testUnitaireTraitement(){
	//int *nb_hotspots = (int*) malloc(uiSimCount * sizeof(int));
	int nb_hotspots[uiSimCount] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	traitementGlobal((unsigned short ***)p_usSrcData, nb_hotspots, uiSimCount, uiSensorCount, uiSensorSize, 0, usHotspotDetectionThreshold, usGrantedError);
	for (int c=0; c < uiSimCount; c++){
		printf("Nombre d'hotspots de l'échantillon %d : %d\n", c+1, nb_hotspots[c]);
	}
	return 0;
}

