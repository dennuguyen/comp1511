#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "queue.h"

int main (void) {
    Queue new = newQueue();
    enqueue(new, 6);
    assert(dequeue(new) = 6);
    destroyQueue(new);
}