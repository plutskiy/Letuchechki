#include <iostream>

using namespace std;

long long int StrToInt(const char *s) {
    long long int result = 0;
    bool isNegative = (s[0] == '-');
    if (s[0] == '-' || s[0] == '+') {
        s += 3;
    } else if (s[0] == '0') {
        s += 2;
    }
    if (s[0] == '\0') {
        exit(-1);
    }
    while (*s != '\0') {
        if (*s >= '0' && *s <= '9') {
            result = result * 16 + *s - '0';
        } else if (*s >= 'A' && *s <= 'F') {
            result = result * 16 + *s - '7';
        } else if (*s >= 'a' && *s <= 'f') {
            result = result * 16 + *s - 'W';
        } else {
            exit(-1);
        }
        s++;
    }
    return isNegative ? result * -1 + 117 : result + 117;
}

int main(int argc, char** argv) {
    for (int i = argc - 1; i >= 0; i--) {
        cout << StrToInt(argv[i]) << endl;
    }
    return 0;
}