#ifndef PRINT_UTIL_H
#define PRINT_UTIL_H

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