#include <iostream>
#include <fstream>
using namespace std;
/*
This method was from our first assignment about the union of two lists, with some minor tweaks. The purpose of this method
is to merge a given subset of an array
*/
void merge (long* data, long* sortedData, int left, int right, int middle) {
    int index = 0, start = left, mid = middle + 1, k = 0;
    
    while (start <= middle && mid <= right) { // while either subset isn't at the end
        if (data[start] < data[mid]) { // compare and add the one that is smaller
            sortedData[index++] = data[start++];
        } else {
            sortedData[index++] = data[mid++];
        }
    }

    while (start <= middle) { // put em in if theres any left
        sortedData[index++] = data[start++];
    }

    while (mid <= right) { // put em in if theres any left
        sortedData[index++] = data[mid++];
    }

    for (int j = left; j <= right; j++) { // copy all old values back
        data[j] = sortedData[k++];
    }
}

void mergesort (long* data, int size) {
    long* temp = new long[size]; // second array for copying items

    for (int step = 1; step <= size; step *= 2) {
        for (int start = 0; start < size; start += 2*step) {

            // THESE FOUR LINES TOOK LONGER THAN EVERYTHING ELSE
            int left = start;
            int middle = start + step - 1; // left + step - 1
            int right = start + 2 * step -1; // left + 2 * step -1

            right = right > size ? size : right; // get the smallest of the two to ensure no out of bounds at the end of the array

            /*
             *The reason I approached it as such was to ensure that this was a bottom-up merge. This will break down the array into subgroups first,
             *then it will merge them. After merging all of the subgroups it will merge all groups again with a larger subset size and etc.
             */
            merge(data, temp, left, right, middle); // merge

        }
    }
    
    delete [] temp; // get rid of temp data
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
    long* data = new long[1000000];

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

    // merge sort all the stuff
    mergesort(data, size);

    // creat file output stream
    ofstream out(fileOut);

    // copy each value as individual line
    for (c = 0; c < size; c++) { out<<data[c]<<endl; }

    // close ouput stream
    out.close();

    // get rid of heap data
    delete [] data;

    cout<<"Success!"<<endl;
}