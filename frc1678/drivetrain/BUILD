package(default_visibility = ["//visibility:public"])

cc_library(
  name = "drive_plant",
  srcs = ["drive_plant.cpp"],
  hdrs = ["drive_plant.h"],
  includes = ["./"],
  deps = ["//muan", "@eigen//:main"]
)

cc_library(
  name = "drive_controller",
  srcs = ["drive_controller.cpp"],
  hdrs = ["drive_controller.h"],
  includes = ["./"],
  deps = ["//muan", "@wpilib//:main", "//unitscpp", "@eigen//:main"]
)

cc_library(
  name = "drive_subsystem",
  srcs = ["drive_subsystem.cpp"],
  hdrs = ["drive_subsystem.h"],
  includes = ["./"],
  deps = ["//muan", ":drive_controller", "@wpilib//:main", "@eigen//:main", "//unitscpp"]
)
