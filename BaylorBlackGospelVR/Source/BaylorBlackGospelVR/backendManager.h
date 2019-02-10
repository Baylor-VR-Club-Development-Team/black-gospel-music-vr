#ifndef BACKENDMANAGER_H
#define BACKENDMANAGER_H

#include <string>
#include <vector>
//#include <curl/curl.h>
#include <fstream>
#include "dependencies/include/curl/curl.h"

using namespace std;

/*
This class will provide an API for developers to easily interface with the
BGMRP database backend. It will be used primarily to provide song and image
info for albums in the database.
*/
class BackendManager {
private:
    static BackendManager bm;

    static bool isInit;

    static const string QUERY_HEAD;

    CURL* handle;

    /*
    This is a private constructor to support singleton referencing of the
    BackendManager class.
    */
    BackendManager();

    /*
    This function is still being defined. It will likely get an xml string
    of all records in the database, or possibly a vector of multiple xml
    strings.
    */
    vector<string> getAllItems();
    
    /*
    This function is a callback that writes data when used by libcurl. It was
    copied from https://gist.github.com/alghanmi/c5d7b761b2c9ab199157
    */
    static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp);

public:
    static BackendManager init();

    /*
    This function will get all the item info for the given album id from the
    BGMRP database. It will be used as a helper function to get the audio and
    image files.

    Input: BGMRP album id
    Output: xml string containing the query result
    */
    string getItemInfo(int id);

    /*
    This function will get an image for the album with the given id from the
    BGMRP database. It will return the file path of the image obtained.

    Input: BGMRP image id
    Output: file path to downloaded asset
    */
    string getImage(int id);

    /*
    This function will get the audio file for the album with the given id
    from the BGMRP database. It will return the file path of the image obtained.

    Input: BGMRP song id
    Output: file path to downloaded asset
    */
    string getSong(int id);

    /*
    This function will get the ids for both sides of the given disc id,
    including both image and audio ids.

    Input: BGMRP find id
    Output: xml string containing the query result
    */
    string getDiscInfo(int id);
};

#endif // BACKENDMANAGER_H
