#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <string>
#include <vector>
#include "List_base.h"

class Playlist: public List_base
{
public:
    Playlist(std::string playlistName);
    ~Playlist();
    void showMenu();
private:
    std::vector<std::string> _tracks;
    std::string _playlistName;
    std::string _playlistFilename;
    bool _deleteMessage;
    void deleteSong(std::string trackName);
    void loadTracks();
    void printTracks();
    bool trackExists(std::string trackName);
    std::string getTrackName(int choice);
    void showTrackMenu(std::string trackName);

};

#endif // PLAYLIST_H
