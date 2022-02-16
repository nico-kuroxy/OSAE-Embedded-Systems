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
 * On compare les samples que nous extrayons grâce à la méthode avec les listes attendues que nous renseignons manuellement.
 * Le test est réussi si les jeux de données comparées sont 100% identiques.
 *
* \return int, 0 si le processus s'est déroulé correctement. */

int testUnitaireMediane();
/**
 * \fn testUnitaireMediane()
 * \brief Test unitaire vérifiant le bon fonctionnement de la fonction médiane.
 *
 *	On crée plusieurs jeux de données dont on va extraire les vecteurs contenant les valeurs médianes.
 *	Nous allons ensuite comparer ces vecteurs médianes avec les vecteurs médianes auxquels nous nous attendons pour chaque jeu de donnée.
 *	Le test est réussi si ces vecteurs sont identiques.
 *	On prendra notamment en compte le fait que le calcul d'une médiane est différent selon que le nombre d'éléments d'une liste est pair ou impair.
 *
* \return int, 0 si le processus s'est déroulé correctement. */

int testUnitaireMoyenne();
/**
 * \fn testUnitaireMoyenne();
 * \brief Test unitaire vérifiant le bon fonctionnement de la fonction moyenne.
 *
 * On crée plusieurs jeux de données ainsi que les vecteurs médianes correspondants.
 * Nous allons ensuite calculer les vecteurs contenant les valeurs moyennes de l'écart à la médiane de chaque pixel.
 * Ces vecteurs seront comparés avec les vecteurs moyennes attendus que nous définissons à la main également.
 * Le test est réussi si ces vecteurs sont identiques.
 * On fera notamment attention au fait qu'on ne considère pas les valeurs aberrantes qui sont trop éloignés de la valeur médiane (par rapport à la constante "seuil").
 *
* \return int, 0 si le processus s'est déroulé correctement. */

int testUnitaireMémorisation();
/**
 * \fn testUnitaireMémorisation();
 * \brief Test unitaire vérifiant le bon fonctionnement de la fonction mémorisation.
 *
 *	On crée plusieurs vecteurs contenant des valeurs tests (aléatoires, identiques...) que l'on va copier dans un second vecteur grâce à
 *	la fonction de mémorisation.
 *	On compare ensuite le vecteur à copier et le vecteur copié.
 *	Le test est réussi si ces vecteurs sont identiques.
 *
* \return int, 0 si le processus s'est déroulé correctement. */

int testUnitaireSoustraction();
/**
 * \fn testUnitaireSoustraction();
 * \brief Test unitaire vérifiant le bon fonctionnement de la fonction soustraction.
 *
 * On crée plusieurs paires de vecteur de référence et de vecteurs moyenne dont on va enregistrer la différence
 * dans un troisième vecteur.
 * On compare ensuite le vecteur de soustraction ainsi obtenu avec un vecteur contenant les résultats attendus.
 * Le test est réussi si ces vecteurs sont identiques.
 * On prendra notamment garde au fait que si le résultat de la soustraction est négatif, on enregistrera non pas ce résultat mais la valeur 0.
 *
* \return int, 0 si le processus s'est déroulé correctement. */

int testUnitaireDécompte();
/**
 * \fn testUnitaireDécompte();
 * \brief Test unitaire vérifiant le bon fonctionnement de la fonction décompte.
 *
 *	On crée un vecteur de valeurs arbitraires qui va être analysé par notre fonction décompte.
 *	On compare le résultat retourné par cette analyse avec le nombre de hotspots attendus pour ce vecteur.
 *	Le test est réussi si ces valeurs sont identiques.
 *
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
