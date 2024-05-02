/*A Music Library System is a software application used to manage the storage and retrieval of Music 
tracks and albums. Hash tables can be used as a data structure to efficiently store and retrieve Music track 
and album information*/
#include<iostream>
#include<string>

#define MAX 7

using namespace std;

class Music {
public:
    string artist;
    string album;
    string track;
    int music_no; // New attribute for music number

    Music() {}

    Music(string a, string b, string c, int no) {
        artist = a;
        album = b;
        track = c;
        music_no = no;
    }
};


class Hash {
public:
    Music data;
    Hash* next;
    Hash* ht[MAX];

    Hash() {
        for (int i = 0; i < MAX; i++) {
            ht[i] = NULL;
        }
    }

    void insert();
    void display();
};

void Hash::insert() {
    string artist, album, track;
    int music_no;
    cout << "\nEnter Artist Name: ";
    cin >> artist;
    cout << "Enter Album Name: ";
    cin >> album;
    cout << "Enter Track Name: ";
    cin >> track;
    cout << "Enter Music Number: ";
    cin >> music_no;

    Music m(artist, album, track, music_no);

    int addr = m.music_no % MAX;
    Hash* temp = new Hash;
    temp->data = m;
    temp->next = NULL;

    if (ht[addr] == NULL) {
        ht[addr] = temp;
    }
    else {
        Hash* ptr = ht[addr];
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}

void Hash::display() {
    cout << "HASH TABLE\n";
    cout << "Index\t" << "Artist\t" << "Album\t" << "Track\n";
    for (int i = 0; i < MAX; i++) {
        Hash* ptr = ht[i];
        cout << i << "::\t";
        while (ptr != NULL) {
            cout << ptr->data.artist << "\t" << ptr->data.album << "\t" << ptr->data.track << endl;
            ptr = ptr->next;
        }
    }
}

int main() {
    Hash h;
    int choice;
    char press;
    do {
        cout << "\nMenu:\n1. Insert\n2. Display\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            h.insert();
            break;
        case 2:
            h.display();
            break;
        }
        cout<<"\nDo you want to continue: ";
        cin>>press;
    } while (press=='y'||press=='Y');
}
