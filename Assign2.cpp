#include <iostream>
using namespace std;

class cms {
    int did;
    long int pno;
    string name;
    float amt;
    cms *next, *pre;

public:
    void accept();
    void display();
    void search();
    void update();
    void DELETE();
} *start = nullptr, *end1 = nullptr;

void cms::accept() {
    cms *nn;
    nn = new cms;
    cout << "Enter the record" << endl;
    cout << "DID NAME PH_NO AMT" << endl;
    cin >> nn->did >> nn->name >> nn->pno >> nn->amt;
    nn->next = nn->pre = nullptr;
    if (start == nullptr) {
        end1 = start = nn;
    } else {
        end1->next = nn;
        nn->pre = end1;
        end1 = nn;
    }
}

void cms::display() {
    cms *temp;
    temp = start;
    if (temp == nullptr) {
        cout << "LIST IS EMPTY" << endl;
    } else {
        while (temp != nullptr) {
            cout << temp->did << "\t" << temp->name << "\t" << temp->pno << "\t" << temp->amt << endl;
            temp = temp->next;
        }
    }
}

void cms::search() {
    cms *temp;
    int id;
    int flag = 0;
    temp = start;
    cout << "Enter the book id which you want to search: ";
    cin >> id;
    while (temp != nullptr) {
        if (temp->did == id) {
            flag = 1;
            cout << "BOOK IS AVAILABLE" << endl;
            cout << temp->did << "\t" << temp->name << "\t" << temp->pno << "\t" << temp->amt << endl;
            break;
        }
        temp = temp->next;
    }
    if (flag == 0) {
        cout << "BOOK IS UNAVAILABLE" << endl;
    }
}

void cms::update() {
    cms *temp;
    int id;
    int flag = 0;
    temp = start;
    cout << "Enter the book id which you want to update: ";
    cin >> id;
    while (temp != nullptr) {
        if (temp->did == id) {
            flag = 1;
            cout << "BOOK IS AVAILABLE" << endl;
            cout << temp->did << "\t" << temp->name << "\t" << temp->pno << "\t" << temp->amt << endl;
            cin >> temp->did >> temp->name >> temp->pno >> temp->amt;
            break;
        }
        temp = temp->next;
    }
    if (flag == 0) {
        cout << "BOOK IS UNAVAILABLE" << endl;
    }
}

void cms::DELETE() {
    int id1;
    cout << "Enter the id of the record you want to delete: ";
    cin >> id1;

    if (start == nullptr) {
        cout << "List is empty. Cannot delete." << endl;
        return;
    }

    cms *temp = start;

    // Deleting the first node
    if (temp->did == id1) {
        start = start->next;
        if (start != nullptr)
            start->pre = nullptr;
        delete temp;
        cout << "Record with ID " << id1 << " deleted successfully." << endl;
        return;
    }

    // Finding the node to delete
    while (temp != nullptr && temp->did != id1)
        temp = temp->next;

    if (temp == nullptr) {
        cout << "Record with ID " << id1 << " not found." << endl;
        return;
    }

    // Adjusting pointers to delete the node
    if (temp->pre != nullptr)
        temp->pre->next = temp->next;
    if (temp->next != nullptr)
        temp->next->pre = temp->pre;

    delete temp;
    cout << "Record with ID " << id1 << " deleted successfully." << endl;
}

int main() {
    int ch;
    do {
        cout << "MENU" << endl;
        cout << "1. accept()" << endl;
        cout << "2. display()" << endl;
        cout << "3. search()" << endl;
        cout << "4. update()" << endl;
        cout << "5. DELETE()" << endl;
        cout << "6. Exit" << endl; // Added exit option
        cout << "Enter your choice: ";
        cin >> ch;
        switch (ch) {
            case 1: {
                cms obj1;
                obj1.accept();
                break;
            }
            case 2:
                cout << "Display the records" << endl;
                if (start != nullptr)
                    start->display();
                else
                    cout << "No records to display" << endl;
                break;

            case 3:
                if (start != nullptr)
                    start->search();
                else
                    cout << "No records to search" << endl;
                break;

            case 4:
                if (start != nullptr)
                    start->update();
                else
                    cout << "No records to update" << endl;
                break;

            case 5:
                if (start != nullptr)
                    start->DELETE();
                else
                    cout << "No records to delete" << endl;
                break;

            case 6:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "INVALID CHOICE" << endl;
                break;
        }
    } while (ch != 6);
    return 0;
}
