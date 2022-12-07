#include "u_map.h"
#include <algorithm>

u_map::u_map()
{
    /*
     * This is an unordered_map class created from scratch using 
     * a dynamic array of lists as its base.
     * The load limit is 0.8 and the array size will be doubled when
     * limit is reached or exceeded.
     * Unordered map is implemented as a hashtable with separate chaining
     * where each bucket is a list of pairs, each pair including a pair
     * of strings and a vector of doubles.
     */
    this->max_load = 0.8; // Current load = num_elements / size_table
    this->num_elements = 0;
    this->size_table = 31; // Decently sized prime for max efficiency
    this->table = new list<pair<pair<string, string>, vector<double>>>[size_table];
    addData();
}

u_map::~u_map()
{
    delete[] table;  // Deletes dynamic array to prevent leaks
}

int u_map::hash(string date, string location)
{
    /*
     * Calculates hash code; DOES NOT CALCULATE THE INDEX.
     * This uses powers of 31 and powers of 2 from ascii
     * Powers of 2 are used for the date because it was giving me
     * large negative numbers before, so now I gave it powers of 2
     * so it can't affect the hash code too much.
     */
    int hashCode = 0;
    for (int i = 0; i < location.length(); i++)
    {
        hashCode += int(location[i])*pow(31, location.length() - (i + 1)) ;
    }
    for (int i = 0; i < date.length(); i++)
    {
        hashCode += int(date[i])*pow(3, date.length() - (i + 1)) ;
    }
    return hashCode;
}

