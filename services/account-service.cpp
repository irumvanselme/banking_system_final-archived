//
// Created by anselme on 23/06/22.
//

#include "../utils/Service.cpp"

class AccountService : Service {

public:
    explicit AccountService() : Service("accounts") {}

    void store() override {
        fstream outputStream;

        outputStream.open(get_data_store_path(), ios::out | ios::app);

        int i, roll, phy, chem, math, bio;
        string name;
        cin >> roll >> name >> math >> phy >> chem >> bio;

        cout << "Enter the data of student :" << endl;

        outputStream << roll << ", " << name << ", " << math << ", " << phy << ", " << chem << ", " << bio << "\n";
    }

    void read() override {
        fstream fin;
        fin.open(get_data_store_path(), ios::in);

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

            for (int i: vect)
                std::cout << i << std::endl;
        }

        cout << "The sum is " << sum << endl;
    }
};
