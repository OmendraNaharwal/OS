#include <bits/stdc++.h>
#include <semaphore>
using namespace std;

int buffer[5], in = 0, out = 0;
counting_semaphore<5> emptySlots(5), full(0);
mutex m;

void producer() {
    for (int i = 1; i <= 5; i++) {
        emptySlots.acquire();
        m.lock();
        buffer[in] = i;
        cout << "Produced: " << i << endl;
        in = (in + 1) % 5;
        m.unlock();
        full.release();
    }
}

void consumer() {
    for (int i = 1; i <= 5; i++) {
        full.acquire();
        m.lock();
        int item = buffer[out];
        cout << "Consumed: " << item << endl;
        out = (out + 1) % 5;
        m.unlock();
        emptySlots.release();
    }
}

int main() {
    thread p(producer), c(consumer);
    p.join();
    c.join();
    return 0;
}
