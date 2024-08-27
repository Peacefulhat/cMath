#include"../headers/vec.h"
// constant vec value if its not defined 
const vec VEC_UNDEFINED = {0,NULL};

// dynamically allocating memory for the vector because vector can grow but
vec allocateVec(unsigned int dim){

  vec ret;
  ret.dim =dim;
  ret.elements = malloc(dim*sizeof(float));
  return ret;
}


// constructs a vector having only one value in every place
vec constructDefaultVector(unsigned int dim, float val){
vec ret = allocateVec(dim);
for(unsigned int i=0;i<dim;i++){
  ret.elements[i]=val;
}
return ret;
}


// constructEmptyVector with some dimension 
vec constructEmptyVector(unsigned int dim){
  return constructDefaultVector(dim,0.0f);
}

// assignes the value to elements of vector using varible arguments
vec newVector(unsigned int dim,...){
vec ret = allocateVec(dim);
va_list list;
va_start(list,dim);
for(int i=0;i<dim;i++){
  ret.elements[i]=va_arg(list,double);
}
va_end(list);
return ret;
}

// return the value the of passed vecotr to function
vec copyVec(vec v){
  return v;
}

// copy vector using reference
vec copyPtrVec(vec *v){
  vec ret ;
  memcpy(&ret,v, sizeof(vec));
  return ret;
}

//prints the vector
void printVec(vec v){
  printf("{");
  for(unsigned int i=0;i<v.dim;i++){
    printf("%f",v.elements[i]);
    if(i<v.dim-1){
      printf(",");
    }
    else{
      printf(" ");
    }
  }
  printf("}\n");
}


// comparision of two vector
bool equals(vec v1 , vec v2){
if(v1.dim==v2.dim){
for(unsigned int i=0;i<v1.dim;i++){
  if(v1.elements[i]!=v2.elements[i]){
    return false;
  }
}
return true;
}
return false;
}


//vector scalar multiplication.
vec scalarMultiplication(vec v, float scalar){
vec ret = allocateVec(v.dim);
for( unsigned int i=0; i<ret.dim;i++){
  ret.elements[i]=v.elements[i]*scalar;
}
return ret;
}


void scalarMultiplicationPtr(vec *v, float scalar){
for( unsigned int i=0; i<v->dim;i++){
  v->elements[i]=v->elements[i]*scalar;
}
}


// vector scalar division
vec scalarDivision(vec v, float scalar){
vec ret = allocateVec(v.dim);
for( unsigned int i=0; i<ret.dim;i++){
  ret.elements[i]=v.elements[i]/scalar;
}
return ret;
}


void scalarDivisionPtr(vec *v, float scalar){
for( unsigned int i=0; i<v->dim;i++){
  v->elements[i]=v->elements[i]/scalar;
}
}

// adding two vector;
vec add(vec v1, vec v2){
  if(v1.dim!=v2.dim){
    return VEC_UNDEFINED;
  }
vec ret = allocateVec(v1.dim);
for( unsigned int i=0; i<ret.dim;i++){
  ret.elements[i]=v1.elements[i]+v2.elements[i];
}
return ret;

}


bool addTo(vec *v1, vec v2){
  if(v1->dim!=v2.dim){
    return false;
  }
for( unsigned int i=0; i<v1->dim;i++){
  v1->elements[i]=v1->elements[i]+v2.elements[i];
}
return true;
}

// vector subtraction
vec subtract(vec v1, vec v2){
  if(v1.dim!=v2.dim){
    return VEC_UNDEFINED;
  }
vec ret = allocateVec(v1.dim);
for( unsigned int i=0; i<ret.dim;i++){
  ret.elements[i]=v1.elements[i]-v2.elements[i];
}
return ret;


}


bool subtractfrom(vec *v1, vec v2){
    if(v1->dim!=v2.dim){
    return false;
  }
for( unsigned int i=0; i<v1->dim;i++){
  v1->elements[i]=v1->elements[i]-v2.elements[i];
}
}


//multiplication of two vectors
vec multiply(vec v1, vec v2){
  if(v1.dim!=v2.dim){
    return VEC_UNDEFINED;
  }
vec ret = allocateVec(v1.dim);
for( unsigned int i=0; i<ret.dim;i++){
  ret.elements[i]=v1.elements[i]*v2.elements[i];
}
return ret;
}


bool multiplyPtr(vec *v1, vec v2){
  if(v1->dim!=v2.dim){
    return false;
  }
for( unsigned int i=0; i<v1->dim;i++){
  v1->elements[i]=v1->elements[i]*v2.elements[i];
}
return true;
}

//Division of two vectors
vec divide(vec v1, vec v2){
if(v1.dim!=v2.dim){
    return VEC_UNDEFINED;
  }
vec ret = allocateVec(v1.dim);
for( unsigned int i=0; i<ret.dim;i++){
  ret.elements[i]=v1.elements[i]/v2.elements[i];
}
return ret;
}


bool dividePtr(vec *v1, vec v2){
if(v1->dim!=v2.dim){
    return false;
  }
for( unsigned int i=0; i<v1->dim;i++){
  v1->elements[i]=v1->elements[i]*v2.elements[i];
}
return true;
}


// vector dotproduct
float dot(vec v1, vec v2){
float ret=0.0f;
if(v1.dim==v2.dim){
  for(unsigned int i=0; i<v1.dim;i++){
  ret +=v1.elements[i]*v2.elements[i];
  }
}
return ret;
}


// vector orthogonal(perpendicular)
bool orthogonal(vec v1 , vec v2){ return v1.dim==v2.dim?dot(v1,v2):false;}


// cross product of two vectors

vec cross(vec v1, vec v2){
if(v1.dim!=3||v2.dim!=3){
  return VEC_UNDEFINED;
}
vec ret = allocateVec(3);
ret.elements[0]=(v1.elements[1]*v2.elements[2])-(v2.elements[2]*v2.elements[1]);
ret.elements[1]=-1*((v1.elements[0]*v2.elements[2])-(v1.elements[2]*v2.elements[0]));
ret.elements[2]=(v1.elements[0]*v2.elements[1])-(v1.elements[1]*v2.elements[0]);
return ret;
}

// magnitude
float magnitude(vec v){
  return sqrt(magnitudeSquared(v));
}


// squared magnitude
float magnitudeSquared(vec v){
float ret =0.0f;
for(unsigned int i=0;i<v.dim;i++){
  ret+= v.elements[i]*v.elements[i];
}
return ret;
}


//normal vector
vec normalized(vec v){
  vec ret = allocateVec(v.dim);
  float mag = magnitude(v);
  
for(unsigned int i=0; i< ret.dim;i++){
ret.elements[i]=v.elements[i]/mag;
}
return ret;
}


void normalizedPtr(vec *v){
float mag=magnitude(*v);
for(unsigned int i=0; i<v->dim;i++){
  v->elements[i]/=mag;
}
}


//power 
vec power(vec v , float k){
vec ret = allocateVec(v.dim);
for(unsigned int  i=0;i<ret.dim;i++){
  ret.elements[i]=powf(v.elements[i],k);
}
return ret;
}


void powerPtr(vec*v, float k){
for(unsigned int i=0;i<v->dim;i++){
  v->elements[i]=powf(v->elements[i],k);
}
}
