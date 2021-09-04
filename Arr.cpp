#include <stdio.h>
#include <mm_malloc.h>

struct Arr
{
    int * pBase;//数组第一个元素地址
    int len;//能容纳的最大元素个数
    int cnt;//当前有效元素个数
    //int increament;//增长因子
    /* data */
};

void init_arr(struct Arr *pArr, int length);
bool append_arr();
bool insert_arr();
int get();
bool is_empty();
bool is_full();
void sort_arr();
void show_arr();
void inverse_arr();

int main(void) 
{

    struct Arr arr;
    init_arr(&arr, 10);
    return 0;
}


void init_arr(struct Arr *pArr, int length) {

    pArr->pBase = (int *) malloc(sizeof(int) * length);
    if (NULL = pArr->pBase)
    {
        printf("动态分配内存失败");
        exit(-1);
    } 
    else
    {
        pArr->len = length;
        pArr->cnt = 0;
    }
    return;
    
}
