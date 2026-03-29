#include <iostream>
using namespace std;

class Movie {
    string title;
    string director;
    int duration;
    public:
        Movie(const string& _title, const string& _director, int _duration) {
            title = _title;
            director = _director;
            duration = _duration;
        }
        string getTitle () const {
            return title;
        }
        string getDirector() const {
            return director;
        }
        int getDuration() const {
            return duration;
        }
};

class Playlist {
    string name;
    Movie* movies[10];
    int numMovies=0;

    public:
        Playlist(const string& _name) : name(_name) {}
        void addMovies(Movie* movie) {
            if (numMovies < 10) {
                movies[numMovies++] = movie;
            }
            else cout << "Error\n";
        }
        void removeMovies(Movie* movie) {
            if (numMovies > 0) {
                for (int i=0; i<numMovies; i++) {
                    if (movies[i] == movie) {
                        for (int j=i+1; j<numMovies; j++) {
                            movies[j-1] = movies[j];
                        }
                        numMovies--;
                    }
                    
                }
            }
            else cout << "Error\n";
        }
        void displayInfo () {
            cout << "Playlist name: " << name;
            if (numMovies==0) cout << "No movies found!\n";
            else {
                for (int i=0; i<numMovies; i++) {
                    cout << movies[i]->getTitle() << " " << movies[i]->getDirector() << " " << movies[i]->getDuration() << endl;
                }
            }
        }
};

class User {
    string name;
    Playlist* playlists[10];
    int numPlaylists=0;
    public:
        // Playlist* getPlaylist(int index) {
        //     return playlists[index];
        // }
        User (const string& _name) : name (_name) {}
        Playlist* createPlaylist(const string& playlistName) {
            if (numPlaylists < 10) {
                playlists[numPlaylists] = new Playlist(playlistName);
                return playlists[numPlaylists++];
            }
            else cout << "Error\n";
            return nullptr;    
        }
        void AddMovieToPlaylist (Playlist* playlist, Movie* movie) {
            for (int i=0; i<numPlaylists; i++) {
                if (playlist == playlists[i]) {
                    playlists[i]->addMovies(movie);
                }
            }
        }
        void RemoveMovieToPlaylist (Playlist* playlist, Movie* movie) {
            for (int i=0; i<numPlaylists; i++) {
                if (playlist == playlists[i]) {
                    playlists[i]->removeMovies(movie);
                }
            }
        }
        void displayUserPlaylist() {
            cout << "Name: " << name;
            for (int i=0; i<numPlaylists; i++) {
                cout << "Playlist: " << i+1;
                playlists[i]->displayInfo();
            }
        }
};

int main () {
    User u("Mujeeb Rehman");
    //Playlist* p1 = u.getPlaylist(0);
    Movie m1("The Dark Knight", "Chritphper Nolan", 2);
    Movie m2("Inception", "Chritopher Nolan", 2);
    // p1.addMovies(&m1);
    // p1.addMovies(&m2);
    //Playlist* p2=u.getPlaylist(1);
    Movie m3("The Hangover", "Todd Phillips", 2);
    Movie m4("Superbad", "Greg Mottola", 2);
    // p2.addMovies(&m3);
    // p2.addMovies(&m4);
    //p1.addMovies("")
    Playlist* p1 = u.createPlaylist("Action Movies");
    Playlist* p2 = u.createPlaylist("Comedy Movies");

    u.AddMovieToPlaylist(p1, &m1);
    u.AddMovieToPlaylist(p1, &m2);
    u.AddMovieToPlaylist(p2, &m3);
    u.AddMovieToPlaylist(p2, &m4);
    u.displayUserPlaylist();
    u.RemoveMovieToPlaylist(p1, &m2);
    u.displayUserPlaylist();
}