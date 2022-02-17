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
	//Série 1
	unsigned short raw_data[3][3][5] = {
			{{1, 5, 8, 9, 10}, //capteur 1
			 {3, 4, 0, 81, 3}, //capteur 2
			 {10, 43, 20, 3, 2} //capteur 3
			}, //sample 2
			{{8, 44, 1, 76, 270}, //capteur 1
			 {53, 77, 53, 1, 33}, //capteur 2
			 {103, 343, 870, 9, 32} //capteur 3
			}, //sample 3
			{{100, 4765, 8728, 9459, 730}, //capteur 1
			 {334, 413, 40, 841, 376}, //capteur 2
			 {610, 65443, 2540, 6653, 2445} //capteur 3
			}
	};
	unsigned short data_expected_1[3][5] = {{1, 5, 8, 9, 10}, //capteur 1
			 {3, 4, 0, 81, 3}, //capteur 2
			 {10, 43, 20, 3, 2} //capteur 3
			};
	unsigned short data_expected_2[3][5] = {{8, 44, 1, 76, 270}, //capteur 1
			 {53, 77, 53, 1, 33}, //capteur 2
			 {103, 343, 870, 9, 32} //capteur 3
			};
	unsigned short data_expected_3[3][5] = {{100, 4765, 8728, 9459, 730}, //capteur 1
			 {334, 413, 40, 841, 376}, //capteur 2
			 {610, 65443, 2540, 6653, 2445} //capteur 3
			};
	//Tests
	for (int i = 0; i <3; i++){
		for (int j = 0; j<5; j++){
			if (data_expected_1[i][j] != raw_data[0][i][j]) flag = -1;
			else if (data_expected_2[i][j] != raw_data[1][i][j]) flag = -1;
			else if (data_expected_3[i][j] != raw_data[2][i][j]) flag = -1;
		}
	}
	if (flag==-1) printf("\n[TEST FAILURE]\n");
	else printf("\n[TEST SUCCESS]\n");
	printf("================================================================================\n");
	return flag;
}

int testUnitaireMediane(){
	printf("\n==================== TEST UNITAIRE MEDIANE ====================\n");
	int flag = 0;
	int len_capteurs = 3;
	int len_pixels = 5;
	//Série 1
	unsigned short data_raw_1[uiSensorCount][uiSensorSize] = {{1, 5, 8, 9, 10}, //capteur 1
			 {3, 4, 0, 81, 3}, //capteur 2
			 {10, 43, 20, 3, 2} //capteur 3
			};
	double Vmediane_attendue_1[len_pixels] = {3, 5, 8, 9, 3};
	double Vmediane[len_pixels] = {0, 0, 0, 0};
	unsigned short temp[len_pixels] = {0, 0, 0, 0};
	SortEngine engine;
	mediane(engine, data_raw_1, temp, Vmediane, len_capteurs, len_pixels);
	for (int i = 0; i < len_pixels; i++){
		printf("Série 1 : Médiane pixel %d : %f, valeur attendue : %f\n", i, Vmediane[i], Vmediane_attendue_1[i]);
		if (Vmediane[i] != Vmediane_attendue_1[i]) flag = -1;
	}
	//Série 2
	unsigned short data_raw_2[uiSensorCount][uiSensorSize] = {{8, 44, 1, 76, 270}, //capteur 1
			 {53, 77, 53, 1, 33}, //capteur 2
			 {103, 343, 870, 9, 32} //capteur 3
			};
	double Vmediane_attendue_2[len_pixels] = {53, 77, 53, 9, 33};
	mediane(engine, data_raw_2, temp, Vmediane, len_capteurs, len_pixels);
	for (int i = 0; i < len_pixels; i++){
		printf("Série 2 : Médiane pixel %d : %f, valeur attendue : %f\n", i, Vmediane[i], Vmediane_attendue_2[i]);
		if (Vmediane[i] != Vmediane_attendue_2[i]) flag = -1;
	}
	//Série 3
	unsigned short data_raw_3[uiSensorCount][uiSensorSize] = {{100, 4765, 8728, 9459, 730}, //capteur 1
			 {334, 413, 40, 841, 376}, //capteur 2
			 {610, 65443, 2540, 6653, 2445}, //capteur 3
			 {61, 643, 250, 653, 24}, //capteur 4
			};
	double Vmediane_attendue_3[len_pixels] = {217, 2704, 1395, 3747, 553};
	mediane(engine, data_raw_3, temp, Vmediane, len_capteurs+1, len_pixels);
	for (int i = 0; i < len_pixels; i++){
		printf("Série 3 : Médiane pixel %d : %f, valeur attendue : %f\n", i, Vmediane[i], Vmediane_attendue_3[i]);
		if (Vmediane[i] != Vmediane_attendue_3[i]) flag = -1;
	}
	//Tests
	if (flag==-1) printf("\n[TEST FAILURE]\n");
	else printf("\n[TEST SUCCESS]\n");
	printf("================================================================================\n");
	return flag;
}

