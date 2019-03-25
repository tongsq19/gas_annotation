//
// Created by shiqi on 2019/3/25.
//

#ifndef GAS_ANNOTATION_UILITY_H
#define GAS_ANNOTATION_UILITY_H

std::vector<std::string>
split(const std::string& str, char delimiter) {
    using namespace std;

    size_t start, index;
    start = index = 0;
    vector<string> result;

    while( index < str.size() ) {
        if(str[index] == delimiter) {
            result.push_back(str.substr(start, index-start));
            start = index + 1;
        } else if(str[index] == '\t' || str[index] == ' ') {
            start = index + 1;
        }
        index++;
    }

    if(index > start) {
        result.push_back(str.substr(start, index-start));
    }

    return result;
}

std::string trim1(const std::string& str) {
    size_t first = str.find_first_not_of('\t');
    if (std::string::npos == first) return str;

    size_t last = str.find_last_not_of('\t');
    return str.substr(first, (last - first + 1));
}

std::string trim(const std::string& str) {
    size_t first = str.find_first_not_of(' ');
    if (std::string::npos == first) return trim1(str);

    size_t last = str.find_last_not_of(' ');
    return trim1(str.substr(first, (last - first + 1)));
}

std::string join(std::vector<std::string> vec, std::string op) {
    std::string result;
    int i = 0;
    for (; i < vec.size()-1; ++i) {
        result.append(vec[i]);
        result.append(op);
    }
    result.append(vec[i]);
    return result;
}

#endif //GAS_ANNOTATION_UILITY_H
