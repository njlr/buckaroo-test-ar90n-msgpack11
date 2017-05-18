#include <gtest/gtest.h>
#include <msgpack11.hpp>

TEST(msgpack11, array) {
  msgpack11::MsgPack::array v1{ 0xbead, 0xbeef, 0x0101 };
  msgpack11::MsgPack packed{v1};

  std::string dumped{packed.dump()};
  EXPECT_EQ(static_cast<uint8_t>(dumped[0]), 0x93u);

  std::string err;
  msgpack11::MsgPack parsed{ msgpack11::MsgPack::parse(dumped, err) };
  EXPECT_TRUE(parsed.is_array());

  msgpack11::MsgPack::array v2 = parsed.array_items();
  msgpack11::MsgPack packed2{v2};

  EXPECT_TRUE(v1 == v2);
}
