#include <iostream>
#include <sstream>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>

using namespace std;

mutex mx;
condition_variable cv;
queue<string> q;

bool finished = false;

void producer(int n) {
    while(true)
    {
        for(int i=0; i<n; ++i) {
            {
                std::lock_guard<std::mutex> lk(mx);
                stringstream ss;
                ss << "Test String " << i;
                q.push(ss.str());
                cout << "Pushing: " << ss.str() << " in queue and sleeping for 1 sec\n";
                this_thread::sleep_for(std::chrono::seconds(1));
            }
            cv.notify_all();
        }

        {
            std::lock_guard<std::mutex> lk(mx);
            finished = true;
        }
        cv.notify_all();
    }
}

void consumer() {
    while (true) {
        //while (!q.empty())
        if(!q.empty())
        {
            std::unique_lock<std::mutex> lk(mx);
            cv.wait(lk, []{ return finished || !q.empty(); });
            cout << q.front() << " printed in thread id " << this_thread::get_id() << endl;
            q.pop();
            //lk.unlock();
        }
        if (finished)
            break;
    }
}

int main() 
{
    int threadCnt = 0;
    cout << "Enter number of consumer threads: ";
    cin >> threadCnt;

	std::thread t1(producer, 10);

    std::thread consumerThreads[threadCnt];

    for(int i=0; i < threadCnt; i++)
    {
        consumerThreads[i] = thread(consumer);
    }

	t1.join();

    for(int i=0; i < threadCnt; i++)
    {
        consumerThreads[i].join();
    }

	std::cout << "finished!" << std::endl;
}
