#include "OMWeather.h"

map<string, pair<unsigned int, double>> avgTemp(int, int)
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

map<string, pair<unsigned int, double>> minTemp(int)
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

map<string, pair<unsigned int, double>> maxTemp(int)
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

map<string, pair<unsigned int, double>> windSpd(int, int)
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

map<string, pair<unsigned int, double>> precipitation(int, int)
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

