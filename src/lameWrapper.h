#ifndef LAMEWRAPPER_H
#define LAMEWRAPPER_H

#include <lame.h>

using namespace std;

/* ENUM to hold standard Bitrate values. Only 128,160,192,256,320Kbps*/
typedef enum{
    BR_128 = 128,
    BR_160 = 160,
    BR_192 = 192,
    BR_256 = 256,
    BR_360 = 360
}bitrate;

/* ENUM to hold standard Samplerate values. Only 8,12,24,32,44kHz*/
typedef enum{
    SR_8 = 8000,
    SR_12 = 12000,
    SR_24 = 24000,
    SR_32 = 32000,
    SR_44 = 44100
}samplerate;

/* Structure to hold the settings of a MP3 Files*/
struct settings_t{
    const char* title;
    const char* artist;
    const char* album;
    const char* description;
    const char* year;
    const char* track;
    const char* genre;

    samplerate samp_freq;
    bitrate br;

    settings_t();
};

/* Wrapper class which could be called from the main function*/
class lameWrapper{
    
    static const int PCM_SIZE = 4096;
    static const int MP3_SIZE = 4096;
    settings_t settings;
    int encoder(char* mp3_in, settings_t set);
    char* pcm_in;
public:
    lameWrapper(char* in);
    ~lameWrapper();

    
    int encode();

};



#endif