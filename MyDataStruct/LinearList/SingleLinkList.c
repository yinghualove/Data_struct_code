#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int            data;
    struct Node    *next;
}Node;


Node *ListInit()
{   Node *List;
    List = (Node *)malloc(sizeof(Node));
    List->data = 0;
    List->next = NULL;

    return List;
}

int  ListInit_int(Node *List)
{   
    List = (Node *)malloc(sizeof(Node));
    if(List == NULL)
        return -1;
    List->data = 0;
    List->next = NULL;

    return 0;
}

int HeaderInsert(Node *List, int data)
{
    Node *node;
   node = (Node *)malloc(sizeof(Node));
   printf("create a node \n");
    if(node == NULL)
    {
        printf("create node failed\n");
        return -1;
    }
    node->data = data; 
    printf("node->data = %d\n", node->data);
    node->next = List->next;
    List->next = node;
    List->data++;
    return 0;
}

int TailInsert(Node *List, int data)
{
    Node *node;
    node = (Node *)malloc(sizeof(Node));
    if(node == NULL)
        return -1;
    node->data = data;
    node->next = NULL;
    while(List)
        List = List->next;
    List->next = node;
    List->data++;

    return 0;
}

void PrintList(Node *List)
{
    Node *node = List->next;
    while(node)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main()
{
    printf("enter \n");
    Node List;
    ListInit_int(&List);
    HeaderInsert(&List, 1);
    HeaderInsert(&List, 2);
    HeaderInsert(&List, 3);
    PrintList(&List);

    // free(&List);
    return 0;
}