// 3. Create a Linked List of N students.
//    Each student node will have roll_no, percentage of marks, and
//    the corresponding grade.The roll_no will vary from 1 to N.
//    Percentage of marks will be taken as a random input.
//    The grading system is as given below.
//    Percentage >= 90 >= 80, < 90 >= 70, < 80 >= 60, < 70 >= 50,< 60 >= 35, < 50 < 35
//    Grade      A     B           C           D           E          P           F
//   WAP to create the group - wise separate Linked lists based on the grades.
// cs20b1100 K.Anuj
// Complexity: n
#include <stdio.h>
#include <stdlib.h>

struct gradesList
{
    int roll_no;
    float percentage;
    char grade;
    struct gradesList *next;
} * head, *headA, *headB, *headC, *headD, *headE, *headP, *headP, *headF;

void CreateList(int N)
{
    struct gradesList *temp;
    head = malloc(sizeof(struct gradesList));
    if (head == NULL)
    {
        printf("Unable to allocate memory.");
        exit(0);
    }
    head->roll_no = 1;
    head->percentage = rand() % 100;
    if (head->percentage >= 90)
    {
        head->grade = 'A';
    }
    else if (head->percentage >= 80 && head->percentage < 90)
    {
        head->grade = 'B';
    }
    else if (head->percentage >= 70 && head->percentage < 80)
    {
        head->grade = 'C';
    }
    else if (head->percentage >= 60 && head->percentage < 70)
    {
        head->grade = 'D';
    }
    else if (head->percentage >= 50 && head->percentage < 60)
    {
        head->grade = 'E';
    }
    else if (head->percentage >= 35 && head->percentage < 50)
    {
        head->grade = 'P';
    }
    else
    {
        head->grade = 'F';
    }
    head->next = NULL;
    temp = head;

    for (int i = 2; i <= N; ++i)
    {
        struct gradesList *newNode;
        newNode = malloc(sizeof(struct gradesList));

        if (newNode == NULL)
        {
            printf("out of memory space\n");
            exit(0);
        }
        newNode->roll_no = i;
        newNode->percentage = rand() % 100;
        if (newNode->percentage >= 90)
        {
            newNode->grade = 'A';
        }
        else if (newNode->percentage >= 80 && newNode->percentage < 90)
        {
            newNode->grade = 'B';
        }
        else if (newNode->percentage >= 70 && newNode->percentage < 80)
        {
            newNode->grade = 'C';
        }
        else if (newNode->percentage >= 60 && newNode->percentage < 70)
        {
            newNode->grade = 'D';
        }
        else if (newNode->percentage >= 50 && newNode->percentage < 60)
        {
            newNode->grade = 'E';
        }
        else if (newNode->percentage >= 35 && newNode->percentage < 50)
        {
            newNode->grade = 'P';
        }
        else
        {
            newNode->grade = 'F';
        }
        newNode->next = NULL;
        temp->next = newNode;
        temp = newNode;
    }
}

