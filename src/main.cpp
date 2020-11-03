/*
A simple Wav to MP3 encoder which uses Lame Encoder Package as a static Library. 

1. Uses a simple wrapper function that calls the lame API for conversion.

2. Only limited settings available for conversion at the moment. No user input option for 
changing the settings. Also Tags are also not updated as the struct corresponding to update Tags
are not implemented.

3. Can be used for cross platform Windows and LINUX based system. In Windows, in case of using
MS Visual Studio, please use x86 Configuraion.

4. Read all *.wav files in a folder and convert them to *.mp3 files.

5. Not Error free - No exceptions defined as of now. So could throw some errors and not tested 
for those conditions. They are for the future Improvements.

6. Not fully developed. Please look into lame.h for all the functions and also decoding options.

Build & Run the Application:
Windows: 
1. Use MS Visual Studio x86 configuration and build all.
2. In command prompt, "lameenc.exe folder-path"

LINUX:(In terminal)
>>mkdir build && cd build
>>cmake ..
>>make
>>./lameenc folder-path

*/
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <lame.h>
#include <vector>
#include <chrono>
#include "lameWrapper.h"
#include "threadpool.h"

#ifdef __linux__
#include <dirent.h>
#elif _WIN32
#include "Windows.h"
#endif

using namespace std;
chrono::steady_clock::time_point beg;

#ifdef __linux__
/* Function to read the directory for Wav Files*/
vector<string> readFile(const char* loc) {
    vector<string> in_files;
    DIR* dirFile = opendir(loc);
    if (dirFile) {
        struct dirent* hFile;
        while ((hFile = readdir(dirFile)) != NULL) {
            string s = loc;
            if (strstr(hFile->d_name, ".wav")) {
                s.append(hFile->d_name);
                in_files.push_back(s);
            }
        }
        closedir(dirFile);
    }

    return in_files;
}
#elif _WIN32
vector<string> readFile(const char* loc) {
    vector<string> in_files;
    string search_path = loc + std::string("*.wav");
    WIN32_FIND_DATA fd;
    HANDLE hFind = ::FindFirstFile(search_path.c_str(), &fd);
    if (hFind != INVALID_HANDLE_VALUE) {
        do {
            string s = string(loc);
            if (!(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
                s.append(fd.cFileName);
                in_files.push_back(s);
            }
        } while (::FindNextFile(hFind, &fd));
        
        ::FindClose(hFind);
    }

    return in_files;
}
#endif

/* Process function which calls encode through Wrapper Class*/
void process(string s) {

    char* pcm_in = const_cast<char*>(s.c_str());
    lameWrapper lw(pcm_in);
    lw.encode();
}

int main(int argc, char* argv[]) {
    beg = chrono::steady_clock::now();
    const char* dir = argv[1];
    vector<string> in_files = readFile(dir);

    std::size_t hardware_conc = thread::hardware_concurrency();
    cout << "No of threads available " << hardware_conc << endl;
    std::size_t thread_count = min(hardware_conc, in_files.size());
    threadpool tp(thread_count);
    cout << "File in Process" << endl;

    for (auto i : in_files) {
        tp.enqueue([=] {
            process(i);
            });
    }


    return 0;

}
