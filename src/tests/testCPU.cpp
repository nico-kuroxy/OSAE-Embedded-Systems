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

int test(const char *testName, int testId) {
int static testCounter = 0;
return testCounter++;
}

int testTri(const char *testName, int testId, int typeTri) {
int static testCounterTri = 0;
return testCounterTri++;
}
