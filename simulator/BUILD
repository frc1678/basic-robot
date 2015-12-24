cc_binary(
  name = "simulator_bin",
  srcs = glob(["**/*.cpp", "**/*.h"]),
  deps = ["@sfml//:main", "//unitscpp", "@eigen//:main"],
  copts = ["-D__STANDALONE__"]
)

cc_library(
  name = "simulator",
  srcs = glob(["**/*.cpp", "**/*.h"]),
  hdrs = glob(["**/*.h"]),
  includes = ["./"],
  deps = ["@sfml//:main", "//unitscpp", "@eigen//:main"],
  visibility = ["//visibility:public"]
)

filegroup(
  name = "assets",
  srcs = ["arial.ttf"]
)
