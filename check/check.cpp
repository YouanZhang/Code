#include <bits/stdc++.h>
using namespace std;
int main() {
    system("g++ data.cpp -g -o data");
    system("g++ my.cpp -g -o my");
    system("g++ ans.cpp -g -o ans");
    while (true)
    {
        system("data.exe > in.txt");
        system("my.exe < in.txt > out.txt");
        system("ans.exe < in.txt > ans.txt");
        if (system("fc out.txt ans.txt")) break;
    }
    
}