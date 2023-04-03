//
// Created by Pedro on 23/03/2023.
//

#ifndef DAPROJECT_STATION_H
#define DAPROJECT_STATION_H

#include <string>

using namespace std;

class Station {
    string name;
    string district;
    string municipality;
    string township;
    string line;
public:
    Station();
    Station(string name_, string district_, string municipality_, string township_, string line_);
    string get_name();
    string get_district();
    string get_municipality();
    string get_township();
    string get_line();
};


#endif //DAPROJECT_STATION_H
