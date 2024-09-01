#ifndef SONG_H
#define SONG_H

typedef struct Song
{
    char *name;
    char *artist;
    float duration;
    struct Song *prev;
    struct Song *next;
} Song;

Song *makeSong(char *name, char *artist, float duration);

#endif