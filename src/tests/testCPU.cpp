/**
 * \file testCPU.cpp
 * \brief Corps des fonctions utilisées pour déterminer le budget CPU du projet de système embarqué.
 * \author Nicolas Erbetti & Hugo Destannes Froment
 * \version 0.1
 * \date 2 février 2022
 *
 * Corps des fonctions de tests qui permettent d'évaluer la sollicitation du CPU par nos algorithmes.
 *
 */

#include "testCPU.h"

int testStart(){
	int static testStart = 0;
	return testStart++;
}

int testEnd(){
	int static testEnd = 0;
	return testEnd++;
}

int testBasic(){
	int static testBasic = 0;
	return testBasic++;
}

int testTriCPU(){

	//INITIALISATION/////////////////////////////////////////////////////////////////////////
	SortEngine *engine = new SortEngine();
	unsigned short quick[uiSensorCount] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	unsigned short heap[uiSensorCount] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	printf("\n====== Test Start TRI GLOBAL ======\n");
	testStart();
	/////////////////////////////////////////////////////////////////////////////////////////

	////////////////////////////////////////////////////////////////////////////////////////
	//Tests cpu des algo de tri : on va tester le tri de TOUTES nos données et en déduire le meilleur des deux.
	printf("\n====== Test Start TRI Sample Complet ======\n");
	testStart();
	//Elaboration de la base de référence pour Quick
	for (int sample = 0; sample < (int)uiSimCount; sample++){
		for (int colonne_pixel_k = 0; colonne_pixel_k<(int)uiSensorSize; colonne_pixel_k++){
			for (int ligne_capteur = 0; ligne_capteur<(int)uiSensorCount; ligne_capteur++){
				int temp = p_usSrcData[sample][ligne_capteur][colonne_pixel_k];
				quick[ligne_capteur] = temp;
			}
			//Tests des tris
			engine->setSortType(SortEngine::QUICK);
			engine->sort(quick, uiSensorCount);
		}
	}
	printf("\n======= Test Quick | Sample complet ======\n");
	testBasic();

	//Elaboration de la base de référence pour Heap
	for (int sample = 0; sample < (int)uiSimCount; sample++){
		for (int colonne_pixel_k = 0; colonne_pixel_k<(int)uiSensorSize; colonne_pixel_k++){
			for (int ligne_capteur = 0; ligne_capteur<(int)uiSensorCount; ligne_capteur++){
				int temp = p_usSrcData[sample][ligne_capteur][colonne_pixel_k];
				heap[ligne_capteur] = temp;
			}
			//Tests des tris;
			engine->setSortType(SortEngine::HEAP);
			engine->sort(heap, uiSensorCount);
		}
	}
	printf("\n======= Test Heap | Sample complet ======\n");
	testBasic();
	printf("\n======= Test End TRI Sample Complet ======\n");
	testEnd();
	/////////////////////////////////////////////////////////////////////////////////////////

	/////////////////////////////////////////////////////////////////////////////////////////
	//Elaboration des listes déjà triées dans un ordre croissant
	for (int index = 0; index< (int) uiSensorCount; index++){
		heap[index] = index;
		quick[index] = index;
	}
	//Affichage des listes nontriées
	printf("\nListe quick croissant nontriée : \n");
	for (int i=0; i<(int)uiSensorCount; i++){
		printf("%d\t", quick[i]);
	}
	printf("\nListe heap croissant nontriée : \n");
	for (int i=0; i<(int)uiSensorCount; i++){
		printf("%d\t", heap[i]);
	}
	//Début du test
	printf("\n\n====== Test Start TRI SIMPLE CROISSANT ======\n");
	testStart();
	//Tests des tris;
	engine->setSortType(SortEngine::QUICK);
	engine->sort(quick, uiSensorCount);
	printf("\n======= Test Quick | Tri Simple Croissant ======\n");
	testBasic();
	engine->setSortType(SortEngine::HEAP);
	engine->sort(heap, uiSensorCount);
	printf("\n======= Test Heap | Tri Simple Croissant ======\n");
	testBasic();
	//Affichage des listes triées
	printf("\nListe quick triée : \n");
	for (int i=0; i<(int)uiSensorCount; i++){
		printf("%d\t", quick[i]);
	}
	printf("\nListe heap triée : \n");
	for (int i=0; i<(int)uiSensorCount; i++){
		printf("%d\t", heap[i]);
	}
	//Fin du test
	printf("\n\n======= Test End TRI SIMPLE CROISSANT ======\n");
	testEnd();
	/////////////////////////////////////////////////////////////////////////////////////////

	/////////////////////////////////////////////////////////////////////////////////////////
	//Elaboration des listes déjà triées dans un ordre décroissant
	for (int index = 0; index< (int) uiSensorCount; index++){
		heap[index] = uiSensorCount-index;
		quick[index] = uiSensorCount-index;
	}
	//Affichage des listes nontriées
	printf("\nListe quick décroissant nontriée : \n");
	for (int i=0; i<(int)uiSensorCount; i++){
		printf("%d\t", quick[i]);
	}
	printf("\nListe heap décroissant nontriée : \n");
	for (int i=0; i<(int)uiSensorCount; i++){
		printf("%d\t", heap[i]);
	}
	//Début du test
	printf("\n\n====== Test Start TRI SIMPLE DéCROISSANT ======\n");
	testStart();
	//Tests des tris;
	engine->setSortType(SortEngine::QUICK);
	engine->sort(quick, uiSensorCount);
	printf("\n======= Test Quick | Tri Simple DéCroissant ======\n");
	testBasic();
	engine->setSortType(SortEngine::HEAP);
	engine->sort(heap, uiSensorCount);
	printf("\n======= Test Heap | Tri Simple DéCroissant ======\n");
	testBasic();
	//Affichage des listes triées
	printf("\nListe quick décroissant triée : \n");
	for (int i=0; i<(int)uiSensorCount; i++){
		printf("%d\t", quick[i]);
	}
	printf("\nListe heap décroissant triée : \n");
	for (int i=0; i<(int)uiSensorCount; i++){
		printf("%d\t", heap[i]);
	}
	//Fin du test
	printf("\n\n======= Test End TRI SIMPLE DéCROISSANT ======\n");
	testEnd();
	/////////////////////////////////////////////////////////////////////////////////////////

	/////////////////////////////////////////////////////////////////////////////////////////
	//Elaboration des listes possédant les mêmes valeurs
	for (int index = 0; index< (int) uiSensorCount; index++){
		heap[index] = 100;
		quick[index] = 100;
	}
	//Affichage des listes nontriées
	printf("\nListe quick same nontriée : \n");
	for (int i=0; i<(int)uiSensorCount; i++){
		printf("%d\t", quick[i]);
	}
	printf("\nListe heap same nontriée : \n");
	for (int i=0; i<(int)uiSensorCount; i++){
		printf("%d\t", heap[i]);
	}
	//Début du test
	printf("\n\n====== Test Start TRI SIMPLE IDENTIQUE ======\n");
	testStart();
	//Tests des tris;
	engine->setSortType(SortEngine::QUICK);
	engine->sort(quick, uiSensorCount);
	printf("\n======= Test Quick | Tri Simple Identique ======\n");
	testBasic();
	engine->setSortType(SortEngine::HEAP);
	engine->sort(heap, uiSensorCount);
	printf("\n======= Test Heap | Tri Simple Identique ======\n");
	testBasic();
	//Affichage des listes triées
	printf("\nListe quick same triée : \n");
	for (int i=0; i<(int)uiSensorCount; i++){
		printf("%d\t", quick[i]);
	}
	printf("\nListe heap same triée : \n");
	for (int i=0; i<(int)uiSensorCount; i++){
		printf("%d\t", heap[i]);
	}
	//Fin du test
	printf("\n\n======= Test End TRI SIMPLE Identique ======\n");
	testEnd();
	/////////////////////////////////////////////////////////////////////////////////////////

	/////////////////////////////////////////////////////////////////////////////////////////
	//Elaboration des séries de mêmes valeurs rangées dans un ordre croissant

	/////////////////////////////////////////////////////////////////////////////////////////

	/////////////////////////////////////////////////////////////////////////////////////////
	//Elaboration des séries de mêmes valeurs rangées dans un ordre décroissant
	for (int index = 0; index < 10; index++){
		for (int index_2 = 0; index_2 < 5; index_2++){
			quick[index*5 + index_2] = 5 - index;
			heap[index*5 + index_2] = 5 - index;
		}
	}
	//Affichage des listes nontriées
	printf("\nListe quick série décroissante nontriée : \n");
	for (int i=0; i<(int)uiSensorCount; i++){
		printf("%d\t", quick[i]);
	}
	printf("\nListe heap série croissante nontriée : \n");
	for (int i=0; i<(int)uiSensorCount; i++){
		printf("%d\t", heap[i]);
	}
	//Début du test
	printf("\n\n====== Test Start TRI SERIE DéCROISSANTE ======\n");
	testStart();
	//Tests des tris;
	engine->setSortType(SortEngine::QUICK);
	engine->sort(quick, uiSensorCount);
	printf("\n======= Test Quick | Tri série décroissante ======\n");
	testBasic();
	engine->setSortType(SortEngine::HEAP);
	engine->sort(heap, uiSensorCount);
	printf("\n======= Test Heap | Tri série décroissante ======\n");
	testBasic();
	//Affichage des listes triées
	printf("\nListe quick série décroissante triée : \n");
	for (int i=0; i<(int)uiSensorCount; i++){
		printf("%d\t", quick[i]);
	}
	printf("\nListe heap série décroissante triée : \n");
	for (int i=0; i<(int)uiSensorCount; i++){
		printf("%d\t", heap[i]);
	}
	//Fin du test
	printf("\n\n======= Test End TRI SéRIE DéCROISSANTE ======\n");
	testEnd();
	/////////////////////////////////////////////////////////////////////////////////////////

	//FIN////////////////////////////////////////////////////////////////////////////////////
	printf("\n======= Test End TRI GLOBAL======\n");
	testEnd();
	delete engine;
	/////////////////////////////////////////////////////////////////////////////////////////

	return 0;
}


