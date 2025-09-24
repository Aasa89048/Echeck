The code snippts:
#include<iostream>
#include<vector>
#include<limits>
#include <cstdlib>
#include <ctime>
#include<algorithm>
using namespace std;

class transaction {
public:
    int id;
    int amount;
    int receiver_number;
    string name;
    transaction* next;
    transaction(int id1, int amount1, string name1, int receiver_number1, transaction* next1 = nullptr)
        : id(id1), amount(amount1), name(name1), receiver_number(receiver_number1), next(next1) {}
};

class LLL {
private:
    transaction* head;
    int number_of_transactions;

public:
    LLL(int number_of_transactions1, transaction* head1 = nullptr)
        : number_of_transactions(number_of_transactions1), head(head1) {}

    void addRandomTransactions(int count) {
        string names[] = { "pizza", "book", "food", "snak", "ali" };
        srand(time(0));
        for (int i = 0; i < count; ++i) {
            int id = rand() % 9000 + 1000;
            int amount = rand() % 1000 + 100;
            int receiver_number = rand() % 900000000 + 100000000;
            string name = names[rand() % 5];
            transaction* newTransaction = new transaction(id, amount, name, receiver_number);
            if (head == nullptr) {
                head = newTransaction;
            }
            else {
                transaction* temp = head;
                while (temp->next != nullptr) {
                    temp = temp->next;
                }
                temp->next = newTransaction;
            }
        }
    }

    void addtransaction() {
        int id, amount, receiver_number;
        string name;
        cout << "Enter transaction number: ";
        cin >> id;
        cout << "Enter transaction amount: ";
        cin >> amount;
        cout << "Enter transaction name: ";
        cin >> name;
        cout << "Enter receiver number: ";
        cin >> receiver_number;
        vector<int> tnarr;
        transaction* temp = head;
        while (temp != nullptr) {
            tnarr.push_back(temp->id);
            temp = temp->next;
        }
    
        if(id < 0 || id > 9999 || find(tnarr.begin(), tnarr.end(), id) != tnarr.end()) {
            cout << "Invalid ID or ID already exists. Please try again." << endl;
            return;
        }
        else{
            transaction* newTransaction = new transaction(id, amount, name, receiver_number);
        if (head == nullptr) {
            head = newTransaction;
        }
        else {
            transaction* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newTransaction;
        }
}
        
    }

    void displaytransactions() {
        transaction* temp = head;
        if (temp == nullptr) {
            cout << "\n📭 No transactions to display.\n";
            return;
        }
        while (temp != nullptr) {
            cout << "_____________________________" << endl;
            cout << "| ID              : " << temp->id << endl;
            cout << "| Amount          : $" << temp->amount << endl;
            cout << "| Name            : " << temp->name << endl;
            cout << "| Receiver Number : " << temp->receiver_number << endl;
            cout << "_____________________________" << endl;
            cout << endl;
            temp = temp->next;
        }
    }

    void sort_Transactions_byID() {
        if (head == nullptr) {
            cout << "no transactions there to sort!" << endl;
            return;
        }
        bool swapMade;
        do {
            swapMade = false;
            transaction* c = head;
            transaction* p = nullptr;
            while (c != nullptr && c->next != nullptr) {
                transaction* n = c->next;
                if (c->id > n->id) {
                    c->next = n->next;
                    n->next = c;
                    if (p == nullptr) {
                        head = n;
                    }
                    else {
                        p->next = n;
                    }
                    p = n;
                    swapMade = true;
                }
                else {
                    p = c;
                    c = c->next;
                }
            }
        } while (swapMade);
    }

    void sortbyamount() {
        if (head == nullptr) {
            cout << "No transactions to sort" << endl;
            return;
        }
        bool swapMade;
        do {
            swapMade = false;
            transaction* c = head;
            transaction* p = nullptr;
            while (c != nullptr && c->next != nullptr) {
                transaction* n = c->next;
                if (c->amount > n->amount) {
                    c->next = n->next;
                    n->next = c;
                    if (p == nullptr) {
                        head = n;
                    }
                    else {
                        p->next = n;
                    }
                    p = n;
                    swapMade = true;
                }
                else {
                    p = c;
                    c = c->next;
                }
            }
        } while (swapMade);
    }

