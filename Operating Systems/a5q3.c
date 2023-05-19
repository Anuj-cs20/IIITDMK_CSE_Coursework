// cs20b1100
// K.Anuj
// Process 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/shm.h>
#include <unistd.h>

int main()
{
    int shmid;
    char str[100];
    void *shm;

    shmid = shmget((key_t)1100, 1024, 0666 | IPC_CREAT);
    if (shmid < 0)
    {
        printf("Error at shmget");
        return 0;
    }

    shm = shmat(shmid, NULL, 0);
    if (shm == (char *)-1)
    {
        printf("Error at shmat");
        return 0;
    }

    printf("Enter P1 string: ");
    scanf("%s", str);
    strcpy(shm, str);
    printf("Shared memory data: %s", shm);

    for (int i = 0; i < 5 / 2; i++)
    {
        printf("Enter P1 string: ");
        scanf("%s", str);
        strcat(shm, str);
        printf("Shared memory data: %s", shm);
    }

    return 0;
}