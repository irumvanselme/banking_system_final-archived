#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

void create() {
    fstream fout;
    fout.open("../store/reportcard.csv", ios::out | ios::app);

    cout << "Enter the details of 5 students:" << " roll name maths phy chem bio" << endl;

    int i, roll, phy, chem, math, bio;
    string name;

    // Read the input
    for (i = 0; i < 5; i++) {

        cin >> roll >> name >> math >> phy >> chem >> bio;

        cout << "Enter the data of student " << i + 1 << ":" << endl;
        // Insert the data to file
        fout << roll << ", " << name << ", " << math << ", " << phy << ", " << chem << ", " << bio << "\n";
    }
}

void read() {
    fstream fin;
    fin.open("../store/reportcard.csv", ios::in);

    string line;

    int sum = 0;


    while (getline(fin, line)) {

        std::stringstream ss(line);
        vector<int> vect;

        for (int i; ss >> i;) {
            vect.push_back(i);
            sum += i;
            if (ss.peek() == ',')
                ss.ignore();
        }

        for (std::size_t i = 0; i < vect.size(); i++)
            std::cout << vect[i] << std::endl;
    }

    cout << "The sum is " << sum << endl;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
//    create();

    read();
    return 0;
}
