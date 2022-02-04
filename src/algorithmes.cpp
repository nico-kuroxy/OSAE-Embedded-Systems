/**
 * \file algorithmes.cpp
 * \brief Corps des fonctions utilisées pour le projet de système embarqué
 * \author Nicolas Erbetti & Hugo Destannes Froment
 * \version 0.1
 * \date 1 février 2022
 *
 * Fonctions développées pour traiter les images acquises par l'instrument et éliminer les hotspots.
 *
 */

#include "algorithmes.h"


void extract(unsigned short **values, unsigned short ***raw_data, int len_capteurs, int len_pixels,  int id_sample){
	for (int i=0; i<len_capteurs; i++){
		for (int j=0; j<len_pixels; j++){
			values[i][j] = p_usSrcData[id_sample][i][j];
		}
	}
}

void mediane(SortEngine engine, unsigned short **values, unsigned short *temp, double *mediane, int len_capteurs, int len_pixels){
	//On crée un buffer temporaire dans lequel on va stocker toutes les valeurs des kièmes pixels de chaque ligne

	//On remplit le tableau des valeurs temporaires pour chaque pixel "k" de tous les capteurs c
	for (int k=0; k<len_pixels; k++){
		//On itère sur tous les capteurs
		for (int c=0; c<len_capteurs; c++){
			temp[c] = values[c][k];
		}
		//On trie le tableau temporaire
		engine.sort(temp, len_capteurs);
		//On extrait la valeur médiane et on la stocke en tant que valeur médiane des pixels "k" dans mediane
		if (len_capteurs%2 == 0)	mediane[k] = (temp[len_capteurs/2] + temp[(len_capteurs/2)-1])/2;
		else mediane[k] = temp[(int)len_capteurs/2];
	}
	//free(temp); //segfault
}

void moyenne(unsigned short **values, double *mediane, double *moyenne, int len_capteurs, int len_pixels, int erreur){
	//On crée une variable temporaire pour calculer les valeurs moyennes en excluant les valeurs aberrantes
	double temp;
	double nb;
	//On itère sur tous les pixels k de chaque capteur
	for (int k=0; k<len_pixels; k++){
		//On initialise temp
		temp = 0;
		nb = 0;
		//On itère sur tous les capteurs c
		for (int c=0; c<len_capteurs; c++){
			if (abs(values[c][k] - mediane[k]) < erreur) {temp += values[c][k]; nb++;}
		}
		//On calcule la moyenne des valeurs des pixels k et on la stocke dans moyenne
		moyenne[k] = temp/nb;
	}
}

void mémorisation(double *Vref, double *Vmu, int len_pixels){
	//On parcourt le vecteur Vmu pour copier la valeur de chacun de ses pixels k dans Vref
	memcpy(Vref, Vmu, len_pixels*sizeof(double));
}

void soustraction(double *Vref, double *Vmu, double *Vs, int len_pixels){
	//On parcourt Vs en lui assignant les bonnes valeurs
	for (int k=0; k<len_pixels; k++){
		Vs[k] = fmax(Vmu[k]-Vref[k],0);
	}
}

int décompteHotspot(double *Vs, double seuil, int len_pixels){
	//On initialise le compteur de hotspots
	int h = 0;
	//On parcourt les valeurs k de Vs
	for (int k=0; k<len_pixels; k++){
		if (Vs[k] > seuil) h++; //On incrémente le compteur de hotspot si la valeur calculée est supérieure au seuil
	}
	return h;
}

void traitementGlobal(unsigned short ***raw_data, int *nb_hotspots, int len_samples, int len_capteurs, int len_pixels, int sample_ref, double seuil, int erreur){

	//VARIABLES/////////////////////////////////////////////////////////////////////////////
	//On initialise les variables dont on va avoir besoin
	unsigned short** values = (unsigned short**) malloc(len_capteurs * sizeof(unsigned short*));
	for (int i = 0; i < len_capteurs; i++){
	    values[i] = (unsigned short*) malloc(sizeof(unsigned short) * len_pixels);
	}
	unsigned short *temp = (unsigned short*) malloc(len_capteurs * sizeof(unsigned short));
	double *Vmediane = (double*) malloc(len_pixels * sizeof(double));
	double *Vmoyenne = (double*) malloc(len_pixels * sizeof(double));
	double *Vref = (double*) malloc(len_pixels* sizeof(double));
	double *Vsoustrait = (double*) malloc(len_pixels * sizeof(double));
	SortEngine *engine = new SortEngine();
	////////////////////////////////////////////////////////////////////////////////////////

	//INITIALISATION////////////////////////////////////////////////////////////////////////
	//On récupère le sample de référence
	extract(values, raw_data, len_capteurs, len_pixels, sample_ref);
	//On en extrait le vecteur médiane
	mediane(*engine, values, temp, Vmediane, len_capteurs, len_pixels);
	//On en extrait le vecteur moyen
	moyenne(values, Vmediane, Vmoyenne, len_capteurs, len_pixels, erreur);
	//On en extrait le vecteur de référence
	mémorisation(Vref, Vmoyenne, len_pixels);
	////////////////////////////////////////////////////////////////////////////////////////

	//DECOMPTAGE HOTSPOT////////////////////////////////////////////////////////////////////
	//On parcourt tous les samples s
	for (int c=0; c<len_samples; c++){
		//On récupère le sample c
		extract(values, raw_data, len_capteurs, len_pixels, c);
		//On en extrait le vecteur médiane
		mediane(*engine, values, temp, Vmediane, len_capteurs, len_pixels);
		//On en extrait le vecteur moyen
		moyenne(values, Vmediane, Vmoyenne, len_capteurs, len_pixels, erreur);
		//On soustrait le vecteur de référence
		soustraction(Vref, Vmoyenne, Vsoustrait, len_pixels);
		//On compte les hotspots
		nb_hotspots[c] = décompteHotspot(Vsoustrait, seuil, len_pixels);
	}
	////////////////////////////////////////////////////////////////////////////////////////

	//CONCLUSION////////////////////////////////////////////////////////////////////////////
	//On nettoie les variables
	delete engine;
	free(Vsoustrait);
	free(Vref);
	free(Vmoyenne);
	free(Vmediane);
	free(temp);
	for (int i = 0; i < len_capteurs; i++){
	    free(values[i]);
	}
	free(values);
	////////////////////////////////////////////////////////////////////////////////////////

}





