#include "OMWeather.h"
#include "u_map.h"
#include <iostream>
#include <algorithm>

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
        /* cout << "1. Search with an Ordered Map" << endl;
        cout << "2. Search with an Unordered Map" << endl;
        cin >> userMap; */

        cout << "Menu:" << endl;
        cout << "1). Search by average temperature" << endl;
        cout << "2). Search by minimum temperature" << endl;
        cout << "3). Search by maximum temperature" << endl;
        cout << "4). Search by wind speed" << endl;
        cout << "5). Search by precipitation" << endl;
        cout << "6). Exit" << endl;
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

            cout << "Time of Ordered Map: " << (endOrdered - startOrdered) / (float)CLOCKS_PER_SEC << " seconds" << endl;
            cout << "Time of Unordered Map: " << (endUnordered - startUnordered) / (float)CLOCKS_PER_SEC << " seconds" << endl;

            break;
        case 2:
            double minTemperature;
            cout << "What is the minumum temperature you desire?" << endl;
            cin >> minTemperature;

            startOrdered = clock();
            ordered.minTemp(minTemperature);
            endOrdered = clock();

            startUnordered = clock();
            unordered.minTemp(minTemperature);
            endUnordered = clock();

            cout << "Time of Ordered Map: " << (endOrdered - startOrdered) / (float)CLOCKS_PER_SEC << " seconds" << endl;
            cout << "Time of Unordered Map: " << (endUnordered - startUnordered) / (float)CLOCKS_PER_SEC << " seconds" << endl;

            break;
        case 3:
            double maxTemperature;
            cout << "What is the maximum temperature you desire?" << endl;
            cin >> maxTemperature;

            startOrdered = clock();
            ordered.maxTemp(maxTemperature);
            endOrdered = clock();

            startUnordered = clock();
            unordered.maxTemp(maxTemperature);
            endUnordered = clock();

            cout << "Time of Ordered Map: " << (endOrdered - startOrdered) / (float)CLOCKS_PER_SEC << " seconds" << endl;
            cout << "Time of Unordered Map: " << (endUnordered - startUnordered) / (float)CLOCKS_PER_SEC << " seconds" << endl;

            break;
        case 4:
            double minwindSpeed, maxWindSpeed;
            cout << "What is minimum wind speed you desire?" << endl;
            cin >> minwindSpeed;
            cout << "What is the maximum wind speed you desire?" << endl;
            cin >> maxWindSpeed;

            startOrdered = clock();
            ordered.windSpeed(minwindSpeed, maxWindSpeed);
            endOrdered = clock();

            startUnordered = clock();
            unordered.windSpd(minwindSpeed, maxWindSpeed);
            endUnordered = clock();

            cout << "Time of Ordered Map: " << (endOrdered - startOrdered) / (float)CLOCKS_PER_SEC << " seconds" << endl;
            cout << "Time of Unordered Map: " << (endUnordered - startUnordered) / (float)CLOCKS_PER_SEC << " seconds" << endl;

            break;
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

            cout << "Time of Ordered Map: " << (endOrdered - startOrdered) / (float)CLOCKS_PER_SEC << " seconds" << endl;
            cout << "Time of Unordered Map: " << (endUnordered - startUnordered) / (float)CLOCKS_PER_SEC << " seconds" << endl;
        case 6:
            cout << "Thank you for using Weather Sort!";
            break;

        default:
            cout << "Invalid menu option. Please try again" << endl;
            break;
        }
    }

    return 0;
}
