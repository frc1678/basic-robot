cc_library(
  name = "robot_subsystems",
  hdrs = ["robot_subsystems.h"],
  deps = ["//frc1678/drivetrain:drive_subsystem"],
  visibility = ["//visibility:public"]
)

cc_binary(
  name="frc1678",
  deps=["@wpilib//:main", "//muan", "//unitscpp", ":robot_subsystems", "//frc1678/auto"],
  srcs=glob(["*.cpp"])
)