int testUnitaireMoyenne(){
	printf("\n==================== TEST UNITAIRE MOYENNE ====================\n");
	int flag = 0;
	int len_capteurs = 3;
	int len_pixels = 5;
	//Série 1
	int erreur = 5;
	unsigned short data_raw_1[uiSensorCount][uiSensorSize] = {{1, 5, 8, 9, 10}, //capteur 1
			 {3, 4, 0, 81, 3}, //capteur 2
			 {10, 43, 20, 3, 2} //capteur 3
			};
	double Vmediane_attendue_1[len_pixels] = {3, 5, 8, 9, 3};
	double Vmoyenne[len_pixels] = {0, 0, 0, 0, 0};
	double Vmoyenne_attendue1[len_pixels] = {2, 4.5, 8, 9, 2.5};
	moyenne(data_raw_1, Vmediane_attendue_1, Vmoyenne, len_capteurs, len_pixels, erreur);
	for (int i = 0; i < len_pixels; i++){
		printf("Série 1 : Moyenne pixel %d : %f, valeur attendue : %f\n", i, Vmoyenne[i], Vmoyenne_attendue1[i]);
		if (Vmoyenne[i] != Vmoyenne_attendue1[i]) flag = -1;
	}
	//Série 2
	unsigned short data_raw_2[uiSensorCount][uiSensorSize] = {{8, 44, 1, 76, 270}, //capteur 1
			 {53, 77, 53, 1, 33}, //capteur 2
			 {103, 343, 870, 9, 32} //capteur 3
			};
	double Vmediane_attendue_2[len_pixels] = {53, 77, 53, 9, 33};
	double Vmoyenne_attendue2[len_pixels] = {53, 77, 53, 9, 32.5};
	moyenne(data_raw_2, Vmediane_attendue_2, Vmoyenne, len_capteurs, len_pixels, erreur);
	for (int i = 0; i < len_pixels; i++){
		printf("Série 1 : Moyenne pixel %d : %f, valeur attendue : %f\n", i, Vmoyenne[i], Vmoyenne_attendue2[i]);
		if (Vmoyenne[i] != Vmoyenne_attendue2[i]) flag = -1;
	}
	//Série 3
	unsigned short data_raw_3[uiSensorCount][uiSensorSize] = {{100, 4765, 8728, 9459, 730}, //capteur 1
			 {334, 413, 40, 841, 376}, //capteur 2
			 {610, 65443, 2540, 6653, 2445}, //capteur 3
			 {61, 643, 250, 653, 24}, //capteur 4
			};
	double Vmediane_attendue_3[len_pixels] = {217, 2704, 1395, 3747, 553};
	double Vmoyenne_attendue3[len_pixels] = {0, 0, 0, 0, 0};
	moyenne(data_raw_3, Vmediane_attendue_3, Vmoyenne, len_capteurs, len_pixels, erreur);
	for (int i = 0; i < len_pixels; i++){
		printf("Série 1 : Moyenne pixel %d : %f, valeur attendue : %f\n", i, Vmoyenne[i], Vmoyenne_attendue3[i]);
		if (Vmoyenne[i] != Vmoyenne_attendue3[i]) flag = -1;
	}
	//Tests
	if (flag==-1) printf("\n[TEST FAILURE]\n");
	else printf("\n[TEST SUCCESS]\n");
	printf("================================================================================\n");
	return flag;
}

