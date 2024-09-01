#include "song.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

Song *makeSong(char *name, char *artist, float duration)
{
    Song *a;
    a = (Song *)malloc(sizeof(Song));
    assert(a != NULL);
    a->name = (char *)malloc(100 * sizeof(char));
    a->name = name;
    a->artist = (char *)malloc(100 * sizeof(char));
    a->artist = artist;
    a->duration = duration;
    a->next = NULL;
    a->prev = NULL;

    return a;
}