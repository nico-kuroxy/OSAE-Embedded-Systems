# OSAE-Embedded-Systems

Dans le cadre d'une étude de phase A d'un instrument spatial, on désire effectuer une étude de faisabilité et un dimensionnement de la partie numérique de cet instrument. L'instrument est constitué d'un ensemble de 50 capteurs linéaires (une colonne) de 100 pixels. Chaque capteur est associé à une électronique de proximité effectuant entre autre une conversion analogique/numérique sur 16 bits et un transfert des résultats vers une RAM accessible par un DPU. Le transfert est effectué au travers d'un lien SpaceWire via le protocole RMAP. On considérera que le lien offre un débit de 50Mbits.s-1.

Ce répertoire git a pour objectif de gérer le versioning des algorithmes que nous avons développés qui visent à traiter les données acquises et transférées telles que décrites dans le paragraphe précédent. Le traitement effectué permet de déterminer le nombre de hotspots ou "points chauds" présent dans un jeu d'images en comparaison à une image de référence.


Lien du google sheet regroupant les différents bilans :
[ICI](https://docs.google.com/spreadsheets/d/11fl3j0zelHn65aaViv8vkDIVxnM8E7WRTuLo4zvRjCg/edit?usp=sharing)



