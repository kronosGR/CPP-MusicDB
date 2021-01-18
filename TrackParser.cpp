#include "TrackParser.h"

using namespace std;
TrackParser::TrackParser()
{
}

TrackParser::~TrackParser()
{
}

/**
 * @brief stripes of spaces from both ends of the string
 * @param stringToTrimmed
 * @return stripped string
 */
string TrackParser::trim(string stringToTrimmed){
    string returnValue = stringToTrimmed;
    int lastPosition = returnValue.length() -1;
    bool found = true;
    
    while (found == true && lastPosition >=0){
        if (returnValue.substr(lastPosition,1) == " "){
            returnValue = returnValue.erase(lastPosition,1);
        }
        else if (returnValue.substr(0,1) == " "){
            returnValue = returnValue.erase(0,1);
        }
        else{
            found = false;
        }
        lastPosition = returnValue.length() -1;
    }
    return returnValue;
}

/**
 * @brief static public method that parses the string 
 * @param stringToParsed
 * @return string in author: title 
 */
string TrackParser::parse(string stringToParsed){
    string title;
    string artist;
    string returnValue="";
    
    if (stringToParsed.find(":") != string::npos){
        int pos = stringToParsed.find(":");
        artist = stringToParsed.substr(0, pos);
        title = stringToParsed.substr(pos+1, stringToParsed.length());
        returnValue = artist + ": "+ title;
    } 
    else if ( stringToParsed.find("-") != string::npos){
        int pos = stringToParsed.find("-");
        title = stringToParsed.substr(0, pos);
        artist = stringToParsed.substr(pos+1 , stringToParsed.length());
        returnValue = artist + ": "+ title;
    } 
    else if (stringToParsed.find(" by ") != string::npos){
        int pos = stringToParsed.find(" by ");
        title =  stringToParsed.substr(0,pos);
        artist = stringToParsed.substr(pos+3, stringToParsed.length());
        returnValue = artist + ": "+ title;
    }
    return returnValue;
}

