#include <stdio.h>
#include <windows.h>
#include <pthread.h>
#include <unistd.h>

void *fun_thread1(void *data)
{
    while (1)
    {
        printf("luong 1\n");
        Sleep(100);
    }
}

void *fun_thread2(void *data)
{
    while (1)
    {
        printf("luong 2\n");
        Sleep(100);
    }
}

int main(int argc, char *argv[])
{
    int status;
    pthread_t thrd_1, thrd_2;
    pthread_create(&thrd_1, NULL, fun_thread1, (void *)0);
    pthread_create(&thrd_2, NULL, fun_thread2, (void *)0);

    pthread_join(thrd_1, (void **)&status);
    pthread_join(thrd_2, (void **)&status);

    Sleep(1000); // Sleep for a while before exiting to allow threads to print

    return 1;
}

