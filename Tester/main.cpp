#ifdef DEBUG
    #include <chrono>
#endif
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
using namespace std;

char cmds[3] = {'1', '2', '3'};

int main() {
    #ifdef DEBUG
        auto start = chrono::high_resolution_clock::now();
    #endif

    FILE * tf = fopen("test.txt", "w");

    long long t = 1e4;

    fprintf(tf, "%lld\n", t);
    while (t--) {
        long long n = 1e4;
        char s[21]; // +1 for null terminator
        fprintf(tf, "%lld\n", n);
        for (int i = 0; i < 20; i++) {
            s[i] = cmds[rand() % 3];
        }
        s[20] = '\0';
        fprintf(tf, "%s\n", s);
    }

    fclose(tf);

    #ifdef DEBUG
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
        cout << duration.count() << " ms\n";
    #endif

    return 0;
}
