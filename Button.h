/* 
 * File:   Button.h
 * Author: zach
 *
 * Created on March 5, 2009, 3:48 PM
 */

#ifndef _BUTTON_H
#define	_BUTTON_H
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <string>
#include "ResourceManager.h"

template<typename Class, typename returntype, typename parameter>
class Button {
public:
  typedef returntype (Class::*Method)(parameter);

  Button(std::string text,int x, int y,Class* _s, Method m, parameter _param){
      _class = _s;
      method = m;
      param = _param;
      upImage = ResourceManager::INSTANCE()->loadImage("resources/images/buttonup.png");
      downImage = ResourceManager::INSTANCE()->loadImage("resources/images/buttondown.png");
      currImage = downImage;    
      offset.x = x;
      offset.y = y;
      invokeTrigger = false;
      TTF_Font *font = TTF_OpenFont("resources/fonts/Acidic.ttf", 28);
      SDL_Color textColor = {0,0,0}; 
      label = TTF_RenderText_Solid(font, text.c_str(), textColor); 
      lblOffset.x = x+40;
      lblOffset.y = y+2;
  }

  void trigger(parameter param) {
      (_class->*method)(param);
  }
  
  void up(){
      currImage = upImage;
      if(invokeTrigger){
          trigger(param);
      }
      invokeTrigger = false;
  }
  
  void down(){
      invokeTrigger = true;
      currImage = downImage;
  }
  
  void update(){
      SDL_PumpEvents();
      SDL_GetMouseState(&mouse_x,&mouse_y);
      if(mouse_x > offset.x && mouse_x < offset.x+100 &&
         mouse_y > offset.y && mouse_y < offset.y+25 &&
         SDL_GetMouseState(NULL, NULL)&SDL_BUTTON(1)){
          down();
      } else {
          up();
      }   
  }
  
  void render(SDL_Surface* screen){
       SDL_BlitSurface(currImage, NULL, screen, &offset);
       SDL_BlitSurface(label, NULL, screen, &lblOffset);
  }
  
   ~Button(){
       TTF_CloseFont(font);
       SDL_FreeSurface(upImage); 
       SDL_FreeSurface(downImage);
       SDL_FreeSurface(currImage);
       SDL_FreeSurface(label);
  }
  private:
    Class* _class;
    Method method;
    parameter param;
    SDL_Surface* upImage;
    SDL_Surface* downImage;
    SDL_Surface* currImage;
    SDL_Rect offset;
    SDL_Rect lblOffset;
    bool invokeTrigger;
    int mouse_x,mouse_y;
    TTF_Font* font;
    SDL_Surface* label;
   
};

#endif	/* _BUTTON_H */

