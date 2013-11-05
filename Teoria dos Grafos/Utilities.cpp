#include "Utilities.h"

std::string returnVectorSaveInfo(const std::vector<unsigned long long>& v) {
    std::string s;
    char tmp[100];
    for (unsigned long long i = 0; i < v.size(); ++i) {
        sprintf(tmp, "%lld", v[i]);
        s += tmp;
        if (i != (v.size() - 1))
            s += " ";
    }
    return s;
}

bool areFilesEqual(const char *filename1, const char *filename2) {
    std::ifstream is1;
    std::ifstream is2;
    is1.open(filename1);
    is2.open(filename2);
    std::string line1, line2;

    while (getline(is1, line1) && getline(is2, line2)) {
        if (line1 != line2)
            return false;
    }
    return true;
}