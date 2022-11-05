#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <cstring>
#include <vector>

void read(std::string path);
bool reg(std::string line);
void output(std::vector<std::string> arr);
std::string tok(std::string line);

int main()
{
    std::string path;
    std::cout << "Enter path to HTML file: ";
    std::cin >> path;
    read(path);
}

void read(std::string path) {
    std::string line;
    std::vector<std::string> arr;
    std::ifstream in(path);
    if (in.is_open())
    {
        while (std::getline(in, line))
        {
            if (reg(line)) {
                arr.push_back(tok(line));
            }
        }
    }
    in.close();
    output(arr);
}

bool reg(std::string line) {
    bool flag = false;
    const std::regex r(R"((<a)(?: |.+)(href="/))");
    if (std::regex_search(line, r)) {
        flag = true;
    }
    return flag;
}

void output(std::vector<std::string> arr) {
    std::string path = "result.txt";
    std::ofstream out(path);
    if (out) {
        for (std::string i : arr)
        {
            out << i << std::endl;
        }
    }
    out.close();
}

std::string tok(std::string line) {

    std::string result = "apple.com";
    std::string delimiter_1 = "href";
    std::string delimiter_2 = " ";
    std::string delimiter_3 = "/";
    std::string delimiter_4 = "\"";
    std::string token = line.substr(line.find(delimiter_1), line.size());
    token = token.substr(0, token.find(delimiter_2));
    token = token.substr(token.find(delimiter_3), token.size());
    token = token.substr(0, token.find(delimiter_4));
    result += token;
    return result;
}
