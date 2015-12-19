#include "gtest/gtest.h"
#include "muan/multithreading/updateable.h"

class TestUpdateable : public Updateable, public testing::Test {
 public:
  TestUpdateable() : Updateable(500 * hz) {}
  int x() { return _x; }

 protected:
  void SetUp() {}

  void TearDown() {}

  virtual void update(Time dt) {
    if (_x > 0) _x--;
  }
  int _x = 300;
};

TEST_F(TestUpdateable, BasicTest) {
  start();
  std::this_thread::sleep_for(std::chrono::milliseconds(700));
  join();
  ASSERT_EQ(_x, 0);
}

TEST_F(TestUpdateable, Stop) {
  start();
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
  join();
  ASSERT_GT(_x, 0);
}

TEST_F(TestUpdateable, StopsPromptly) {
  start();
  // The countdown takes .6 seconds total at 500hz, so it should not finish if
  // left for .595 seconds - it should finish very quickly when called.
  std::this_thread::sleep_for(std::chrono::milliseconds(595));
  join();
  ASSERT_GT(_x, 0);
}
