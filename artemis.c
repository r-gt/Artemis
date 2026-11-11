#include "artemis.h"

float rapidez(float vi, float a, float t){

	return vi + a*t;

}


float altura(float y, float v, float t, float a){

	return y + (v*t) + ((1.0/2.0) * a * t*t);

}
