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
	printf("\n==================== TEST UNITAIRE EXTRACTION ====================\n");
	int flag = 0;
	printf("================================================================================\n");
	return flag;
}

int testUnitaireMediane(){
	printf("\n==================== TEST UNITAIRE MEDIANE ====================\n");
	int flag = 0;
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
	printf("================================================================================\n");
	return flag;
}

int testUnitaireMoyenne(){
	printf("\n==================== TEST UNITAIRE MOYENNE ====================\n");
	int flag = 0;
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
	printf("================================================================================\n");
	return flag;
}

int testUnitaireMémorisation(){
	printf("\n==================== TEST UNITAIRE MEMORISATION ====================\n");
	int flag = 0;
	int len_pixels = 4;
	double test[4] = {10, 5, 2, 1000};
	double Vref[len_pixels] = {0, 0, 0, 0};
	mémorisation(Vref, test, len_pixels);
	printf("testUnitaireMémorisation\n");
	for (int i = 0; i < len_pixels; i++){
		printf("Vecteur d'origine case %d : %f\n", i, test[i]);
		printf("Vecteur copié case %d: %f\n\n", i, Vref[i]);
	}
	printf("================================================================================\n");
	return flag;
}

int testUnitaireSoustraction(){
	printf("\n==================== TEST UNITAIRE SOUSTRACTION ====================\n");
	int flag = 0;
	int len_pixels = 4;
	double Vref[4] = {100, 5, 2, 1000};
	double Vmu[4] = {10, 53, 23, 10003};
	double Vs[len_pixels] = {0, 0, 0, 0};
	soustraction(Vref, Vmu, Vs, len_pixels);
	printf("testUnitaireSoustraction\n");
	for (int i = 0; i < len_pixels; i++){
		printf("Vecteur soustrait case %d : %f\n", i, Vs[i]);
	}
	printf("================================================================================\n");
	return flag;
}

int testUnitaireDécompte(){
	printf("\n==================== TEST UNITAIRE DECOMPTE HOTSPOT ====================\n");
	int flag = 0;
	int len_pixels = 4;
	//Série 1
	double Vs[4] = {100, 5, 2, 1000};
	double seuil = 100;
	int nb_1 = 1;
	int k_1 = décompteHotspot(Vs, seuil, len_pixels);
	printf("Nombre de hotspots détectés série 1 : %d\n", k_1);
	printf("Nombre de hotspots attendus : %d\n", nb_1);
	//Série 2
	double Vs2[4] = {0, 0, 0, 0};
	seuil = 1;
	int nb_2 = 0;
	int k_2 = décompteHotspot(Vs2, seuil, len_pixels);
	printf("Nombre de hotspots détectés série 2 : %d\n", k_2);
	printf("Nombre de hotspots attendus : %d\n", nb_2);
	//Série 3
	double Vs3[4] = {1000, 1001, 0.1, 10000};
	seuil = 0;
	int nb_3 = 4;
	int k_3 = décompteHotspot(Vs3, seuil, len_pixels);
	printf("Nombre de hotspots détectés série 1 : %d\n", k_3);
	printf("Nombre de hotspots attendus : %d\n", nb_3);
	//Tests
	if (k_1 != nb_1){ flag = -1; printf("\n[TEST FAILURE]\n");}
	else if (k_2 != nb_2){ flag = -1; printf("\n[TEST FAILURE]\n");}
	else if (k_3 != nb_3){ flag = -1; printf("\n[TEST FAILURE]\n");}
	else printf("\n[TEST SUCCESS]\n");
	printf("================================================================================\n");
	return flag;
}

int testUnitaireTraitement(){
	printf("\n==================== TEST UNITAIRE TRAITEMENT ====================\n");
	int flag = 0;
	int nb_hotspots[uiSimCount] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int nb_hotspots_attendus[uiSimCount] = {
			0, 9, 6, 9, 11,
			9, 7, 7, 5, 7,
			11, 12, 8, 11, 8,
			9, 3, 15, 11, 19,
			8, 4, 11, 13, 10,
			14, 10, 11, 9, 8,
			9, 10, 10, 9, 11,
			11, 7, 5, 6, 6,
			14, 10, 6, 8, 8,
			11, 6, 14, 6, 7
	};
	traitementGlobal(p_usSrcData, nb_hotspots, uiSimCount, uiSensorCount, uiSensorSize, 0, usHotspotDetectionThreshold, usGrantedError);
	float nb_correspondance = 0;
	for (int c=0; c < (int)uiSimCount; c++){
		if (nb_hotspots[c] == nb_hotspots_attendus[c]){ nb_correspondance ++;}
		printf("Nombre d'hotspots de l'échantillon %d : %d\n", c+1, nb_hotspots[c]);
		printf("Nombre d'hostpots attendus pour l'échantillon %d : %d\n", c+1, nb_hotspots_attendus[c]);
	}
	float taux_de_correspondance = nb_correspondance/uiSimCount;
	if (taux_de_correspondance<0.95){
		printf("\n[TEST FAILURE] : taux de correspondance de %f, inférieur à 0.95.\n", taux_de_correspondance);
		flag = -1;
	}
	else printf("\n[TEST SUCCESS] : taux de correspondance de %f, supérieur ou égal à 0.95.\n", taux_de_correspondance);
	printf("================================================================================\n");
	return flag;
}

