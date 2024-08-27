#ifndef VEC_H
#define VEC_H
#include<stdarg.h>
#include<stdio.h>
#include"cmath.h"
#include<stdlib.h>
#include<string.h>
#include<math.h>
typedef struct{
unsigned int dim; // dimension for vector
float *elements; // 
}vec;

extern const vec VEC_UNDEFINED;
//Basic allocation of vector
vec allocateVec(unsigned int dim);// allocating vector
vec constructDefaultVector(unsigned int dim, float val);
vec constructEmptyVector(unsigned int dim);
vec newVector(unsigned int dim,...);
#define vector(...)newVector(NUMARGS(float,__VA_ARGS__),##__VA_ARGS__)
vec copyPtrVec(vec *v);
vec copyVec(vec v);
void print(vec v);


// vector operation function
bool equals(vec v1, vec v2);
vec scalarMultiplication(vec v, float scalar);
void scalarMultiplicationPtr(vec *v, float scalar);
vec scalarDivision(vec v, float scalar);
void scalarDivisionPtr(vec *v, float scalar);
vec add(vec v1, vec v2);
bool addTo(vec *v1, vec v2);
vec subtract(vec v1, vec v2);
bool subtractfrom(vec *v1, vec v2);
vec multiply(vec v1, vec v2);
bool multiplyPtr(vec *v1, vec v2);
vec divide(vec v1, vec v2);
bool dividePtr(vec *v1, vec v2);
float dot(vec v1, vec v2);
bool orthogonal(vec v1, vec v2);
vec cross(vec v1, vec v2);
float magnitude(vec v );
float magnitudeSquared(vec v);
vec normalized(vec v);
void normalizedPtr(vec *v);
vec power(vec v , float k);
void powerPtr(vec*v, float k);
#endif // !VEC_H

