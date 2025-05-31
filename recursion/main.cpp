#include <iostream>
#include <vector>

long long find(std::vector<long long> &f, std::vector<long long> &A, int &index) {
    if (f[1] % 2 != 0) A.push_back(f[1]);
    if (A.size() > index)
        return A[index];

    long long next_f = 5 * f[1] + f[0];
    f[0] = f[1];
    f[1] = next_f;

    return find(f, A, index);
}

int main() {
    std::vector<long long> f = { 1, 3 }; // f(0) = 1, f(1) = 3
    std::vector<long long> A; // Массив для нечетных значений
    if (f[0] % 2 != 0) A.push_back(f[0]);
    int index = 39;

    std::cout << find(f, A, index) << std::endl;
    return 0;
}