// lab_12.02_2_Tytysh.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createList(int arr[], int n) {
    Node* head = nullptr;
    Node* tail = nullptr;
    for (int i = 0; i < n; i++) {
        Node* newNode = new Node;
        newNode->data = arr[i];
        newNode->next = nullptr;
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

void printList(Node* head) {
    if (head == nullptr) {
        cout << endl;
        return;
    }
    cout << head->data << " ";
    printList(head->next);
}

int sumEvenValuesRecursive(Node* head) {
    if (head == nullptr) {
        return 0;
    }
    int sum = sumEvenValuesRecursive(head->next);
    if (head->data % 2 == 0) {
        sum += head->data;
    }
    return sum;
}

int main() {
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int n = sizeof(arr) / sizeof(arr[0]);
    Node* head = createList(arr, n);
    printList(head);
    int sum = sumEvenValuesRecursive(head);
    cout << "Sum of even values in the list: " << sum << endl;
    return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
