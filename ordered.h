//
// Created by Maxime Techoueyres on 12/5/22.
//

#ifndef TESTTT_TEST_H
#define TESTTT_TEST_H


#include <map>
#include <vector>
#include <utility>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

struct Node {
    pair<string ,string> dateLocation;
    double precipitation;
    double avgTemp;
    double minTemp;
    double maxTemp;
    double windSpeed;
    Node* left;
    Node* right;

public:
    Node() {
        this->dateLocation = {"",""};
        this->precipitation = 0;
        this->avgTemp = 0;
        this->minTemp = 0;
        this->maxTemp = 0;
        this->windSpeed = 0;
        this->left = nullptr;
        this->right = nullptr;
    }
    Node(pair <string, string> dateLocation, double avgTemp, double minTemp, double maxTemp, double precipitation, double windSpeed) {
        this->dateLocation = dateLocation;
        this->precipitation = precipitation;
        this->avgTemp = avgTemp;
        this->minTemp = minTemp;
        this->maxTemp = maxTemp;
        this->windSpeed = windSpeed;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class weatherMap
{
private:
    vector <pair <int, string>> results;
    Node *insertHelper(Node *&root, pair <string, string> dateLocation, double avgTemp, double minTemp, double maxTemp, double precipitation, double windSpeed);
    vector <pair <int, string> > avgTempHelper(Node *node, double low, double high);
    vector <pair <int, string> > minTempHelper(Node *node, double min);
    vector <pair <int, string> > maxTempHelper(Node *node, double max);
    vector <pair <int, string> > windSpeedHelper(Node *node, double low, double high);
    vector <pair <int, string> > precipitationHelper(Node *node, double low, double high);
    bool searchVector(vector <pair <int, string> > results, string location);



public:
    Node *root;

    // Constructor && Destructor
    weatherMap();
    ~weatherMap();
    void addData();

    // insert function
    void insert(pair <string, string> dateLocation, double avgTemp, double minTemp, double maxTemp, double precipitation, double windSpeed);

    // main command functions
    vector <pair <int, string> > avgTemp(double low, double high);
    vector <pair <int, string> > minTemp(double min);
    vector <pair <int, string> > maxTemp(double max);
    vector <pair <int, string> > windSpeed(double low, double high);
    vector <pair <int, string> > precipitation(double low, double high);


    //rotate helper functions based off class slides
    Node *rotateLeft(Node *node);
    Node *rotateRight(Node *node);
    Node *rotateLeftRight(Node *node);
    Node *rotateRightLeft(Node *node);

    //additional helper functions
    void deleteMap(Node *node);
    double getHeight(Node *node);
    double getBalanceFactor(Node *node);


};


#endif //TESTTT_TEST_H