int testUnitaireMémorisation(){
	printf("\n==================== TEST UNITAIRE MEMORISATION ====================\n");
	int flag = 0;
	int len_pixels = 4;
	//Série 1
	double test[len_pixels] = {10, 5, 2, 1000};
	double Vref[len_pixels] = {0, 0, 0, 0};
	double Vattendu[len_pixels] = {10, 5, 2, 1000};
	mémorisation(Vref, test, len_pixels);
	for (int i = 0; i < len_pixels; i++){
		printf("Vecteur d'origine 1 case %d : %f\n", i, test[i]);
		printf("Vecteur copié 1 case %d: %f\n", i, Vref[i]);
		if (Vref[i] != Vattendu[i]) flag = -1;
	}
	//Série 2
	double test2[len_pixels] = {0, 0, 0, 0};
	double Vref2[len_pixels] = {0, 0, 0, 0};
	double Vattendu2[len_pixels] = {0, 0, 0, 0};
	mémorisation(Vref2, test2, len_pixels);
	for (int i = 0; i < len_pixels; i++){
		printf("Vecteur d'origine 2 case %d : %f\n", i, test2[i]);
		printf("Vecteur copié 2 case %d: %f\n", i, Vref2[i]);
		if (Vref2[i] != Vattendu2[i]) flag = -1;
	}
	//Série 3
	double test3[len_pixels] = {10.0, 5.32, 193.342, 1000};
	double Vref3[len_pixels] = {0, 0, 0, 0};
	double Vattendu3[len_pixels] = {10.0, 5.32, 193.342, 1000};
	mémorisation(Vref3, Vattendu3, len_pixels);
	for (int i = 0; i < len_pixels; i++){
		printf("Vecteur d'origine 3 case %d : %f\n", i, test3[i]);
		printf("Vecteur copié 3 case %d: %f\n", i, Vref3[i]);
		if (Vref3[i] != test3[i]) flag = -1;
	}
	//Tests
	if (flag==-1) printf("\n\n[TEST FAILURE]\n");
	else printf("\n\n[TEST SUCCESS]\n");
	printf("================================================================================\n");
	return flag;
}

int testUnitaireSoustraction(){
	printf("\n==================== TEST UNITAIRE SOUSTRACTION ====================\n");
	int flag = 0;
	int len_pixels = 4;
	//Série 1
	double Vref[4] = {100, 5, 2, 1000};
	double Vmu[4] = {10, 53, 23, 10003};
	double Vs[len_pixels] = {0, 0, 0, 0};
	double Vattendu[len_pixels] = {0, 48, 21, 9003};
	soustraction(Vref, Vmu, Vs, len_pixels);
	for (int i = 0; i < len_pixels; i++){
		printf("Vecteur soustrait 1 case %d : %f\t", i, Vs[i]);
		printf("\nVecteur attendu 1 case %d : %f\t", i, Vattendu[i]);
		if (Vs[i] != Vattendu[i]) flag = -1;
	}
	//Série 2
	double Vref2[4] = {100, 500, 200, 100000};
	double Vmu2[4] = {10, 53, 23, 10003};
	double Vs2[len_pixels] = {0, 0, 0, 0};
	double Vattendu2[len_pixels] = {0, 0, 0, 0};
	soustraction(Vref2, Vmu2, Vs2, len_pixels);
	for (int i = 0; i < len_pixels; i++){
		printf("\nVecteur soustrait 2 case %d : %f\t", i, Vs2[i]);
		printf("\nVecteur attendu 2 case %d : %f\t", i, Vattendu2[i]);
		if (Vs2[i] != Vattendu2[i]) flag = -1;
	}
	//Série 3
	double Vref3[4] = {1, 50, 200, 100};
	double Vmu3[4] = {10, 234, 2712, 653};
	double Vs3[len_pixels] = {0, 0, 0, 0};
	double Vattendu3[len_pixels] = {9, 184, 2512, 553};
	soustraction(Vref3, Vmu3, Vs3, len_pixels);
	for (int i = 0; i < len_pixels; i++){
		printf("\nVecteur soustrait 3 case %d : %f\t", i, Vs3[i]);
		printf("\nVecteur attendu 3 case %d : %f\t", i, Vattendu3[i]);
		if (Vs3[i] != Vattendu3[i]) flag = -1;
	}
	//Tests
	if (flag==-1) printf("\n\n[TEST FAILURE]\n");
	else printf("\n\n[TEST SUCCESS]\n");
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

