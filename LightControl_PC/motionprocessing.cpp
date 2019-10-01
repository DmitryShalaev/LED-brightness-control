#include "MainWindow.h"

void MainWindow::MotionDetection(bool MotionDetected)
{
    if(TurnOffLightIsChecked && AutomaticControlActivated && TheTimeHasCome){

        if(MotionDetected){

            BufSend[1] = ALLPWM;

            BufSend[2] = MeanPWM;

            Send();

            MotionTimer->stop();

            if(MaintainLuxLevelIsChecked){

                RequestLuxTimer->start(RequestLuxTime);
            }else {

                MeanPWM = (PWM1 + PWM2 + PWM3) / 3;
            }

        }else {

            MotionTimer->start(MotionTime);
        }
    }
}

void MainWindow::TurningOffTheLights()
{    
    RequestLuxTimer->stop();

    BufSend[1] = ALLPWM;

    BufSend[2] = 0;

    Send();
}
