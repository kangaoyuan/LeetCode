#include <bits/stdc++.h>

int main(int argc, char** argv) {
    if(argc != 4){
        fprintf(stderr, "./p-c producer consumers capacity\n");
        exit(-1);
    }

    int num_producers = atoi(argv[1]);
    int num_consumers = atoi(argv[2]);
    uint num_capacity = atoi(argv[3]);

    uint slot = 0;
    std::vector<int> buf(num_capacity);
    uint front = 0, rear = 0;
    std::mutex mtx;
    std::condition_variable cv;

    auto producer = [&] (int id) {
        while(true){
            std::unique_lock<std::mutex> lck(mtx);
            cv.wait(lck, [&]() { return slot < num_capacity; });

            buf[rear] = 77;
            std::cout << "Producer " << id << " produced: " << "buf[" <<  rear << "]: " << buf[rear] << std::endl;
            rear = (rear+1) % num_capacity;

            slot++;
            cv.notify_all();
        }


    };

    auto consumer = [&] (int id) {
        while(true){
            std::unique_lock<std::mutex> lck(mtx);
            cv.wait(lck, [&]() { return slot > 0; } );

            std::cout << "Consumer " << id << " consumer: " << "buf[" <<  front << "]: " << buf[front] << std::endl;
            front = (front+1) % num_capacity;

            slot--;
            cv.notify_all();
        }
    };

    std::vector<std::jthread> producers;
    std::vector<std::jthread> consumers;

    for(int i = 0; i < num_producers; ++i){
        producers.emplace_back(producer, i);
    }

    for(int i = 0; i < num_consumers; ++i){
        consumers.emplace_back(consumer, i);
    }

    return 0;
}
