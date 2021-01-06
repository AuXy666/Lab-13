#include<iostream>
using namespace std;
const int starting_Roll = 17551;
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




    int hash_Function(int key)
    {
        return (key - starting_Roll);
    }

    void displayHash()
    {
        for (int i = 0; i < BUCKET; i++)
        {
            cout << i << " |";
            table[i].display();
            cout << endl;
        }

    }
};



int main()
{


    int a[450] = { 0 };
    int counter = starting_Roll;
    counter++;
    for (int i = 0; i < 450; i++)
    {
        a[i] = counter;
        counter++;
    }
    counter--;

    int maxRoll = (a[0] - starting_Roll);
    for (int i = 0; i < 450; i++)
    {
        if (maxRoll < (a[i] - starting_Roll))
        {
            maxRoll = (a[i] - starting_Roll);
        }
    }


    Hash h(maxRoll);
    for (int i = 0; i < 450; i++)
        h.insert(a[i]);





    h.displayHash();

    return 0;
}