void newLists()
{
    struct gradesList *node = head;
    static int countA, countB, countC, countD, countE, countP, countF;
    struct gradesList *tempA, *tempB, *tempC, *tempD, *tempE, *tempP, *tempF;
    headA = malloc(sizeof(struct gradesList));
    headB = malloc(sizeof(struct gradesList));
    headC = malloc(sizeof(struct gradesList));

    headD = malloc(sizeof(struct gradesList));
    headE = malloc(sizeof(struct gradesList));
    headP = malloc(sizeof(struct gradesList));
    headF = malloc(sizeof(struct gradesList));
    while (node != NULL)
    {
        if (node->grade == 'A')
        {
            ++countA;
            struct gradesList *ptrA;
            ptrA = malloc(sizeof(struct gradesList));
            ptrA->roll_no = node->roll_no;
            ptrA->percentage = node->percentage;
            ptrA->grade = node->grade;
            ptrA->next = NULL;
            if (countA == 1)
            {
                headA = ptrA;
                tempA = ptrA;
            }
            else
            {
                tempA->next = ptrA;
                tempA = ptrA;
            }
        }
        else if (node->grade == 'B')
        {
            ++countB;
            struct gradesList *ptrB;
            ptrB = malloc(sizeof(struct gradesList));
            ptrB->roll_no = node->roll_no;
            ptrB->percentage = node->percentage;
            ptrB->grade = node->grade;
            ptrB->next = NULL;
            if (countB == 1)
            {
                headB = ptrB;
                tempB = ptrB;
            }
            else
            {
                tempB->next = ptrB;
                tempB = ptrB;
            }
        }
        else if (node->grade == 'C')
        {
            ++countC;
            struct gradesList *ptrC;
            ptrC = malloc(sizeof(struct gradesList));
            ptrC->roll_no = node->roll_no;
            ptrC->percentage = node->percentage;
            ptrC->grade = node->grade;
            ptrC->next = NULL;
            if (countC == 1)
            {
                headC = ptrC;
                tempC = ptrC;
            }
            else
            {
                tempC->next = ptrC;
                tempC = ptrC;
            }
        }
        else if (node->grade == 'D')
        {
            ++countD;
            struct gradesList *ptrD;
            ptrD = malloc(sizeof(struct gradesList));
            ptrD->roll_no = node->roll_no;
            ptrD->percentage = node->percentage;
            ptrD->grade = node->grade;
            ptrD->next = NULL;
            if (countD == 1)
            {
                headD = ptrD;
                tempD = ptrD;
            }
            else
            {
                tempD->next = ptrD;
                tempD = ptrD;
            }
        }
        else if (node->grade == 'E')
        {
            ++countE;
            struct gradesList *ptrE;
            ptrE = malloc(sizeof(struct gradesList));
            ptrE->roll_no = node->roll_no;
            ptrE->percentage = node->percentage;
            ptrE->grade = node->grade;
            ptrE->next = NULL;
            if (countE == 1)
            {
                headE = ptrE;
                tempE = ptrE;
            }
            else
            {
                tempE->next = ptrE;
                tempE = ptrE;
            }
        }
        else if (node->grade == 'P')
        {
            ++countP;
            struct gradesList *ptrP;
            ptrP = malloc(sizeof(struct gradesList));
            ptrP->roll_no = node->roll_no;
            ptrP->percentage = node->percentage;
            ptrP->grade = node->grade;
            ptrP->next = NULL;
            if (countP == 1)
            {
                headP = ptrP;
                tempP = ptrP;
            }
            else
            {
                tempP->next = ptrP;
                tempP = ptrP;
            }
        }
        else
        {
            ++countF;
            struct gradesList *ptrF;
            ptrF = malloc(sizeof(struct gradesList));
            ptrF->roll_no = node->roll_no;

            ptrF->percentage = node->percentage;
            ptrF->grade = node->grade;
            ptrF->next = NULL;
            if (countF == 1)
            {
                headF = ptrF;
                tempF = ptrF;
            }
            else
            {
                tempF->next = ptrF;
                tempF = ptrF;
            }
        }
        node = node->next;
    }
}

void TraverseList(struct gradesList *node)
{
    printf("roll_no\tpercentage\tgrade\n");
    while (node != NULL)
    {
        printf("%d\t%f\t%c", node->roll_no, node->percentage, node->grade);
        node = node->next;
        puts("");
    }
    puts("");
}
void freeList(struct gradesList *head)
{
    struct gradesList *tmp;
    while (head != NULL)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}
int main()
{
    int n;
    puts("Enter size of linked list of characters");
    scanf("%d", &n);
    puts("");
    CreateList(n);
    puts("ALL STUDENTS LIST");
    TraverseList(head);
    newLists();
    puts("students with grade A");
    TraverseList(headA);
    puts("students with grade B");
    TraverseList(headB);
    puts("students with grade C");
    TraverseList(headC);
    puts("students with grade D");
    TraverseList(headD);
    puts("students with grade E");
    TraverseList(headE);
    puts("students with grade P");
    TraverseList(headP);
    puts("students with grade F");
    TraverseList(headF);
    freeList(head);
    freeList(headA);
    freeList(headB);
    freeList(headC);
    freeList(headD);
    freeList(headE);
    freeList(headP);
    freeList(headF);
    return 0;
}