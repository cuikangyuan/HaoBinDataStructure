#include <stdio.h>
#include <mm_malloc.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node * pNext;

}NODE, *PNODE;

PNODE create_list(void);
void traverse_list(PNODE);
bool is_empty(PNODE);
int length_list(PNODE);//TODO
void sort_list(PNODE);//TODO
void insert_list(PNODE, int, int);//TODO insert val before pos in the list, pos start from 1
void delete_list(PNODE, int, int*);//TODO

int main(void)
{

   PNODE pHead = NULL;
   pHead = create_list();
   traverse_list(pHead);

   return 0;
}

PNODE create_list(void) 
{
    int len;
    int i;
    int val;

    PNODE pHead = (PNODE)malloc(sizeof(NODE));
    if (NULL == pHead)
    {
        printf("pHead malloc failed");
        exit(-1);
    }
    
    PNODE pTail = pHead;
    pTail->pNext = NULL;

    printf("please input the len: ");
    scanf("%d", &len);

    for (i = 0; i < len; i++)
    {
        printf("please input the node val: ");
        scanf("%d", &val);
        PNODE pNew = (PNODE)malloc(sizeof(NODE));

        if (NULL == pNew)
        {
            printf("pNew malloc failed");
            exit(-1);
        }

        pNew->data = val;
        pNew->pNext = NULL;
        
        pTail->pNext = pNew;
        pTail = pNew;
    }
    
    return pHead;
}

void traverse_list(PNODE pHead)
{
    PNODE p = pHead->pNext;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->pNext;
    }

    printf("\n");

}


bool is_empty(PNODE pHead)
{
    return pHead->pNext == NULL;
    
}

int length_list(PNODE)
{
    int count = 0;

    PNODE p = pHead->pNext;
    while (p != NULL)
    {
        count++;
        p = p->pNext;
    }


    return count;
}
