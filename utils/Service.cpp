#include "headers.h"

class Service {
private:
    std::string filename;

protected:
    string get_data_store_path() {
        return "../store/" + filename + ".csv";
    }

public:
    explicit Service(std::string filename) : filename(std::move(filename)) {}

    virtual void store() = 0;

    virtual void read() = 0;
};