#include <cstdio>
#include <cstdlib>

#define size 5

class ListAdt {
private:
    int arr[size];
    int count;

public:
    ListAdt();

    int insertbeg(int value);
    int insertend(int value);
    int insertpos(int value, int pos);
    int deletebeg();
    int deleteend();
    int deletepos(int pos);
    int search(int value);
    void display();
    int rotate(int k);

    void setcount(int newcount);
    int getcount();
    void setelement(int value, int pos);
    int getelement(int pos);
};

int main() {
    int choice, value, pos, k;
    ListAdt L1adt;

    while (true) {
        printf("\nMenu\n");
        printf("1.Insert beginning\n");
        printf("2.Insert end\n");
        printf("3.Insert at given position\n");
        printf("4.Delete beginning\n");
        printf("5.Delete end\n");
        printf("6.Delete position\n");
        printf("7.Search\n");
        printf("8.Display\n");
        printf("9.Rotate\n");
        printf("10.Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                L1adt.insertbeg(value);
                L1adt.display();
                break;
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                L1adt.insertend(value);
                L1adt.display();
                break;
            case 3:
                printf("Enter value and position to insert: ");
                scanf("%d %d", &value, &pos);
                L1adt.insertpos(value, pos);
                L1adt.display();
                break;
            case 4:
                L1adt.deletebeg();
                L1adt.display();
                break;
            case 5:
                L1adt.deleteend();
                L1adt.display();
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                L1adt.deletepos(pos);
                L1adt.display();
                break;
            case 7:
                printf("Enter value to search: ");
                scanf("%d", &value);
                pos = L1adt.search(value);
                if (pos != -1) {
                    printf("Value found at position %d\n", pos);
                } else {
                    printf("Value not found\n");
                }
                break;
            case 8:
                L1adt.display();
                break;
            case 9:
                printf("Enter rotation count: ");
                scanf("%d", &k);
                L1adt.rotate(k);
                L1adt.display();
                break;
            case 10:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Enter a valid choice\n");
        }
    }
    return 0;
}

// Constructor
ListAdt::ListAdt() {
    count = 0;
}

int ListAdt::getcount() {
    return count;
}

void ListAdt::setcount(int newcount) {
    count = newcount;
}

int ListAdt::getelement(int pos) {
    if (pos >= 0 && pos < count) {
        return arr[pos];
    }
    printf("Invalid position!\n");
    return -1;
}

void ListAdt::setelement(int value, int pos) {
    if (pos >= 0 && pos < size) {
        arr[pos] = value;
    } else {
        printf("Invalid position!\n");
    }
}

// Insert at beginning
int ListAdt::insertbeg(int value) {
    if (count >= size) {
        printf("List is full\n");
        return 0;
    }
    for (int i = count; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = value;
    count++;
    return 1;
}

// Insert at end
int ListAdt::insertend(int value) {
    if (count >= size) {
        printf("List is full\n");
        return 0;
    }
    arr[count++] = value;
    return 1;
}

// Insert at position
int ListAdt::insertpos(int value, int pos) {
    if (count >= size) {
        printf("List is full\n");
        return 0;
    }
    if (pos < 0 || pos > count) {
        printf("Invalid position\n");
        return 0;
    }
    for (int i = count; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    count++;
    return 1;
}

// Delete at beginning
int ListAdt::deletebeg() {
    if (count == 0) {
        printf("List is empty\n");
        return 0;
    }
    for (int i = 0; i < count - 1; i++) {
        arr[i] = arr[i + 1];
    }
    count--;
    return 1;
}

// Delete at end
int ListAdt::deleteend() {
    if (count == 0) {
        printf("List is empty\n");
        return 0;
    }
    count--;
    return 1;
}

// Delete at position
int ListAdt::deletepos(int pos) {
    if (pos < 0 || pos >= count) {
        printf("Invalid position\n");
        return 0;
    }
    for (int i = pos; i < count - 1; i++) {
        arr[i] = arr[i + 1];
    }
    count--;
    return 1;
}

// Search
int ListAdt::search(int value) {
    for (int i = 0; i < count; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

// Display
void ListAdt::display() {
    if (count == 0) {
        printf("List is empty\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Rotate
int ListAdt::rotate(int k) {
    if (count == 0) {
        printf("List is empty\n");
        return 0;
    }
    k = k % count;
    int temp[size];
    for (int i = 0; i < count; i++) {
        temp[(i + k) % count] = arr[i];
    }
    for (int i = 0; i < count; i++) {
        arr[i] = temp[i];
    }
    return 1;
}
