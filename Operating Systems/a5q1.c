// cs20b1100
// K.Anuj
// Writer

#include <stdio.h>
#include <unistd.h>
#include <sys/shm.h>

int main()
{
    int shmid;
    int *shm;

    shmid = shmget((key_t)1100, 1024, 0666|IPC_CREAT);
    if (shmid < 0)
    {
        printf("Error at shmget");
        return 0;
    }

    shm = shmat(shmid, NULL, 0);
    if (shm < 0)
    {
        printf("Error");
        return 0;
    }

    int n;
    printf("Enter n value: ");
    scanf("%d", &n);
    shm[0] = n;

    printf("Enter data: ");
    for (int i = 1; i < n + 1; i++)
    {
        scanf("%d", &shm[i]);
    }

    return 0;
}