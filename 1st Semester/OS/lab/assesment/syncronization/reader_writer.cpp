#include <Windows.h>
#include <iostream>
#include <pthread.h>

using namespace std;

class monitor
{
private:
    // no. of readers
    int rcnt;

    // no. of writers
    int wcnt;

    // no. of readers waiting
    int wait_r;

    // no. of writers waiting
    int wait_w;

    // condition variable to check whether reader can read
    pthread_cond_t can_read;

    // condition variable to check whether writer can write
    pthread_cond_t can_write;

    // mutex for synchronization
    pthread_mutex_t cond_lock;

public:
    monitor()
    {
        rcnt = 0;
        wcnt = 0;
        wait_r = 0;
        wait_w = 0;

        pthread_cond_init(&can_read, NULL);
        pthread_cond_init(&can_write, NULL);
        pthread_mutex_init(&cond_lock, NULL);
    }

    // mutex provide synchronization so that no other thread
    // can change the value of data
    void beginread(int i)
    {
        pthread_mutex_lock(&cond_lock);

        // if there are active or waiting writers
        if (wcnt == 1 || wait_w > 0)
        {
            // incrementing waiting readers
            wait_r++;

            // reader suspended
            pthread_cond_wait(&can_read, &cond_lock);
            wait_r--;
        }

        // else reader reads the resource
        rcnt++;
        cout << "reader " << i << " is reading\n";
        pthread_mutex_unlock(&cond_lock);
        pthread_cond_broadcast(&can_read);
    }

    void endread(int i)
    {

        // if there are no readers left then writer enters monitor
        pthread_mutex_lock(&cond_lock);

        if (--rcnt == 0)
            pthread_cond_signal(&can_write);

        pthread_mutex_unlock(&cond_lock);
    }

    void beginwrite(int i)
    {
        pthread_mutex_lock(&cond_lock);

        // a writer can enter when there are no active
        // or waiting readers or other writer
        if (wcnt == 1 || rcnt > 0)
        {
            ++wait_w;
            pthread_cond_wait(&can_write, &cond_lock);
            --wait_w;
        }
        wcnt = 1;
        cout << "writer " << i << " is writing\n";
        pthread_mutex_unlock(&cond_lock);
    }

    void endwrite(int i)
    {
        pthread_mutex_lock(&cond_lock);
        wcnt = 0;

        // if any readers are waiting, threads are unblocked
        if (wait_r > 0)
            pthread_cond_signal(&can_read);
        else
            pthread_cond_signal(&can_write);
        pthread_mutex_unlock(&cond_lock);
    }

}

// global object of monitor class
M;

void *reader(void *id)
{
    int c = 0;
    int i = *(int *)id;

    // each reader attempts to read 5 times
    while (c < 5)
    {
        Sleep(1);
        M.beginread(i);
        M.endread(i);
        c++;
    }
}

void *writer(void *id)
{
    int c = 0;
    int i = *(int *)id;

    // each writer attempts to write 5 times
    while (c < 5)
    {
        Sleep(1);
        M.beginwrite(i);
        M.endwrite(i);
        c++;
    }
}

int main()
{
    pthread_t r[5], w[5];
    int id[5];
    for (int i = 0; i < 5; i++)
    {
        id[i] = i;

        // creating threads which execute reader function
        pthread_create(&r[i], NULL, &reader, &id[i]);

        // creating threads which execute writer function
        pthread_create(&w[i], NULL, &writer, &id[i]);
    }

    for (int i = 0; i < 5; i++)
    {
        pthread_join(r[i], NULL);
    }
    for (int i = 0; i < 5; i++)
    {
        pthread_join(w[i], NULL);
    }
}