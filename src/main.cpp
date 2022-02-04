/**
 * \file main.cpp
 * \brief Programme de tests du projet de système embarqué.
 * \author Nicolas Erbetti & Hugo Destannes Froment
 * \version 0.1
 * \date 1 février 2022
 *
 * Programme de test pour les différents algorithmes développés dans le cadre du projet d'informatique embarquée
 * du Master 2 OSAE. On testera nos propres fonctions, les algorithmes de tri et leurs intégrations à l'algorithme
 * de traitement global.
 *
 */

#include "algorithmes.h"
#include "tests/testsUnitaires.h"
#include "shared/data.h"
#include "shared/SortEngine.h"
#include <string.h>
#include <stdio.h>

unsigned short quick[uiSensorSize];
unsigned short heap[uiSensorSize];


int main() {
/**
* \fn int main()
* \brief Fonction principale de notre projet. Elle exécute l'algorithme de traitement des pixels ainsi que les méthodes de tests associées.
*
* \return int, 0 si le processus s'est déroulé correctement.
*/

	//TESTS UNITAIRES//////////////////////////////////////////////////////////////
	if (testUnitaireExtract()) printf("Erreur détectée dans la fonction extract().\n");

	if (testUnitaireMediane()) printf("Erreur détectée dans la fonction mediane().\n");

	if (testUnitaireMoyenne()) printf("Erreur détectée dans la fonction moyenne().\n");

	if (testUnitaireMémorisation()) printf("Erreur détectée dans la fonction mémorisation().\n");

	if (testUnitaireSoustraction()) printf("Erreur détectée dans la fonction soustraction().\n");

	if (testUnitaireDécompte()) printf("Erreur détectée dans la fonction décompteHotspot().\n");

	if (testUnitaireTraitement()) printf("Erreur détectée dans la fonction traitementGlobal.\n");
	///////////////////////////////////////////////////////////////////////////////

	//TESTS CPU////////////////////////////////////////////////////////////////////////
	/*//Ne pas oublier de supprimer l'objet à la fin pour éviter les fuites mémoires
	SortEngine engine;
	test("start", 0);


	//Tests cpu des algorithmes de traitement

	//Tests cpu des algo de tri

	//Copie des données à trier
	for (int i = 0; i<(int)uiSensorSize; i++){
		int temp = p_usSrcData[0][0][i];
		quick[i] = temp;
		heap[i] = temp;
	}

	//Tests de tris
	engine.setSortType(SortEngine::QUICK);
	engine.sort(quick, uiSensorSize);
	testTri("quicksort", 1, 0);
	engine.setSortType(SortEngine::HEAP);
	engine.sort(heap, uiSensorSize);
	testTri("heapsort", 1, 1);

	test("end", 2);*/
	/////////////////////////////////////////////////////////////////////////////////

	return 0;
}
