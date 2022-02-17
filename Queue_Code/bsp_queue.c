#include "bsp_queue.h"
#include <stdio.h>

uint8_t temp_val;
Queue1 switch_sta;

void S_QueueEmpty(uint8_t** head, uint8_t** tail, uint8_t* pbuff)
{
    *head = pbuff;
    *tail = pbuff;
}

void S_QueueDataIn(uint8_t** head, uint8_t** tail, uint8_t* pbuff, uint16_t len, uint8_t* pdata, uint16_t data_len)
{
    uint16_t index;

    //关闭中断

    for (index = 0; index < data_len; index++, pdata++)
    {
        **tail = *pdata;
        (*tail)++;

        if (*tail == pbuff + len)
        {
            *tail = pbuff;
        }
        if (*tail == *head)
        {
            if (++(*head) == pbuff + len)
            {
                *head = pbuff;
            }
        }
    }

    //打开中断
}

uint8_t S_QueueDataOut(uint8_t** head, uint8_t** tail, uint8_t* pbuff, uint16_t len, uint8_t* pdata)
{
    uint8_t status = 0;
    //关闭中断
        if (*head != *tail)
        {
            *pdata = **head;
            status = 1;
            if (++(*head) == pbuff + len)
            {
                *head = pbuff;
            }
        }
    //打开中断
    return status;
}

uint16_t S_QueueDataLen(uint8_t** head, uint8_t** tail, uint8_t* pbuff, uint16_t len)
{
    if (*tail > * head)
    {
        return (*tail - *head);
    }
    if (*tail < *head)
    {
        return (*tail + len - *head);
    }
}

void queue_test_fun(void)
{
    uint8_t temp;

    printf("请输入一个开关值 : ");
    if(scanf("%d",&temp_val) == 1)
    {
        QueueDataIn(switch_sta,&temp_val,1);
    }
}
