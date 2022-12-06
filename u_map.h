#include <utility>
#include <vector>
#include <string>
#include <list>
#include <fstream>
#include <sstream>
#include <iostream>
#include <math.h>
#include <iterator>
using namespace std;

class u_map
{
    list<pair<pair<string, string>, vector<double>>> *table; // Array of lists
    float max_load;
    int num_elements;
    int size_table;

    public:
    u_map();
    ~u_map();
    int hash(string, string);
    void insert(pair<string, string>, vector<double>);
    void rehash();
    void addData();
    vector<pair<int, string>> avgTemp(int, int);
    vector<pair<int, string>> minTemp(int);
    vector<pair<int, string>> maxTemp(int);
    vector<pair<int, string>> windSpd(int, int);
    vector<pair<int, string>> precip(int, int);
};