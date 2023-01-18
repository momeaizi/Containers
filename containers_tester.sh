
sed -i.bak 's/" std::vector"/" vector"/g' main.cpp
make > /dev/null
./containers > ft

sed -i.bak 's/" vector"/" std::vector"/g' main.cpp
make re > /dev/null
./containers > std

diff std ft