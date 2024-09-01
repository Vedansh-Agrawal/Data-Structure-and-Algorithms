#include "musicplayer.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

Song *tail = NULL;

MusicPlayer *createMusicPlayer(void)
{
    MusicPlayer *a;
    a = (MusicPlayer *)malloc(sizeof(MusicPlayer));
    a->currentsong = NULL;
    a->head = NULL;
    return a;
}
int addSongToQueue(MusicPlayer *a, Song *song)
{
    if (tail == NULL || a->head == NULL)
    {
        a->head = song;
        tail = song;
        return 0;
    }
    else
    {
        song->prev = tail;
        tail->next = song;
        tail = song;
        return 0;
    }
    return 1;
}
int removeSongFromQueue(MusicPlayer *a, int index)
{
    if (a->head == NULL)
    {
        return 1;
    }
    int i = 0;
    Song *S;
    for (S = a->head; S != NULL; S = S->next)
    {
        i++;
    }
    if (index >= i)
    {
        return 1;
    }
    S = a->head;
    if (index != 0)
    {
        for (int j = 0; j < index; j++)
        {
            S = S->next;
        }
        S->prev->next = S->next;
        if (S->next != NULL)
        {
            S->next->prev = S->prev;
        }

        return 0;
    }
    if (index == 0)
    {
        Song *S = a->head;
        a->head = a->head->next;
        if (S->next != NULL)
        {
            S->next->prev = S->prev;
            return 0;
        }
        else
        {
            a->head = NULL;
            tail = NULL;
            return 0;
        }
    }
    return 1;
}
int playSong(MusicPlayer *a)
{
    if (a->head == NULL)
    {
        return 1;
    }


    if (a->currentsong == NULL)
    {
        a->currentsong = a->head;
        a->head = a->head->next;
        return 0;
    }

    else
    {
        a->currentsong = a->head;
        a->head = a->head->next;
        return 0;
    }
    
    return 1;
}
Song *getCurrentSong(MusicPlayer *a)
{
    return a->currentsong;
}