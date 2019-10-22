#include <bits/stdc++.h>
using namespace std;
int main() {
    while (true)
    {
        system("data.exe > in.txt");
        system("my.exe < in.txt > out.txt");
        system("ans.exe < in.txt > ans.txt");
        if (system("fc out.txt ans.txt")) break;
    }
    
}