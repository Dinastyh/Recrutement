#include <gtest/gtest.h>

extern "C"
{
    #include "info_connection.h"
}

TEST(Info_connection, get_from_config_file)
{
    struct info_connection *info = get_from_config_file();
}
