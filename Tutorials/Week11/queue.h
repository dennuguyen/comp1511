// declare functions

typedef struct _queue *Queue;

Queue newQueue();
void destroyQueue(Queue q);
int dequeue(Queue q);
void enqueue(Queue q, int item);