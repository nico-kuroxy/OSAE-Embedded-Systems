/**
 * \file algorithmes.h
 * \brief Déclarations des fonctions utilisées pour le projet de système embarqué
 * \author Nicolas Erbetti & Hugo Destannes Froment
 * \version 0.1
 * \date 1 février 2022
 *
 * Déclaration des fonctions développées pour traiter les images acquises par l'instrument et éliminer les hotspots.
 *
 */

#ifndef STAR_H_
#define STAR_H_


#include "shared/const.h"
#include "shared/data.h"
#include "shared/SortEngine.h"
#include <string.h>
#include  <stdio.h>
#include  <stdlib.h>
#include  <math.h>


void extract(unsigned short values[][uiSensorSize], unsigned short raw_data[][uiSensorCount][uiSensorSize], int len_capteurs, int len_pixels,  int id_sample);
/**
 * \fn extract(unsigned short values[][uiSensorSize], unsigned short raw_data[][uiSensorCount][uiSensorSize], int len_capteurs, int len_pixels,  int id_sample);
 * \brief Fonction d'acquisition d'une nouvelle série de données issue d'un sample donné depuis l'ensemble fourni.
 *
 * \param values tableau à 2 dimensions de short int. Chaque ligne correspond aux données d'un capteur, chaque colonne k contient les valeurs des pixels numéro "k" de chaque capteur.
 * \param raw_data tableau à 3 dimennsions de short int. La première correspond aux samples, la deuxième correspond aux capteurs et la troisième correspond aux données de ces capteurs.
 * \param len_capteurs int représentant le nombre de capteurs de notre système.
 * \param len_pixels int représentant le nombre de pixels de chaque capteur.
 * \param id_sample entier représentant le numéro du sample que l'on souhaite extraire.
 *
 * \return Rien, on va modifier le tableau "values" initialisé en dehors de la fonction pour y stocker les données extraites.
 */

void mediane(SortEngine engine, unsigned short values[][uiSensorSize], unsigned short *temp, double *mediane, int len_capteurs, int len_pixels);
/**
 * \fn mediane(SortEngine engine, unsigned short values[][uiSensorSize], unsigned short *temp, double *mediane, int len_capteurs, int len_pixels);
 * \brief On va remplir un vecteur contenant à chaque case k la valeur médiane de tous les k-ièmes pixels de chaque capteur.
 *
 * \param engine SortEngine contenant l'algorithme de tri que nous allons utiliser.
 * \param values tableau à 2 dimensions de short int. Chaque ligne correspond aux données d'un capteur, chaque colonne k contient les valeurs des pixels numéro "k" de chaque capteur.
 * \param temp tableau à 1 dimension qui sert de buffer pour le tri des tableaux dont on veut extraire la médiane.
 * \param mediane tableau à 1 dimension contenant à chaque cas k la valeur médiane de tous les k-ièmes pixels de chaque capteur.
 * \param len_capteurs int représentant le nombre de capteurs de notre système.
 * \param len_pixels int représentant le nombre de pixels de chaque capteur.
 *
 * \return Rien, on va modifier le tableau "mediane" initialisé en dehors de la fonction pour y stocker les valeurs des médianes.
 */


void moyenne(unsigned short values[][uiSensorSize], double *mediane, double *moyenne, int len_capteurs, int len_pixels, int erreur);
/**
 * \fn moyenne(unsigned short values[][uiSensorSize], double *mediane, double *moyenne, int len_capteurs, int len_pixels, int erreur);
 * \brief On va remplir un vecteur contenant à chaque case k la valeur moyenne de tous les k-ièmes pixels de chaque capteurs en excluant les valeurs aberrantes.
 *
 * \param values tableau à 2 dimensions de short int. Chaque ligne correspond aux données d'un capteur, chaque colonne k contient les valeurs des pixels numéro "k" de chaque capteur.
 * \param mediane tableau à 1 dimension contenant à chaque cas k la valeur médiane de tous les k-ièmes pixels de chaque capteur.
 * \param moyenne tableau à 1 dimension contenant à chaque cas k la valeur moyenne de tous les k-ièmes pixels de chaque capteur en excluant les valeurs aberrantes.
 * \param len_capteurs int représentant le nombre de capteurs de notre système.
 * \param len_pixels int représentant le nombre de pixels de chaque capteur.
 * \param erreur int représentant l'écart à la moyenne autorisé.
 *
 * \return Rien, on va modifier le tableau "moyenne" initialisé en dehors de la fonction pour y stocker les valeurs des moyennes.
 */

