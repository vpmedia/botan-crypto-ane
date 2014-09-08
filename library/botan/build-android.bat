SET PATH=%PATH%;%MSYS_HOME%\bin;%MINGW_HOME%\bin
python configure.py --os=mingw --cpu=arm --gen-amalgamation --no-autoload --enable-modules=sha-512
make