#include "OMWeather.h"

void weatherMap::addData(string fileName)
{
    string line, word;
    vector <string> row;

    fstream file(fileName, ios::in);
    if (file.is_open())
    {
        while (getline(file, line))
        {
            row.clear();
            stringstream str(line);
            while(getline(str, word, ','))
            {
                row.push_back(word);
                /*
                 * index legend
                 * 0 - precipitation
                 * 1 - full date
                 * 2 - month
                 * 3 - week
                 * 4 - year
                 * 5 - city
                 * 6 - code
                 * 7 - city/state
                 * 8 - state
                 * 9 - avgTemp
                 * 10 - maxTemp
                 * 11 - minTemp
                 * 12 - windDirection
                 * 13 - windSpeed
                 */
            }
            data[{row[1],row[7]}] = vector <double> {stod(row[0]), stod(row[9]), stod(row[10]), stod(row[11]), stod(row[13])};
        }
    }
}

map<string, pair<unsigned int, double>> weatherMap::avgTemp(int low, int high)
{
    /*
    * Inputs are boundaries of temperature threshold, first int is the floor
    * second is the ceiling
    * Returns a map that includes the name of the location as the key and
    * a pair as the value which includes the num of times the location meets the
    * criteria in the data (unsigned int) and the overall average temperature (double)
    * between all of the entries added to this map
    * Locations are added to the map if the data for avg temp is between inputs
    */
}

map<string, pair<unsigned int, double>> weatherMap::minTemp(int min)
{
    /*
    * Input is minimum temperature desired
    * Returns map including name of the location as the key and a pair as
    * the value which includes the num times the location meets the criteria in the data
    * (unsigned int) and the minimum temperature of all the qualified entries for the 
    * given location
    * Locations are added to map if min temp data is greater than the input
    */
}

map<string, pair<unsigned int, double>> weatherMap::maxTemp(int max)
{
    /*
    * Input is maximum temperature desired
    * Returns map including name of the location as the key and a pair as
    * the value which includes the num times the location meets the criteria in the data
    * (unsigned int) and the maximum temperature of all the qualified entries for the 
    * given location
    * Locations are added to map if max temp data is less than the input
    */
}

map<string, pair<unsigned int, double>> weatherMap::windSpd(int low, int high)
{
    /*
    * Input is threshold values for wind speed, first int is minimum desired wind
    * speed and second int is maximum desired wind speed.
    * Returns map including name of location as the key and a pair as the value
    * which includes the num times the location met the criteria in the data 
    * (unsigned int) and the maximum temperature of all qualified entries for 
    * given location
    * Locations are added to map if wind speed data is between the inputs
    */
}

map<string, pair<unsigned int, double>> weatherMap::precipitation(int low, int high)
{
    /*
    * Input is threshold values for precipitation, first int is minimum desired wind
    * speed and second int is maximum desired precipitaion.
    * Returns map including name of location as the key and a pair as the value
    * which includes the num times the location met the criteria in the data 
    * (unsigned int) and the maximum temperature of all qualified entries for 
    * given location
    * Locations are added to map if precipitation data is between the inputs
    */
}

