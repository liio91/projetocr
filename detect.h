
/* detect.h*/

# include <stdlib.h>
# include <SDL.h>



void init_sdl(void);
SDL_Surface* display_image(SDL_Surface *img);
SDL_Surface* load_image(char *path);
void wait_for_keypressed(void);
