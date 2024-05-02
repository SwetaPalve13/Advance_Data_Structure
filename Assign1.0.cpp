#include <iostream>
using namespace std;

class abc {
public:
    int price, bid;
    string title, author;
    abc* next;

    void accept();
    void display();
    void search();
    void update();
    void insert_AF();
    void insert_AE();
    void Delete_FN();
    void Delete_LN();
};

abc* start = nullptr;
abc* last = nullptr;

void abc::accept() {
    abc* newnode = new abc;
    cout << "Enter bid, price, title, author: ";
    cin >> newnode->bid >> newnode->price >> newnode->title >> newnode->author;
    newnode->next = nullptr;
    if (start == nullptr) {
        last = start = newnode;
    }
    else {
        last->next = newnode;
        last = newnode;
    }
}

void abc::display() {
    abc* temp = start;
    if (temp == nullptr) {
        cout << "List is empty" << endl;
    }
    else {
        while (temp != nullptr) {
            cout << temp->bid << "\t" << temp->price << "\t" << temp->title << "\t" << temp->author << endl;
            temp = temp->next;
        }
    }
}

void abc::search() {
    int id;
    cout << "Enter book id you want to search: ";
    cin >> id;
    abc* temp = start;
    bool found = false;
    while (temp != nullptr) {
        if (temp->bid == id) {
            found = true;
            cout << "Book available" << endl;
            cout << temp->bid << "\t" << temp->price << "\t" << temp->title << "\t" << temp->author << endl;
            break;
        }
        temp = temp->next;
    }
    if (!found) {
        cout << "Book not found" << endl;
    }
}

void abc::update() {
    int bookid;
    cout << "Enter the book id you want to update: ";
    cin >> bookid;
    abc* temp = start;
    bool found = false;
    while (temp != nullptr) {
        if (temp->bid == bookid) {
            found = true;
            cout << "Book available. Enter new bid, price, title, author: ";
            cin >> temp->bid >> temp->price >> temp->title >> temp->author;
            break;
        }
        temp = temp->next;
    }
    if (!found) {
        cout << "Book not found" << endl;
    }
}

void abc::Delete_FN() {
    if (start == nullptr) {
        cout << "List is empty. Cannot delete." << endl;
        return;
    }
    abc* temp = start;
    start = start->next;
    delete temp;
}

void abc::Delete_LN() {
     if (start == nullptr) {
        cout << "List is empty. Cannot delete." << endl;
        return;
    }
    if (start->next == nullptr) {
        delete start;
        start = nullptr;
        last = nullptr;
        return;
    }
    abc* temp = start;
    while (temp->next != last) {
        temp = temp->next;
    }
    delete last;
    last = temp;
    last->next = nullptr;

}

void abc::insert_AF() {
    abc* newnode = new abc;
    cout << "Enter bid, price, title, author to insert at the beginning: ";
    cin >> newnode->bid >> newnode->price >> newnode->title >> newnode->author;
    newnode->next = start;
    start = newnode;
}

void abc::insert_AE() {
    abc* newnode = new abc;
    cout << "Enter bid, price, title, author to insert at the end: ";
    cin >> newnode->bid >> newnode->price >> newnode->title >> newnode->author;
    newnode->next = nullptr;
    if (start == nullptr) {
        start = last = newnode;
    }
    else {
        last->next = newnode;
        last = newnode;
    }
}

int main() {
    int ch;
    abc obj;
    do {
        cout << "\nMENU" << endl;
        cout << "1. Accept()" << endl;
        cout << "2. Display()" << endl;
        cout << "3. Search()" << endl;
        cout << "4. Update()" << endl;
        cout << "5. Insert_AF()" << endl;
        cout << "6. Insert_AE()" << endl;
        cout << "7. Delete_first_node()" << endl;
        cout << "8. Delete_last_node()" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
        case 1:
            obj.accept();
            break;
        case 2:
            obj.display();
            break;
        case 3:
            obj.search();
            break;
        case 4:
            obj.update();
            break;
        case 5:
            obj.insert_AF();
            break;
        case 6:
            obj.insert_AE();
            break;
        case 7:
            obj.Delete_FN();
            cout<<"deleted successfully";
            break;
        case 8:
            obj.Delete_LN();
            cout<<"deleted successfully";
            break;
        case 9:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (ch != 9);

    return 0;
}
