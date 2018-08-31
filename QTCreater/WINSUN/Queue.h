
#ifndef  __QUEUE_H__
#define  __QUEUE_H__

#ifdef __cplusplus
extern "C" {
#endif

/* ------------------------------------------------------------------------- */
/* ------------------- simple ring buffer implementation ------------------- */
/* ------------------------------------------------------------------------- */

#define RING_BUFFER_SIZE  512

typedef struct tagRingBuffer{
    unsigned int   readIndex;
    unsigned int   writeIndex;
    unsigned char   buffer[RING_BUFFER_SIZE];
}RingBuffer_t;

extern RingBuffer_t KeyRingBuffer;
//extern RingBuffer_t UartRingBuffer;

void  RingBufferWrite(RingBuffer_t *rb, unsigned char c);
unsigned char RingBufferHasData(RingBuffer_t *rb);
unsigned int RingBufferCount(RingBuffer_t *rb);
unsigned char RingBufferRead(RingBuffer_t *rb);
void RingBufferClear(RingBuffer_t *rb);

#ifdef __cplusplus
};
#endif

#endif
