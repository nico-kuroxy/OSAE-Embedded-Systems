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

unsigned short quick[uiSensorSize] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
unsigned short heap[uiSensorSize] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

int test(const char *testName, int testId) {
int static testCounter = 0;
return testCounter++;
}

int testTri(const char *testName, int testId, int typeTri) {
int static testCounterTri = 0;
return testCounterTri++;
}

int testTriCPU(){

	SortEngine *engine = new SortEngine();

	test("start Tri", 0);
	//Tests cpu des algo de tri
	//Copie des données à trier
	for (int i = 0; i<(int)uiSensorSize; i++){
		int temp = p_usSrcData[0][0][i];
		quick[i] = temp;
		heap[i] = temp;
	}
	//Tests de tris
	engine->setSortType(SortEngine::QUICK);
	engine->sort(quick, uiSensorSize);
	testTri("quicksort", 1, 0);
	engine->setSortType(SortEngine::HEAP);
	engine->sort(heap, uiSensorSize);
	testTri("heapsort", 1, 1);

	test("end Tri", 2);
	delete engine;

	return 0;
}


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
	test("start Algo", 0);
	//Test d'extraction
	extract(values, (unsigned short ***)p_usSrcData, len_capteurs, len_pixels, 0);
	test("extraction de l'échantillon", 1);
	//Test du calcul de médiane
	mediane(engine, values, temp, Vmediane, len_capteurs, len_pixels);
	test("vecteur médiane de l'échantillon", 1);
	//Test du calcul de moyenne
	moyenne(values, Vmediane, Vmoyenne, len_capteurs, len_pixels, erreur);
	test("vecteur moyenne de l'échantillon", 1);
	//Test de mémorisation
	mémorisation(Vref, Vmoyenne, len_pixels);
	test("mémorisation du vecteur de référence", 1);
	//Test de soustraction
	soustraction(Vref, Vmoyenne, Vsoustrait, len_pixels);
	test("soustraction des vecteurs", 1);
	//Test de décompte de hotspots
	décompteHotspot(Vsoustrait, seuil, len_pixels);
	test("décompte des hotspots", 1);
	//Test du traitement global
	traitementGlobal((unsigned short ***)p_usSrcData, nb_hotspots, uiSimCount, uiSensorCount, uiSensorSize, 0, usHotspotDetectionThreshold, usGrantedError);
	test("traitement global de tous les échantillons", 1);
	//fin de la phase de tests
	test("end Algo", 2);

	return 0;
}
