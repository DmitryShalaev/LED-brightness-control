#include "MainWindow.h"

void MainWindow::TimeCheck()
{
    if((CurrentTime >= OnTime) && (CurrentTime <= OffTime)){

        if(!TheTimeHasCome){

            TheTimeHasCome = true;

            if (TurnOffLightIsChecked) {

                BufSend[1] = 0x0D;

                BufSend[2] = 0;

                Send();

            }else if(MaintainLuxLevelIsChecked){

                RequestLuxTimer->start(RequestLuxTime);
            }
        }

    }else{

        RequestLuxTimer->stop();

        TheTimeHasCome = false;

    }

}
