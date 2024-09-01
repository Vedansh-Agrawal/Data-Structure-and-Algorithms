#ifndef MUSIC_PLAYER_H
#define MUSIC_PLAYER_H
#include "song.h"

typedef struct MusicPlayer
{
    Song *currentsong;
    Song *head; // header to first non playing song
} MusicPlayer;

MusicPlayer *createMusicPlayer(void);
int addSongToQueue(MusicPlayer *a, Song *song);
int removeSongFromQueue(MusicPlayer *a, int index);
int playSong(MusicPlayer *a);
Song *getCurrentSong(MusicPlayer *a);
#endif