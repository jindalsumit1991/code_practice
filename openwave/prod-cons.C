#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <atomic>
#include <condition_variable>

using namespace std;

std::mutex mtx;
std::condition_variable produce;

std::queue<int> q;
int cnt  = 0;
std::atomic<bool> finished;

void producer()
{
    while(true)
    {
        std::lock_guard<std::mutex> lock(mtx);
        if(q.empty())
        {
            //cout << "Pushing " << ++cnt << " into queue and sleeping" << endl;
            q.push(++cnt);
            //this_thread::sleep_for(std::chrono::seconds(1));
        }
        //finished = true;
        produce.notify_all();
    }
}

void consumer() 
{
	while (true) 
    {
		std::unique_lock<std::mutex> lk(mtx);
		produce.wait(lk, []{ return !q.empty(); });
		cout << q.front() << " printed in thread id " << this_thread::get_id() << endl;
		q.pop();
		if (q.empty())
			break;
	}
}

int main()
{
	int threadCnt = 0;
	cout << "Enter number of consumer threads: ";
	cin >> threadCnt;

	std::thread t1(producer);

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
	return 0;
}
