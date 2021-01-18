#include "ListIndex.h"
#include "Playlist.h"

using namespace std;

ListIndex::ListIndex()
{
}

ListIndex::~ListIndex()
{
}

/**
 * @brief shows the initial menu
 */
void ListIndex::showMenu(){
    string choice;
    bool wrongChoice = false;
    
    while(true){    
        //load the playlists
        this->loadPlaylists();
        
        this->clearScreen();
        
        //check if wrong choice selected
        if (wrongChoice==true){
            this->showChoiceError();
            wrongChoice = false;
        }
        cout << endl;
        cout << "Main Menu" << endl;
        cout << "c. Create a Playlist" << endl;
        cout << "x. Exit program" << endl;
        
        if (this->playlists.size() >0) {
            cout << endl ;
            cout << "Select Playlist #" << endl;
            cout << endl ;
            
            //print the playlists if any
            this->printPlaylists();
            
        }
        
        cout << endl;
        cout << "Your choice: ";
        cin >> choice;
        
        if (choice == "x"){
            cout << "Farewell" << endl;
            break;
        }
        else if (choice  == "c")
        {
            //create playlist
            string  playlistName;
            cout << "Enter a name for your new playlist" << endl;
            cin.ignore();
            getline(cin, playlistName);
            
            //check if playlist exists
            if (this->playlistsExists(playlistName) == true){
                cout << "Sorry.  That Playlist already exists. Please try again " << endl;
                cout << "Press Enter to continue" << endl;
                cin.ignore();
            } else {
                //create a .playlist file to the disk
                string filename = playlistName +".playlist";
                this->createFile(filename);
                
                //add the list to the playlists
                this->playlists.push_back(playlistName);
                               
                //sort the playlists
                sort(this->playlists.begin(), this->playlists.end());
                
                //save the playlists
                this->writeFile("index.txt", this->playlists);
            }
        }
        else if(this->playlists.size() > 0 ) {
            if (this->isNumber(choice)){
                if (stoi(choice) >0 && stoi(choice) <= this->playlists.size()){
                    //handle the click
                    string name = this->getPlaylistName(stoi(choice));
                    Playlist newPlaylist(name);
                    newPlaylist.showMenu();
                    
                } else {
                    //error
                    wrongChoice = true;    
                }                
            }
        }
        else {
            //error
            wrongChoice = true;
        }
        
        
    }
}



/**
 * @brief show a choice error
 */
void ListIndex::showChoiceError(){
    cout << endl;
    cout << "Playlist number not Found" << endl;
}

/**
 * @brief reads the index.txt
 * @return a vector with the playlists
 */
void ListIndex::loadPlaylists(){
    this->playlists.clear();
    this->playlists = this->readFile("index.txt");
}

/**
 * @brief print the playlists on the screen
 */
void ListIndex::printPlaylists(){
    vector<string>::iterator itLists = this->playlists.begin();
    int index = 1;
    while(itLists != this->playlists.end()){
        cout << index << " " << *itLists << endl;
        itLists++;
        index++;
    }
}

/**
 * @brief check if the a playlist exists
 * @param playlistName the name to search
 * @return true if exists
 */
bool ListIndex::playlistsExists(string playlistName){
    bool exists = false;
    vector<string>::iterator itList = this->playlists.begin();
    while(itList !=this->playlists.end()){
        if (playlistName == *itList){
            exists = true;
            break;
        }
        itList++;
    }
    return exists;
}

/**
 * @brief gets the filename according to the choice
 * @param choice the index of the playlist
 * @return the playlistname
 */
string ListIndex::getPlaylistName(int choice){
    string name;
    vector<string>::iterator itList = this->playlists.begin();
    int index = 1;
    while(itList != this->playlists.end()){
        if (index == choice){
            name = *itList;
            break;
        }
        itList++;
        index++;
    }
    return name;    
}

/**
 * @brief remove a playlist from the list
 * @param playlistName
 */
void ListIndex::deletePlaylist(string playlistName){
    //load playlists from the file
    this->loadPlaylists();
    
    //find the playlist in the liss
    int position = 0;
     vector<string>::iterator itList = this->playlists.begin();
     while(itList != this->playlists.end()){
         if (playlistName == *itList){
             this->playlists.erase(this->playlists.begin() + position);
             break;
         }
         itList++;
         position++;
     }
     
     //save the playlists
     this->writeFile("index.txt", this->playlists);
}