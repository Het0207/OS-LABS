#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <stdio.h>

int main(){
    struct dirent *dir;
    DIR *de = opendir("C:/Users/Het/Desktop");

    while((dir = readdir(de)) != NULL){
        printf("%s \n", dir->d_name);
    }
}