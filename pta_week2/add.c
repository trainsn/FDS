#include <stdio.h>
#include <stdlib.h>

#define COMPARE(numa,numb) (numa>numb?-1:(numa<numb?1:0))

typedef struct Node *PtrToNode;
struct Node
{
    int Coefficient;
    int Exponent;
    PtrToNode Next;
};

typedef PtrToNode Polynomial;

Polynomial Create(char * filename)
{
    FILE * file;
    int coefficient;
    int exponent;
    int val;
    PtrToNode front, tail, temp;

    tail = (PtrToNode)malloc(sizeof(struct Node));
    if (tail == NULL)
    {
        printf("The memory is full!\n");
        exit(1);
    }

    front = tail;
    front->Exponent = -1;

    file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Cant't open %s!\n", filename);
        exit(1);
    }
    while (!feof(file))
    {
        val = fscanf(file, "%d, %d", &coefficient, &exponent);
        printf("val = %d\n", val);
        if (exponent < -1)
        {
            printf("In File %s: the exponent of polynomial is not less than 0!\n", filename);
            exit(1);
        }

        temp = (PtrToNode)malloc(sizeof(struct Node));
        if (temp == NULL)
        {
            printf("The memory is full!\n");
            exit(1);
        }

        temp->Coefficient = coefficient;
        temp->Exponent = exponent;
        temp->Next = NULL;
        tail->Next = temp;
        tail = temp;
    }
    fclose(file);
    return front;
}

void Output(Polynomial poly, char * filename)
{
    FILE * file;
    file = fopen(filename, "w");
    PtrToNode curNode = poly->Next;
    if (file == NULL)
    {
        printf("Cant't open %s!\n", filename);
        exit(1);
    }
    while (curNode != NULL)
    {
        fprintf(file, "%d,%d\n",curNode->Coefficient,curNode->Exponent);
        curNode = curNode->Next;
    }
    fclose(file);
}

void Attach(int coefficient, int exponent, PtrToNode * ptr)
{
    PtrToNode temp;
    temp = (PtrToNode)malloc(sizeof(struct Node));
    if (temp == NULL)
    {
        printf("The memory is full!\n");
        exit(1);
    }

    temp->Coefficient = coefficient;
    temp->Exponent = exponent;
    temp->Next = NULL;

    (*ptr)->Next = temp;
    *ptr = temp;
}

Polynomial Add(Polynomial polya, Polynomial polyb)
{
    PtrToNode front, tail;
    int sum;

    tail = (PtrToNode)malloc(sizeof(struct Node));
    if (tail == NULL)
    {
        printf("The memory is full!\n");
        exit(1);
    }

    front = tail;
    front->Exponent = -1;

    polya = polya->Next;
    polyb = polyb->Next;
    while (polya && polyb)
    {
        switch (COMPARE(polya->Exponent, polyb->Exponent))
        {
        case -1:
            Attach(polyb->Coefficient, polyb->Exponent, &tail);
            polyb = polyb->Next;
            break;
        case 0:
            sum = polya->Coefficient + polyb->Coefficient;
            if (sum)
                Attach(sum, polya->Exponent, &tail);
            polya = polya->Next;
            polyb = polyb->Next;
            break;
        case 1:
            Attach(polya->Coefficient, polya->Exponent, &tail);
            polya = polya->Next;
            break;
        }
    }
    for ( ; polya; polya = polya-> Next )
        Attach(polya-> Coefficient, polya-> Exponent, &tail);
    for ( ; polyb; polyb = polyb-> Next )
        Attach(polyb-> Coefficient, polyb-> Exponent, &tail);
    tail->Next = NULL;
    return  front;
}

void Delete(Polynomial poly)
{
    PtrToNode node, tmp;
    node = poly;
    while (node != NULL)
    {
        tmp = node->Next;
        free(node);
        node = tmp;
    }
}

int main(int argc, char *argv[])
{
    Polynomial polya;
    Polynomial polyb;
    Polynomial polyc;
    polya = Create(argv[1]);
    polyb = Create(argv[2]);
    polyc = Add(polya, polyb);
    Output(polyc, argv[3]);
    Delete(polya);
    Delete(polyb);
    Delete(polyc);
    return 0;
}
