#include "Calculs.h"
#include <math.h>

int PourcentageEntier(float pourcentage, float valeur) {
	int x = valeur / 100 * pourcentage;
	return x;
}