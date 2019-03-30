#include "MainWindow.h"

void MainWindow::MotionDetection(bool MotionDetected)
{
    if(TurnOffLightIsChecked){

        if(MotionDetected){

            BufSend[1] = 0x0D;

            BufSend[2] = static_cast<uint8_t> (MeanPWM);

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

    BufSend[1] = 0x0D;

    BufSend[2] = static_cast<uint8_t> (0);

    Send();
}
