#include <iostream>
#include <fstream>
using namespace std;

struct Node {
    long value;
    Node* next;
};

void deleteList (Node* head) {
    Node* next;
    Node* current;

    current = head;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

}

Node* buildLinkedList (long* data, long size) {
    
    long i = 0;
    
    Node* head = new Node();
    Node* temp = new Node();

    head->value = data[i++];
    temp->value = data[i++];

    head->next = temp;

    while (i < size) {
        Node* next = new Node();
        temp->next = next;
        next->value = data[i++];
        temp = next;
    }

    return head;

}

void print (Node* head) {
    Node* a = head;
    cout<<"List: "<<endl;
    for (int i = 0; i < 10; i++) {
        cout<<a->value<<endl;
        a = a->next;
    }
    cout<<endl;
}

Node* insertionSort (Node* head) {
    Node* index = head;
    Node* prev = head;
    Node* current = head->next;

    Node* next;
    long count = 0;
    while (current != NULL) {
        count++;      
        // loop through each index to find place
        index = head;

        // cout<<"Cur: "<<current->value<<endl;

        // cout<<"Prev: "<<prev->value<<endl;
        // print(head);


        if (current->value < index->value) { // its smaller than the first number! how
            Node* temp = current->next;
            prev->next = temp;
            current->next = head;
            head = current;
            current = temp;
        } else {
            Node* tempNode = prev->next;
            while (index != current) {
                if (current->value < index->next->value) { // temp found its home
                    Node* temp = index->next;

                    Node* other = current;

                    prev->next = current->next;

                    tempNode = current;
                    
                    index->next = current;

                    current->next = temp;

                    current = other;

                    break;
                } else {
                    index = index->next;
                }
            }
            prev = tempNode;
            current = current->next;
        }

        if (count > 10) {break;}
    }

    return head;
}

main(int argc, char** argv)
{
    // make sure the amount of arguments is correct
    if (argc < 3) {
        cout << "Usage: " << argv[0] << " infile outfile\n";
        exit(1);
    }

    // get filenames
    char* fileIn = argv[1];
    char* fileOut = argv[2];

    // initialize new heap array
    long* data = new long[10000000];

    // create file input strem
    ifstream infile(fileIn);

    long c = 0, temp;

    // copy each line into array
    while (infile >> temp) { data[c++] = temp; }

    // record size
    long size = c;

    cout << "Size of array to be sorted: " << size << endl;

    // close input stream
    infile.close();
    
    Node* list = buildLinkedList(data, size);

    cout<<list<<endl;

    list = insertionSort(list);

    cout<<list<<endl;

    // create file output stream
    ofstream out(fileOut);

    Node* p = list;

    cout<<p->value<<endl;
    cout<<p->next<<endl;

    while (p != NULL) {
        out<<p->value<<endl;
        p = p->next;
    }

    // close ouput stream
    out.close();

    delete [] data;
    deleteList(list);

    cout<<"Success!"<<endl;
}