#ifndef LISTINDEX_H
#define LISTINDEX_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "List_base.h"

class ListIndex: public List_base
{
public:
    ListIndex();
    ~ListIndex();
    void showMenu();
    void deletePlaylist(std::string playlistName);
private:
    std::vector<std::string> playlists;
    void showChoiceError();
    void loadPlaylists();
    void printPlaylists();
    bool playlistsExists(std::string);
    std::string getPlaylistName(int choice);
    
    
    
};

#endif // LISTINDEX_H
