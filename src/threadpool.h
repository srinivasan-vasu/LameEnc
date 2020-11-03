#ifndef THREADPOOL_H
#define THREADPOOL_H

#include <iostream>
#include <thread>
#include <functional>
#include <future>
#include <condition_variable>
#include <vector>
#include <queue>

using namespace std;
extern chrono::steady_clock::time_point beg;
using Task = function<void()>;

class threadpool{
private:
    vector<thread> mThreads;
    condition_variable mEventvar;
    mutex mEventMutex;
    bool flag{false};
    queue<Task> mTask;

    void start_thread(std::size_t numThreads);

    void stop() noexcept;

public:

    threadpool(std::size_t numThreads) {
        start_thread(numThreads);
    }

    ~threadpool(){
        stop();
    }

    /* Enqueue Function which adds tasks to the queue*/
    template<class T>
    auto enqueue(T task)->future<decltype(task())>{
    
        auto wrapper = make_shared<packaged_task<decltype(task()) ()>>(move(task));
        {
            unique_lock<mutex> lock{mEventMutex};
            mTask.emplace([=]{(*wrapper)();});
        }

        mEventvar.notify_one();
        return wrapper->get_future();

    }

};






#endif