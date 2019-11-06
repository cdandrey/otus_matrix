
#include "../lib/matrix.h"
#include <gtest/gtest.h>
#include <iostream>
#include <random>
#include <array>

const unsigned C_NUM_TEST{1000000};
const unsigned C_SIZE{1000};
using arr_t = std::array<int,C_SIZE>;
using aarr_t = std::array<arr_t,C_SIZE>;

aarr_t arr;

TEST(matrix_test,random_assign_read)
{
    unsigned op;
    unsigned i;
    unsigned j;
    int val;
    
    Matrix<int,-1> mtx;
    for (auto &aa : arr)
        for (auto &a : aa)
            a = -1;

    std::size_t arr_size{0};

    std::random_device rd;
    std::mt19937 gen(rd());
    std::discrete_distribution<unsigned> dis_op = {70,30};
    std::uniform_int_distribution<unsigned> dis_idx(0,C_SIZE - 1);
    std::uniform_int_distribution<int> dis_val;

    for (unsigned t = 0; t < C_NUM_TEST; ++t)
    {
        op = dis_op(gen);
        i = dis_idx(gen);
        j = dis_idx(gen);
        val = dis_val(gen);

        switch (op)
        {
            // read
            case 0:
                EXPECT_EQ(mtx[i][j],arr[i][j]);
                EXPECT_EQ(mtx.size(),arr_size);
                break;

            // assign
            case 1:

                if (arr[i][j] == -1)
                    ++arr_size;

                arr[i][j] = val;
                mtx[i][j] = val;
                EXPECT_EQ(mtx[i][j],arr[i][j]);
                EXPECT_EQ(mtx.size(),arr_size);
                break;
        }
    }
    
    EXPECT_EQ(mtx.size(),arr_size);
    for (i = 0; i < C_SIZE; ++i)
        for (j = 0; j < C_SIZE; ++j)
            EXPECT_EQ(mtx[i][j],arr[i][j]);
}
//----------------------------------------------------------------------------------


TEST(matrix_test,hand)
{
    const int C_DEFAULT_VALUE_V0 = 5;

    int tmp;
    Matrix<int,C_DEFAULT_VALUE_V0> mv0;

    tmp = mv0[100][100];
    EXPECT_EQ(tmp,C_DEFAULT_VALUE_V0);
    EXPECT_EQ(mv0.size(),0);

    tmp = 100;
    mv0[100][100] = tmp;
    EXPECT_EQ(mv0.size(),1);
    EXPECT_EQ(mv0[100][100],tmp);

    tmp = mv0[1][1];
    mv0[1][1] = tmp;
    EXPECT_EQ(mv0.size(),2);
    EXPECT_EQ(mv0[1][1],tmp);

}
//----------------------------------------------------------------------------------


int main (int argc,char *argv[])
{
    ::testing::InitGoogleTest(&argc,argv);

    return RUN_ALL_TESTS();
}
