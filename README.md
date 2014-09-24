N D C  l!inkS

Alot of moving pieces this one. libCurl is a dependency and didn't feel 
like cooperating with me so I had to go in and modify the actual curl/curlbuild
headers. I will make this more verbose and go into detail on how I went about modifying
and will eventually include the modified files in this repository. 

This was tested using libcurl 7.19.3-win32-ssl-msvc package. Source code can 
be found over at http://curl.haxx.se/ if you want to try it on your own.

This was originally ported from Bash to python and then to C++.
Implementation is not the best but surprisingly, the most efficient out of the
three platforms, beating out the briefness of the 7 line shell file. 

Other versions from other languages will be pushed to new repos soon.

@ZWeed4U