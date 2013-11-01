/* 
 * File:   Utilities.h
 * Author: thiago
 *
 * Created on October 31, 2013, 11:43 PM
 */

#ifndef UTILITIES_H
#define	UTILITIES_H

#include <string>
#include <vector>

// from <algorithms>
// std::equal(v.begin(), v.begin() + v.size(), v2.begin());
template <class T>
bool compareVectors(const std::vector<T>& v1, const std::vector<T>& v2) {
    if (v1.size() != v2.size())
        return false;
    for (int i = 0; i < (int) v1.size(); ++i)
        if (v1[i] != v2[i])
            return false;
    return true;
}

template<class T>
std::string printVector(const std::vector<T>& v) {
//    for (int i = 0; i < (int) v.size(); ++i)
//        std::cout << v[i] << " ";
//    std::cout << std::endl;
    std::string s;
    s += ": ";
    char tmp[100];
    for (int i = 0; i < (int) v.size(); ++i) {
        sprintf(tmp, "%lld", v[i]);
        s += tmp;
        s += " ";
    }
    s += "\n";
    return s;
}

#endif	/* UTILITIES_H */

