cc_test(
  name = "multithreading",
  srcs = ["multithreading_test.cpp"],
  deps = ["//muan:multithreading", "@gtest//:main"]
)

cc_test(
  name = "statemachine",
  deps = ["//muan:statemachine", "@gtest//:main"],
  srcs = ["state_machine_test.cpp"]
)

cc_test(
  name = "dummy_system",
  deps = ["//muan", "@gtest//:main"],
  srcs = glob(["dummy_system/**/*.cpp", "dummy_system/**/*.h"]),
)
