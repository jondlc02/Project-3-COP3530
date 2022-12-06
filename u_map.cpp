#include "u_map.h"
#include <math.h>
#include <iterator>

u_map::u_map()
{
    this->max_load = 0.8;
    this->num_elements = 0;
    this->size_table = 20;
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

void u_map::insert(pair<string, string> dateLoca, vector<double> data)
{
    int hashCode = hash(dateLoca.first, dateLoca.second);
    int index = hashCode % size_table;
    table[index].push_back(make_pair(dateLoca, data));
    this->num_elements++;
    if ((this->num_elements / this->size_table) >= max_load)
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
                int index = hashCode % size_table;
                temp[index].push_back(make_pair((*it).first, (*it).second));
            }
        }
    }

    delete[] table;
    this->table = temp;
}