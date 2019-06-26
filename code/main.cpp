#include <dummy_controller.hpp>
#include <hwlib.hpp>
#include <manual_control.hpp>
#include <comm.hpp>

int main(void) {
    // kill the watchdog
    WDT->WDT_MR = WDT_MR_WDDIS;
    hwlib::wait_ms(1000);
    hwlib::cout << "starting up.../n";
    hwlib::wait_ms(1000);
    auto test = r2d2::manual_control::dummy_controller_c();


    r2d2::comm_c comm;
    r2d2::manual_control::module_c controller(comm, test);

    
    for(;;){
        controller.process();

        hwlib::wait_ms(10);
    }

}