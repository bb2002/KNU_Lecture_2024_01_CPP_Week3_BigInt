#include<string>
#include<iostream>

std::string padding(std::string a, int size) {
    std::string result = "";
    for (int i = 0; i < size; ++i) {
        result += "0";
    }

    return result + a;
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
        segment += ((a[i] - 48) + (b[i] - 48));
        
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