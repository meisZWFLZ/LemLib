#include "lemlib/ui/ui.hpp"

void lemlib::ui::registerPage(lemlib::ui::Page* page) {
    lemlib::ui::registeredPages[page->getName()] = page;
}

lemlib::ui::Page* lemlib::ui::getPage(std::string name) {
    return lemlib::ui::registeredPages[name];
}

void lemlib::ui::setCurrentPage(std::string name) {
    if (lemlib::ui::currentPage != "") getPage(lemlib::ui::currentPage)->destroy();

    lemlib::ui::currentPage = name;

    lemlib::ui::getPage(name)->initialize();

    std::cout << "Current Page: " << name << std::endl;
}

void lemlib::ui::loop() {
    while (true) {
        if (lemlib::ui::currentPage == "") {
            pros::delay(100);
            continue;
        }

        lemlib::ui::getPage(lemlib::ui::currentPage)->render();
        pros::delay(50);
    }
}

void lemlib::ui::initialize() {
    pros::Task task(lemlib::ui::loop);
}
