
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <math.h>
#include "pixel.h"
# include <err.h>
#include "detect.h"

/* Charger l'image */



void init_sdl(void) {
  // Init only the video part
  if( SDL_Init(SDL_INIT_VIDEO)==-1 ) {
    // If it fails, die with an error message
    errx(1,"Could not initialize SDL: %s.\n", SDL_GetError());
  }
  // We don't really need a function for that ...
}

void wait_for_keypressed(void) {
  SDL_Event             event;
  // Infinite loop, waiting for event
  for (;;) {
    // Take an event
    SDL_PollEvent( &event );
    // Switch on event type
    switch (event.type) {
    // Someone pressed a key -> leave the function
    case SDL_KEYDOWN: return;
    default: break;
    }
  // Loop until we got the expected event
  }
}

/*

SDL_Surface* load_image(char *path) {
  SDL_Surface          *img;
  // Load an image using SDL_image with format detection
  img = IMG_Load(path);
  if (!img)
    // If it fails, die with an error message
    errx(3, "can't load %s: %s", path, IMG_GetError());
  return img;
}
*/

SDL_Surface* display_image(SDL_Surface *img) {
  SDL_Surface          *screen;
  // Set the window to the same size as the image
  screen = SDL_SetVideoMode(img->w, img->h, 0, SDL_SWSURFACE|SDL_ANYFORMAT);
  if ( screen == NULL ) {
    // error management
    errx(1, "Couldn't set %dx%d video mode: %s\n",
         img->w, img->h, SDL_GetError());
  }
 
  /* Blit onto the screen surface */
  if(SDL_BlitSurface(img, NULL, screen, NULL) < 0)
    warnx("BlitSurface error: %s\n", SDL_GetError());
 
  // Update the screen
  SDL_UpdateRect(screen, 0, 0, img->w, img->h);
 
  // wait for a key
  wait_for_keypressed();
 
  // return the screen for further uses
  return screen;
}


SDL_Surface *load_image(char *filename)
{
  SDL_Surface *loadedImage;
  SDL_Surface *optimizedImage;

  loadedImage = NULL;
  optimizedImage = NULL;
  loadedImage = SDL_LoadBMP(filename);
  if (loadedImage != NULL)
    {
      optimizedImage = SDL_DisplayFormat(loadedImage);
      SDL_FreeSurface(loadedImage);
    }
  return (optimizedImage);
}
/*

void trace_boxline(SDL_Surface *image, t_line_set *linelist)
{
  t_line_set *tmp;
  Uint32 cl;


  cl = SDL_MapRGB(image->format, 0x00, 0x00, 0x00);
  draw_line(0, 230, 3, 23, cl, image);
  tmp = linelist;
  while (tmp != NULL)
    {
      draw_line(0, tmp->pos, image->w, 1, cl, image);
      draw_line(0, (tmp->pos + tmp->height), image->w, 1, cl, image);
      tmp = tmp->next;
    }
}

*/

/*
SDL_Surface detect_block(SDL_Surface *image)
{
  for (int i = 5; i < screen->w; i += 5){
  
    for (int j = 5; j < screen->h; j += 5)
      {
	
      }
}

*/
int main()
{

  // affiche une image (+4 lignes)
  
  SDL_Surface *imagefond = NULL;
  init_sdl();
  imagefond = SDL_LoadBMP("Lorem-Droid.bmp");
  display_image(imagefond);
  return EXIT_SUCCESS;
}
