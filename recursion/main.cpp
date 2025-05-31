#include <iostream>
#include <vector>
#include <string>

//функция для сложения двух больших чисел в строковом формате
std::string addStrings(const std::string& num1, const std::string& num2) {
    std::string result;
    int carry = 0;
    int i = num1.length() - 1;
    int j = num2.length() - 1;
    
    while (i >= 0 || j >= 0 || carry) {
        int digit1 = i >= 0 ? num1[i] - '0' : 0;
        int digit2 = j >= 0 ? num2[j] - '0' : 0;
        
        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        result.push_back(sum % 10 + '0');
        
        i--; j--;
    }
    
    std::reverse(result.begin(), result.end());
    return result;
}

//функция для умножения строки на число
std::string multiplyString(const std::string& num, int multiplier) {
    std::string result = "0";
    for (int i = 0; i < multiplier; i++) {
        result = addStrings(result, num);
    }
    return result;
}


bool isOdd(const std::string& num) {
    return (num.back() - '0') % 2 != 0;
}

std::string find(std::vector<std::string> &f, std::vector<std::string> &A, int &index) {
    if (isOdd(f[1])) A.push_back(f[1]);
    if (A.size() > index)
        return A[index];

    std::string next_f = addStrings(multiplyString(f[1], 5), f[0]);
    f[0] = f[1];
    f[1] = next_f;
    return find(f, A, index);
}

int main() {
    std::vector<std::string> f = { "1", "3" }; // f(0) = 1, f(1) = 3
    std::vector<std::string> A; // Массив для нечетных значений
    if (isOdd(f[0])) A.push_back(f[0]);
    int index = 39;

    std::cout << find(f, A, index) << std::endl;
    return 0;
}