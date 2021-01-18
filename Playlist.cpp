#include "Playlist.h"
#include "ListIndex.h"
#include "TrackParser.h"

using namespace std;

Playlist::Playlist(string playlistName)
{
    this->_playlistName = playlistName;
    this->_playlistFilename = playlistName+".playlist";
}

Playlist::~Playlist()
{
}


void Playlist::showMenu(){
    string choice;
    bool wrongChoice = false;
    this->_deleteMessage = false;
    
    while (true){        
        //load the tracks
        this->loadTracks();
        
        this->clearScreen();
        
        //check if wrong choice selected
        if (wrongChoice==true){
            cout << endl;
            cout << "Invalid track number. Please try again." << endl;
            wrongChoice = false;
        }
        
        //check if track deleted
        if (this->_deleteMessage==true){
            cout << endl;
            cout << "Track deleted." << endl;
            this->_deleteMessage = false;
        }
        
        cout << endl;
        cout << "Playlist '" << this->_playlistName << "' Menu:" << endl;
        cout << endl;
        cout << "a. Add track(s) to playlist" << endl;
        cout << "d. Delete this playlist " << endl;
        cout << "x. Exit to main menu " << endl;
        
        if (this->_tracks.size()>0){
            cout << endl;
            cout << "Select Track # " << endl;
            cout << endl;
            
            //print the tracks 
            this->printTracks();
        }
        
        cout << endl;
        cout << "Your choice:" << endl;
        cin >> choice;
        cin.ignore();
        if (choice == "x"){
            break;
        }
        else if( choice == "d"){
            ListIndex newList;
            newList.deletePlaylist(this->_playlistName);
            cout << "Playlist Deleted" << endl;
            cout << "Press Enter to continue" << endl;
            cin.ignore();
            break;
        }
        else if (choice == "a"){
            while (true){
                string track;
                cout << "Enter a title and artist, or 'x' to exit" << endl;
                getline(cin, track);
                
                if (track.size()==0){
                    cout << "No text entered. Please try again" << endl;                 
                } else {
                    if (track =="x"){
                        break;
                    }
                    //check if exists
                    if (this->trackExists(track) == true){
                            cout << "That track already exists. Please try again" << endl;
                    } else {
                        //parse the track
                        string parsedTrack = TrackParser::parse(track);
                        if (parsedTrack.size() == 0){
                            cout << "Unrecognized format. Please try again" << endl;
                        } else {
                            //add the track to the playlist
                            this->_tracks.push_back(parsedTrack);
                            
                            //sort the playlist
                            sort(this->_tracks.begin(), this->_tracks.end());
                            
                            //save to the playlist file
                            this->writeFile(this->_playlistFilename, _tracks);
                        }
                    }
                }
            }            
        }
        else if (this->_tracks.size() >0 ){
            if (this->isNumber(choice)){
                if (stoi(choice) >0 && stoi(choice) <=this->_tracks.size()){
                    //handle the click
                    string trackName = this->getTrackName(stoi(choice));
                    
                    //show the track menu
                    this->showTrackMenu(trackName);
                }
                else {
                    //error
                    wrongChoice = true;    
                }
            }
        } else {
            //error
            wrongChoice = true;    
        }
    }
}

/**
 * @brief loads the contents of the playlist and insert them to _tracks vector
 */
void Playlist::loadTracks(){
    this->_tracks.empty();
    this->_tracks = this->readFile(this->_playlistFilename);
}

/**
 * @brief print the tracks to the screen
 */
void Playlist::printTracks(){
    vector<string>::iterator itTrack =this->_tracks.begin();
    int index = 1;
    while (itTrack != this->_tracks.end()){
        cout << index << " "<< *itTrack << endl;
        itTrack++;
        index++;
    }
}

/**
 * @brief check if track exists in playlist
 * @param trackName
 * @return true if exists
 */
bool Playlist::trackExists(string trackName){
    bool exists = false;
    vector<string>::iterator itTrack = this->_tracks.begin();
    while (itTrack != this->_tracks.end()){
        if (trackName == *itTrack){
            exists = true;
            break;
        }
        itTrack ++;
    }
    return exists;
}

/**
 * @brief gets the track name according to the choice
 * @param choice index of the track
 * @return the track name
 */
std::string Playlist::getTrackName(int choice){
    string track;
    vector<string>::iterator itTrack = this->_tracks.begin();
    int index = 1;
    while (itTrack != this->_tracks.end()){
        if (index == choice){
            track =  *itTrack;
            break;
        }
        itTrack++;
        index++;
    }
    return track;
}

/**
 * @brief shows the menu for the selected tracj
 * @param trackName the track name
 */
void Playlist::showTrackMenu(string trackName){
    bool invalidChoice = false;
    
    while (true){
        this->clearScreen();
        
        if (invalidChoice == true){
            cout << endl;
            cout << "Invalid choice. Please try again." << endl;
            invalidChoice = false;
        }
        
        cout << endl;
        cout << "Playlist '" << this->_playlistName << "'" << endl;
        cout << "Track '" << trackName << "' Menu :" << endl;
        cout << endl;
        cout << "d. Delete this track" << endl;
        cout << "x. Exit to Playlist menu" << endl;
        cout << endl;
        cout << "Your choice"  << endl;
        
        string yourChoice;
        getline(cin, yourChoice);
        
        if (yourChoice == "x"){
            break;
        }
        else if (yourChoice == "d"){
            //delete the track from the _tracks
            this->deleteSong(trackName);
            //write to file
            this->writeFile(this->_playlistFilename, this->_tracks);
            
            //set true the _deleteMessage and break;
            this->_deleteMessage = true;
            break;
        }
        else {
            invalidChoice = true;
        }
    }    
}

void Playlist::deleteSong(string trackName){
    int pos = 0;
    vector<string>::iterator itTrack = this->_tracks.begin();
    while (itTrack != this->_tracks.end()){
        if (trackName == *itTrack) {
            this->_tracks.erase(this->_tracks.begin() + pos);
            break;
        }
        itTrack++;
        pos++;
    }
}