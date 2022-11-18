#include <stdio.h>
#include <stdlib.h>
#define CAPACITY 5
int queue[CAPACITY], front = 0, rear = 0;
void enqueue(void);
void dequeue(void);
void display(void);
int main(void)
{
    short ch;
    while (1)
    {
        printf("1 : Enqueue\n");
        printf("2 : Dequeue\n");
        printf("3 : Display Queue Elements\n");
        printf("4 : Exit\n\n");
        printf("Enter your Choice :\n");
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
            printf("Worng Choice..!!\n");
            break;
        }
    }
    return 0;
}
void enqueue()
{
    if (rear == CAPACITY)
        printf("Queue is Overflo...!!\n");
    else
    {
        int ele;
        printf("Enter Element :\n");
        scanf("%d", &ele);
        queue[rear] = ele;
        printf("%d Element Pushed...!!\n", queue[rear]);
        rear++;
    }
}

void dequeue()
{
    if (front == rear)
        printf("Queue is Empty...!!\n");
    else
    {
        printf("%d : is Deleted\n", queue[front]);
        for (int i = 0; i < rear - 1; i++)
            queue[i] = queue[i + 1];
        rear--;
    }
}

void display()
{
    if (front == rear)
        printf("Queue is Empty...!!\n");
    else
    {
        for (int i = 0; i < rear; i++)
            printf("Element %d : %d\n", i + 1, queue[i]);
    }
    printf("\n");
}
