#include <stdio.h>
// #define LOG_COLOR 0
#define LOG_LEVEL 0
#include "celog.h"

int main(int argc, char const *argv[])
{

    celog_debug("hello");
    celog_alert("hello");
    celog_crit("hello");
    celog_emerg("hello");
    celog_err("hello");
    celog_info("hello");
    celog_notice("hello");
    celog_warning("hello");

    return 0;
}
