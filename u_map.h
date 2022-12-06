#include <utility>
#include <vector>
#include <string>
#include <list>
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
};