#ifndef SOUND_H
#define SOUND_H

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL2/SDL_image.h>
#include <string>
#include<cstdio>
using namespace std;

class sound
{
	public:
		sound();//default constructor
		sound(string); //constructor that loads song
		void play(); //plays song
		void pause(); //pauses song, only works for music, not effects
		void stop(); // stops music
		void load(string); //loads song
	private:
		string filename; //name of song
		Mix_Chunk *effect; //file loaded
		Mix_Music *song; // file loaded
		int loaded; //says if song is loaded

};

#endif

sound::sound(){ //default constructor
        loaded = 0; //not loaded
        effect = NULL; //set variables to NULL
        song = NULL; //set variables to NULL

}

sound::sound(string music){
        loaded = 0; //loaded to zero
        effect = NULL; //sets variables to NULL
        song = NULL;
        load(music); //loads song into variable
}

void sound::play(){ //plays sound{
        if (song != NULL && Mix_PlayingMusic() == 0){
                Mix_PlayMusic(song,-1);
        }
        if (song != NULL && Mix_PlayingMusic() != 0 && Mix_PausedMusic() == 1){ //resumes music if paused{
                Mix_ResumeMusic();
        }
        if (effect != NULL){
                Mix_PlayChannel(-1, effect, 0); //play soundeffect
        }


}

void sound::pause(){ //pause music
        if (song != NULL && Mix_PlayingMusic() != 0 && Mix_PausedMusic() == 0){
                Mix_PauseMusic();
        }

}

void sound::stop(){
        Mix_HaltMusic(); //stop music from playing
}

void sound::load(string music){
        music = "images/"+music; //add file path

        if (loaded == 0){
        	song = Mix_LoadMUS(music.c_str()); // load music if coder specifies music type

                if (song == NULL){
                        cout << "error loading music " << music << Mix_GetError() << endl; //error thrown
                }
                loaded = 1;
        }

}
