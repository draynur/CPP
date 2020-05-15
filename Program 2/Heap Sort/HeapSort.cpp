#include <iostream>
#include <fstream>
using namespace std;

void percolateDown (long* data, long index, long size) {
    long temp, swap;

    if (index * 2 <= size) { // if there are any children 
        if (index * 2 + 1 <= size) { // two children
            if (data[index] < data[index*2] || data[index] < data[index*2+1]) { // one of the children is larger

                temp = data[index];

                swap = data[index*2] < data[index*2+1] ? index*2+1 : index*2; // decides which one is larger, uses that index to swap

                data[index] = data[swap];
                data[swap] = temp;

                percolateDown(data, swap, size);

            } // if neither child is larger than don't do anything and exit
        } else { // one child
            if (data[index] < data[index*2]) { // child is greater

                temp = data[index];
                data[index] = data[index*2];
                data[index*2] = temp;

                percolateDown(data, index*2, size);

            } // if the child is smaller than don't do anything and exit
        }
    }
}

void buildHeap (long* data, long size) {

    long half = size / 2; // start from halfway point

    while (half >= 1) { percolateDown(data, half--, size / 2); }

}

void heapsort (long* data, long size) {
    // Build heap
    buildHeap(data, size);
    
    while (size > 1) {
        long temp = data[1];

        data[1] = data[size];

        data[size] = temp;

        percolateDown(data, 1, --size);
    }

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
    long* data = new long[10000001];

    // create file input strem
    ifstream infile(fileIn);

    long c = 1, temp;

    // copy each line into array
    while (infile >> temp) { data[c++] = temp; }

    // record size
    long size = c;
    // set size

    cout << "Size of array to be sorted: " << size - 1 << endl;

    // close input stream
    infile.close();

    // heap sort all the stuff
    heapsort(data, size);

    // creat file output stream
    ofstream out(fileOut);

    // copy each value as individual line
    for (c = 1; c < size; c++) { out<<data[c]<<endl; }

    // close ouput stream
    out.close();

    // get rid of heap data
    delete [] data;

    cout<<"Success!"<<endl;
}