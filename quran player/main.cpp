#include <iostream>
#include <iomanip>
#include <conio.h>
#include <windows.h>
#include <mmsystem.h>
#include "surah.h"
#include "doublylinkedlist.h"
#include "playlist.h"
#include "elsheikh.h"


using namespace std;

int main()
{
    Playlist <Elsheikh> Playlist ;
    int option ;
    while (true)
    {
        cout << setw(110) << "============================================================" << endl ;
        cout << setw(51) << "|" << setw(43) << "Quraan Playlist Manager Menu" << setw(16) << "|" << endl ;
        cout << setw(110) << "============================================================" << endl ;
        cout << setw(51) << "|" << setw(20) << "  1. Add a new playlist" << setw(36) << "|" << endl ;
        cout << setw(51) << "|" << setw(25) << "  2. Add Surah to an existing playlist" << setw(21) << "|" << endl ;
        cout << setw(51) << "|" << setw(25) << "  3. Remove Surah from an existing playlist" << setw(16) << "|" << endl ;
        cout << setw(51) << "|" << setw(25) << "  4. Update the order of existing playlist" << setw(17) << "|" << endl ;
        cout << setw(51) << "|" << setw(25) << "  5. Display all current playlist" << setw(26) << "|" << endl ;
        cout << setw(51) << "|" << setw(25) << "  6. Display all playlist Surah" << setw(28) << "|" << endl ;
        cout << setw(51) << "|" << setw(25) << "  7. Display Surah in aspecific playlist" << setw(19) << "|" << endl ;
        cout << setw(51) << "|" << setw(25) << "  8.Play Surah from specific playlist" << setw(22) << "|" << endl ;
        cout << setw(51) << "|" << setw(35) << "     Use left arrow (<-) to play the previous Surah" << setw(8) << "|" << endl ;
        cout << setw(51) << "|" << setw(35) << "     Use right arrow (->) to play the next surah" << setw(11) << "|" << endl ;
        cout << setw(51) << "|" << setw(35) << "     Use up arrow (^) to pause the current Surah" << setw(11) << "|" << endl ;
        cout << setw(51) << "|" << setw(35) << "     Use down arrow (v) to resume the current Surah" << setw(8) << "|" << endl ;
        cout << setw(51) << "|" << setw(25) << "  9. Save an existing playlist to a file" << setw(19) << "|" << endl ;
        cout << setw(51) << "|" << setw(25) << "  10. Load an existing playlist from a file" << setw(16) << "|" << endl ;
        cout << setw(51) << "|" << setw(25) << "  11. Remove an existing playlisy" << setw(26) << "|" << endl ;
        cout << setw(51) << "|" << setw(10) << "  12. Exit" << setw(49) << "|" << endl ;
        cout << setw(110) << "============================================================" << endl ;
        cout << setw(69) << endl << "Enter your option : " ;
        cin >> option ;



        switch (option)
        {
        case 1 :
        {
            Playlist.addPlaylist();
            getch() ;
            system("cls") ;
            break ;
        }
        case 2 :
        {
            int index ;
            Playlist.displayAllPlaylists() ;
            cout <<endl<< setw (83) << "Enter The Index of The playlist : " ;
            cin >> index ;
            Surah surah  ;
            surah . inputSurah() ;
            Playlist.addSurahToPlaylist(index-1,surah ) ;

            getch() ;
            system("cls") ;
            break ;
        }
        case 3 :
        {
            int index ;
            Playlist.displayAllPlaylists() ;
            cout <<endl<< setw (83) << "Enter The Index of The playlist : " ;
            cin >> index ;
            cout << endl ;
            Playlist.displaySurahsInPlaylist(index-1) ;
            string  surahName ;
            cout <<endl<< setw (80) << "Enter The Name Of The Surah : " ;
            cin >> surahName ;
            Playlist.removeSurahFromPlaylist(index - 1, surahName ) ;

            getch() ;
            system("cls") ;
            break ;
        }
        case 4 :
        {
           int plIndex , pos ;
           string surahName ;
            Playlist.displayAllPlaylists() ;
            cout << endl ;
            cout << setw(70) << "Enter The Index of The playlist : " ;
            cin >> plIndex ;
            cout << endl ;
            Playlist.displaySurahsInPlaylist(plIndex-1) ;
            cout << endl ;
            cout << setw(70) << "Enter The Name of The Surah : " ;
            cin >> surahName ;
            cout << endl ;
            cout << setw(70) << "Enter The New Position : " ;
            cin >> pos ;
            cout << endl ;
            Playlist.Update_Suhrah_pos(plIndex - 1 , surahName , pos - 1) ;
            getch() ;
            system("cls") ;
            break ;

        }
        case 5 :
        {
            Playlist.displayAllPlaylists();
            getch() ;
            system("cls") ;
            break ;
        }
        case 6 :
        {
            Playlist.display_all_playlists_with_surahs(Playlist) ;
            getch() ;
            system("cls") ;
            break ;
        }
        case 7 :
        {
            Playlist.displayAllPlaylists();
            int index ;
            cout <<endl<< setw (83) << "Enter The Index of The playlist : " ;
            cin >> index ;
            Playlist.displaySurahsInPlaylist(index-1) ;
            getch() ;
            system("cls") ;
            break ;
        }
        case 8 :
        {
            Playlist.play_track();
            getch() ;
            system("cls") ;
            break ;
        }
        case 9 :
        {
            string filename = "Playlist-File.txt" ;
            Playlist.saveToFile("Playlist-File.txt") ;
            getch() ;
            system("cls") ;
            break ;
        }
        case 10 :
        {
            string filename = "Playlist-File.txt" ;
            Playlist.loadFromFile("Playlist-File.txt") ;
            getch() ;
            system("cls") ;
            break ;
        }
        case 11 :
        {
            Playlist.displayAllPlaylists();
            int index ;
            cout <<endl<< setw (83) << "Enter The Index of The playlist : " ;
            cin >> index ;
            Playlist.removePlaylist(index-1);
            getch() ;
            system("cls") ;
            break ;
        }
        case 12 :
        {
            return 0 ;
        }
        default :
        {
            cout << endl << setw(100) << "Invalid Input , Please Enter Number (From 1 To 12)." << endl << endl ;
            getch() ;
            system("cls") ;
        }

        }
    }


    return 0;
}
