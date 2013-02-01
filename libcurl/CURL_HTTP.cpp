/*
 * CURL_HTTP_Get.cpp
 *
 *  Created on: 2010-3-3
 *      Author: Zx.MYS
 */

#include "CURL_HTTP.h"

char* HTTP_data;

CURL_HTTP::CURL_HTTP() {
    // TODO Auto-generated constructor stub

}

CURL_HTTP::~CURL_HTTP() {
    // TODO Auto-generated destructor stub
}

char* CURL_HTTP::HTTP_POST(const char* url,const char* postdata) {
	HTTP_data=NULL;
    CURL* curl;
    curl_global_init(CURL_GLOBAL_ALL);
    curl=curl_easy_init();
    curl_easy_setopt(curl,CURLOPT_URL,url);
    curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION,write_data);
    curl_easy_setopt(curl,CURLOPT_POSTFIELDS,postdata);
    curl_easy_perform(curl);
    curl_easy_cleanup(curl);
    return HTTP_data;
}

char* CURL_HTTP::HTTP_GET(const char* url) {
	HTTP_data=NULL;
    CURL* curl;
    curl_global_init(CURL_GLOBAL_ALL);
    curl=curl_easy_init();
    curl_easy_setopt(curl,CURLOPT_URL,url);
    curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION,write_data);
    curl_easy_perform(curl);
    curl_easy_cleanup(curl);
    return HTTP_data;
}

const char* CURL_HTTP::make_POST_data(const char* name[],const char* val[]){
	string ret="";
	for(unsigned int i=0;i<=sizeof(name)/sizeof(char*);i++){
		ret+="&";
		ret+=name[i];
		ret+="=";
		ret+=val[i];
	}
	return (char*)(ret.c_str()+1);
}
