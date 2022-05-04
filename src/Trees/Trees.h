#ifndef TREES_H
#define TREES_H

#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<unordered_map>
#include<climits>

/* Overloading cout to print vector of any type */
template <typename T>
std::ostream & operator << (std::ostream & os, const std::vector<T> & vec)
{
    os << "[ ";
    for(auto elem : vec)
    {
        os << elem << " ";
    }
    os << "]\n";
    return os;
}
#endif