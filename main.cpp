#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

void push(Node** head, int data)
{
    Node *tmp = (Node*)malloc(sizeof(Node));
    tmp->value = data;
    tmp->next = (*head);
    (*head) = tmp;
}

int pop(Node **head)
{
    Node* prev = NULL;
    int val;
    if (head == NULL)
    {
        exit(-1);
    }
    prev = (*head);
    val = prev->value;
    (*head) = (*head)->next;
    free(prev);
    return val;
}

Node* getNth(Node* head, int n)
{
    int counter = 0;
    while (counter < n && head)
    {
        head = head->next;
        counter++;
    }
    return head;
}

Node* getLast(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    while (head->next)
    {
        head = head->next;
    }
    return head;
}

void pushBack(Node *head, int value)
{
    Node *last = getLast(head);
    Node *tmp = (Node*) malloc(sizeof(Node));
    tmp->value = value;
    tmp->next = NULL;
    last->next = tmp;
}

Node* getLastButOne(Node* head)
{
    if (head == NULL)
    {
        exit(-2);
    }
    if (head->next == NULL)
    {
        return NULL;
    }
    while (head->next->next)
    {
        head = head->next;
    }
    return head;
}


int popBack(Node **head)
{
    int val;
    Node *lastbn = NULL;
    if (!head)
    {
        exit(-1);
    }
    if (!(*head))
    {
        exit(-1);
    }
    lastbn = getLastButOne(*head);
    if (lastbn == NULL)
    {
        free(*head);
        *head = NULL;
    }
    else
    {
        free(lastbn->next);
        lastbn->next = NULL;
        val = lastbn->value;
        return val;
    }
}

void insert(Node *head, unsigned n, int val)
{
    unsigned i = 0;
    Node *tmp = NULL;
    while (i < n && head->next)
    {
        head = head->next;
        ++i;
    }
    tmp = (Node*) malloc(sizeof(Node));
    tmp->value =val;
    if (head->next)
    {
        tmp->next = head->next;
    }
    else
    {
        tmp->next = NULL;
    }
    head->next = tmp;
}

int deleteNth(Node **head, int n)
{
    if (n == 0)
    {
        return pop(head);
    }
    else
    {
        Node *prev = getNth(*head, n-1);
        Node *elm  = prev->next;
        int val = elm->value;

        prev->next = elm->next;
        free(elm);
        return val;
    }
}

void deleteList(Node **head)
{
    while ((*head)->next)
    {
        pop(head);
        *head = (*head)->next;
    }
    free(*head);
}

void printLinkedList(const Node *head)
{

    while (head)
    {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}

Node* myFunction(Node* head, int A, int B)
{
    int i = 0;
    Node *tmp = NULL;
    while (i < A && head->next)
    {
        head = head->next;
        ++i;
    }
    while ( i < B && head->next)
    {
        pushBack(head, head->value);
        head = head->next;
        ++i;
    }
    return tmp;
}

void title ()
{
    system ("cls");
    printf(" 0 - createList\n");
    printf(" 1 - push\n");
    printf(" 2 - pop\n");
    printf(" 3 - getNth\n");
    printf(" 4 - getLast\n");
    printf(" 5 - getLastButOne\n");
    printf(" 6 - insert\n");
    printf(" 7 - printLinkedList\n");
    printf(" 8 - deleteNth\n");
    printf(" 9 - deleteList\n");
    printf("10 - pushBack\n");
    printf("11 - popBack\n");
    printf("12 - myFunction\n");
    printf("13 - exit\n");
}

int main()
{
    Node* point = NULL;
    int value = 0;
    char boolean;
    unsigned operation, number = 0;

    printf("Do you want to start working with the list Y or N? ");
    scanf("%c",&boolean);
    if (boolean == 'N')
    {
        printf("");
        return 0;
    }
    else
    {
        Node *head = NULL;
        while ("True")
        {
            title();

            printf ("please write number of the operation ");
            scanf("%d",&operation);
            printf("\n");

            switch(operation)
            {
            case 0:
                {
                Node* head = NULL;
                break;
                }
            case 1:
                printf("please enter added element - ");
                scanf("%d",value);
                push(&head,value);
                break;
            case 2:
                pop(&head);
                printf("extracted element = %d",value);
                break;
            case 3:
                printf("please enter number cell for which you need a pointer - ");
                scanf("%d",number);
                point = getNth(head,number);
                break;
            case 4:
                point = getLast(head);
                break;
            case 5:
                point = getLastButOne(head);
                break;
            case 6:
                printf("please enter added element - ");
                scanf("%d",value);
                printf("\n");
                printf("please enter  ");
                scanf("%d",number);
                insert(head,number,value);
                break;
            case 7:
                printLinkedList(head);
                break;
            case 8:
                printf("please enter number of element which you want to delete - ");
                scanf("%d",number);
                deleteNth(&head,number);
                break;
            case 9:
                deleteList(&head);
                break;
            case 10:
                printf("please enter added element - ");
                scanf("%d",value);
                pushBack(head,value);
                break;
            case 11:
                value = popBack(&head);
                break;
            case 12:
                char C;
                int A,B;
                printf("please enter ");
                scanf("%d %d",&A,&B);
                point = myFunction(head,A,B);
                printf ("\nif you please enter Y or N ");
                scanf("%c",&C);
                if (C == 'Y')
                {
                    deleteList(&head);
                    head = point;
                }
                else
                {
                    printLinkedList(point);
                }
                break;
            case 13:
                deleteList(&head);
                return 1;
            default: printf("\n --incorrect operand-- \n");
            }
        system("pause");
        }
    }
}
