#include <steering_wheel_controller.hpp>

r2d2::manual_control::steering_wheel_controller_c::steering_wheel_controller_c(
    hwlib::target::pin_in &button1, hwlib::target::pin_in &button2,
    hwlib::target::pin_in &button3, hwlib::target::pin_in &button4,
    hwlib::target::pin_adc &wheel, hwlib::target::pin_adc &pedals)
    : buttons{&button1, &button2, &button3, &button4},
      sliders{&wheel, &pedals} {
}

bool r2d2::manual_control::steering_wheel_controller_c::read() {
    this->refresh();

    return false;
}

int8_t r2d2::manual_control::steering_wheel_controller_c::get_slider(
    const int &slider) {
    if (slider == 0) {
        int wheel_degrees = sliders[0]->read();

        return ((wheel_degrees - 320) * 180 / (4030 - 320) - 90);
    } else {

        int pedal_percentage = sliders[1]->read();

        return ((pedal_percentage - 340) * 200 / (4030 - 340) - 110);
    }
}

bool r2d2::manual_control::steering_wheel_controller_c::get_button(
    const int &button) {
    return !buttons[button]->read();
}

void r2d2::manual_control::steering_wheel_controller_c::print() {
    hwlib::cout << "B1: " << buttons[0]->read()
                << "| B2: " << buttons[1]->read()
                << "| B3: " << buttons[2]->read()
                << "| B4: " << buttons[3]->read() << "| \n";

    hwlib::cout << "wheel: " << get_slider(0)
                << " | pedals: " << get_slider(1)
                << "\n";
}