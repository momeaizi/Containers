RED="\033[31m"
GREEN="\033[32m"
NORMAL=$(tput sgr0)


sed -i.bak 's/ std::vector/ vector/g' main.cpp
make > /dev/null
./Containers > ft

sed -i.bak 's/ vector/ std::vector/g' main.cpp
make re > /dev/null
./Containers > std

SUCCESS=$(diff std ft | wc -c)



if [ $SUCCESS == 0 ]; then
    printf	"$GREEN%s""\033[1m[SUCCESS]\033[0m	${NORMAL}\n"$RESET
    rm -f ft std
else
    printf	"$RED%s""\033[1m[FAILLURE]\033[0m	${NORMAL}\n"$RESET
fi