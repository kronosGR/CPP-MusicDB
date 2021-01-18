#ifndef TRACKPARSER_H
#define TRACKPARSER_H

#include <string>

class TrackParser
{
public:
    TrackParser();
    ~TrackParser();
    static std::string parse(std::string stringToParsed);
private:
    static std::string trim(std::string stringToTrimmed);
};

#endif // TRACKPARSER_H
