#include "OMWeather.h"
#include "u_map.h"
#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    bool menu = true;
    int userMap;
    int userOption;
    weatherMap ordered;
    u_map unordered;
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

        clock_t startOrdered, endOrdered, startUnordered, endUnordered;

        switch (userOption)
        {
        case 1:
            double min;
            double max;
            cout << "What is the minimum temperature you desire?" << endl;
            cin >> min;
            cout << "What is the maximum temperature you desire?" << endl;
            cin >> max;

            startOrdered = clock();
            ordered.avgTemp(min, max);
            endOrdered = clock();

            startUnordered = clock();
            unordered.avgTemp(min, max);
            endUnordered = clock();

            cout << "Time of Ordered Map: "
                 << (endOrdered - startOrdered) / (float)CLOCKS_PER_SEC << " seconds"
                 << endl;
            cout << "Time of Unordered Map: "
                 << (endUnordered - startUnordered) / (float)CLOCKS_PER_SEC
                 << " seconds" << endl;
            menu = false;

            break;
        case 2:
        {

            double minTemperature;
            cout << "What is the minumum temperature you desire?" << endl;
            cin >> minTemperature;

            startOrdered = clock();
            vector<pair<int, string>> results = unordered.minTemp(50);

            cout << "Your optimal location(s) are: " << endl;

            // this should print out first element of vector and those with the same
            // freq. as it
            /* for (int i = 0; i < results.size(); i++) {
              if (i == 0) {
                cout << results[i].second << endl;
              } else if (results[i].first == results[0].first) {
                cout << results[i].second << endl;
              } else {
                break;
              }
            } */

            // this is just to test
            cout << results[0].second << endl;
            endOrdered = clock();

            /* startUnordered = clock();
            unordered.minTemp(minTemperature);
            endUnordered = clock(); */

            cout << "Time of Ordered Map: "
                 << (endOrdered - startOrdered) / (float)CLOCKS_PER_SEC << " seconds"
                 << endl;
            /* cout << "Time of Unordered Map: "
                 << (endUnordered - startUnordered) / (float)CLOCKS_PER_SEC
                 << " seconds" << endl; */
            menu = false;

            break;
        }
        case 3:
        {
            double maxTemperature;
            cout << "What is the maximum temperature you desire?" << endl;
            cin >> maxTemperature;
            vector<pair<int, string>> results;

            startOrdered = clock();
            ordered.maxTemp(maxTemperature);
            cout << "Your optimal location(s) are: " << endl;
            for (int i = 0; i < results.size(); i++)
            {
                if (i == 0)
                {
                    cout << results[i].second << endl;
                }
                if (results[i].first == results[0].first)
                {
                    cout << results[i].second << endl;
                }
                else
                {
                    break;
                }
            }
            endOrdered = clock();

            startUnordered = clock();
            unordered.maxTemp(maxTemperature);
            endUnordered = clock();

            cout << "Time of Ordered Map: "
                 << (endOrdered - startOrdered) / (float)CLOCKS_PER_SEC << " seconds"
                 << endl;
            cout << "Time of Unordered Map: "
                 << (endUnordered - startUnordered) / (float)CLOCKS_PER_SEC
                 << " seconds" << endl;
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
            vector<pair<int, string>> results;

            startOrdered = clock();
            results = ordered.windSpeed(minwindSpeed, maxWindSpeed);
            cout << "Your optimal location(s) are: " << endl;
            for (int i = 0; i < results.size(); i++)
            {
                if (i == 0)
                {
                    cout << results[i].second << endl;
                }
                if (results[i].first == results[0].first)
                {
                    cout << results[i].second << endl;
                }
                else
                {
                    break;
                }
            }
            endOrdered = clock();

            startUnordered = clock();
            unordered.windSpd(minwindSpeed, maxWindSpeed);
            endUnordered = clock();

            cout << "Time of Ordered Map: "
                 << (endOrdered - startOrdered) / (float)CLOCKS_PER_SEC << " seconds"
                 << endl;
            cout << "Time of Unordered Map: "
                 << (endUnordered - startUnordered) / (float)CLOCKS_PER_SEC
                 << " seconds" << endl;
            menu = false;

            break;
        }
        case 5:
            double minPrecipitation, maxPrecipitation;
            cout << "What is the minimum precipitation you desire?" << endl;
            cin >> minPrecipitation;
            cout << "What is the maximum precipitation you desire?" << endl;
            cin >> maxPrecipitation;

            startOrdered = clock();
            ordered.precipitation(minPrecipitation, maxPrecipitation);
            endOrdered = clock();

            startUnordered = clock();
            unordered.windSpd(minPrecipitation, maxPrecipitation);
            endUnordered = clock();

            cout << "Time of Ordered Map: "
                 << (endOrdered - startOrdered) / (float)CLOCKS_PER_SEC << " seconds"
                 << endl;
            cout << "Time of Unordered Map: "
                 << (endUnordered - startUnordered) / (float)CLOCKS_PER_SEC
                 << " seconds" << endl;
            menu = false;
            break;
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
            int userInput;
            cout << "Would you like to select a menu option again?" << endl;
            cout << "1). Yes" << endl;
            cout << "2). No" << endl;
            cout << "Enter option: ";
            cin >> userInput;

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