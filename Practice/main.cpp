#include <bits/stdc++.h>
#include <math.h>
using namespace std;

struct Node {
    Node *prev;
    Node *next;
    char val;
    Node (char c) : val(c),next(nullptr),prev(nullptr) {}
};

void two(Node *head, int x) {
    Node *current = head;
    for (int i = 0; i < x; i++) {
        if (i == (x - 1)) {
            cout << current->val << "\n";
            break;
        } else {
            current = current->next;
        }
    }
}

int main() {
    int N, Q;
    cin >> N >> Q;

    char S;
    cin >> S;

    Node *head = new Node(S);
    Node *current = head;

    for (int i = 1; i < N; i++) {
        cin >> S;
        current->next = new Node(S);
        current->next->prev = current;
        current = current->next;
    }

    Node *tail = current;
    tail->next = head;
    head->prev = tail;

    // print
    // current = head;

    // for (int i = 0; i < N; i++) {
    //     cout << current->val;
    //     current = current->next;
    // }

    // cout << current->val;
    // cout << "\n";

    for (int i = 0; i < Q; i++) {
        int action, x;
        cin >> action >> x;
        // cout << action << " " << x << "\n";
        if (action == 1) {
            for (int j = 0; j < x; j++) {
                tail = tail->prev;
                head = head->prev;
            }
        } else if (action == 2) {
            two(head, x);
        }
        // print
        // current = head;

        // for (int i = 0; i < N; i++) {
        //     cout << current->val;
        //     current = current->next;
        // }

        // // cout << current->val;
        // cout << "\n";
    }

    return 0;
}
