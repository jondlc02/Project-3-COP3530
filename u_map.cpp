#include "u_map.h"

u_map::u_map()
{
    this->max_load = 0.8;
    this->num_elements = 0;
    this->size_table = 30000;
    this->table = new list<pair<pair<string, string>, vector<double>>>[size_table];
}

u_map::~u_map()
{
    delete[] table;
}

int u_map::hash(string date, string location)
{
    int hashCode = 0;
    for (int i = 0; i < location.length(); i++)
    {
        hashCode += int(location[i])*pow(31, location.length() - (i + 1)) ;
    }
    for (int i = 0; i < date.length(); i++)
    {
        hashCode += int(date[i])*pow(31, date.length() - (i + 1)) ;
    }
    return hashCode;
}

void u_map::addData()
{
    string line, word;
    vector <string> row;

    ifstream file("weather.csv", ios::binary);
    getline(file, line); // Empties top with labels
    while (getline(file, line))
    {
        stringstream str(line);
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
        insert(dateLoca, data);
        row.clear();
    }
}
void u_map::insert(pair<string, string> dateLoca, vector<double> data)
{
    int hashCode = hash(dateLoca.first, dateLoca.second);
    int index = abs(hashCode) % size_table;
    table[index].push_back(make_pair(dateLoca, data));
    this->num_elements++;
    if ((this->num_elements / (double)this->size_table) >= max_load)
    {
        rehash();
    }
}

void u_map::rehash() // I may scrap this and just make the hash table bigger by default
{
    this->size_table *= 2;
    list<pair<pair<string, string>, vector<double>>> *temp =
    new list<pair<pair<string, string>, vector<double>>>[size_table];
    for (int i = 0; i < size_table / 2; i++)
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
                int hashCode = hash((*it).first.first, (*it).first.second);
                int index = abs(hashCode) % size_table;
                temp[index].push_back(make_pair((*it).first, (*it).second));
            }
        }
    }

    delete[] table;
    this->table = temp;
}

vector<pair<int, string>> u_map::avgTemp(int low, int high)
{
    vector<pair<int, string>> results;
    cout << size_table << " " << num_elements << endl;
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
                if (low <= (*it).second[1] && (*it).second[1] <= high)
                {
                    if (results.size() == 0)
                    {
                        results.push_back(make_pair(1, (*it).first.second));
                    }
                    else
                    {
                        for (int j = 0; j < results.size(); j++)
                        {
                            if (results.at(j).second == (*it).first.second)
                            {
                                results.at(j).first++;
                            }
                            else
                            {
                                results.push_back(make_pair(1, (*it).first.second));
                            }
                        }
                    }
                }
            }
        }
    }
    return results;
}

vector<pair<int, string>> u_map::minTemp(int low)
{
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
                        for (int j = 0; j < results.size(); j++)
                        {
                            if (results.at(j).second == (*it).first.second)
                            {
                                results.at(j).first++;
                            }
                            else
                            {
                                results.push_back(make_pair(1, (*it).first.second));
                            }
                        }
                    }
                }
            }
        }
    }
    return results;
}

vector<pair<int, string>> u_map::maxTemp(int high)
{
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
                        for (int j = 0; j < results.size(); j++)
                        {
                            if (results.at(j).second == (*it).first.second)
                            {
                                results.at(j).first++;
                            }
                            else
                            {
                                results.push_back(make_pair(1, (*it).first.second));
                            }
                        }
                    }
                }
            }
        }
    }
    return results;
}

vector<pair<int, string>> u_map::windSpd(int low, int high)
{
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
                        for (int j = 0; j < results.size(); j++)
                        {
                            if (results.at(j).second == (*it).first.second)
                            {
                                results.at(j).first++;
                            }
                            else
                            {
                                results.push_back(make_pair(1, (*it).first.second));
                            }
                        }
                    }
                }
            }
        }
    }
    return results;
}

vector<pair<int, string>> u_map::precip(int low, int high)
{
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
                        for (int j = 0; j < results.size(); j++)
                        {
                            if (results.at(j).second == (*it).first.second)
                            {
                                results.at(j).first++;
                            }
                            else
                            {
                                results.push_back(make_pair(1, (*it).first.second));
                            }
                        }
                    }
                }
            }
        }
    }
    return results;
}