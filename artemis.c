#include "artemis.h"
#include <math.h>

float rapidez(float vi, float ac, float t){
	return vi + (ac * t);
}
float altura(float yi, float vi, float ac, float t){
	return yi + (vi * t) + (0.5 * ac * t * t);
}
float rapidezG(float ac){
	return ac / 9.8;
}
float rapidez_tramo2(float v, float a, float y){
    return sqrt(v*v + 2.0 * a *y);
}
float altura_max(float h, float v){
    return h + (v*v)/19.6;
}
