#include <map>
#include <vector>
#include <utility>
#include <string>
using namespace std;

class weatherMap
{
    map<pair<string, string>, vector<double>> data;



    public:
    map<string, pair<unsigned int, double>> avgTemp(int, int);
    map<string, pair<unsigned int, double>> minTemp(int);
    map<string, pair<unsigned int, double>> maxTemp(int);
    map<string, pair<unsigned int, double>> windSpd(int, int);
    map<string, pair<unsigned int, double>> precipitation(int, int);

};