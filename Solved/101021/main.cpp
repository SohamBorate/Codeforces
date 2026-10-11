#include <cstdio>
#include <cstring>

using namespace std;

int main() {
    int l = 1, h = 1000000;
    while (l != h) {
        int mid = (l + h + 1) / 2;
        printf("%d\n", mid);
        fflush(stdout);

        char response[3];
        scanf("%s", response);
        if (strcmp(response, "<") == 0) {
            h = mid - 1;
        } else {
            l = mid;
        }
    }

    printf("! %d\n", l);
    fflush(stdout);
}
