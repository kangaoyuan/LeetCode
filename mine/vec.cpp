#include "../headers.h" // IWYU pragma: keep

int main() {
    vector vec = {1, 2, 3, 4, 5, 6, 7, 27, 77};

    /*
     *vec.erase(
     *    std::remove_if(vec.begin(), vec.end(), [](int x) { return x % 2 != 0; }),
     *    vec.end()
     *);
     */

    /*
     *for(auto it = vec.begin(); it != vec.end(); ){
     *    if(*it % 2 != 1)
     *        it = vec.erase(it);
     *    else
     *        it++;
     *}
     */

    vec.erase(
        std::remove_if(vec.begin(), vec.end(), []([[maybe_unused]]int x) {
            static int index = 0;
            return index++ % 2;
        }),
        vec.end()
    );

    /*
     *for(uint i = 1; i < vec.size(); i++){
     *    vec.erase(vec.begin()+i);
     *}
     */

    // Remove element and get the iterator to the next element
    /*
     *for (auto it = vec.begin() + 1; it != vec.end();) {
     *    it = vec.erase(it);
     *    if (it != vec.end())
     *        ++it;  // Skip the next element
     *}
     */

    for (int val : vec) {
        cout << val << " ";  // Output: 2 4 6 8 10
    }
    cout << endl;

    return 0;

}
