#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MIN_NR = 10, MAX_NR = 99, MIN_LS = 5, MAX_LS = 20;

//function prototypes 
void loadNames(vector<string>& names);
string getRandomName(const vector<string>& names);

class DoublyLinkedList {
private:
    struct Node {
       string data;
        Node* prev;
        Node* next;
        Node(string val, Node* p = nullptr, Node* n = nullptr) {
            data = val; 
            prev = p;
            next = n;
        }
    };

    Node* head;
    Node* tail;

public:
    DoublyLinkedList() { head = nullptr; tail = nullptr; }

    void push_back(string v) {
        Node* newNode = new Node(v);
        if (!tail)
            head = tail = newNode;
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    
    void push_front(string v) {
        Node* newNode = new Node(v);
        if (!head)
            head = tail = newNode;
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    
    void pop_front() {

        if (!head) return;

        Node* temp = head;

        if (head->next) {
            head = head->next;
            head->prev = nullptr;
        } 
        else
            head = tail = nullptr;
        delete temp;
    }

    void pop_back() {
        if (!tail) return;
        
        Node* temp = tail;

        if (tail->prev) {
            tail = tail->prev;
            tail->next = nullptr;
        }
        else
            head = tail = nullptr;
        delete temp;
    } 

    void delete_val(string value) {
        Node* temp = head;

        while (temp && temp->data != value)
            temp = temp->next;

        if (!temp) return;

        if (temp->prev)
            temp->prev->next = temp->next;
        else 
            head = temp->next;

        if (temp->next)
            temp->next->prev = temp->prev;
        else
            tail = temp->prev;
        
        delete temp;
    } 

    bool isEmpty() {
        return head == nullptr;
    }

    string getFront() {
        if (head) return head->data;
        return "";
    }

    string getBack() {
        if (tail) return tail->data;
        return "";
    }

    //removing the random person (10%)
    void remove_random() {
        if (!head) return;

        int count = 0;
        Node* temp = head;

        while (temp) {
            count++;
            temp = temp->next;
        }
    }