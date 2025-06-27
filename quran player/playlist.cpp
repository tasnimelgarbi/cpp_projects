#include "Playlist.h"
#include <windows.h>
#include <mmsystem.h>
#include <iomanip>
#include <fstream>
template<typename T>
Playlist<T>::Playlist() {}
template<typename T>
Playlist<T>::~Playlist()
{
   playlists.clear();
}
template<typename T>
void Playlist<T>::addPlaylist()
{
    string sheikhName ;
    cout << setw (78) <<"Enter The Name Of Elshiekh : " ;
    cin >> sheikhName ;
    Elsheikh newSheikh(sheikhName);
    playlists.append(newSheikh);
    cout << endl << setw(63) << "Playlist for \"" << sheikhName << "\" added successfully." << endl;
}
template<typename T>
void Playlist<T>::removePlaylist(int playlistIndex)
{
    if (playlistIndex < 0 || playlistIndex >= playlists.getsize())
    {
        cout <<endl<< setw (72) <<"Invalid playlist index." << endl;
        return;
    }

    DoublyLinkedList<Elsheikh>::Node* current = playlists.getFirst ();
    for (int i = 0; i < playlistIndex; ++i)
    {
        current = current->next;
    }

    playlists.Delete(current->item);
    cout <<endl<< setw (79) <<"Playlist removed successfully." << endl;
}
template<typename T>
void Playlist<T>::addSurahToPlaylist(int playlistIndex, Surah surah )
{
    if (playlistIndex < 0 || playlistIndex >= playlists.getsize())
    {
        cout <<endl<< setw (72) <<"Invalid playlist index." << endl;
        return ;
    }

    DoublyLinkedList<Elsheikh>::Node* current = playlists.getFirst();
    for (int i = 0; i < playlistIndex; ++i)
    {
        current = current->next;
    }

    current->item.addSurah(surah);
    cout <<endl<< setw (56) <<"Surah \"" << surah . getName() << "\" added successfully to playlist \"" << current->item.getName() << "\"." << endl;
}
template<typename T>
void Playlist<T>::removeSurahFromPlaylist(int playlistIndex, const string& surahName)
{
    if (playlistIndex < 0 || playlistIndex >= playlists.getsize())
    {
        cout <<endl<< setw (72) <<"Invalid playlist index." << endl;
        return;
    }

    DoublyLinkedList<Elsheikh>::Node* current = playlists.getFirst();
    for (int i = 0; i < playlistIndex; ++i)
    {
        current = current->next;
    }

    current->item.deleteSurahByName(surahName);
}
template<typename T>
void Playlist<T>::displayAllPlaylists()
{
    if (playlists.isEmpty())
    {
        cout <<endl<< setw (72) << "No playlists available." << endl;
        return;
    }

    int index = 1 ;
    DoublyLinkedList<Elsheikh>::Node* current = playlists.getFirst();
    do
    {
        cout <<endl<< setw (50) << index << ". " << current->item.getName() << endl;
        current = current->next;
        index ++ ;
    }
    while (current != playlists.getFirst());
}
template<typename T>
void Playlist<T>::displaySurahsInPlaylist(int playlistIndex)
{
    if (playlistIndex < 0 || playlistIndex >= playlists.getsize())
    {
        cout <<endl<< setw (72) <<"Invalid playlist index." << endl;
        return;
    }

    DoublyLinkedList<Elsheikh>::Node* current = playlists.getFirst();
    for (int i = 0; i < playlistIndex; ++i)
    {
        current = current->next;
    }

    current->item.printSheikh();
}

