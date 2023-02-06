/**
 * Vector implementation.
 *
 * - Implement each of the functions to create a working growable array (vector).
 * - Do not change any of the structs
 * - When submitting, You should not have any 'printf' statements in your vector 
 *   functions.
 *
 * IMPORTANT: The initial capacity and the vector's growth factor should be 
 * expressed in terms of the configuration constants in vect.h
 */
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <string.h>

#include "vect.h"

/** Main data structure for the vector. */
struct vect {
  char **data;             /* Array containing the actual data. */
  unsigned int size;       /* Number of items currently in the vector. */
  unsigned int capacity;   /* Maximum number of items the vector can hold before growing. */
};

/** Construct a new empty vector. */
vect_t *vect_new() {

  /* [TODO] Complete the function */

  vect_t *v = (vect_t *)malloc(sizeof(vect_t));
  //  v->data = malloc(sizeof(char) * VECT_INITIAL_CAPACITY);
  v->data = calloc(VECT_INITIAL_CAPACITY, sizeof(char));
  v->size = 0;
  v->capacity = VECT_INITIAL_CAPACITY;

  return v;
}

/** Delete the vector, freeing all memory it occupies. */
void vect_delete(vect_t *v) {

  /* [TODO] Complete the function */
  for(int i = 0; i < v->size; i++){
    free(v->data[i]);
  }
  
  free(v->data);
  free(v);

}

/** Get the element at the given index. */
const char *vect_get(vect_t *v, unsigned int idx) {
  assert(v != NULL);
   assert(idx < v->size);

  /* [TODO] Complete the function */
  return v->data[idx];
}

/** Get a copy of the element at the given index. The caller is responsible
 *  for freeing the memory occupied by the copy. */
char *vect_get_copy(vect_t *v, unsigned int idx) {
  assert(v != NULL);
  assert(idx < v->size);

  /* [TODO] Complete the function */
  char *target = (char *) malloc(strlen(v->data[idx]) + 1);
  strcpy(target, v->data[idx]);
  return target;
}
/** Set the element at the given index. */
void vect_set(vect_t *v, unsigned int idx, const char *elt) {
  assert(v != NULL);
  assert(idx < v->size);

  /* [TODO] Complete the function */
  // char* dest;
  // strcpy(dest, elt);
  //  char* target = strdup(elt);
  char *target = (char *) malloc(strlen(elt) + 1);
  strcpy(target, elt);
  v->data[idx] = target;
}

/** Add an element to the back of the vector. */
void vect_add(vect_t *v, const char *elt) {
  assert(v != NULL);

  if(v->size == v-> capacity){
    v->capacity = v->capacity * VECT_GROWTH_FACTOR;
    v->data = realloc(v->data, sizeof(long) * v->capacity);
  }

  char *target = (char *) malloc(strlen(elt) + 1);
  strcpy(target, elt);
  v->data[v->size] = target;
  v->size = v->size + 1;
}

/** Remove the last element from the vector. */
void vect_remove_last(vect_t *v) {
  assert(v != NULL);

  /* [TODO] Complete the function */
  if(v->size > 0){
    v->size = v->size - 1;
    free(v->data[v->size]);
  }
}

/** The number of items currently in the vector. */
unsigned int vect_size(vect_t *v) {
  assert(v != NULL);

  /* [TODO] Complete the function */

  return v->size;
}

/** The maximum number of items the vector can hold before it has to grow. */
unsigned int vect_current_capacity(vect_t *v) {
  assert(v != NULL);

  /* [TODO] Complete the function */

  return v->capacity;
}

