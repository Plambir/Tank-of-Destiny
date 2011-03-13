#include <SDL/SDL.h>

SDL_Surface*
SDL_SetVideoMode(int width, int height, int bitsperpixel, Uint32 flags)
{
  (void)width;
  (void)height;
  (void)bitsperpixel;
  (void)flags;

  return (SDL_Surface*)1;
}
