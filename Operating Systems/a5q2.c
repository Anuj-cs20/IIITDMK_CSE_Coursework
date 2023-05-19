// cs20b1100
// K.Anuj
// Reader

#include <stdio.h>
#include <unistd.h>
#include <sys/shm.h>

int main()
{
    int shmid;
    int *shm;

    shmid = shmget((key_t)1100, 1024, 0666 | IPC_CREAT);
    if (shmid < 0)
    {
        printf("Error");
        return 0;
    }

    shm = shmat(shmid, NULL, 0);
    if (shm < 0)
    {
        printf("Error");
        return 0;
    }

    for (int i = 1; i < shm[0] + 1; i++)
    {
        if (shm[i] % 2 == 0)
        {
            printf("EVEN ");
        }
        else
        {
            printf("ODD ");
        }
    }

    return 0;
}