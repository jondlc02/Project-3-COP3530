#include <map>
#include <vector>
#include <utility>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

class weatherMap
{
    map<pair<string, string>, vector<double>> data;

    public:
    void addData();
    map<string, pair<unsigned int, double>> avgTemp(int low, int high);
    map<string, pair<unsigned int, double>> minTemp(int min);
    map<string, pair<unsigned int, double>> maxTemp(int max);
    map<string, pair<unsigned int, double>> windSpd(int low, int high);
    map<string, pair<unsigned int, double>> precipitation(int low, int high);

};