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

std::string toUTF(char in) {
    string s = string(in, 1);
    return toUTF(s.c_str());
}

std::string toUTF(const std::string & in) {
    return toUTF(in.c_str());
}

std::string toUTF(const char * i) {
    const unsigned char *in = (unsigned char*) i;
    string res = "";
    if (isUTF8(i)) {
        res = i;
    } else {
        while (*in)
            if (*in < 128) res.append(1, static_cast<char> (*in++));
            else res.append(1, static_cast<char> (0xc2 + (*in > 0xbf))), res.append(1, static_cast<char> ((*in++&0x3f) + 0x80)); //    string out;
    }
    return res;
}

std::string toISO(const char * in) {
    string res = "";
    if (!isUTF8(in)) {
        res = in;
    } else {
        unsigned int codepoint;
        while (*in != 0) {
            unsigned char ch = static_cast<unsigned char> (*in);
            if (ch <= 0x7f)
                codepoint = ch;
            else if (ch <= 0xbf)
                codepoint = (codepoint << 6) | (ch & 0x3f);
            else if (ch <= 0xdf)
                codepoint = ch & 0x1f;
            else if (ch <= 0xef)
                codepoint = ch & 0x0f;
            else
                codepoint = ch & 0x07;
            ++in;
            if (((*in & 0xc0) != 0x80) && (codepoint <= 0x10ffff)) {
                if (codepoint <= 255) {
                    res.append(1, static_cast<char> (codepoint));
                } else {
                    // do whatever you want for res-of-bounds characters
                }
            }
        }
    }
    return res;
}

std::string toISO(const string &s) {
    return toISO(s.c_str());
}

bool isUTF8(const char * string) {
    if (!string)
        return false;

    const unsigned char * bytes = (const unsigned char *) string;
    while (*bytes) {
        if ((// ASCII
                // use bytes[0] <= 0x7F to allow ASCII control characters
                bytes[0] == 0x09 ||
                bytes[0] == 0x0A ||
                bytes[0] == 0x0D ||
                (0x20 <= bytes[0] && bytes[0] <= 0x7E)
                )
                ) {
            bytes += 1;
            continue;
        }

        if ((// non-overlong 2-byte
                (0xC2 <= bytes[0] && bytes[0] <= 0xDF) &&
                (0x80 <= bytes[1] && bytes[1] <= 0xBF)
                )
                ) {
            bytes += 2;
            continue;
        }

        if ((// excluding overlongs
                bytes[0] == 0xE0 &&
                (0xA0 <= bytes[1] && bytes[1] <= 0xBF) &&
                (0x80 <= bytes[2] && bytes[2] <= 0xBF)
                ) ||
                (// straight 3-byte
                ((0xE1 <= bytes[0] && bytes[0] <= 0xEC) ||
                bytes[0] == 0xEE ||
                bytes[0] == 0xEF) &&
                (0x80 <= bytes[1] && bytes[1] <= 0xBF) &&
                (0x80 <= bytes[2] && bytes[2] <= 0xBF)
                ) ||
                (// excluding surrogates
                bytes[0] == 0xED &&
                (0x80 <= bytes[1] && bytes[1] <= 0x9F) &&
                (0x80 <= bytes[2] && bytes[2] <= 0xBF)
                )
                ) {
            bytes += 3;
            continue;
        }

        if ((// planes 1-3
                bytes[0] == 0xF0 &&
                (0x90 <= bytes[1] && bytes[1] <= 0xBF) &&
                (0x80 <= bytes[2] && bytes[2] <= 0xBF) &&
                (0x80 <= bytes[3] && bytes[3] <= 0xBF)
                ) ||
                (// planes 4-15
                (0xF1 <= bytes[0] && bytes[0] <= 0xF3) &&
                (0x80 <= bytes[1] && bytes[1] <= 0xBF) &&
                (0x80 <= bytes[2] && bytes[2] <= 0xBF) &&
                (0x80 <= bytes[3] && bytes[3] <= 0xBF)
                ) ||
                (// plane 16
                bytes[0] == 0xF4 &&
                (0x80 <= bytes[1] && bytes[1] <= 0x8F) &&
                (0x80 <= bytes[2] && bytes[2] <= 0xBF) &&
                (0x80 <= bytes[3] && bytes[3] <= 0xBF)
                )
                ) {
            bytes += 4;
            continue;
        }

        return false;
    }

    return true;
}
#endif

