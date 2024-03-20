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

    bool needMinus = false;
    for (int i = 0; i < a.length(); ++i) {
        if (stoi(a[i]) < stoi(b[i])) {
            std::string tmp = a;
            a = b;
            b = tmp;
            needMinus = true;
            break;
        }
    }

    std::string sum = "";
    bool under = false;
    for (int i = a.length() - 1; i >= 0; --i) {
        int segmentA = stoi(a[i]) - (under ? 1 : 0);
        int segmentB = stoi(b[i]);
        under = false;

        if (segmentA < segmentB) {
            segmentA += 10;
            under = true;
        }

        sum = std::to_string(segmentA - segmentB) + sum;
    }

    int remainPadding = 0;
    for (int i = 0; i < sum.length() - 1; ++i) {
        if (sum[i] == '0') {
            remainPadding++;
        } else {
            break;
        }
    }
    sum = sum.substr(remainPadding, sum.length());

    if (needMinus) {
        sum = "-" + sum;
    }

    return sum;
}