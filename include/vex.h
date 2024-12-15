#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <cmath>
#include <string>
#include <vector>

#include "v5.h"
#include "v5_vcs.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

competition Competition;

brain Brain;
controller Controller1 = controller(primary);

inertial Inertial = inertial(PORT1);

motor ConveyorMotor = motor(PORT2, ratio18_1, true);
motor LBMotor = motor(PORT18, ratio36_1, true);

motor LA = motor(PORT9, ratio6_1, true);
motor LB = motor(PORT7, ratio6_1, true);
motor LC = motor(PORT8, ratio6_1, true);
motor RA = motor(PORT4, ratio6_1, false);
motor RB = motor(PORT5, ratio6_1, false);
motor RC = motor(PORT6, ratio6_1, false);

motor_group L = motor_group(LA, LB, LC);
motor_group R = motor_group(RA, RB, RC);

//digital_out MogoPiston = digital_out(Brain.ThreeWirePort.A); // fix this to use both ports
digital_out MogoOut = digital_out(Brain.ThreeWirePort.A);
digital_out MogoIn = digital_out(Brain.ThreeWirePort.B);
digital_out Doinker = digital_out(Brain.ThreeWirePort.C);

rotation LBRotation = rotation(PORT11, false);

distance RingDistance = distance(PORT19);
optical RingColor = optical(PORT10);

/*vex-vision-config:begin*/
signature OldFrontVision__RING_RED = signature(1, 9671, 12289, 10980, -1047, -255, -651, 6, 0);
signature OldFrontVision__RING_BLUE = signature(2, -3629, -3197, -3413, 8977, 9929, 9453, 9.8, 0);
signature OldFrontVision__MOGO_YELLOW = signature(3, -1239, -587, -913, -5645, -4943, -5294, 8.3, 0);
vision OldFrontVision = vision(PORT13, 50, OldFrontVision__RING_RED, OldFrontVision__RING_BLUE, OldFrontVision__MOGO_YELLOW);
/*vex-vision-config:end*/

aivision FrontVision = aivision(PORT20, aivision::ALL_AIOBJS);

#define waitUntil(condition)                                                   \
  do {                                                                         \
    wait(5, msec);                                                             \
  } while (!(condition))

#define repeat(iterations)                                                     \
  for (int iterator = 0; iterator < iterations; iterator++)