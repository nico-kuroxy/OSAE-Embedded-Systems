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
#include "tests/testCPU.h"
#include "tests/testsUnitaires.h"
#include "shared/data.h"
#include "shared/SortEngine.h"
#include <string.h>
#include <stdio.h>

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
	if (testTriCPU()) printf("Erreur détectée durant les tests CPU des fonctions de tri.\n");

	if (testAlgoCPU()) printf("Erreur détectée durant les tests CPU des fonctions de traitement.\n");
	/////////////////////////////////////////////////////////////////////////////////

	return 0;
}
