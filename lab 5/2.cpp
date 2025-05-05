#include <iostream>
using namespace std;

class list {
private:
    struct node {
        int data;
        node* next;
    } *head;

public:
    list() {
        head = NULL;
    }

    void insertbeginning(int);
    void insertend(int);
    void insertpos(int, int);
    int deletebeginning();
    int deleteend();
    int deletepos(int);
    int search(int);
    void display();
};

void list::insertbeginning(int num) {
    node* newnode = new node;
    newnode->data = num;

    if (head == NULL) {
        newnode->next = newnode;
        head = newnode;
        cout << "Element inserted at beginning!" << endl;
        return;
    }

    node* temp = head;
    while (temp->next != head)
        temp = temp->next;

    newnode->next = head;
    temp->next = newnode;
    head = newnode;
    cout << "Element inserted at beginning!" << endl;
}

void list::insertend(int num) {
    node* newnode = new node;
    newnode->data = num;

    if (head == NULL) {
        newnode->next = newnode;
        head = newnode;
        cout << "Element inserted at end!" << endl;
        return;
    }

    node* temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = newnode;
    newnode->next = head;
    cout << "Element inserted at end!" << endl;
}

void list::insertpos(int num, int pos) {
    node* newnode = new node;
    newnode->data = num;

    if (pos < 1) {
        cout << "Invalid position!" << endl;
        delete newnode;
        return;
    }

    if (pos == 1) {
        insertbeginning(num);
        return;
    }

    if (head == NULL) {
        cout << "Invalid position! List is empty." << endl;
        delete newnode;
        return;
    }

    int count = 1;
    node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
        count++;
    }

    if (pos > count + 1) {
        cout << "Invalid position!" << endl;
        delete newnode;
        return;
    }

    temp = head;
    for (int i = 1; i < pos - 1; ++i)
        temp = temp->next;

    newnode->next = temp->next;
    temp->next = newnode;

    cout << "Element inserted at position " << pos << "!" << endl;
}

int list::deletebeginning() {
    if (head == NULL)
        return -1;

    int data;
    if (head->next == head) {
        data = head->data;
        delete head;
        head = NULL;
        return data;
    }

    node* temp = head;
    while (temp->next != head)
        temp = temp->next;

    node* todelete = head;
    data = todelete->data;
    head = head->next;
    temp->next = head;
    delete todelete;

    return data;
}

int list::deleteend() {
    if (head == NULL)
        return -1;

    if (head->next == head) {
        int data = head->data;
        delete head;
        head = NULL;
        return data;
    }

    node* temp = head;
    while (temp->next->next != head)
        temp = temp->next;

    node* todelete = temp->next;
    int data = todelete->data;
    temp->next = head;
    delete todelete;

    return data;
}

int list::deletepos(int pos) {
    if (head == NULL)
        return -1;

    int count = 1;
    node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
        count++;
    }

    if (pos < 1 || pos > count)
        return 0;

    if (pos == 1)
        return deletebeginning();

    if (pos == count)
        return deleteend();

    node* prev = head;
    for (int i = 1; i < pos - 1; ++i)
        prev = prev->next;

    node* todelete = prev->next;
    int data = todelete->data;
    prev->next = todelete->next;
    delete todelete;

    return data;
}

int list::search(int target) {
    if (head == NULL)
        return -1;

    node* temp = head;
    int pos = 1;

    do {
        if (temp->data == target)
            return pos;
        temp = temp->next;
        pos++;
    } while (temp != head);

    return -1;
}

void list::display() {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    node* temp = head;
    cout << "The elements of the list are: ";
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main() {
    list l1;
    int choice, num, pos, result;

    while (true) {
        cout << "\nThe Menu\n"
             << "1. Insert Beginning\n"
             << "2. Insert End\n"
             << "3. Insert at Position\n"
             << "4. Delete Beginning\n"
             << "5. Delete End\n"
             << "6. Delete at Position\n"
             << "7. Search\n"
             << "8. Display\n"
             << "9. Exit\n"
             << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the element: ";
                cin >> num;
                l1.insertbeginning(num);
                break;

            case 2:
                cout << "Enter the element: ";
                cin >> num;
                l1.insertend(num);
                break;

            case 3:
                cout << "Enter the element: ";
                cin >> num;
                cout << "Enter position (starting from 1): ";
                cin >> pos;
                l1.insertpos(num, pos);
                break;

            case 4:
                result = l1.deletebeginning();
                if (result != -1)
                    cout << result << " has been deleted." << endl;
                else
                    cout << "List is empty!" << endl;
                break;

            case 5:
                result = l1.deleteend();
                if (result != -1)
                    cout << result << " has been deleted." << endl;
                else
                    cout << "List is empty!" << endl;
                break;

            case 6:
                cout << "Enter position (starting from 1): ";
                cin >> pos;
                result = l1.deletepos(pos);
                if (result == -1)
                    cout << "List is empty!" << endl;
                else if (result == 0)
                    cout << "Invalid position!" << endl;
                else
                    cout << result << " has been deleted from position " << pos << "." << endl;
                break;

            case 7:
                cout << "Enter the element to search: ";
                cin >> num;
                result = l1.search(num);
                if (result == -1)
                    cout << "Element not found!" << endl;
                else
                    cout << "Element found at position " << result << "." << endl;
                break;

            case 8:
                l1.display();
                break;

            case 9:
                cout << "Exiting the program." << endl;
                return 0;

            default:
                cout << "Invalid choice! Try again." << endl;
        }
    }

    return 0;
}
