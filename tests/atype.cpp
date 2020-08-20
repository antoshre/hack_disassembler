//
// Created by rob on 8/19/20.
//

#include "hack_dis/hack_dis.h"
#include "gtest/gtest.h"

#include <sstream>

TEST(AType, FromLine) {
    hack_dis::HackLine line(42, -1, "00000000000000000");

    ASSERT_TRUE(hack_dis::A_Type::identify(line));

    hack_dis::A_Type ainst(line);
    EXPECT_EQ(ainst.line_loc, 42);
    EXPECT_EQ(ainst.inst_loc, -1);


    hack_dis::HackLine line2(1337, 10101, "0000111011001101");
    ASSERT_TRUE(hack_dis::A_Type::identify(line2));

    hack_dis::A_Type ainst2(line2);
    EXPECT_EQ(ainst2.value, 3789);
    EXPECT_EQ(ainst2.line_loc, 1337);
    EXPECT_EQ(ainst2.inst_loc, 10101);
}