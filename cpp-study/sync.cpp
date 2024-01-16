// 동시성 연습해보자
// 큐에 작업을 넣고 큐에서 작업을 빼고
// condition variable로 제어하기

#include <iostream>
#include <string>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;
using data_t = int; // data type

class task_queue {
    private:
        mutex m_lock;
        condition_variable m_empt;
        condition_variable m_full;
        queue<data_t> tq;

    public:
        void push(data_t data) { tq.push(data); }
        void pop() { tq.pop(); }
        data_t& front() { return tq.front(); }
        data_t& back() { return tq.back(); }

        // getters
        void lock() { m_lock.lock(); }
        void unlock() { m_lock.unlock(); }
        void if_full() { m_full.wait(); }

        condition_variable& is_empt() { return m_empt; }
        condition_variable& is_full() { return m_full; }
}

class producer {
    int tid;
    data_t data;
    string name; // for debugging
    public:
        producer(int tid, data_t data, string name): tid(tid), name(name){};
        producer(producer& p) = delete;
        producer& operator=(producer& p) = delete;
        ~producer() = default;

        // push task into queue
        void work(const task_queue& tq) {
            // 접근 락을 획득
            tq.lock();
            // 큐가 가득 차 있지 않을 때까지 기다립니다.
            tq.is_full().wait
            // 큐에 데이터 삽입
            // 큐가 비어 있지 않았다는 신호를 보냅니다.
            // 접근 락 해제
        }
        void show() {
            // 현재 스레드 
        }
        
}