    void search_byid(int id) {
        transaction* temp = head;
        bool found = false;
        while (temp != nullptr) {
            if (temp->id == id) {
                found = true;
                cout << "_____________________________" << endl;
                cout << "| ID              : " << temp->id << endl;
                cout << "| Amount          : $" << temp->amount << endl;
                cout << "| Name            : " << temp->name << endl;
                cout << "| Receiver Number : " << temp->receiver_number << endl;
                cout << "_____________________________" << endl;
                cout << endl;
            }
            temp = temp->next;
        }
        if (!found) {
            cout << "No transaction found with ID: " << id << endl;
        }
    }

    void search_byiamount(int amount) {
        transaction* temp = head;
        bool found = false;
        while (temp != nullptr) {
            if (temp->amount == amount) {
                found = true;
                cout << "_____________________________" << endl;
                cout << "| ID              : " << temp->id << endl;
                cout << "| Amount          : $" << temp->amount << endl;
                cout << "| Name            : " << temp->name << endl;
                cout << "| Receiver Number : " << temp->receiver_number << endl;
                cout << "_____________________________" << endl;
                cout << endl;
            }
            temp = temp->next;
        }
        if (!found) {
            cout << "No transaction found with amount: " << amount << endl;
        }
    }

    void search_byname(string n) {
        transaction* temp = head;
        bool found = false;
        while (temp != nullptr) {
            if (temp->name == n) {
                found = true;
                cout << "_____________________________" << endl;
                cout << "| ID              : " << temp->id << endl;
                cout << "| Amount          : $" << temp->amount << endl;
                cout << "| Name            : " << temp->name << endl;
                cout << "| Receiver Number : " << temp->receiver_number << endl;
                cout << "_____________________________" << endl;
                cout << endl;
            }
            temp = temp->next;
        }
        if (!found) {
            cout << "No transaction found with name: " << n << endl;
        }
    }
};

int main() {
    int number_of_transactions;
    cout << "Enter number of transactions: ";
    cin >> number_of_transactions;

    LLL list(number_of_transactions);
    list.addRandomTransactions(3);

    for (int i = 0; i < number_of_transactions; i++) {
        list.addtransaction();
    }

    list.displaytransactions();

    while (true) {
        int choice;
        cout << "What operation do you want to perform?\n\n     < 1.SORT >       < 2.SEARCH >" << endl;
        cout << "Enter your choice (1 or 2): ";
        cin >> choice;
        if (cin.fail() || (choice != 1 && choice != 2)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter 1 or 2 only." << endl;
            continue;
        }

        if (choice == 1) {
            while (true) {
                int choice1;
                cout << "Sorting the transaction cards by ...\n\n     < 1.Id >      < 2.Amount >      " << endl;
                cout << "Enter your choice ( 1  or  2 ): ";
                cin >> choice1;
                if (cin.fail() || (choice1 < 1 || choice1 > 2)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter 1 or 2" << endl;
                    continue;
                }
                if (choice1 == 1) {
                    cout << "Sorting transactions by ID..." << endl;
                    list.sort_Transactions_byID();
                    list.displaytransactions();
                    break;
                }
                else if (choice1 == 2) {
                    cout << "Sorting transactions by Amount..." << endl;
                    list.sortbyamount();
                    list.displaytransactions();
                    break;
                }
            }

        }
        else if (choice == 2) {
            while (true) {
                int choice2;
                cout << "searching the transaction cards by ...\n\n     < 1.Id >      < 2.Amount >      < 3.name >" << endl;
                cout << "Enter your choice (1 or 2 or 3): ";
                cin >> choice2;
                if (cin.fail() || (choice2 < 1 || choice2 > 3)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter (1 or 2 or 3)" << endl;
                    continue;
                }
                if (choice2 == 1) {
                    cout << "Searching transactions by ID..." << endl;
                    int id;
                    cout << "Enter the ID to search: ";
                    cin >> id;
                    list.search_byid(id);
                    break;
                }
                else if (choice2 == 2) {
                    cout << "Searching transactions by Amount..." << endl;
                    int amount;
                    cout << "Enter the amount to search: ";
                    cin >> amount;
                    list.search_byiamount(amount);
                    break;
                }
                else if (choice2 == 3) {
                    string name;
                    cout << "Searching transactions by Name..." << endl;
                    cout << "Enter the name to search: ";
                    cin >> name;
                    list.search_byname(name);
                    break;
                }
            }
        }
    }

    system("pause");
    return 0;
}
