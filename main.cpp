/*
█▀▄▀█ █▀▀█ █▀▀▄ █▀▀ 　 █▀▀▄ █░░█ 
█░▀░█ █▄▄█ █░░█ █▀▀ 　 █▀▀▄ █▄▄█ 
▀░░░▀ ▀░░▀ ▀▀▀░ ▀▀▀ 　 ▀▀▀░ ▄▄▄█
█▄─█▀▀▀█─▄█─█─█▄─▄█─▄─▄─█▄─▄▄─█░█░██─▄▄▄▄█▄─▄███▄─▄▄─█
██─█─█─█─██─▄─██─████─████─▄█▀█▄▄░██─██▄─██─██▀██─▄█▀█
▀▀▄▄▄▀▄▄▄▀▀▄▀▄▀▄▄▄▀▀▄▄▄▀▀▄▄▄▄▄▀▀▄▄▄▀▄▄▄▄▄▀▄▄▄▄▄▀▄▄▄▄▄▀
*/

#include <bits/stdc++.h>
using namespace std;

    struct Node {
        string item_name;
        float item_price;
        Node* next;
    };

    Node* head = NULL;

    Node* createNode(const string& name, float price) {
        Node* node1 = new Node();
        node1->item_name = name;
        node1->item_price = price;
        node1->next = NULL;
        return node1;
    }

    void sortList() {
        if (head == NULL || head->next == NULL) {
            return; 
        }

        Node* current = head;
    
        while (current != NULL) {
            Node* minNode = current;
            Node* nextNode = current->next;
            while (nextNode != NULL) {
                if (nextNode->item_price < minNode->item_price) {
                    minNode = nextNode;
                }
                nextNode = nextNode->next;
            }            
            if (minNode != current) {
                swap(current->item_name, minNode->item_name);
                swap(current->item_price, minNode->item_price);
            }            
            current = current->next;
        }
}


    void saveInventory() {
        ofstream file("inventory.data", ios::trunc);
        Node* temp = head;
        while (temp != NULL) {
            file << temp->item_name << " " << temp->item_price << "\n";
            temp = temp->next;
        }
        file.close();
    }

    void InsertValue(const string& name, float price) {
        Node* newnode = createNode(name, price);
        if (head == NULL) {
            head = newnode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newnode;
        }
        saveInventory();
        sortList();
    }

    void showList() {
        int count = 1;
        Node* temp1 = head;
        cout << "\t\tAvailable items\t\t\n";
        while (temp1 != NULL) {
            cout << "\t\tItem " << count <<" "<< temp1->item_name << ", Price: Tk." << temp1->item_price << endl;
            temp1 = temp1->next;
            count++;
        }
        cout << endl;
    }


    void loadInventory() {
        ifstream file("inventory.data");
        if (!file) return;
        string name;
        float price;
        while (file >> name >> price) {
            InsertValue(name, price);
        }
        file.close();
    }

    class sortify {
    public:
        string user_name;
        int user_choice, number_of_items;

        sortify() {
            cout << "\t\t|Sortify Inventory Management|\t\t\n";
            loadInventory();
            loginMenu();
        }

        void loginMenu() {
            int choice;
            cout << "\t\t1. Register\n";
            cout << "\t\t2. Login\n";
            cout << "\t\tEnter your choice: ";
            cin >> choice;

            switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            default:
                cout << "\t\tInvalid choice. Try again.\n";
                loginMenu();
                break;
            }
        }

        void registerUser() {
            system("cls");
            string username, password;
            cout << "\t\tEnter a username: ";
            cin >> username;
            cout << "\t\tEnter a password: ";
            cin >> password;

            
            ofstream file("users.data", ios::app);
            if (file) {
                file << username << " " << password << "\n";
                file.close();
                cout << "\t\tRegistration successful!\n";
            } else {
                cout << "\t\tError: Unable to save user information.\n";
            }
            loginMenu();
    }

        void loginUser() {
            system("cls");
            string username, password, file_username, file_password;
            cout << "\t\tEnter your username: ";
            cin >> username;
            cout << "\t\tEnter your password: ";
            cin >> password;

            
            ifstream file("users.data");
            bool loginSuccess = false;
            if (file) {
                while (file >> file_username >> file_password) {
                    if (username == file_username && password == file_password) {
                        loginSuccess = true;
                        break;
                    }
                }
                file.close();
            } else {
                cout << "\t\tError: Unable to access user information.\n";
            }

            if (loginSuccess) {
                user_name = username;
                cout << "\t\tLogin successful!\n";
                home();
            } else {
                cout << "\t\tInvalid username or password. Try again.\n";
                loginMenu();
            }
        }


        void home() {
            system("cls");
            cout << "\t\tWelcome " << user_name << "\t\t\n\n\n";
            if (head == NULL) {
                cout << "\t\tNo items\t\t\n\n\n";
            } else {
                showList();
            }
            cout << "\t\t0. Exit\n";
            cout << "\t\t1. Add Item\n";
            cout << "\t\t2. Update Item\n";
            cout << "\t\t3. Search Item\n";
            cout << "\t\t4. Delete Item\n";
            cout << "\t\tEnter your choice: ";
            choice();
        }

        void choice() {
            cin >> user_choice;

            switch (user_choice) {
            case 0:
                saveInventory();
                break;

            case 1: {
                cout << "\t\tHow many items do you want to add?: \t\t\n";
                cin >> number_of_items;
                cout << "\t\tEnter the items: \t\t\n";
                for (int i = 0; i < number_of_items; i++) {
                    string itemName;
                    float itemPrice;
                    cout << i + 1 << ": ";
                    cin >> itemName >> itemPrice;
                    InsertValue(itemName, itemPrice);
                }
                showList();
                home();
                break;
            }

            default:
                cout << "\t\tInvalid Choice!\t\t\n";
                home();
            }
        }
    };

    int main() {
        sortify app;
        return 0;
    }