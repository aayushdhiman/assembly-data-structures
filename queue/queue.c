/*
 * Queue implementation.
 *
 * - Implement each of the functions to create a working circular queue.
 * - Do not change any of the structs
 * - When submitting, You should not have any 'printf' statements in your queue 
 *   functions. 
 */
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include "queue.h"

/** The main data structure for the queue. */
struct queue{
  unsigned int back;      /* The next free position in the queue
                           * (i.e. the end or tail of the line) */
  unsigned int front;     /* Current 'head' of the queue
                           * (i.e. the front or head of the line) */
  unsigned int size;      /* How many total elements we currently have enqueued. */
  unsigned int capacity;  /* Maximum number of items the queue can hold */
  long *data;             /* The data our queue holds  */
};

/** 
 * Construct a new empty queue.
 *
 * Returns a pointer to a newly created queue.
 * Return NULL on error
 */
queue_t *queue_new(unsigned int capacity) {

  /* [TODO] Complete the function */
  queue_t *q = (queue_t *)malloc(sizeof(queue_t));
  q->back = -1;
  q->front = -1;
  q->size = 0;
  q->capacity = capacity;
  q->data = malloc(capacity * sizeof(long));
  return q;
}

/**
 * Check if the given queue is empty
 *
 * Returns a non-0 value if the queue is empty, 0 otherwise.
 */
int queue_empty(queue_t *q) {
  assert(q != NULL);

  /* [TODO] Complete the function */
  if(q->front == -1)
    return 1;

  return 0;
}

/**
 * Check if the given queue is full.
 *
 * Returns a non-0 value if the queue is empty, 0 otherwise.
 */
int queue_full(queue_t *q) {
  assert(q != NULL);

  /* [TODO] Complete the function */
  if((q->front == q->back + 1) || (q->front == 0 && q->back == q->capacity - 1))
    return 1;

  return 0;
}

/** 
 * Enqueue a new item.
 *
 * Push a new item into our data structure.
 */
void queue_enqueue(queue_t *q, long item) {
  assert(q != NULL);
  assert(q->size < q->capacity);

  /* [TODO] Complete the function */
  if(queue_full(q))
    printf("\nQueue is full!\n");
  else{
    if(q->front == -1) 
      q->front = 0;
    q->back = (q->back + 1) % q->capacity;
    q->data[q->back]=item;
    q->size = q->size + 1;
  }
}

/**
 * Dequeue an item.
 *
 * Returns the item at the front of the queue and removes an item from the 
 * queue.
 *
 * Note: Removing from an empty queue is an undefined behavior (i.e., it could 
 * crash the program)
 */
long queue_dequeue(queue_t *q) {
  assert(q != NULL);
  assert(q->size > 0);

  /* [TODO] Complete the function */

  if(queue_empty(q)){
    printf("\nEmpty queue!\n");
    return -1;
  } else {
    long item = q->data[q->front];
    if(q->front == q->back){
      q->front = -1;
      q->back = -1;
      } else {
      q->front = (q->front + 1) % q->capacity;
    }
    q->size = q->size - 1;
    return item;
  }
  return -1;
}

/** 
 * Queue size.
 *
 * Queries the current size of a queue (valid size must be >= 0).
 */
unsigned int queue_size(queue_t *q) {
  assert(q != NULL);

  /* [TODO] Complete the function */
  if(q->size >= 0)
    return q->size;
  return 0;
}

/** 
 * Delete queue.
 * 
 * Remove the queue and all of its elements from memory.
 *
 * Note: This should be called before the proram terminates.
 */
void queue_delete(queue_t* q) {
  assert(q != NULL);

  /* [TODO] Complete the function */
  free(q->data);
  free(q);
}

