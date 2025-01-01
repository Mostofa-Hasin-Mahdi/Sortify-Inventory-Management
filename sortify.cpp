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


struct Node{
    string item_name;
    float  item_price;
    Node* next;
};

Node* head = NULL;

Node* createNode(const string& name, float price){
    Node* node1 = new Node();
    node1 -> item_name = name;
    node1 -> item_price = price;
    node1 -> next = NULL;
    return node1;
}

void InsertValue(const string& name, float price){
    Node* newnode = createNode(name, price);
    if(head == NULL){
        head = newnode;
    }
    else{
        Node* temp = head;
        while(temp -> next != NULL){
            temp = temp -> next;
        }
        temp -> next = newnode;
    }
}

void showList(){
    Node* temp1 = head;
    cout<<"\t\tAvailable items\t\t\n";
    while(temp1 != NULL){
        cout<<"\t\tItem: "<< temp1 -> item_name << ", Price: Tk."<< temp1 -> item_price<<endl;
        temp1 = temp1 -> next;
    }
    cout<<endl;
}

class sortify{

    public:

    string user_name;
    int user_choice, number_of_items;

    
    sortify(){
        cout<<"\t\t|Sortify Inventory Management|\t\t\n";
        cout<<"\t\t  ****Enter company name:****\n";
        get_name();
        home();

    }

    void get_name(){
        cin>>user_name;
    }

    void home(){
        cout<<"\t\tWelcome "<<user_name<<"\t\t\n";
        if(head == NULL){
            cout<<"\t\tNo items\t\t\n";
            cout << "0. Exit\n";
            cout << "1. Add Item\n";
            cout << "2. Update Item\n";
            cout << "3. Search Item\n";
            cout << "4. Delete Item\n";
            cout << "Enter your choice: ";
            choice();
        }
        else{
            cout<<"\t\tAvailable items\t\t\n";
            showList();
            cout << "0. Exit\n";
            cout << "1. Add Item\n";
            cout << "2. Update Item\n";
            cout << "3. Search Item\n";
            cout << "4. Delete Item\n";
            cout << "Enter your choice: ";
            choice();
        }
    }

    void choice(){

        cin>>user_choice;

        switch(user_choice){

            case 0:
                break;
            
            case 1:
                cout<<"\t\tHow many items do you want to add?: \t\t\n";
                cin>>number_of_items;
                cout<<"\t\tEnter the items: \t\t\n";
                for(int i = 0; i < number_of_items; i++){
                    string itemName;
                    float itemPrice;
                    cout<< i+1 <<": ";
                    cin>> itemName >> itemPrice;
                    InsertValue(itemName, itemPrice);
                }
                showList();
                break;

            default:
                cout<<"\t\tInvalid Choice!\t\t\n";

        }
    }

    void reshow(){
        char answer;
        cout<<"\t\tDo you want to make any further changes to the inventory?: (y/n)\t\t\n";
        cin>> answer;
        if(answer == 'y'){
            home();
        }
        else{
            
        }
    }

};

int main(){

    sortify ala;


    return 0;
}