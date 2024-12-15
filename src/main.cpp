//Sidh Is cracked at coding
//(foward 200 __FLT_EVAL_METHOD__)

#include "vex.h"
using namespace vex;







void ModeSelector()
{
  
}

void auton()
{
  // wait for field control or competition switch
  waitUntil((Competition.isFieldControl() || Competition.isCompetitionSwitch()) && Competition.isEnabled());
}

void driver()
{
  // wait for field control or competition switch
  waitUntil((Competition.isFieldControl() || Competition.isCompetitionSwitch()) && Competition.isEnabled());
}

int main()
{
  // initialize things i guess
  Competition.autonomous(auton);
  Competition.drivercontrol(driver);
  competition::bStopAllTasksBetweenModes = true;    // stops auton tasks before driver starts

  // setup things
  L.setStopping(brake);
  R.setStopping(brake);
  MogoOut.set(false);
  MogoIn.set(true);
  Doinker.set(false);
  ConveyorMotor.setStopping(hold);
  ConveyorMotor.setVelocity(200, rpm);
  LBMotor.setStopping(hold);
  LBMotor.setVelocity(100, rpm);
  RingColor.setLightPower(100, percent);
  RingColor.setLight(ledState::on);
  FrontVision.modelDetection(true);



  while (true)
  {
    wait(20, msec);
  }
  return 0;
}