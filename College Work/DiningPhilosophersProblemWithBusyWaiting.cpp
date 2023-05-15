#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>
#include <cstdlib>
#include <mutex>
using namespace std;

mutex mo; // Global mutex for outputting to the console

int myrand(int min, int max)
{
    return rand() % (max - min) + min;
}

void lock(atomic_flag &m)
{
    // Set value of lock to 1 if it is available (0) otherwise busy waiting
    while (m.test_and_set())
        ; // busy waiting
}

void unlock(atomic_flag &m)
{
    // Set value of lock to 0
    m.clear();
}

void phil(int ph, atomic_flag &ma, atomic_flag &mb, int fork1, int fork2)
{
    while (true)
    {
        int duration = myrand(1000, 2000);
        {
            // Lock guard acquires the mutex when the code block is entered and releases it when it is exited or because of error
            lock_guard<mutex> g(mo);
            cout << ph << " thinks " << duration << "ms\n";
        }
        this_thread::sleep_for(chrono::milliseconds(duration));

        lock(ma);
        {
            lock_guard<mutex> g(mo);
            cout << "\t\t" << ph << " got ma (Fork " << fork1 << ")\n";
        }
        this_thread::sleep_for(chrono::milliseconds(1000)); // Thinking b4 acquiring second lock (fork)

        lock(mb);
        {
            lock_guard<mutex> g(mo);
            cout << "\t\t" << ph << " got mb (Fork " << fork2 << ")\n";
        }

        duration = myrand(1000, 2000);
        {
            lock_guard<mutex> g(mo);
            cout << "\t\t\t\t" << ph << " eats " << duration << "ms\n";
        }
        this_thread::sleep_for(chrono::milliseconds(duration));

        unlock(mb);
        unlock(ma);
    }
}

int main()
{
    srand(time(0));

    atomic_flag m1, m2, m3, m4;
    // All forks are available in the start
    unlock(m1);
    unlock(m2);
    unlock(m3);
    unlock(m4);

    thread t1([&]
              { phil(1, m1, m2, 1, 2); });
    thread t2([&]
              { phil(2, m2, m3, 2, 3); });
    thread t3([&]
              { phil(3, m3, m4, 3, 4); });
    thread t4([&]
              { phil(4, m1, m4, 1, 4); });

    t1.join();
    t2.join();
    t3.join();
    t4.join();
}