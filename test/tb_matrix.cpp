
#include "../lib/matrix.h"
#include <gtest/gtest.h>
#include <iostream>
#include <random>
#include <array>

static const unsigned N{1000};

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<unsigned> dis_ip(0,255);

TEST(matrix_test,random_assign_read)
{
    //const unsigned C_NUM_TEST{1000000};
    //const unsigned C_SIZE_MAP{10000};
    //unsigned op;
    //unsigned key;

    //std::map<int,int> map_std;

    //std::random_device rd;
    //std::mt19937 gen(rd());
    //std::discrete_distribution<unsigned> dis_op = {60,20,20};
    //std::uniform_int_distribution<unsigned> dis_key(0,C_SIZE_MAP - 1);

    //for (unsigned i = 0; i < C_NUM_TEST; ++i)
    //{
    //    op = dis_op(gen);
    //    key = dis_key(gen);

    //    switch (op)
    //    {
    //        // read
    //        case 0:
    //            EXPECT_EQ(map_std.emplace(std::make_pair(key,(~key + 1))).second,map_alc.emplace(std::make_pair(key,(~key + 1))).second);
    //            break;

    //        // assign
    //        case 1:
    //            EXPECT_EQ(map_std.erase(key),map_alc.erase(key));
    //            break;
    //    }
    //}
    
    //auto it_std = map_std.cbegin();
    //auto it_alc = map_alc.cbegin();
    //for (; it_std != map_std.cend() && it_alc != map_alc.cend(); ++it_std, ++it_alc)
    //{
    //    EXPECT_EQ(it_std->first,it_alc->first);
    //    EXPECT_EQ(it_std->second,it_alc->second);
    //}

    //EXPECT_EQ(map_std.size(), map_alc.size());
}
//----------------------------------------------------------------------------------


int main (int argc,char *argv[])
{
    ::testing::InitGoogleTest(&argc,argv);

    return RUN_ALL_TESTS();
}
