string print_vector_int(vector<int> vec);


string print_vector_int(vector<int> vec)
{
    string result = "";
    result += "[ ";
    for(int i = 0; i < vec.size(); i++)
        result += to_string(vec[i])+ " ";
    result += ']';
    return result;
}