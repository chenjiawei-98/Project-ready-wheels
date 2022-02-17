#include <stdio.h>
#include <stdlib.h>
#include "bsp_queue.h"

Queue4 keymsg;
Queue64 modul_data;


int main()
{

    char str_arr[] = {"taskid is asfhasfoafoiaeofaoe"};
    char str_arr1[] = {"string enter queue test"};
    char str_arr2[] = {"string enter queue test1"};
    char array1[64] = {0};
    uint8_t temp = 25;
    uint8_t temp1 = 0;
    uint8_t temp2 = 0;
    uint8_t temp3 = 0;
    uint8_t i=0;

    QueueEmpty(switch_sta);

    queue_test_fun();
//    QueueDataOut(switch_sta,&temp2);
//    printf("temp2 = %d \r\n",temp2);

    printf("请再次输入一个值: \r\n");
    scanf("%d",&temp1);
    QueueDataIn(switch_sta,&temp1,1);
    QueueDataOut(switch_sta,&temp3);
    printf("temp3 = %d \r\n",temp3);

    temp1 = 0;
    QueueDataIn(switch_sta,&temp1,1);
    printf("temp3 = %d \r\n",temp3);
    temp1 = 1;
    QueueDataIn(switch_sta,&temp1,1);
    printf("temp3 = %d \r\n",temp3);
    temp1 = 2;
    QueueDataIn(switch_sta,&temp1,1);
    printf("temp3 = %d \r\n",temp3);
    temp1 = 4;
    QueueDataIn(switch_sta,&temp1,1);
    QueueDataOut(switch_sta,&temp3);
    printf("temp3 = %d \r\n",temp3);
    temp1 = 5;
    QueueDataIn(switch_sta,&temp1,1);
    QueueDataOut(switch_sta,&temp3);
    printf("temp3 = %d \r\n",temp3);

    QueueEmpty(modul_data);
    QueueDataIn(modul_data,str_arr1,strlen(str_arr1));
    for(int i=0;i<strlen(modul_data.buff);i++)
    {
        QueueDataOut(modul_data,array1+i);
    }

    printf("%s \r\n",array1);

    return 0;
}
