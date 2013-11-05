#ifndef UTILITIES_H
#define	UTILITIES_H

#include <algorithm>    // std::reverse
#include <cstring>
#include <deque>
#include <exception>    // std::exception
#include <iomanip>
#include <iostream>     // std::cout, std::endl
#include <fstream>
#include <functional>   // std::greater
#include <limits>       // std::numeric_limits
#include <queue>
#include <stdexcept>    // custom exceptions
#include <stack>
#include <string>
#include <utility>      // std::pair
#include <vector>

const double INF = std::numeric_limits<double>::max();

std::string returnVectorSaveInfo(const std::vector<unsigned long long>& v);
bool areFilesEqual(const char *filename1, const char *filename2);

template <class T> bool compareVectors(const std::vector<T>& v1, const std::vector<T>& v2) {
    // from <algorithms>
    // std::equal(v.begin(), v.begin() + v.size(), v2.begin());

    if (v1.size() != v2.size())
        return false;
    for (unsigned long long i = 0; i < v1.size(); ++i)
        if (v1[i] != v2[i])
            return false;
    return true;
}

template<class T> std::string printVector(const std::vector<T>& v) {
    std::string s;
    s += ": ";
    char tmp[100];
    for (unsigned long long i = 0; i < v.size(); ++i) {
        sprintf(tmp, "%lld", v[i]);
        s += tmp;
        s += " ";
    }
    s += "\n";
    return s;
}

#endif	/* UTILITIES_H */
