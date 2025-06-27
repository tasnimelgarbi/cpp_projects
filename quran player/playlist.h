#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "Elsheikh.h"
#include "Surah.h"
#include "DoublyLinkedList.h"
#include <string>
#include <iostream>
using namespace std;

template <typename T>

class Playlist {
private:
    DoublyLinkedList <Elsheikh> playlists;

public:
     Playlist();
    ~Playlist();

    void addPlaylist();
    void removePlaylist(int playlistIndex);
    void addSurahToPlaylist(int playlistIndex , Surah surah );
    void removeSurahFromPlaylist(int playlistIndex, const string& surahName);
    void displayAllPlaylists() ;
    void displaySurahsInPlaylist(int playlistIndex) ;
    void saveToFile(const string& filename)  ;
    void loadFromFile(const string& filename) ;
    void display_all_playlists_with_surahs ( Playlist<T>);
    void Update_Suhrah_pos (int plindex , string surahName , int pos) ;
    int returnSize () ;
    void play_track () ;
};

#endif // PLAYLIST_H
