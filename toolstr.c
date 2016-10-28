
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <math.h>
#include "pixel.h"
#include <err.h>
#include "toolstr.h"



void initPoint(struct Point *point)
{
  point->x = 0;
  point->y = 0;
}


void initBlock(struct Block *block)
{
  initPoint(&block->origin);
  block->width = 0;
  block->height = 0;
};

void initSymbol(struct Symbol *symbol)
{
  initPoint(&symbol->origin);
  symbol->width = 0;
  symbol->height = 0;
}

struct Vector *make_vector()
{
  struct Vector *vect = malloc(sizeof(struct Vector));
  vect->capacity_b = 1;
  vect->size_b = 0;
  vect->block = malloc(sizeof(struct Block));
  vect->capacity_l = 1;
  vect->size_l = 0;
  vect->capacity_s = 1;
  vect->size_s = 0;
  vect->symbol = malloc(sizeof(struct Symbol));
  return vect;
}

int main()
{
}
