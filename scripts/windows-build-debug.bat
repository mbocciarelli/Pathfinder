cd ..
mkdir build-debug && cd build-debug
cmake .. -DCMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_PREFIX=.. -DBUILD_SHARED_LIBS=ON -G "Visual Studio 16 2019"
cd ..
PAUSE