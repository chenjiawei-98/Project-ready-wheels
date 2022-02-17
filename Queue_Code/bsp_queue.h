#ifndef BSP_QUEUE_H_
#define BSP_QUEUE_H_

#include <stdint.h>

typedef struct
{
    uint8_t* head;
    uint8_t* tail;
    uint8_t buff[1+1];
}Queue1;

typedef struct
{
    uint8_t* head;
    uint8_t* tail;
    uint8_t buff[4 + 1];
}Queue4;

typedef struct
{
    uint8_t* head;
    uint8_t* tail;
    uint8_t buff[64 + 1];
}Queue64;

void S_QueueEmpty(uint8_t** head, uint8_t** tail, uint8_t* pbuff);
void S_QueueDataIn(uint8_t** head, uint8_t** tail, uint8_t* pbuff, uint16_t len, uint8_t* pdata, uint16_t data_len);
uint8_t S_QueueDataOut(uint8_t** head, uint8_t** tail, uint8_t* pbuff, uint16_t len, uint8_t* pdata);
uint16_t S_QueueDataLen(uint8_t** head, uint8_t** tail, uint8_t* pbuff, uint16_t len);

void queue_test_fun(void);

extern Queue1 switch_sta;



#define QueueEmpty(x)   S_QueueEmpty((uint8_t **)&(x).head,(uint8_t **)&(x).tail,(uint8_t *)&(x).buff)
#define QueueDataIn(x,y,z)  S_QueueDataIn((uint8_t **)&(x).head,(uint8_t **)&(x).tail,(uint8_t *)(x).buff,sizeof((x).buff),y,z)
#define QueueDataOut(x,y)   S_QueueDataOut((uint8_t **)&(x).head,(uint8_t **)&(x).tail,(uint8_t *)(x).buff,sizeof((x).buff),y);
#define QueueDataLen(x)  S_QueueDataLen((uint8_t **)&(x).head,(uint8_t **)&(x).tail,(uint8_t *)(x).buff,sizeof((x).buff));


#endif // BSP_QUEUE_H_
