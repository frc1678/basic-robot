/*
 * MotionProfile.h
 *
 *  Created on: Sep 25, 2015
 *      Author: Kyle
 */

#ifndef SRC_ROBOTCODE_MOTIONPROFILE_H_
#define SRC_ROBOTCODE_MOTIONPROFILE_H_
#include "unitscpp/unitscpp.h"

template <typename DistanceU>
class MotionProfile {
 public:
  typedef Units<DistanceU::u1, DistanceU::u2 - 1, DistanceU::u3, DistanceU::u4>
      VelocityU;
  typedef Units<DistanceU::u1, DistanceU::u2 - 2, DistanceU::u3, DistanceU::u4>
      AccelerationU;
  MotionProfile() {}
  virtual ~MotionProfile() {}
  virtual VelocityU CalculateSpeed(Time time) = 0;
  virtual DistanceU CalculateDistance(Time time) = 0;
  virtual bool IsDone(Time time) = 0;
};

#endif /* SRC_ROBOTCODE_MOTIONPROFILE_H_ */
