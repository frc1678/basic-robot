package(default_visibility = ["//visibility:public"])

cc_library(
  name = "logging",
  srcs = glob(["logging/**/*.cpp"]),
  hdrs = glob(["logging/**/*.h"]),
  includes = ["logging"]
)

cc_library(
  name = "multithreading",
  srcs = glob(["multithreading/**/*.cpp"]),
  hdrs = glob(["multithreading/**/*.h"]),
  includes = ["multithreading"],
  deps = ["//unitscpp"]
)