/*int testAlgoCPUGlobal(){

	//déclaration des variables utiles aux tests
	int len_samples = uiSimCount;
	int len_capteurs = uiSensorCount;
	int len_pixels = uiSensorSize;
	int seuil = usHotspotDetectionThreshold;
	int erreur = usGrantedError;
	unsigned short values[uiSensorCount][uiSensorSize];
	unsigned short temp[len_capteurs] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	double Vmediane[len_pixels] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	double Vmoyenne[len_pixels] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	double Vref[len_pixels] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	double Vsoustrait[len_pixels] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int nb_hotspots[len_samples] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	SortEngine engine;
	engine.setSortType(SortEngine::QUICK);

	//début de la phase de tests
	printf("\n====== Test Start Algorithmes ======\n");
	testStart();
	//Test d'extraction
	extract(values, p_usSrcData, len_capteurs, len_pixels, 0);
	printf("\n======= Test Extract ======\n");
	testBasic();//test("extraction de l'échantillon", id_1);
	//Test du calcul de médiane
	mediane(engine, values, temp, Vmediane, len_capteurs, len_pixels);
	printf("\n======= Test Mediane ======\n");
	testBasic();//test("vecteur médiane de l'échantillon", id_1);
	//Test du calcul de moyenne
	moyenne(values, Vmediane, Vmoyenne, len_capteurs, len_pixels, erreur);
	printf("\n======= Test Moyenne ======\n");
	testBasic();//test("vecteur moyenne de l'échantillon", id_1);
	//Test de mémorisation
	mémorisation(Vref, Vmoyenne, len_pixels);
	printf("\n======= Test Mémorisation ======\n");
	testBasic();//test("mémorisation du vecteur de référence", id_1);
	//Test de soustraction
	soustraction(Vref, Vmoyenne, Vsoustrait, len_pixels);
	printf("\n======= Test Soustraction ======\n");
	testBasic();//test("soustraction des vecteurs", id_1);
	//Test de décompte de hotspots
	décompteHotspot(Vsoustrait, seuil, len_pixels);
	printf("\n======= Test Hotspot ======\n");
	testBasic();//test("décompte des hotspots", id_1);
	//Test du traitement global
	traitementGlobal(p_usSrcData, nb_hotspots, uiSimCount, uiSensorCount, uiSensorSize, 0, usHotspotDetectionThreshold, usGrantedError);
	printf("\n======= Test Algo ======\n");
	testBasic();//test("traitement global de tous les échantillons", id_1);
	//fin de la phase de tests
	printf("\n======= Test End Algorithme ======\n");
	testEnd();

	return 0;
}*/

