#include "../headers.h" // IWYU pragma: keep

bool isPerfectSquare(int num) {
    int left = 0, right = num;
    while (left <= right) {
        long mid = left + (right - left) / 2;
        if (mid * mid <= num)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return right * right == num;
}

bool isPerfectSquare_(int num) {
    long left = 0, right = (long)num + 1;
    while (left < right) {
        long mid = left + (right - left) / 2;
        if (mid * mid <= num)
            left = mid + 1;
        else
            right = mid;
    }
    return (right - 1) * (right - 1) == num;
}