void u_map::addData()
{
    /*
     * Adds data from csv into private table
     */
    string line, word;
    vector <string> row;

    // How to read csv from:
    // https://java2blog.com/read-csv-file-in-cpp/#:~:text=To%20read%20a%20CSV%20file%2C,variable%20as%20its%20second%20argument.
    ifstream file("weather.csv", ios::binary);
    getline(file, line); // Empties top with labels
    while (getline(file, line))
    {
        stringstream str(line);
        // Separates data in the csv by quotations b/c
        // the locations have commas in them
        while (getline(str, word, '"'))
        {
            if (word == "" || word == ",")
            {
                continue;
            }
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
        pair<string, string> dateLoca = make_pair(row[1], row[7]);
        vector<double> data = {stod(row[0]), stod(row[9]), stod(row[10]), stod(row[11]), 
                               stod(row[12]), stod(row[13])};
        /*
         * Index Legend for Data Vector:
         * 0 - Precipiation
         * 1 - avgTemp
         * 2 - maxTemp
         * 3 - minTemp
         * 4 - windDirection -> not used in any search
         * 5 - windSpeed
         */
        insert(dateLoca, data);
        row.clear();
    }
}
void u_map::insert(pair<string, string> dateLoca, vector<double> data)
{
    int hashCode = hash(dateLoca.first, dateLoca.second);
    int index = abs(hashCode) % size_table; // Calculates index based on hashCode and table size
    table[index].push_back(make_pair(dateLoca, data));
    this->num_elements++;
    if ((this->num_elements / (double)this->size_table) >= max_load)
    {  // Rehashes hash table if current load exceeds or equals max load
        rehash();
    }
}

void u_map::rehash() 
{
    /*
     * Dynamically resizes array in order to keep it as efficient as possible.
     * Doubles the size of the array.
     * Creates temporary array of twice the size the original and all the previously
     * added data points have a new hashCode calculated for the new table
     */
    this->size_table *= 2;
    list<pair<pair<string, string>, vector<double>>> *temp =
    new list<pair<pair<string, string>, vector<double>>>[size_table];
    for (int i = 0; i < size_table / 2; i++) // Iterates through old table and puts values in
    {                                        // new table
        if (table[i].empty())
        {
            continue;
        }
        else
        {
            list<pair<pair<string, string>, vector<double>>>::iterator it;
            for (it = table[i].begin(); it != table[i].end(); ++it)
            { // New hash code is calculated
                int hashCode = hash((*it).first.first, (*it).first.second);
                int index = abs(hashCode) % size_table;
                temp[index].push_back(make_pair((*it).first, (*it).second));
            }
        }
    }

    delete[] table; // Old table is deleted and the temp table replaces it
    this->table = temp;
}

vector<pair<int, string>> u_map::avgTemp(int low, int high)
{
    /*
     * Takes two ints as input, low and high.
     * low acts as floor for avgTemp and high acts as ceiling.
     * Adds locations to vector if their avgTemp data point is within range. 
     * If the location already exists in the vector it increases its frequency by one
     * Location name is stored as the second part of the pair
     * Frequency is stored as the first part of the pair
     */
    vector<pair<int, string>> results; // To be returned
    for (int i = 0; i < size_table; i++)
    { // Tries to find non-empty bucket
        if (table[i].empty())
        {
            continue;
        }
        else
        {
            list<pair<pair<string, string>, vector<double>>>::iterator it;
            for (it = table[i].begin(); it != table[i].end(); ++it)
            { // Iterates through list if bucket isn't empty
                if (low <= (*it).second[1] && (*it).second[1] <= high)
                {
                    if (results.size() == 0)
                    {
                        results.push_back(make_pair(1, (*it).first.second));
                    }
                    else
                    {
                        bool unique = true;
                        for (int j = 0; j < results.size(); j++)
                        {
                            if (results.at(j).second == (*it).first.second)
                            { // Increments frequency for a given location if it appears multiple times
                                results.at(j).first++;
                                unique = false;
                                break;
                            }
                        }
                        
                        if (unique)
                        { // Creates brand new data point in set if it doesn't already exist
                            results.push_back(make_pair(1, (*it).first.second));
                        }
                    }
                }
            }
        }
    }
    // From https://www.geeksforgeeks.org/sort-c-stl/
    sort(results.begin(), results.end(), greater<pair<int, string>>());
    // Sorts vector so locations with the greatest frequency are at the beginning for easy access
}

vector<pair<int, string>> u_map::minTemp(int low)
{
    /*
     * Takes one int as input: low
     * low acts as floor for minTemp.
     * Adds locations to vector if their minTemp data point is greater than the input. 
     * If the location already exists in the vector it increases its frequency by one
     * Location name is stored as the second part of the pair
     * Frequency is stored as the first part of the pair
     * Refer to avgTemp for more detailed comments on how this works.
     * All the below functions function exactly the same.
     */
    vector<pair<int, string>> results;
    for (int i = 0; i < size_table; i++)
    {
        if (table[i].empty())
        {
            continue;
        }
        else
        {
            list<pair<pair<string, string>, vector<double>>>::iterator it;
            for (it = table[i].begin(); it != table[i].end(); ++it)
            {
                if (low <= (*it).second[3])
                {
                    if (results.size() == 0)
                    {
                        results.push_back(make_pair(1, (*it).first.second));
                    }
                    else
                    {
                        bool unique = true;
                        for (int j = 0; j < results.size(); j++)
                        {
                            if (results.at(j).second == (*it).first.second)
                            {
                                results.at(j).first++;
                                unique = false;
                                break;
                            }
                        }
                        
                        if (unique)
                        {
                            results.push_back(make_pair(1, (*it).first.second));
                        }
                    }
                }
            }
        }
    }
    sort(results.begin(), results.end(), greater<pair<int, string>>());
    return results;
}

vector<pair<int, string>> u_map::maxTemp(int high)
{
    /*
     * Takes one int as input: high
     * low acts as ceiling for maxTemp.
     * Adds locations to vector if their maxTemp data point is less than the input. 
     * If the location already exists in the vector it increases its frequency by one
     * Location name is stored as the second part of the pair
     * Frequency is stored as the first part of the pair
     * Refer to avgTemp for more detailed comments on how this works.
     * All the below functions function exactly the same.
     */
    vector<pair<int, string>> results;
    for (int i = 0; i < size_table; i++)
    {
        if (table[i].empty())
        {
            continue;
        }
        else
        {
            list<pair<pair<string, string>, vector<double>>>::iterator it;
            for (it = table[i].begin(); it != table[i].end(); ++it)
            {
                if (high <= (*it).second[3])
                {
                    if (results.size() == 0)
                    {
                        results.push_back(make_pair(1, (*it).first.second));
                    }
                    else
                    {
                        bool unique = true;
                        for (int j = 0; j < results.size(); j++)
                        {
                            if (results.at(j).second == (*it).first.second)
                            {
                                results.at(j).first++;
                                unique = false;
                                break;
                            }
                        }
                        
                        if (unique)
                        {
                            results.push_back(make_pair(1, (*it).first.second));
                        }
                    }
                }
            }
        }
    }
    sort(results.begin(), results.end(), greater<pair<int, string>>());
    return results;
}

vector<pair<int, string>> u_map::windSpd(int low, int high)
{
    /*
     * Takes two ints as input, low and high.
     * low acts as floor for windSpd and high acts as ceiling.
     * Adds locations to vector if their windSpd data point is within range. 
     * If the location already exists in the vector it increases its frequency by one
     * Location name is stored as the second part of the pair
     * Frequency is stored as the first part of the pair
     */
    vector<pair<int, string>> results;
    for (int i = 0; i < size_table; i++)
    {
        if (table[i].empty())
        {
            continue;
        }
        else
        {
            list<pair<pair<string, string>, vector<double>>>::iterator it;
            for (it = table[i].begin(); it != table[i].end(); ++it)
            {
                if (low <= (*it).second[5] &&  (*it).second[5] <= high)
                {
                    if (results.size() == 0)
                    {
                        results.push_back(make_pair(1, (*it).first.second));
                    }
                    else
                    {
                        bool unique = true;
                        for (int j = 0; j < results.size(); j++)
                        {
                            if (results.at(j).second == (*it).first.second)
                            {
                                results.at(j).first++;
                                unique = false;
                                break;
                            }
                        }
                        
                        if (unique)
                        {
                            results.push_back(make_pair(1, (*it).first.second));
                        }
                    }
                }
            }
        }
    }
    sort(results.begin(), results.end(), greater<pair<int, string>>());
    return results;
}

vector<pair<int, string>> u_map::precip(int low, int high)
{
    /*
     * Takes two ints as input, low and high.
     * low acts as floor for precip and high acts as ceiling.
     * Adds locations to vector if their avgTemp data point is within range. 
     * If the location already exists in the vector it increases its frequency by one
     * Location name is stored as the second part of the pair
     * Frequency is stored as the first part of the pair
     */
    vector<pair<int, string>> results;
    for (int i = 0; i < size_table; i++)
    {
        if (table[i].empty())
        {
            continue;
        }
        else
        {
            list<pair<pair<string, string>, vector<double>>>::iterator it;
            for (it = table[i].begin(); it != table[i].end(); ++it)
            {
                if (low <= (*it).second[0] && (*it).second[0] <= high)
                {
                    if (results.size() == 0)
                    {
                        results.push_back(make_pair(1, (*it).first.second));
                    }
                    else
                    {
                        bool unique = true;
                        for (int j = 0; j < results.size(); j++)
                        {
                            if (results.at(j).second == (*it).first.second)
                            {
                                results.at(j).first++;
                                unique = false;
                                break;
                            }
                        }
                        
                        if (unique)
                        {
                            results.push_back(make_pair(1, (*it).first.second));
                        }
                    }
                }
            }
        }
    }
    sort(results.begin(), results.end(), greater<pair<int, string>>());
    return results;
}