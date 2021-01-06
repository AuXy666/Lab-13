#include<iostream>
#include <iomanip>
using namespace std;
const int starting_cnic[3] = { 38601, 7891234, 1 };
class node
{
public:
    int data;
    node* next;
    node()
    {
        data = 0;
        next = NULL;
    }
};

class linklist
{
public:
    node* head;
    linklist()
    {
        head = NULL;
    }

    void push(int key)
    {
        node* temp = new node;
        temp->data = key;
        temp->next = head;
        head = temp;
    }
    void search(int key)
    {
        node* temp = head;
        node* temp2 = head;
        while (temp != NULL)
        {
            if (temp->data == key)
            {

                if (head->next == NULL)
                {
                    head = NULL;
                    break;
                }

                else
                {
                    if (temp == head)
                    {
                        head = head->next;
                    }
                    else
                    {
                        while (temp2->next != temp)
                        {
                            temp2 = temp2->next;
                        }
                        temp2->next = temp->next;
                        delete temp;
                    }

                    break;

                }
            }
            temp = temp->next;
        }

    }
    void display()
    {

        if (head == NULL)
        {
            return;
        }
        node* temp = new node;
        temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

};


class Hash
{
    int BUCKET;
    linklist* table;
public:
    Hash(int V)
    {

        this->BUCKET = V;
        table = new linklist[BUCKET];

    }


    void insert(int x)
    {
        int index = hash_Function(x);
        table[index].push(x);
    }



    //7873683
    int hash_Function(int key)
    {
        return (key % 15);
    }

    void displayHash()
    {
        for (int i = 0; i < BUCKET; i++)
        {
            cout <<setw(2)<< i << " |";
            cout << "38601 ";
            table[i].display();
            cout << endl;
        }

    }
};



int main()
{
    int counter1 = 38601;
    int counter2= 7891234;
    int counter3 = 1;
    int cnic[15][3];
    for (int i = 0; i < 15; i++)
    {
        cnic[i][0] = counter1;
        cnic[i][1] = counter2;
        cnic[i][2] = counter3;
        counter2++;
        counter3++;
        if (counter3 > 9)
        {
            counter3 = 2;
        }
    }
   

    int key[3];
    key[0] = 38601;
    key[1] = 15;
    key[2] = 9;
   
    Hash h(key[1]);
    for (int i = 0; i < 15; i++)
    {
        h.insert(cnic[i][1]);
        h.insert(cnic[i][2]);
    }


    h.displayHash();

    return 0;
}

