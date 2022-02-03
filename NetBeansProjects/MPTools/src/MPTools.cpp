/**
 * @file mptools
 */
#include <cstring>
#include <string>
#include <fstream>
#include "MPTools.h"

#define A 54059 /* a prime */
#define B 76963 /* another prime */
#define C 86969 /* yet another prime */
#define FIRSTH 37 /* also prime */

using namespace std;

unsigned mphash(const unsigned char * s, int size) {
    unsigned h = FIRSTH;
    while (size > 0) {
        h = (h * A) ^ (s[0] * B);
        s++;
        size--;
    }
    return h;
}

bool mpSavePGMImage(std::string filename, const unsigned char *buffer, int width, int height) {
    ofstream f;
    f.open(filename.c_str(), ios::binary);
    if (!f)
        return false;
    f << "P5" << endl;
    f << width << ' ' << height << endl;
    f << 255 << endl;
    f.write((const char *) buffer, width * height);
    f.close();
    return true;
}


#ifdef __WINDOWS__

void mpDisplayImage(string filename, string windowtitle) {
    string fullpath = filename;

    string realpath = fullpath;
    realpath[realpath.length() - 3] = 'p';
    realpath[realpath.length() - 2] = 'n';
    realpath[realpath.length() - 1] = 'g';
    string command = "convert " + fullpath + " " + realpath;
    //    system(command.c_str());
    command = command + " && " + "explorer " + realpath;
    system(command.c_str());
}

#else

void mpDisplayImage(string filename, string windowtitle) {
    string fullpath = filename;
    string command = "display -title " + windowtitle + " " + fullpath + " &";
    FILE *fp;
    fp = popen(command.c_str(), "r");
    pclose(fp);
}

#endif

