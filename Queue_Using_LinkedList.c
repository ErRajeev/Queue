#include <stdio.h>
#include <stdlib.h>
void enqueue(void);
void dequeue(void);
void display(void);
struct node
{
    int data;
    struct node *link;
};
struct node *front = NULL, *rear = NULL;
int main(void)
{
    short ch;
    while (1)
    {
        printf("1 : Enqueue\n");
        printf("2 : Dequeue\n");
        printf("3 : Display\n");
        printf("4 : Exit\n");
        printf("Enter Your Choice :\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Wrong Input...!!\n");
            break;
        }
    }
    return 0;
}
void enqueue()
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data :\n");
    scanf("%d", &temp->data);
    temp->link = NULL;
    if ((front == NULL) && (rear == NULL))
        front = rear = temp;
    else
    {
        rear->link = temp;
        rear = temp;
    }
}
void dequeue()
{
    struct node *temp = front;
    if (rear == NULL)
        printf("Queue is Empty...!!!\n");
    else
    {
        printf("%d : is Dequeued !!\n", front->data);
        front = front->link;
    }
    free(temp);
}

void display()
{
    if (rear == NULL)
        printf("Queue is Empty...!!\n");
    else
    {
        struct node *p = front;
        while (p != NULL)
        {
            printf("%d", p->data);
            p = p->link;
            if (p != NULL)
                printf(" ---> ");
            else
                printf("\n");
        }
    }
}
