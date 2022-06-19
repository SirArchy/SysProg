#include "../lib/queue.h"
#include <stdlib.h>
#include <stdio.h>

int queue_add(void* new_obejct, queue_object* queue){
/**
 * adds a new queue object right behind the very first element in the queue (@param queue remains the
 * head of the queue).
 * 
 * Remember to allocate space for a new queue object and to adjust the pointers of the affected objects.
 * 
 * @param new_object pointer to some object you want to add into the FIFO queue
 * @param queue the pointer to a queue you want to add the obejct to 
 * @return 0 if everything was fine, else return 1
 */
    return 1;
}

void* queue_poll(queue_object* queue){
/**
 * Gets and deletes the oldest item from the queue.
 * 
 * Remember to properly check for NULL-values before dereferencing pointers and to free removed queue object.
 * Also make sure to adjust pointers correctly.
 * 
 * @param queue The pointer to a queue handler you want to poll from
 * @result pointer to an object that was previously added using function int queue_add or NULL if the queue is empty
 */ 
    return NULL;
}

queue_object* new_queue(){
/**
 * Creates and returns a new queue. Should be called before working with the queue.
 * 
 * A new queue consists of a single queue object which is used as a head element.
 * Remember to allocate enough space for any object you need to create.
 * 
 * @result a pointer to a new queue handler.
 */
    return NULL;
}


void free_queue(queue_object* queue){
/**
 * Deletes and frees all queue items.
 * 
 * @param queue The pointer to the queue you want to delete
 */
}

void* queue_peek(queue_object* queue){
/**
 * Gets the oldest item in the queue, but doesn't delete it.
 * 
 * Remember to properly check for NULL-values before dereferencing pointers.
 * 
 * @param queue Pointer to the queue you want to peek from
 * @result pointer to an object that was previously added using queue add or NULL if the queue is empty
 */
    return NULL;
}


//BEISPIEL

// A structure to represent a queue
struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};
 
// function to create a queue
// of given capacity.
// It initializes size of queue as 0
struct Queue* createQueue(unsigned capacity)
{
    struct Queue* queue = (struct Queue*)malloc(
        sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
 
    // This is important, see the enqueue
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(
        queue->capacity * sizeof(int));
    return queue;
}
 
// Queue is full when size becomes
// equal to the capacity
int isFull(struct Queue* queue)
{
    return (queue->size == queue->capacity);
}
 
// Queue is empty when size is 0
int isEmpty(struct Queue* queue)
{
    return (queue->size == 0);
}
 
// Function to add an item to the queue.
// It changes rear and size
void enqueue(struct Queue* queue, int item)
{
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1)
                  % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
    printf("%d enqueued to queue\n", item);
}
 
// Function to remove an item from queue.
// It changes front and size
int dequeue(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1)
                   % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}
 
// Function to get front of queue
int front(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->front];
}
 
// Function to get rear of queue
int rear(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->rear];
}
 
// Driver program to test above functions./
int main()
{
    struct Queue* queue = createQueue(1000);
 
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
 
    printf("%d dequeued from queue\n\n",
           dequeue(queue));
 
    printf("Front item is %d\n", front(queue));
    printf("Rear item is %d\n", rear(queue));
 
    return 0;
}