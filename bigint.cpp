#include<string>
#include<iostream>

std::string padding(std::string a, int size) {
    std::string result = "";
    for (int i = 0; i < size; ++i) {
        result += "0";
    }

    return result + a;
}

int stoi(char s) {
    return s - 48;
}

std::string sum(std::string a, std::string b) {
    if (a.length() < b.length()) {
        a = padding(a, b.length() - a.length());
    }

    if (a.length() > b.length()) {
        b = padding(b, a.length() - b.length());
    }

    std::string sum = "";
    bool upper = false;
    for (int i = a.length() - 1; i >= 0; --i) {
        int segment = upper ? 1 : 0;
        upper = false;
        segment += (stoi(a[i]) + stoi(b[i]));
        
        if (segment >= 10) {
            upper = true;
            segment -= 10;
        }

        sum = std::to_string(segment) + sum;
    }

    if (upper) {
        sum = "1" + sum;
    }

    return sum;
}

std::string minus(std::string a, std::string b) {
    if (a.length() < b.length()) {
        a = padding(a, b.length() - a.length());
    }

    if (a.length() > b.length()) {
        b = padding(b, a.length() - b.length());
    }

    // a 가 무조건 더 크도록 수정
    bool needMinus = false;
    if (a < b) {
        std::string tmp = a;
        a = b;
        b = tmp;
        needMinus = true;
    }

    int borrow = 0;
    std::string result = "";
    for (int i = a.length() - 1; i >= 0; --i) {
        int digit1 = stoi(a[i]);
        int digit2 = stoi(b[i]);
        int diff = digit1 - digit2 - borrow;
        if (diff < 0) {
            borrow = 1;
            diff += 10;
        } else {
            borrow = 0;
        }
        result = std::to_string(diff) + result;
    }

    // 0 제거
    int remainPadding = 0;
    for (int i = 0; i < result.length() - 1; ++i) {
        if (result[i] == '0') {
            remainPadding++;
        } else {
            break;
        }
    }

    result = result.substr(remainPadding, result.length());
    if (result.empty()) {
        return "0";
    }

    // 마이너스 처리
    if (needMinus) {
        return std::string("-") + result;
    } else {
        return result;
    }
}