#ifndef LAMEWRAPPER_CPP
#define LAMEWRAPPER_CPP

#include <iostream>
#include <stdio.h>
#include "lameWrapper.h"
using namespace std;

/* Set the default settings for MP3 File*/
settings_t::settings_t(){
    title = "";
    artist = "";
    album = "";
    description = "";
    year = "";
    track = "";
    genre = "";

    samp_freq = SR_44;
    br = BR_128;
}

lameWrapper::lameWrapper(char* in){
    this->pcm_in = in;
    cout << in << endl;
}

lameWrapper::~lameWrapper(){
    //
}

int lameWrapper::encode(){
    settings_t set;
    string in = this->pcm_in;
    string out = in.substr(0, in.length()-3);
    out.append("mp3");

    char* mp3_in = const_cast<char *>(out.c_str());
    
    return encoder(mp3_in, set);
}

/* Encoder Function to convert wav to mp3.*/
int lameWrapper::encoder(char* mp3_in, settings_t set){
    
    lame_global_flags* lgf = NULL;
    lgf = lame_init();

    //Init ID3 tag
    id3tag_init(lgf);
    id3tag_v2_only(lgf);
    id3tag_set_album(lgf, set.album);
    id3tag_set_artist(lgf, set.artist);
    id3tag_set_comment(lgf, set.description);
    id3tag_set_genre(lgf, set.genre);
    id3tag_set_title(lgf, set.title);
    id3tag_set_track(lgf, set.track);
    id3tag_set_year(lgf, set.year);

    /* Set Sample frequency*/
    lame_set_out_samplerate(lgf, set.samp_freq); 

    if(lame_init_params(lgf) == -1){
        cout << "Error Occured" << endl;
        return -2;
    }else{
        int read{0}, write{0};
        long pcm_in_size{0};

        short int pcm_buf[PCM_SIZE*2];
        unsigned char mp3_buf[MP3_SIZE];

        
        FILE *pcm = fopen(pcm_in, "rb");
        FILE *mp3 = fopen(mp3_in, "wb");


        /* Error check PCM file*/
        if(pcm == NULL){
            cout << "PCM file is Null. Error Occured" << endl;
            return -1;
        }
        //Set the position to end
        fseek(pcm, 0, SEEK_END);
        pcm_in_size = ftell(pcm);
        fseek(pcm, 0, SEEK_SET);

        /* Error check MP3 file*/
        if(mp3 == NULL){
            cout << "MP3 file is Null. Error Occured" << endl;
            return -1;
        }

        unsigned char* buffer = new unsigned char[LAME_MAXMP3BUFFER];
        int imp3 = lame_get_id3v2_tag(lgf, buffer, LAME_MAXMP3BUFFER);
        fwrite(buffer, sizeof(char), imp3, mp3);
        long audio_pos = ftell(mp3);

        do{
            read = fread(pcm_buf, 2*sizeof(short int), PCM_SIZE, pcm);
            if(read == 0){
                write = lame_encode_flush(lgf, mp3_buf, MP3_SIZE);
            }else{
                write = lame_encode_buffer_interleaved(lgf, pcm_buf,read, mp3_buf, MP3_SIZE);
            }
            fwrite(mp3_buf, write, sizeof(char), mp3);

        }while(read != 0);

        imp3 = lame_get_id3v1_tag(lgf, buffer, LAME_MAXMP3BUFFER);
        fwrite(buffer, sizeof(char), imp3, mp3);

        imp3 = lame_get_lametag_frame(lgf, buffer, LAME_MAXMP3BUFFER);
        if(fseek(mp3, audio_pos, SEEK_SET) != 0){
            //Error
        }
        fwrite(buffer, sizeof(char), imp3, mp3);

        delete[] buffer;

        fclose(mp3);
        fclose(pcm);

    }
    
    lame_close(lgf);

    return 0;
}


#endif