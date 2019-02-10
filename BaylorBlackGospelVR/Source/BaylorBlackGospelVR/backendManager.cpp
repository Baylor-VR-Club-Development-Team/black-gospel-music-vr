/*
Author: J.R. Diehl
Date Created: 10/04/2018

This is the implementation file for the BackendManager class.
*/

#include "backendManager.h"

using namespace std;

const string BackendManager::QUERY_HEAD = 
    "https://server17178.contentdm.oclc.org/dmwebservices/index.php?q=";

bool BackendManager::isInit = false;

BackendManager BackendManager::bm;

BackendManager::BackendManager() {
    this->handle = curl_easy_init();
}

vector<string> BackendManager::getAllItems() {
     // TODO: Implement
    return vector<string>();
}

BackendManager BackendManager::init() {
    if (!isInit) {
        // note: this will only work on windows
        //curl_global_init(CURL_GLOBAL_ALL);
        bm = BackendManager();
        isInit = true;
    }
    return bm;
}

string BackendManager::getDiscInfo(int id) {
    string query = BackendManager::QUERY_HEAD + "dmGetStreamingFile/fa-gospel/"
        + to_string(id) + ".cpd/xml";

    CURLcode res;
    string readBuffer;
    
    this->handle = curl_easy_init();
    if (this->handle) {
        curl_easy_setopt(this->handle, CURLOPT_URL, query.c_str());
        curl_easy_setopt(this->handle, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(this->handle, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(this->handle);
        curl_easy_cleanup(this->handle);
    }

    return readBuffer;
}

string BackendManager::getItemInfo(int id) {
    string query = BackendManager::QUERY_HEAD + "dmGetItemInfo/fa-gospel/"
    + to_string(id) + ".cpd/xml";
    
    CURLcode res;
    string readBuffer;
    
    this->handle = curl_easy_init();
    if (this->handle) {
        curl_easy_setopt(this->handle, CURLOPT_URL, query.c_str());
        curl_easy_setopt(this->handle, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(this->handle, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(this->handle);
        curl_easy_cleanup(this->handle);
    }
    
    return readBuffer;
}

string BackendManager::getImage(int id) {
    string query = BackendManager::QUERY_HEAD + "dmGetStreamingFile/fa-gospel/"
    + to_string(id) + ".jp2/xml";
    
    CURLcode res;
    string readBuffer;
    
    this->handle = curl_easy_init();
    if (this->handle) {
        curl_easy_setopt(this->handle, CURLOPT_URL, query.c_str());
        curl_easy_setopt(this->handle, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(this->handle, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(this->handle);
        curl_easy_cleanup(this->handle);
    }
    
    string path = "./" + to_string(id) + ".jp2";
    ofstream out;
    out.open(path, ios::binary);
    
    out << readBuffer;
    
    out.close();
    
    return path;
}

string BackendManager::getSong(int id) {
    string query = BackendManager::QUERY_HEAD + "dmGetStreamingFile/fa-gospel/"
    + to_string(id) + ".mp3/xml";
    
    CURLcode res;
    string readBuffer;
    
    this->handle = curl_easy_init();
    if (this->handle) {
        curl_easy_setopt(this->handle, CURLOPT_URL, query.c_str());
        curl_easy_setopt(this->handle, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(this->handle, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(this->handle);
        curl_easy_cleanup(this->handle);
    }
    
    string path = "./" + to_string(id) + ".mp3";
    ofstream out;
    out.open(path, ios::binary);
    
    out << readBuffer;
    
    out.close();
    
    return path;
}

size_t BackendManager::WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}
