#include "gtest/gtest.h"
#include "muan/multithreading/updateable.h"
#include "muan/utils/timing_utils.h"

class TestUpdateable : public Updateable, public testing::Test {
 public:
  TestUpdateable() : Updateable(100 * hz) {}

 protected:
  void SetUp() override { sleep_for(.01 * s); }
  void TearDown() override {}
  void Update(Time dt) override {
    if (x_ > 0) x_--;
  }
  int x_ = 100;
};

TEST_F(TestUpdateable, BasicTest) {
  Start();
  sleep_for(1.05 * s);
  Stop();
  ASSERT_EQ(x_, 0);
}

TEST_F(TestUpdateable, Stop) {
  Start();
  sleep_for(0.2 * s);
  Stop();
  ASSERT_NE(x_, 0);
}

TEST_F(TestUpdateable, StopsPromptly) {
  Start();
  // The countdown takes one second total at 100hz, so it should not finish if
  // left for .95 seconds - in other words, it should exit very quickly when
  // Stop() is called. It runs for .97 seconds because there will always be
  // a small delay between the calling of Stop() and when the thread actually
  // exits
  sleep_for(.95 * s);
  Stop();
  ASSERT_NE(x_, 0);
}