void mémorisation(double *Vref, double *Vmu, int len_pixels);
/**
 * \fn mémorisation(double *Vref, double *Vmu, int len_pixels);
 * \brief On va copier le vecteur Vmu dans le vecteur Vref. Cette fonction est utilisée pour mémoriser le vecteur de référence.
 *
 * \param Vref double* tableau à 1 dimension contenant les valeurs de référence pour tester les hotspots.
 * \param Vmu double* tableau à 1 dimension contenant les valeurs du vecteur à mémoriser.
 * \param len_pixels int représentant le nombre de pixels de chaque capteur.
 *
 * \return Rien, on va modifier le tableau "Vref" initialisé en dehors de la fonction pour y copier le vecteur de référence.
 */

void soustraction(double *Vref, double *Vmu, double *Vs, int len_pixels);
/**
 * \fn soustraction(double *Vref, double *Vmu, double *Vs, int len_pixels);
 * \brief On va soustraire au vecteur moyen considéré Vmu le vecteur de référence Vref. Le vecteur résultant est stocké dans Vs.
 *
 * \param Vs double* tableau à 1 dimension contenant le résultat de la soustraction.
 * \param Vref double* tableau à 1 dimension contenant les valeurs de référence pour tester les hotspots.
 * \param Vmu double* tableau à 1 dimension contenant les valeurs moyenne du vecteur à soustraire.
 * \param len_pixels int représentant le nombre de pixels de chaque capteur.
 *
 * \return Rien, on va modifier le tableau "Vs" initialisé en dehors de la fonction pour y stocker les valeurs des données soustraites.
 */

int décompteHotspot(double *Vs, double seuil, int len_pixels);
/**
 * \fn décompteHotspot(double *Vs, double seuil, int len_pixels);
 * \brief On va incrémenter un compteur à chaque fois qu'on détecte un hotspot dont la valeur est supérieure à seuil dans le vecteur Vs.
 *
 * \param Vs double* tableau à 1 dimension contenant le résultat de la soustraction.
 * \param seuil double valeur seuil à partir de laquelle on définit qu'un pixel présente un hotspot.
 * \param len_pixels int représentant le nombre de pixels de chaque capteur.
 *
 * \return int contenant le nombre de hotspots détectés.
 */

void traitementGlobal(unsigned short raw_data[][uiSensorCount][uiSensorSize], int *nb_hotspots, int len_samples, int len_capteurs, int len_pixels, int sample_ref, double seuil, int erreur);
/**
 * \fn traitementGlobal(unsigned short raw_data[][uiSensorCount][uiSensorSize], int *nb_hotspots, int len_samples, int len_capteurs, int len_pixels, int sample_ref, double seuil, int erreur);
 * \brief Intégration des différentes méthodes développées pour mener l'opération de traitement des données sur tous les samples.
 *
 * \param raw_data tableau à 3 dimennsions de short int. La première correspond aux samples, la deuxième correspond aux capteurs et la troisième correspond aux données de ces capteurs.
 * \param nb_hotspots int* dans lequel on va stocker dans chaque case s le nombre de hotspots détectés dans le sample s.
 * \param len_samples int représentant le nombre de samples dans notre jeu de données.
 * \param len_capteurs int représentant le nombre de capteurs de notre système.
 * \param len_pixels int représentant le nombre de pixels de chaque capteur.
 * \param sample_ref int représentant le numéro du sample que l'on souhaite définir comme sample de référence.
 * \param seuil double valeur seuil à partir de laquelle on définit qu'un pixel présente un hotspot.
 * \param erreur int représentant l'écart à la moyenne autorisé.
 *
 * \return Rien, on va afficher le nombre de hotspots détectés pour chaque sample.
 */

#endif /* STAR_H_ */
