#include <stdio.h>
#include <sys/sysinfo.h>

int main() {
    printf("Hello, WSL!\n");

    struct sysinfo *info;

    if (sysinfo(info) == 1) {
        printf("Success of Info\n");
    }

    printf("Success\n");
    
    return 0;
}

//git add .
//git commit -m "message"
//git push 

//git pull origin master
//git reset --hard origin/master to overwrite local
// code . to open to curent directory
// git branch to check branch
//git checkout branch to checkout branch
