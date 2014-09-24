#include <stdio.h>
#include <curl.h>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;


size_t write_data(void *buffer, size_t size, size_t nmemb, void *userp)
{
   return size * nmemb;
}

int main(int argc, char** argv)
{

	cout<<" #####################################"<<endl;
	cout<<" ##                                 ##"<<endl;
	cout<<" ##   NIKE EARLY LINK BRUTE FORCE   ##"<<endl;
	cout<<" ##                                 ##"<<endl;
	cout<<" ##     By: @ZWeed4U/@Jayzer1217    ##"<<endl;
	cout<<" ##                                 ##"<<endl;
	cout<<" #####################################"<<endl<<endl;
	int start;
	int end;
	cout<<"Starting PID: ";
	cin>>start;
	cout<<"Ending PID:   ";
	cin>>end;
	cout<<endl<<endl<<endl;


	for(start; start<=end; start++)
	{

  
   
		string base = "http://store.nike.com/us/en_us/pd/a,,/pid-";
		string base2 = "/pgid-";
		stringstream sstart;
		sstart << start;
    


		string newURL = base+sstart.str()+base2+sstart.str();
		

		//"http://store.nike.com/us/en_us/pd/a,,/pid-"+sstart.str()+"/pgid-"+sstart.str()


	
		CURL *curl;
		CURLcode curl_res;

		curl_global_init(CURL_GLOBAL_ALL);


		curl = curl_easy_init();
		if (curl)
		{
			curl_easy_setopt(curl, CURLOPT_URL, newURL.c_str());
			curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);
			curl_easy_setopt(curl, CURLOPT_USERAGENT, "Mozilla/4.0 (compatible; MSIE 5.01; Windows NT 5.0)");
			//curl_easy_setopt(curl, CURLOPT_NOBODY, false); 
			curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);


			/* Perform the request, curl_res will get the return code */ 
			curl_res = curl_easy_perform(curl);                //PING SOUND STARTS AND HTML CODE SHOWN


		
			/* Check for errors */ 
			if(curl_res != CURLE_OK)
			  fprintf(stderr, "curl_easy_perform() failed: %s\n",
					curl_easy_strerror(curl_res));

			if(CURLE_OK == curl_res) 
			{
				 char *url;
				 curl_res = curl_easy_getinfo(curl, CURLINFO_EFFECTIVE_URL, &url);

				 if((CURLE_OK == curl_res) && url)
					//system("cls");
					cout<<sstart.str()<<" - "<<url<<endl<<endl;
					
			}
		
			/* always cleanup */ 
			curl_easy_cleanup(curl);

			/* we're done with libcurl, so clean it up */ 
			curl_global_cleanup();

		}
		else
		{
			printf("cURL error.\n");
		}

	}


	system("pause");
    return 0;
}