int testAlgoCPU(){

	//déclaration des variables utiles aux tests
	int len_samples = uiSimCount;
	int len_capteurs = uiSensorCount;
	int len_pixels = uiSensorSize;
	int seuil = usHotspotDetectionThreshold;
	int erreur = usGrantedError;
	unsigned short values[uiSensorCount][uiSensorSize];
	unsigned short temp[len_capteurs] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	double Vmediane[len_pixels] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	double Vmoyenne[len_pixels] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	double Vref[len_pixels] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	double Vsoustrait[len_pixels] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int nb_hotspots[len_samples] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	SortEngine engine;
	engine.setSortType(SortEngine::QUICK);

	//début de la phase de tests
	printf("\n====== Test Start Algorithmes ======\n");
	testStart();

	//Début de la phase : référence
	//Test d'extraction
	extract(values, p_usSrcData, len_capteurs, len_pixels, 0);
	printf("\n======= Test Extract Référence ======\n");
	//testBasic();//test("extraction de l'échantillon", id_1);
	//Test du calcul de médiane
	mediane(engine, values, temp, Vmediane, len_capteurs, len_pixels);
	printf("\n======= Test Mediane Référence ======\n");
	//testBasic();//test("vecteur médiane de l'échantillon", id_1);
	//Test du calcul de moyenne
	moyenne(values, Vmediane, Vmoyenne, len_capteurs, len_pixels, erreur);
	printf("\n======= Test Moyenne Référence======\n");
	//testBasic();//test("vecteur moyenne de l'échantillon", id_1);
	//Test de mémorisation
	mémorisation(Vref, Vmoyenne, len_pixels);
	printf("\n======= Test Mémorisation Référence ======\n");
	testBasic();//test("mémorisation du vecteur de référence", id_1);

	//Début de la phase : all sample
	//On parcourt tous les samples s
	for (int c=0; c<len_samples; c++){
		//On récupère le sample c
		extract(values, p_usSrcData, len_capteurs, len_pixels, c);
		printf("\n======= Test Extract sample n°%d ======\n", c+1);
		testBasic();
		//On en extrait le vecteur médiane
		mediane(engine, values, temp, Vmediane, len_capteurs, len_pixels);
		printf("\n======= Test Mediane Référence n°%d ======\n", c+1);
		testBasic();
		//On en extrait le vecteur moyen
		moyenne(values, Vmediane, Vmoyenne, len_capteurs, len_pixels, erreur);
		printf("\n======= Test Moyenne Référence n°%d ======\n", c+1);
		testBasic();
		//On soustrait le vecteur de référence
		soustraction(Vref, Vmoyenne, Vsoustrait, len_pixels);
		printf("\n======= Test Soustraction n°%d ======\n", c+1);
		testBasic();//test("soustraction des vecteurs", id_1);
		//On compte les hotspots
		nb_hotspots[c] = décompteHotspot(Vsoustrait, seuil, len_pixels);
		printf("\n======= Test Hotspot sample n°%d ======\n", c+1);
		testBasic();//test("décompte des hotspots", id_1);
	}

	//Test du traitement global
	traitementGlobal(p_usSrcData, nb_hotspots, uiSimCount, uiSensorCount, uiSensorSize, 0, usHotspotDetectionThreshold, usGrantedError);
	printf("\n======= Test Algo ======\n");
	testBasic();//test("traitement global de tous les échantillons", id_1);

	//fin de la phase de tests
	printf("\n======= Test End Algorithme ======\n");
	testEnd();

	return 0;
}
