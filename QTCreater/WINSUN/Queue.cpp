//#include "typedef.h"
#include "Queue.h"
/* ------------------------------------------------------------------------- */
/*
void InitRingBuffer(RingBuffer_t *rb)
{
	rb->readIndex=0;
	rb->writeIndex=0;
}
*/

void  RingBufferWrite(RingBuffer_t *rb, unsigned char c)
{
    unsigned int   newWriteIndex = rb->writeIndex + 1;
	
    if(newWriteIndex >= RING_BUFFER_SIZE)
        newWriteIndex = 0;
    if(newWriteIndex != rb->readIndex){ /* not yet full */
        rb->buffer[rb->writeIndex] = c;
        rb->writeIndex = newWriteIndex;
    }
}

unsigned char RingBufferHasData(RingBuffer_t *rb)
{
    return rb->readIndex != rb->writeIndex;
}

unsigned int RingBufferCount(RingBuffer_t *rb)
{
    int   x = rb->writeIndex - rb->readIndex;
	
    if(rb->writeIndex >= rb->readIndex)
        return x;
    return (x + RING_BUFFER_SIZE);
}

unsigned char RingBufferRead(RingBuffer_t *rb)
{
    unsigned char c = rb->buffer[rb->readIndex];
    rb->readIndex++;
    if(rb->readIndex >= RING_BUFFER_SIZE)
        rb->readIndex = 0;
    return c;
}

void RingBufferClear(RingBuffer_t *rb)
{
	rb->readIndex=0;
	rb->writeIndex=0;
}
