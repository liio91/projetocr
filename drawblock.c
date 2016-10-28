#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>

#include "toolstr.h"

void blockDetection(SDL_Surface *screen, struct Vector *vect)
{
  for (int i = 5; i < screen->w; i += 5)
  {
    for (int j = 5; j < screen->h; j += 5)
    {
      if (getPixel(screen, i, j) == SDL_MapRGB(screen->format, 0, 0, 0))
      {
        int canBeCreated = 1;
        for (int k = 0; k < vect->size_b; k++)
        {
          struct Block *tmp = &vect->block[k];
          if (i >= tmp->origin.x &&
                i <= tmp->origin.x + tmp->width &&
                j >= tmp->origin.y && j <= tmp->origin.y + tmp->height)
          {
            canBeCreated = 0;
          }
        }

        if (canBeCreated)
        {
          struct Block *new = malloc(sizeof(struct Block));
          initBlock(new);
          new->origin.x = i;
          new->origin.y = j;
          createBlock(screen, new);
          vector_push_back_b(vect, new);
        }
      }  
    }
  }

  for (int i = 0; i < vect->size_b; i++)
  {
    drawBlockBorders(screen, &vect->block[i]);
  }
}

void createBlock(SDL_Surface *screen, struct Block *block)
{
  int size = 8;
  searchUpperBorder(screen, block, size);
  searchLeftBorder(screen, block, size);
  searchBottomBorder(screen, block, size);
  searchRightBorder(screen, block, size);
}

void searchUpperBorder(SDL_Surface *screen, struct Block *block, int size)
{
  int found = 0;
  for (int j = block->origin.y - 1; j >= block->origin.y - size; j--)
    for (int i = block->origin.x; i < block->origin.x +block->width + size;i++)
      if (j > 0 && i > 0)
        if (!found &&getPixel(screen, i, j) ==SDL_MapRGB(screen->format,0,0,0))
        {
          if (block->origin.y - size < 0)
            block->origin.y = 0;
          else
            block->origin.y -= size;
          block->height += size;
          createBlock(screen, block);
          found = 1;
        }
}

void searchLeftBorder(SDL_Surface *screen, struct Block *block, int size)
{
  int found = 0;
  for (int i = block->origin.x - 1; i >= block->origin.x - size; i--)
    for (int j = block->origin.y; j<block->origin.y + block->height + size;j++)
      if (j > 0 && i > 0)
        if (!found && getPixel(screen, i, j) ==
            SDL_MapRGB(screen->format, 0, 0, 0))
        {
          if (block->origin.x - size < 0)
            block->origin.x = 0;
          else
            block->origin.x -= size;
          block->width += size;
          createBlock(screen, block);
          found = 1;
        }
}

void searchBottomBorder(SDL_Surface *screen, struct Block *block, int size)
{
  int found = 0;
  for (int j = block->origin.y + block->height + 1;
      j <= block->origin.y + block->height + size; j++)
    for (int i = block->origin.x; i < block->origin.x +block->width +size; i++)
      if (j < screen->h && i < screen->w)
        if (!found &&getPixel(screen, i, j) ==SDL_MapRGB(screen->format,0,0,0))
        {
          block->height += size;
          createBlock(screen, block);
          found = 1;
        }

}

void searchRightBorder(SDL_Surface *screen, struct Block *block, int size)
{
  int found = 0;
  for (int i = block->origin.x + block->width + 1;
      i <= block->origin.x + block->width + size; i++)
    for (int j = block->origin.y; j<block->origin.y +block->height + size; j++)
      if (j < screen->h && i < screen->w)
        if (!found &&getPixel(screen, i, j) ==SDL_MapRGB(screen->format,0,0,0))
        {
          block->width += size;
          createBlock(screen, block);
          found = 1;
        }
}#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>

#include "toolstr.h"


void blockdetect (SDL_Surface *scrren, int n)

for (int i = 0;i < screen->w; i += 1)
  {
    for (int j = 0;j<screen->h;j+=1)
      {
	
      }
  }


void draw_line(int x, int y, int w,int h, Uint32 color,
	       SDL_Surface* surface)
{
  SDL_Rect r;

  r.x = x;
  r.y = y;
  r.w = w;
  r.h = h;
  SDL_FillRect(surface, &r, color);
}
