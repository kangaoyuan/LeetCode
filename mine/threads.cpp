#include "../headers.h" // IWYU pragma: keep

int main(){
    // condition_variable need the mutex and corresponding unique_lock<>.
    mutex mtx;
    condition_variable cv;
    // condition_variable wait() method need a lambda to judge the possibility.
    int turn = 'A', cnt = 0;

    auto thread_A = [&]() {
        int mine = 0;
        while (true) {
            unique_lock<mutex> lck(mtx);
            cv.wait(lck, [&turn]() { return turn == 'A'; });
            cout << "Threa_A: "
                 << "A" << endl;
            cnt++;
            mine++;
            turn = 'B';
            if (cnt == 91){
                cout << "Threa_A: " << mine << " iterations." << endl;
                cv.notify_all();
                return;
            }
            cv.notify_all();
        }
    };
    auto thread_B = [&]() {
        int mine = 0;
        while (true) {
            unique_lock<mutex> lck(mtx);
            cv.wait(lck, [&turn]() { return turn == 'B'; });
            cout << "Threa_B: "
                 << "B" << endl;
            cnt++;
            mine++;
            turn = 'C';
            if (cnt == 92){
                cout << "Threa_B: " << mine << " iterations." << endl;
                cv.notify_all();
                return;
            }
            cv.notify_all();
        }
    };
    auto thread_C = [&]() {
        int mine = 0;
        while (true) {
            unique_lock<mutex> lck(mtx);
            cv.wait(lck, [&turn]() { return turn == 'C'; });
            cout << "Threa_C: "
                 << "C" << endl;
            cnt++;
            mine++;
            turn = 'A';
            if (cnt == 93){
                cout << "Threa_B: " << mine << " iterations." << endl;
                cv.notify_all();
                return;
            }
            cv.notify_all();
        }
    };

    std::jthread t1(thread_A);
    std::jthread t2(thread_B);
    std::jthread t3(thread_C);

    /*
     *t1.join();
     *t2.join();
     *t3.join();
     */

    std::cout << std::endl;
    return 0;
}
