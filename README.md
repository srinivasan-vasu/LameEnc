# LameEnc

C++ Cross Platform Windows and Linux Mp3 Encoder using Lame Aint. Information on Lame available at https://lame.sourceforge.io/

## Features
1. Cross Platform using cmake.
2. Only limited encoding settings enabled and tags are not updated yet.
3. Multithreading using Threadpool
4. Read all *.wav files in a folder and create correponding *.mp3 files in the same folder
5. Portable - lame is linked using static library on both platforms
6. No exceptions defined so might have bugs and not tested for those conditions

## Build Instructions
1. Linux:
- >>mkdir build && cd build
- >>cmake ..
- >>make
- >>./lameenc folder-path

2. Windows (x86 Debug Configuration)
- Use MS Visual Studio x86 configuration and build all.
- In command prompt, 
- >>"lameenc.exe folder-path"

## Libraries Used
Lame libraries are used by static link. Please check for lame.h for the LAME API.

## Additional Instruction
For changing Bitrate and Samplerate modify the struct settings_t::settings_t() in lameWrapper.cpp. Only limited options defined. Please check lameWrapper.h for available Samplerates and Bit rates. 

# References
I have used many available online contents including other github repositories. Follwing are the works that are the main references:
- https://github.com/eel76/wav2mp3
- https://github.com/antonl1911/encode