#ifndef THREADPOOL_CPP
#define THREADPOOL_CPP

#include "threadpool.h"

using namespace std;

/* Starting of threadpool at the start of the program and process assigned tasks in a queue*/
void threadpool::start_thread(std::size_t numThreads){
        
    for(int i=0; i<numThreads; ++i){
        mThreads.emplace_back([=]{
            while(true){
                Task task;
                {
                    unique_lock<mutex> lock{mEventMutex};
                    mEventvar.wait(lock, [=]{return flag || !mTask.empty();});

                    if(flag && mTask.empty()){break;}

                    task = move(mTask.front());
                    mTask.pop();
                }
                task();
            }
        });
    }
}

/* End of threadpool. Threads are joined */
void threadpool::stop() noexcept{
    {
        unique_lock<mutex> lock{mEventMutex};
        flag = true;
    }
    mEventvar.notify_all();

    for(auto &threads:mThreads){
        threads.join();
    }
    chrono::steady_clock::time_point end = chrono::steady_clock::now();
    cout << "Time Elapsed:" << chrono::duration_cast<chrono::milliseconds> (end-beg).count() << "ms" << endl;
}



#endif