# Page principale # {#mainpage}


Documentation utilisateur du projet de système embarqué
============

***

## Avant-propos :

Dans le cadre d'une étude de phase A d'un instrument spatial, on désire effectuer une étude de
faisabilité et un dimensionnement de la partie numérique de cet instrument. L'instrument est
constitué d'un ensemble de 50 capteurs linéaires (une colonne) de 100 pixels. Chaque capteur
est associé à une électronique de proximité effectuant entre autre une conversion
analogique/numérique sur 16 bits et un transfert des résultats vers une RAM accessible par un
DPU. Le transfert est effectué au travers d'un lien SpaceWire via le protocole RMAP. On
considérera que le lien offre un débit de 50Mbits.s-1.

La présente documentation a pour objectif de référencer les algorithmes que nous avons développés qui visent à traiter les données acquises et transférées telles que décrites dans le paragraphe précédent. Le traitement effectué permet de déterminer le nombre de hotspots ou "points chauds" présent dans un jeu d'images en comparaison à une image de référence.


***

## Auteurs : 

- Nicolas Erbetti
- Hugo Destannes Froment

***

## Encadrants : 

- Philippe Plasson.
- LeeRoy Malac-Allain.

***

## Installation

* Télécharger le répertoire "Projet" contenant nos codes sources ainsi que le fichier de configuration du projet sous Eclipse.
* Importer ce répertoire dans Eclipse ("File" -> "Import" -> "General" -> "Project from folder or archive").
* Compiler le projet en s'assurant que le builder type est "internal builder" (C/C++ Build), que le préfix et le path valent respectivement "sparc-gaisler-elf-" et votre chemin vers le dossier bin du dossier de bcc (ATTENTION : cette variable dépend de votre répertoire d'installation du dossier de bcc ! Chez nous, elle était dans un dossier bin dans home/user/ mais il faut l'adapter à votre configuration !) (C/C++ Build -> Settings), et que le mode d'optimisation est O2 (C/C++ Build -> Settings -> Cross G++ Compiler -> Optimization -> Optimization Level).
* Adapter les chemins renseignés dans les fichiers gdb_batch_001.txt et start_tsim.csh du sous-dossier Test_L à votre configuration.


***

## Exécution

Dans Eclipse, après avoir ouvert le projet et suivi les étapes de la section Installation :
* Créer une nouvelle configuration de lancement s'il n'y en a pas. Create Launch Configuration -> Debug -> C/C++ Application puis sélectionner les différents fichiers / projets qui nous intéressent ici. 
* Lancer le programme en mode run sur la configuration de lancement dédiée.

***

## Références bibliographiques : 

* Sujet du projet.
* Cours de systèmes embarqués pour le spatial dispensés par M. Plasson.

***
