/*
    C-Dogs SDL
    A port of the legendary (and fun) action/arcade cdogs.
    Copyright (C) 1995 Ronny Wester
    Copyright (C) 2003 Jeremy Chin 
    Copyright (C) 2003-2007 Lucas Martin-King 

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

    This file incorporates work covered by the following copyright and
    permission notice:

    Copyright (c) 2013, Cong Xu
    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:

    Redistributions of source code must retain the above copyright notice, this
    list of conditions and the following disclaimer.
    Redistributions in binary form must reproduce the above copyright notice,
    this list of conditions and the following disclaimer in the documentation
    and/or other materials provided with the distribution.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
    AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
    ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
    LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
    CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
    INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
    CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
    ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
    POSSIBILITY OF SUCH DAMAGE.
*/
#ifndef __SOUNDS
#define __SOUNDS

#include <SDL_mixer.h>

#include "music.h"
#include "utils.h"

typedef enum
{
	SND_EXPLOSION,
	SND_LAUNCH,
	SND_MACHINEGUN,
	SND_FLAMER,
	SND_SHOTGUN,
	SND_POWERGUN,
	SND_SWITCH,
	SND_KILL,
	SND_KILL2,
	SND_KILL3,
	SND_KILL4,
	SND_HAHAHA,
	SND_BANG,
	SND_PICKUP,
	SND_DOOR,
	SND_DONE,
	SND_LASER,
	SND_MINIGUN,
	SND_COUNT
} sound_e;

typedef struct
{
	char name[81];
	int isLoaded;
	Mix_Chunk *data;
} SoundData;

typedef struct
{
	int isInitialised;
	int volume;
	int musicVolume;
	int channels;
	Mix_Music *music;
	music_status_e musicStatus;
	char musicErrorMessage[128];
	Vector2i earLeft;
	Vector2i earRight;
	SoundData sounds[SND_COUNT];
} SoundDevice;

extern SoundDevice gSoundDevice;

int SoundInitialize(void);
void SoundTerminate(int isWaitingUntilSoundsComplete);
void SoundPlay(SoundDevice *device, sound_e sound);
void SoundSetVolume(int volume);
int SoundGetVolume(void);
void SoundSetLeftEar(int x, int y);
void SoundSetRightEar(int x, int y);
void SoundSetEars(int x, int y);
void SoundPlayAt(sound_e sound, int x, int y);
void SoundSetChannels(int channels);
int SoundGetChannels(void);

#endif