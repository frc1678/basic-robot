/*
 * TrapezoidalMotionProfile.h
 *
 *  Created on: Sep 25, 2015
 *      Author: Kyle
 */

#ifndef SRC_ROBOTCODE_TRAPEZOIDALMOTIONPROFILE_H_
#define SRC_ROBOTCODE_TRAPEZOIDALMOTIONPROFILE_H_

#include "motion_profile.h"
#include <cmath>

template <typename DistanceU>
class TrapezoidalMotionProfile : public MotionProfile<DistanceU> {
  typedef Units<DistanceU::u1, DistanceU::u2 - 1, DistanceU::u3, DistanceU::u4>
      VelocityU;
  typedef Units<DistanceU::u1, DistanceU::u2 - 2, DistanceU::u3, DistanceU::u4>
      AccelerationU;
  Time accel_time_;
  Time total_time_;
  Time deccel_time_;
  VelocityU max_speed_;
  AccelerationU max_acceleration_;

 public:
  TrapezoidalMotionProfile<DistanceU>(DistanceU distance, VelocityU max_speed,
                                      AccelerationU max_acceleration) {
    accel_time_ = max_speed / max_acceleration;
    deccel_time_ = max_speed / max_acceleration;
    max_speed_ = max_speed;
    max_acceleration_ = max_acceleration;

    if (distance > (accel_time_ + deccel_time_) * max_speed_ / 2) {
      total_time_ = accel_time_ + deccel_time_ +
                    (distance - max_speed_ * (deccel_time_ + accel_time_) / 2) /
                        max_speed_;
    } else {
      DistanceU accel_dist = distance / 2;

      accel_time_ = std::sqrt((2 * accel_dist / max_acceleration)()) * s;
      deccel_time_ = accel_time_;
      max_speed_ = accel_time_ * max_acceleration_;
      total_time_ = accel_time_ + deccel_time_;
    }
  }
  virtual ~TrapezoidalMotionProfile() {}
  virtual VelocityU CalculateSpeed(Time time) override {
    VelocityU speed = 0;

    if (time <= accel_time_) {
      speed = max_speed_ * (time / accel_time_);
    } else if (time <= total_time_ - deccel_time_) {
      speed = max_speed_;
    } else if (time <= total_time_) {
      speed = max_speed_ * ((total_time_ - time) / deccel_time_);
    }

    return speed;
  }
  virtual DistanceU CalculateDistance(Time time) override {
    DistanceU accel_dist = max_speed_ * accel_time_ / 2;
    DistanceU full_dist =
        max_speed_ * (total_time_ - deccel_time_ - accel_time_);

    DistanceU distance = accel_dist + full_dist + deccel_time_ * max_speed_ / 2;

    if (time <= accel_time_) {
      distance = time * time * max_speed_ / accel_time_ / 2;
    } else if (time <= total_time_ - deccel_time_) {
      distance = (time - accel_time_ / 2) * max_speed_;
    } else if (time <= total_time_) {
      distance = accel_dist + full_dist +
                 (deccel_time_ + time - total_time_) * max_speed_ / 2;
    }

    return distance;
  }
  bool IsDone(Time time) override { return time > total_time_; }
};

#endif /* SRC_ROBOTCODE_TRAPEZOIDALMOTIONPROFILE_H_ */
