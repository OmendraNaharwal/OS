#include <bits/stdc++.h>
#include <semaphore>
using namespace std;

counting_semaphore<4> room(4);
mutex forks[5];

void philosopher(int i) {
    for (int j = 0; j < 2; j++) {
        cout << "Philosopher " << i << " is thinking\n";

        room.acquire();
        forks[i].lock();
        forks[(i + 1) % 5].lock();

        cout << "Philosopher " << i << " is eating\n";

        forks[(i + 1) % 5].unlock();
        forks[i].unlock();
        room.release();
    }
}

int main() {
    thread t[5];

    for (int i = 0; i < 5; i++)
        t[i] = thread(philosopher, i);

    for (int i = 0; i < 5; i++)
        t[i].join();

    return 0;
}
