#ifndef ARTEMIS_H
#define ARTEMIS_H
	float rapidez(float vi, float ac, float t);
	float altura(float yi, float vi, float ac, float t);
	float rapidezG(float ac);
	float rapidez_tramo2(float v, float a, float y);
	float altura_max(float h, float v);

	typedef struct{
		double vel;
		double posi;
		double ac;
	}nave;


#endif
