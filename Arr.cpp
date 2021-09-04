#include <stdio.h>
#include <mm_malloc.h>
#include <stdlib.h>

struct Arr
{
    int * pBase;//first element address
    int len;//max element count
    int cnt;//current valid element count
    //int increament;//increament factor
    /* data */
};

void init_arr(struct Arr *pArr, int length);
bool append_arr(struct Arr *pArr, int val);

//insert element before position of pos, pos start from "1"
bool insert_arr(struct Arr *pArr, int pos, int val);
bool delete_arr(struct Arr *pArr, int pos, int * pVal);
int get();
bool is_empty(struct Arr *pArr);
bool is_full(struct Arr *pArr);
void sort_arr(struct Arr *pArr);
void show_arr(struct Arr *pArr);
void inverse_arr(struct Arr *pArr);

int main(void) 
{

    int count = 5;
    struct Arr arr;
    init_arr(&arr, count);
    append_arr(&arr, -1);
    append_arr(&arr, 0);
    append_arr(&arr, 1);
    append_arr(&arr, 2);
    append_arr(&arr, 3);

    // for (int i = 0; i < count; i++)
    // {
    //     append_arr(&arr, i);
    // }

    show_arr(&arr);
    
    inverse_arr(&arr);
    show_arr(&arr);

    sort_arr(&arr);
    show_arr(&arr);

    return 0;
}


void init_arr(struct Arr *pArr, int length) {

    pArr->pBase = (int *) malloc(sizeof(int) * length);
    if (NULL == pArr->pBase)
    {
        printf("malloc failed");
        exit(-1);
    } 
    else
    {
        pArr->len = length;
        pArr->cnt = 0;
    }
    return;
    
}

bool is_empty(struct Arr *pArr) {

    return 0 == pArr->cnt;

}

bool is_full(struct Arr *pArr) {

    return pArr->len == pArr->cnt;

}

bool append_arr(struct Arr *pArr, int val)
{
    if (!is_full(pArr))
    {
        //correct
        // pArr->pBase[pArr->cnt] = val;
        // ++pArr->cnt;

        //correct
        int index = pArr->cnt++;
        //printf("index: %d, val: %d\n", index, val);
        pArr->pBase[index] = val;
        return true;
    }
    
    return false;
}


void show_arr(struct Arr *pArr) {

    if (!is_empty(pArr))
    {
       for (size_t i = 0; i < pArr->cnt; i++)
       {   
         
           printf("%d ", pArr->pBase[i]); //correct

           //printf("%d ", *(pArr->pBase+i)); //correct
       }
        printf("\n");

    } else
    {
        printf("array is empty");
    }

    return;
}

bool delete_arr(struct Arr *pArr, int pos, int * pVal) 
{
    if (is_empty(pArr))
    {
        printf("array already empty");
        return false;
    }

    if (pos < 1 || pos > pArr->cnt)
    {
        printf("delete pos not valid");
    }

    *pVal = pArr->pBase[pos - 1];

    int i;
    for (i = pos; i < pArr->cnt; i++)
    {
        pArr->pBase[i-1] = pArr->pBase[i];
    }
    
    pArr->cnt--;

    return true;
}


bool insert_arr(struct Arr *pArr, int pos, int val)
{
    if (is_full(pArr))
    {
        printf("array already full");
        return false;
    }
    
    if (pos < 1 || pos > pArr->cnt+1)
    {   
        printf("insert pos not valid");
        return false;
    }

    int i;
    for (i = pArr->cnt - 1; i >= pos - 1; i--)
    {
        // if (i+1 > pArr->len - 1)
        // {
        //     continue;
        // }
        
        pArr->pBase[i+1] = pArr->pBase[i];


    }
    pArr->pBase[pos-1] = val;
    pArr->cnt++;
    return true;
    
}

void inverse_arr(struct Arr *pArr) 
{


    int i = 0;
    int j = pArr->cnt - 1;
    int t;

    while (i < j)
    {
        t = pArr->pBase[i];
        pArr->pBase[i] = pArr->pBase[j];
        pArr->pBase[j] = t;
        ++i;
        --j;
    }
    return;
}

void sort_arr(struct Arr *pArr) 
{

    for (int i = 0; i < pArr->cnt; i++)
    {
        for (int j = 0; j < pArr->cnt - 1 - i; j++)
        {
            if (pArr->pBase[j] > pArr->pBase[j+1])
            {
                    int temp = pArr->pBase[j];
                    pArr->pBase[j] = pArr->pBase[j+1];
                    pArr->pBase[j+1] = temp;
            }
            

        }
        
    }
    


}
