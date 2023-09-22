
#pragma once
#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include "main.h"
#include <stdbool.h>

#define WIDTH 720
#define HEIGHT 720

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Surface* surface;
SDL_Texture* texture;
SDL_Texture* tImage;
SDL_Rect box1, box2, collision_pic;

// function declaration
bool init_sdl();
void sdl_Window();
void sdl_Render();
void handle_inputs();
void update_Sdl();



// box function declaration
void boxIntersect_pic();
void object1();
void object2();
SDL_Texture* load_image(const char *filaname, SDL_Renderer* ren);
void render_box();

bool collision_detection();
