cc_binary(
  name="frc1678",
  deps=["@wpilib//:main", "//muan:logging"],
  srcs=glob(["*.cpp"]),
  copts = ["-D__WPILIB__=<WPILib.h>"]
)

cc_binary(
  name = "simulate",
  deps = ["//muan", "//simulator"],
  srcs = glob(["*.cpp"]),
  copts = ["-D__WPILIB__=\\\"simulator/wpilib/WPILib.h\\\""]
)
