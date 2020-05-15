/**
 * Name: John Runyard
 * IT 279 - 002
 * Program 5 - Bin Packing - Redo
 * 
 * This is my resubmission for Program 5. This is an implementation of several different bin packing algorithms. It will display their average bins required and how frequently
 * they were the fastest strategy. A more detailed report of the application is generated at rawdata.txt.
 * 
 */
#include <bits/stdc++.h>
using namespace std;

/**
 * Prints formatted content of 'bins', which are represented via a vector
 */
void printBins(const vector<int>& bins, ofstream& raw) {
    raw << "Bin Contents (bin #, value): " << endl;
    for (int i = 0; i < bins.size(); i++) {
        raw << "(" << i << ", " << bins[i] <<") ";
        if (i % 10 == 0 && i)
            raw << endl;
    }
    raw << endl << endl;
}

/**
 * Method that packs bins using the next fit strategy. Will return the total number of bins that it created.
 */
int nextFit(const vector<int>& data, ofstream& raw, int binsize) {
    vector<int> bins {0};
    int it = 0;

    raw << "Next fit strategy" << endl
        << "Placing data in bins... (data, bin)" << endl;

    for (int a = 0; a < data.size(); a++) {
        int i = data[a];
        raw << " (" << i << ", ";
        if (bins[it] + i <= binsize) {
            bins[it] += i;
            raw << it << "),";
        } else {
            bins.push_back(i);
            raw << ++it << "),";
        }
        if (a % 10 == 0 && a)
            raw << endl;
    }

    raw << endl << "# of Bins: " << bins.size() << endl << endl;
    printBins(bins,raw);
    return bins.size();
}

/**
 * Bin packing method that uses the first fit strategy. Will return the total number of bins that it created.
 */
int firstFit(const vector<int>& data, ofstream& raw, int binsize) {
    vector<int> bins {0};
    
    raw << "First fit strategy" << endl
        << "Placing data in bins... (data, bin)" << endl;
    
    for (int a = 0; a < data.size(); a++) {
        int i = data[a];
        raw << " (" << i << ", ";
        bool fit = false;
        for (int it = 0; it < bins.size(); it++) {
            if (bins[it] + i <= binsize) {
                bins[it] += i;
                raw << it << "),";
                fit = true;
                break;
            }
        }
        if (!fit) {
            bins.push_back(i);
            raw << bins.size()-1 << "),";
        }
        if (a % 10 == 0 && a)
            raw << endl;
    }

    raw << endl << "# of Bins: " << bins.size() << endl << endl;
    printBins(bins,raw);
    return bins.size();
}

/**
 * Bin packing method that uses the best fit strategy. Will return the total number of bins that it created.
 */
int bestFit(const vector<int>& data, ofstream& raw, int binsize) {
    vector<int> bins;

    raw << "Best fit strategy" << endl
        << "Placing data in bins... (data, bin)" << endl;
    
    for (int a = 0; a < data.size(); a++) {
        int i = data[a];
        raw << " (" << i << ", ";
        int least = binsize, index = -1;

        for (int it = 0; it < bins.size(); it++) {
            if (bins[it] + i <= binsize && binsize-bins[it] < least) {
                index = it;
                least = binsize-bins[it];
            }
        }

        if (bins.empty()) {
            raw << bins.size() << ")";
            bins.push_back(i);
            index = 0;
            least = binsize - i;
        } else if (index < 0) {
            raw << bins.size() << ")";
            bins.push_back(i);
        } else {
            bins[index] += i;
            raw << index << ")";
        }

        if (a % 10 == 0 && a)
            raw << endl;
    }
    raw << endl << "# of Bins: " << bins.size() << endl << endl;

    printBins(bins,raw);
    return bins.size();
}

/**
 * Helper method that will help determine the index of the winning bin packing strategy. New lowest amount of bins is also updated here.
 */