template<typename T>
void Playlist<T>::display_all_playlists_with_surahs ( Playlist<T> playlist)
{
    for (int i = 0 ; i<playlist.returnSize() ; i++)
    {
        playlist.displaySurahsInPlaylist(i) ;
    }
}
template<typename T>
int Playlist<T>::returnSize ()
{
    return playlists.getsize() ;
}
template<typename T>
void Playlist<T>::play_track ()
{
    int plindex, surahindex ;
    displayAllPlaylists() ;
    cout << endl ;
    cout <<endl<< setw (83)  << "Enter The Index of The playlist : " ;
    cin >> plindex ;
    cout << endl ;
    displaySurahsInPlaylist(plindex-1) ;
    cout << endl ;
    cout <<endl<< setw (80) << "Enter The Index of The Surah : " ;
    cin >> surahindex ;
    cout << endl ;

    DoublyLinkedList<Elsheikh>::Node* currentPlaylist = playlists.getFirst();
    for (int i = 0; i < plindex - 1; ++i)
    {
        currentPlaylist = currentPlaylist->next;
    }
    Elsheikh& selectedSheikh = currentPlaylist->item;
    DoublyLinkedList<Surah>& surahList = selectedSheikh.getSuar();


    DoublyLinkedList<Surah>::Node* currentSurah = surahList.getFirst();
    for (int i = 0; i < surahindex - 1; ++i)
    {
        currentSurah = currentSurah->next;
    }

    bool musicPlaying = false;
    cout << setw(95)   << "     Use left arrow (<-) to play the previous Surah"   << endl ;
    cout << setw(92)   << "     Use right arrow (->) to play the next surah"  << endl ;
    cout << setw(92)   << "     Use up arrow (^) to pause the current Surah"   << endl ;
    cout << setw(95)   << "     Use down arrow (v) to resume the current Surah"   << endl ;
    cout << setw(84)   << "     Use space button to return to Menu "   << endl ;

    while (true)
    {
        if (GetAsyncKeyState(VK_UP) & 0x8000)
        {
            if (!musicPlaying)
            {
                PlaySound(currentSurah->item.getPath().c_str(), NULL, SND_FILENAME | SND_ASYNC);
                musicPlaying = true;
                cout <<endl<< setw (72) <<"Playing sound..." << endl;
            }
        }
        else if (GetAsyncKeyState(VK_DOWN) & 0x8000)
        {
            if (musicPlaying)
            {
                PlaySound(NULL, NULL, 0);
                musicPlaying = false;
                cout<<endl<< setw (70) <<"Sound stopped." << endl;
            }
        }
        else if (GetAsyncKeyState(VK_LEFT) & 0x8000)
        {
             if (currentSurah->prev)
            {
                currentSurah =currentSurah->prev;
            }
            else
            {
                surahList.getLast ();
            }
            PlaySound(currentSurah->item.getPath().c_str(), NULL, SND_FILENAME | SND_ASYNC);
            musicPlaying = true;
            cout <<endl<< setw (81)<< "Playing previous Surah..." << endl;
        }
        else if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
        {
             if (currentSurah->next)
            {
                currentSurah =currentSurah->next;
            }
            else
            {
                surahList.getFirst ();
            }
            PlaySound(currentSurah->item.getPath().c_str(), NULL, SND_FILENAME | SND_ASYNC);
            musicPlaying = true;
            cout <<endl<< setw (77)<<"Playing next Surah..." << endl;
        }
        else if (GetAsyncKeyState(VK_SPACE) & 0x8000)
        {
            PlaySound(NULL, NULL, 0);
            return;
        }

        Sleep(250);
    }
}
template<typename T>
void Playlist<T>::Update_Suhrah_pos(int plIndex, string surahName, int newPos) {

    if (plIndex < 0 || plIndex >= playlists.getsize()) {
        cout << setw (78) <<"Invalid playlist index." << endl;
        return;
    }

    DoublyLinkedList<Elsheikh>::Node* currentPlaylist = playlists.getFirst();
    for (int i = 0; i < plIndex; ++i) {
        currentPlaylist = currentPlaylist->next;
    }

    Elsheikh& selectedSheikh = currentPlaylist->item;
    DoublyLinkedList<Surah>& surahList = selectedSheikh.getSuar();
    DoublyLinkedList<Surah>::Node* currentSurah = surahList.getFirst();
    while(currentSurah->item.getName()!=surahName){
        currentSurah = currentSurah->next;
    }
    if (newPos < 0 || newPos >= surahList.getsize()) {
        cout <<endl<< setw (72) <<"Invalid new position." << endl;
        return;
    }

    surahList.update_pos_of_Value( newPos , currentSurah->item );

    cout<<endl<< setw (72) <<"Surah position updated successfully in playlist \"" << selectedSheikh.getName() << "\"." << endl;
}


template<typename T>
void Playlist<T>::saveToFile(const string& filename)  {
    ofstream outFile(filename);
    if (!outFile) {
        std::cerr <<endl<< setw (72) << "Error opening file!" << std::endl;
        return;
    }

    DoublyLinkedList<Elsheikh>::Node* current = playlists.getFirst();
   do
    {
        outFile << current->item.getName() << endl;
        DoublyLinkedList<Surah>::Node* surahNode = current->item.getSuar().getFirst();
        do
        {
            outFile << surahNode->item.getName() << ","
                    << surahNode->item.getType() << ","
                    << surahNode->item.getPath() << endl;
            surahNode = surahNode->next;
        }while (surahNode != current->item.getSuar().getFirst());
        outFile << "#END" << endl;
        current = current->next;
    }while (current!=playlists.getFirst());

    outFile.close();
    cout <<endl<< setw (72)<<"Playlists saved to file successfully." << endl;
}
template<typename T>
void Playlist<T>::loadFromFile(const string& filename)
{
    ifstream inFile(filename);
    if (!inFile)
    {
        cout <<endl<< setw (72)<<"Error opening file for reading." << endl;
        return;
    }

    playlists.clear();
    string line;
    while (getline(inFile, line))
        {
        if (line == "#END")
        {
            continue;
        }

        Elsheikh sheikh(line);
        while (getline(inFile, line) && line != "#END")
        {
            size_t firstComma = line.find(',');
            size_t secondComma = line.find(',', firstComma + 1);

            string surahName = line.substr(0, firstComma);
            string surahType = line.substr(firstComma + 1, secondComma - firstComma - 1);
            string surahPath = line.substr(secondComma + 1);
            Surah surah (surahName,surahType,surahPath) ;
            sheikh.addSurah(surah);
        }
        playlists.append(sheikh);
    }

    inFile.close();
    cout <<endl<< setw (89) <<"Playlists loaded from file successfully." << endl;
}
template class Playlist<Elsheikh>;
