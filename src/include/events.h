/*
    C-Dogs SDL
    A port of the legendary (and fun) action/arcade cdogs.
    Copyright (C) 1995 Ronny Webster
    Copyright (C) 2003 Jeremy Chin 
    Copyright (C) 2003 Lucas Martin-King 

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

-------------------------------------------------------------------------------

 events.h - <description here>
 
 Author: $Author$
 Rev:    $Revision$
 URL:    $HeadURL$
 ID:     $Id$
 
*/



struct MouseRect {
	int left, top, right, bottom;
	int tag;
};


void InitMouse(void);
void Mouse(int *x, int *y, int *button);
int GetKey(void);
void SetMouseRects(struct MouseRect *rects);
void SetSecondaryMouseRects(struct MouseRect *rects);
int GetMouseRectTag(int x, int y, int *tag);

#define EVENT_QUIT	SDL_QUITMASK
int IsEventPending (unsigned int m);