void determineWinner(const vector<int>& results, ofstream& raw, vector<int>& wins, vector<string> types, int max) {
    int amount = max;
    vector<int> q;

    raw << "Results: ";
    for (int t: results)
        raw << t << ", ";
    raw << endl;

    for (int i = 0; i < results.size(); i++) {
        if (amount == results[i]) {
            q.push_back(i);
        } else if (amount > results[i]) {
            q.clear();
            q.push_back(i);
            amount = results[i];
        }
    }
    raw << endl << "Winners: ";
    for (int i: q) {
        wins[i]++;
        raw << types[i] << ", ";
    }
    raw << endl;
}

/**
 * This will load a reference to a vector up with random numbers given a set length and size. Also will print out each value generated with formatting.
 */
void loadRandomNumbers (vector<int>& data, int length, int size, ofstream& raw) {
    raw << "Initial data: " << endl;
    for (int i = 0; i < length; i++) {
        int r = rand() % size + 1;
        if (i != 0 && i % 10 == 0)
            raw << endl;
        raw << r << ", ";
        data.push_back(r);
    }
    raw << endl;
}

main() {
    // Setting random seed so we can get different results everytime.
    srand(time(0)); 
    // Number of trials to do
    const int TRIALS = 10; 
    // Max bin size
    const int BINSIZE = 100; 
    // Length of data set to bin
    const int DATASIZE = 100;
    // Different strategy names to display results
    const vector<string> TYPES {"Next Fit", "First Fit", "Best Fit", "Offline First Fit", "Offline Best Fit"}; 
    // Starting vector with 5 places to represent different averages
    vector<int> avg {0,0,0,0,0}; 
    // Starting vector with 5 places to represent different wins
    vector<int> wins = avg; 
    // output files
    ofstream summary("results.txt"), rawdata("rawdata.txt"); 

    // Running trials
    for (int zzz = 0; zzz < TRIALS; zzz++) {
        int nextfit, onlinefit, onlinebest, offlinefirst, offlinebest;
        vector<int> data;

        rawdata << "Trial " << zzz+1 << ":\n" << endl;

        // Creating the data to be packed
        loadRandomNumbers(data, DATASIZE, BINSIZE, rawdata);

        rawdata << endl << "\t\tONLINE BIN METHODS:\n" << endl;

        // record # of bins used for each strat and add to average
        avg[0] += nextfit = nextFit(data, rawdata, BINSIZE);
        avg[1] += onlinefit = firstFit(data, rawdata, BINSIZE);
        avg[2] += onlinebest = bestFit(data, rawdata, BINSIZE);

        // Sort elements into reverse order. This makes the following methods offline since we altered them before sending them to the bins.
        sort (data.begin(), data.end(), greater<int>()); 
        
        rawdata << "\t\tOFFLINE BIN METHODS:\n" << endl;

        // record # of bins used for each strat and add to average
        avg[3] += offlinefirst = firstFit(data, rawdata, BINSIZE);
        avg[4] += offlinebest = bestFit(data, rawdata, BINSIZE);

        // create vector of all winnings
        vector<int> results {nextfit, onlinefit, onlinebest, offlinefirst, offlinebest};

        // Decides who won, will print out results to rawdata.txt
        determineWinner(results, rawdata, wins, TYPES, DATASIZE);

        rawdata << endl << "=======================================" << endl << endl;
    }

    // Displaying results
    for (int zzz = 0; zzz < 5; zzz++) {
        cout    << TYPES[zzz] << ": Wins - " << wins[zzz] << " Avg bins: " << avg[zzz]/TRIALS << endl;
        summary << TYPES[zzz] << ": Wins - " << wins[zzz] << " Avg bins: " << avg[zzz]/TRIALS << endl;
        rawdata << TYPES[zzz] << ": Wins - " << wins[zzz] << " Avg bins: " << avg[zzz]/TRIALS << endl;
    }
    
    // Closing files
    summary.close(); rawdata.close();

    // Done
}