#include "MainWindow.h"

void MainWindow::RequestLuxLevel()
{
    MaintainLux = true;

    memset(BufSend, 0, sizeof(BufSend));

    BufSend[1] = LUX;

    Send();
}

void MainWindow::MaintainLuxLevel(double value)
{
    MaintainLux = false;

    if(abs(MaintainLuxLevelValue - value) > 50){

        if((MaintainLuxLevelValue - value) > 0) {

            if((MeanPWM + MaintainLuxLevelStep) <= 255){

                MeanPWM += MaintainLuxLevelStep;

                BufSend[1] = ALLPWM;

                BufSend[2] = MeanPWM;

                Send();
            }

        } else {

            if((MeanPWM - MaintainLuxLevelStep) >= 0){

                MeanPWM -= MaintainLuxLevelStep;

                BufSend[1] = ALLPWM;

                BufSend[2] = MeanPWM;

                Send();

            }
        }
    }
}


