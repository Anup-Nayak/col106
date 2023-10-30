std::string str2 = id.substr(16,6); 
    int a=stoi(str2);
    int hash_value=a%100003;
    return hash_value;