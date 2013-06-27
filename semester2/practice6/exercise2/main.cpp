#include <cstdlib>
#include <vector>
#include <iostream>
#include <stdexcept>

using namespace std;

void populate1(vector<int>& elements) {
    elements.push_back(0);
    elements.push_back(0);
    elements.push_back(0);
    elements.push_back(0);
    elements.push_back(0);
    elements.push_back(0);
    elements.push_back(0);
    elements.push_back(0);
}

void populate2(vector<char>& elements) {
    elements.push_back('Z');
    elements.push_back('G');
    elements.push_back('B');
    elements.push_back('A');
    elements.push_back('D');
    elements.push_back('O');
}

template <class T> bool isSorted(vector<T>& elements) {
    for (int i = 0; i < elements.size() - 1; i++) {
        if (elements.at(i) > elements.at(i + 1)) return false;
    }
    return true;
}

template<class T> void printTestResult(vector<T>& tmp, string testType, string description) {
    bool successful = isSorted(tmp);
    if (!successful) cout << "\nFAILED test ";
    else cout << "\n succeeded test ";
    cout << testType << '(' << description << ')' << endl;

}

template<class T>void quicksort(vector<T> &elements, int uIndex, int oIndex) {
    if (elements.size() < 1) {
        throw runtime_error("Fehler, Kein ein Element im Vektor");
    }
    if (elements.size() == 1) {
        throw runtime_error("Fehler, Nur ein Element im Vektor");
    }

    int pivot = elements.at(oIndex);
    int i = uIndex, j = oIndex - 1;

    do {
        while (elements.at(i) <= pivot && i < oIndex) {
            i++;
        }
        while (elements.at(j) >= pivot && j > uIndex) {
            j--;
        }

        if (i < j) {
            swap(elements.at(i), elements.at(j));
        }
    } while (i < j);


    if (elements.at(i) > pivot) {
        swap(elements.at(i), elements.at(oIndex));
    }
    if (uIndex < j) quicksort(elements, uIndex, j);
    if (i < oIndex) quicksort(elements, i, oIndex);
}

int main(int argc, char** argv) {

    try {
        vector<int> iData;
        vector<char> cData;

        //populate1(iData);
        iData.push_back(5);
        iData.push_back(5);
        populate2(cData);

        quicksort(iData, 0, iData.size() - 1);
        for (int i = 0; i < iData.size(); i++) {
            cout << iData.at(i) << " ";
        }

        //    cout << endl;
        //    quicksort(cData, 0, cData.size() - 1);
        //    for (int i = 0; i < cData.size(); i++) {
        //        cout << cData.at(i) << " ";
        //    }



        printTestResult(iData, "checkTrue", "isSorted iData");

        vector<int> empty;
        quicksort(empty, 0, empty.size() -1);
        printTestResult(empty, "checkTrue", "isSorted empty");
        return 0;
    }    catch (runtime_error &e) {
        cerr << e.what();
        return -2;
    }    catch (...) {
        cerr << "Unbekannter Fehler!";
        return -1;
    }
}

