#include "ordered.h"
#include "u_map.h"
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    bool menu = true;
    int userMap;
    int userOption;
    clock_t startOrdBuild, endOrdBuild, startUnBuild, endUnBuild;

    cout << "Building data structures..." << endl;
    startOrdBuild = clock();
    weatherMap ordered;
    endOrdBuild = clock();
    startUnBuild = clock();
    u_map unordered;
    endUnBuild = clock();

    cout << "Time to build Unordered Map: "
                 << (endUnBuild - startUnBuild) / (float)CLOCKS_PER_SEC
                 << " seconds" << endl;
    cout << "Time of to build Ordered Map: "
                 << (endOrdBuild - startOrdBuild) / (float)CLOCKS_PER_SEC 
                 << " seconds" << endl << endl;

    while (menu)
    {
        cout << "Welcome to Weather Sort!" << endl;
        cout << "------------------------" << endl;

        cout << "Menu:" << endl;
        cout << "1). Search by average temperature" << endl;
        cout << "2). Search by minimum temperature" << endl;
        cout << "3). Search by maximum temperature" << endl;
        cout << "4). Search by wind speed" << endl;
        cout << "5). Search by precipitation" << endl;
        cout << "6). Exit" << endl;
        cout << "Enter option: ";
        cin >> userOption;
        cout << endl;

        clock_t startOrdered, endOrdered, startUnordered, endUnordered;

        switch (userOption)
        {
        case 1:
        {
            double min;
            double max;
            cout << "What is the minimum temperature you desire?" << endl;
            cin >> min;
            cout << "What is the maximum temperature you desire?" << endl;
            cin >> max;

            startUnordered = clock();
            vector<pair<int, string>> resultsUnordered = unordered.avgTemp(min, max);
            endUnordered = clock();

            cout << "Your optimal location(s) are: " << endl;
            if (resultsUnordered.size() != 0)
            {
                cout << resultsUnordered[0].second;
            }
            for (int i = 1; i < resultsUnordered.size(); i++)
            {
                if (resultsUnordered[i].first == resultsUnordered[0].first)
                {
                    cout << " | " << resultsUnordered[i].second;
                }
                else
                {
                    break;
                }
            }
            cout << endl;

            // ordered
            startOrdered = clock();
            vector<pair<int, string>> resultsOrdered = ordered.avgTemp(min, max);
            endOrdered = clock();

            cout << endl << "Time of Unordered Map: "
                 << (endUnordered - startUnordered) / (float)CLOCKS_PER_SEC
                 << " seconds" << endl;
            cout << "Time of Ordered Map: "
                 << (endOrdered - startOrdered) / (float)CLOCKS_PER_SEC << " seconds"
                 << endl;
            menu = false;

            break;
        }
        case 2:
        {

            double minTemperature;
            cout << "What is the minumum temperature you desire?" << endl;
            cin >> minTemperature;

            startUnordered = clock();
            vector<pair<int, string>> resultsUnordered = unordered.minTemp(minTemperature);
            endUnordered = clock();

            cout << "Your optimal location(s) are: " << endl;
            // this should print out first element of vector and those with the same
            // freq. as it
            if (resultsUnordered.size() != 0)
            {
                cout << resultsUnordered[0].second;
            }
            for (int i = 1; i < resultsUnordered.size(); i++)
            {
                if (resultsUnordered[i].first == resultsUnordered[0].first)
                {
                    cout << " | " << resultsUnordered[i].second;
                }
                else
                {
                    break;
                }
            }
            cout << endl;

            // ordered
            startOrdered = clock();
            vector<pair<int, string>> resultsOrdered = ordered.minTemp(minTemperature);
            endOrdered = clock();

            cout << "Time of Unordered Map: "
                 << (endUnordered - startUnordered) / (float)CLOCKS_PER_SEC
                 << " seconds" << endl;
            cout << "Time of Ordered Map: "
                 << (endOrdered - startOrdered) / (float)CLOCKS_PER_SEC << " seconds"
                 << endl;
            menu = false;

            break;
        }
        case 3:
        {
            double maxTemperature;
            cout << "What is the maximum temperature you desire?" << endl;
            cin >> maxTemperature;

            // unordered
            startUnordered = clock();
            vector<pair<int, string>> resultsUnordered = unordered.maxTemp(maxTemperature);
            endUnordered = clock();

            cout << "Your optimal location(s) are: " << endl;
            if (resultsUnordered.size() != 0)
            {
                cout << resultsUnordered[0].second;
            }
            for (int i = 1; i < resultsUnordered.size(); i++)
            {
                if (resultsUnordered[i].first == resultsUnordered[0].first)
                {
                    cout << " | " << resultsUnordered[i].second;
                }
                else
                {
                    break;
                }
            }
            cout << endl;

            // ordered

            startOrdered = clock();
            vector<pair<int, string>> resultsOrdered = ordered.maxTemp(maxTemperature);
            endOrdered = clock();

            cout << "Time of Unordered Map: "
                 << (endUnordered - startUnordered) / (float)CLOCKS_PER_SEC
                 << " seconds" << endl;
            cout << "Time of Ordered Map: "
                 << (endOrdered - startOrdered) / (float)CLOCKS_PER_SEC << " seconds"
                 << endl;
            menu = false;

            break;
        }
        case 4:
        {
            double minwindSpeed, maxWindSpeed;
            cout << "What is minimum wind speed you desire?" << endl;
            cin >> minwindSpeed;
            cout << "What is the maximum wind speed you desire?" << endl;
            cin >> maxWindSpeed;

            // unordered
            startUnordered = clock();
            vector<pair<int, string>> resultsUnordered = unordered.windSpd(minwindSpeed, maxWindSpeed);
            endUnordered = clock();

            cout << "Your optimal location(s) are: " << endl;
            if (resultsUnordered.size() != 0)
            {
                cout << resultsUnordered[0].second;
            }
            for (int i = 1; i < resultsUnordered.size(); i++)
            {
                if (resultsUnordered[i].first == resultsUnordered[0].first)
                {
                    cout << " | " << resultsUnordered[i].second;
                }
                else
                {
                    break;
                }
            }
            cout << endl;

            // ordered
            startOrdered = clock();
            vector<pair<int, string>> resultsOrdered = ordered.windSpeed(minwindSpeed, maxWindSpeed);
            endOrdered = clock();

            cout << "Time of Unordered Map: "
                 << (endUnordered - startUnordered) / (float)CLOCKS_PER_SEC
                 << " seconds" << endl;
            cout << "Time of Ordered Map: "
                 << (endOrdered - startOrdered) / (float)CLOCKS_PER_SEC << " seconds"
                 << endl;
            menu = false;

            break;
        }
        case 5:
        {
            double minPrecipitation, maxPrecipitation;
            cout << "What is the minimum precipitation you desire?" << endl;
            cin >> minPrecipitation;
            cout << "What is the maximum precipitation you desire?" << endl;
            cin >> maxPrecipitation;

            // unordered
            startUnordered = clock();
            vector<pair<int, string>> results = unordered.precip(minPrecipitation, maxPrecipitation);
            endUnordered = clock();

            cout << "Your optimal location(s) are: " << endl;
            if (results.size() != 0)
            {
                cout << results[0].second;
            }
            for (int i = 1; i < results.size(); i++)
            {
                if (results[i].first == results[0].first)
                {
                    cout << " | " << results[i].second;
                }
                else
                {
                    break;
                }
            }
            cout << endl;

            // ordered
            startOrdered = clock();
            vector<pair<int, string>> resultsOrdered = ordered.precipitation(minPrecipitation, maxPrecipitation);
            endOrdered = clock();

            cout << "Time of Unordered Map: "
                 << (endUnordered - startUnordered) / (float)CLOCKS_PER_SEC
                 << " seconds" << endl;
            cout << "Time of Ordered Map: "
                 << (endOrdered - startOrdered) / (float)CLOCKS_PER_SEC << " seconds"
                 << endl;
            menu = false;
            break;
        }
        case 6:
            cout << "Thank you for using Weather Sort!" << endl;
            menu = false;
            break;

        default:
            cout << "Invalid menu option. Please try again" << endl;
            break;
        }
        while (!menu)
        {
            if (userOption == 6)
            {
                break;
            }
            int userInput;
            cout << endl << "Would you like to select a menu option again?" << endl;
            cout << "1). Yes" << endl;
            cout << "2). No" << endl;
            cout << "Enter option: ";
            cin >> userInput;
            cout << endl;

            if (userInput == 1)
            {
                menu = true;
            }
            else if (userInput == 2)
            {
                cout << "Thank you for using Weather Sort!" << endl;
                break;
            }
            else
            {
                cout << "Invalid input. Please enter valid input" << endl;
                break;
            }
        }
    }

    return 0;
}