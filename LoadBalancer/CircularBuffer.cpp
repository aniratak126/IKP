#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include "CircularBuffer.h"


/*void cb_init(circular_buffer* cb, size_t capacity, size_t sz)
{
    if (cb->buffer == NULL)
        //printf("Buffer is NULL!!!");
        cb->buffer = malloc(capacity * sz);

    cb->buffer_end = (char*)cb->buffer + capacity * sz;
    cb->capacity = capacity;
    cb->count = 0;
    cb->sz = sz;
    cb->head = cb->buffer;
    cb->tail = cb->buffer;
    printf("Buffer inited!!!\n");
}*/

circular_buffer* create_buffer()
{
    circular_buffer* cb = (circular_buffer*)malloc(sizeof(circular_buffer));
    cb->buffer = (DataClient*)malloc(BUFFER_SIZE * sizeof(DataClient));
    cb->head = 0;
    cb->tail = 0;
    return cb;
}

void cb_free(circular_buffer* cb)
{
    free(cb->buffer);
    free(cb);
}

void cb_push(circular_buffer* cb, DataClient data)
{
    cb->buffer[cb->head] = data;
    cb->head = (cb->head + 1) % BUFFER_SIZE;
}

DataClient cb_pop(circular_buffer* cb)
{
    DataClient data = cb->buffer[cb->tail];
    cb->tail = (cb->tail + 1) % BUFFER_SIZE;
    return data;
}

/*void cb_free(circular_buffer* cb)
{
    free(cb->buffer);
    free(cb->buffer_end);
    //free(cb->capacity);
    //free(cb->count);
    free(cb->head);
    free(cb->tail);
    //free(cb->sz);
    // clear out other fields too, just to be safe
}


void cb_push(circular_buffer* cb, const void* item)
{
    if (cb->count == cb->capacity) {
        // handle error
    }
    memcpy(cb->head, item, cb->sz);
    cb->head = (char*)cb->head + cb->sz;
    if (cb->head == cb->buffer_end)
        cb->head = cb->buffer;
    cb->count++;
}

DataClient cb_pop(circular_buffer* cb, void* item)
{
    if (cb->count == 0) {
        // handle error
    }
    memcpy(item, cb->tail, cb->sz);
    cb->tail = (char*)cb->tail + cb->sz;
    if (cb->tail == cb->buffer_end)
        cb->tail = cb->buffer;
    cb->count--;
}*/


void  printBuffer(circular_buffer* cb)
{
    printf("Current state of circular baffer:\n");
    int i;
    for (i = cb->tail; i != cb->head; i = (i + 1) % BUFFER_SIZE)
    {
        printf("%d: %c ", i, cb->buffer->data); //nije ovo dobro
    }
    printf("\n");
}


