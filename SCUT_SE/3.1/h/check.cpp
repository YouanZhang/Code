#include <bits/stdc++.h>
using namespace std;
int main() {
    while (1) {
        system("data.exe > in.txt");
        system("h.exe < in.txt > out.txt");
        system("h1.exe < in.txt > ans.txt");
        if (system("fc out.txt ans.txt")) break;
    }
}