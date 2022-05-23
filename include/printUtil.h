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

/* Overloading cout to print vector of any type */
template <typename T>
std::ostream & operator << (std::ostream & os, const std::vector<vector<T>> & vec)
{
    for(auto row : vec)
    {
        os << "[ ";
        for(auto elem : row)
        {
            os << elem << " ";
        }
        os << "]\n";
    }
    return os;
}

#endif