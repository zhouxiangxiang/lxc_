#include <stdio.h>
#include <lxc/lxccontainer.h>

int main() {
    struct lxc_container *pc;
    int ret = 1;
    
    pc = lxc_container_new("apicontainer", NULL);
    if (!pc) {
        fprintf(stderr, "Failed to setup lxc_container struct \n");        
    }
    
    if (pc->is_defined(pc)) {
        fprintf(stderr, "container already exists \n");
        goto out;
    }
    
    if (!pc->createl(c, "download", NULL, NULL, LXC_CREATE_QUIET, "-d", "ubuntu", "-r", "-a", "i386", NULL, )) {
        fprintf(stderr, "Failed to create the container\n");
        goto out;
    }
    
    if (!pc->start(pc, 0, NULL) {
        fprintf(stderr, "Failed to start the container
        n");
        goto out;
    }
    
    printf("container state: %s \n", pc->state(c));
    printf("container PID: %d\n", pc->init_pid(pc));
    
    if (!pc->shutdown(pc, 30)){
        fprintf(stderr, "failed to kill the contianer.\n");
        goto out;
    }
    
    if (!pc->destroy(pc)){
        fprintf(stderr, "failed to destroy the container.\n");
        goto out;
    }
    
    ret = 0;
    
out:
    lxc_container_put(pc);
    
    
    return ret;
}