#include "headers.h"

class Service {
private:
    std::string filename;

protected:
    string get_data_store_path() {
        return "../store/" + filename + ".csv";
    }

    string get_temp_data_store_path() {
        return "../store/temp__" + filename + ".csv";
    }

public:
    explicit Service(std::string filename) : filename(std::move(filename)) {}
};