#include "lemlib/ui/ui.hpp"
#include <string>

void lemlib::ui::registerPage(lemlib::ui::Page* page) {
    lemlib::ui::registeredPages[page->getName()] = page;
}

lemlib::ui::Page* lemlib::ui::getPage(std::string name) {
    return lemlib::ui::registeredPages[name];
}

std::string lemlib::ui::getCurrentPage() {
    return lemlib::ui::currentPage;
}

void lemlib::ui::setCurrentPage(std::string name) {
    if (lemlib::ui::currentPage == name) return;

    if (lemlib::ui::currentPage != "") getPage(lemlib::ui::currentPage)->destroy();

    lemlib::ui::currentPage = name;

    std::cout << "Current Page: " << name << std::endl;
}

lv_obj_t* createScreen() {
    lv_disp_t* display = lv_disp_get_default();
    lv_theme_t* theme = lv_theme_default_init(display, lv_palette_main(LV_PALETTE_BLUE),
                                                lv_palette_main(LV_PALETTE_RED), true, LV_FONT_DEFAULT);
    lv_disp_set_theme(display, theme);

    lv_obj_t* screen = lv_obj_create(NULL);
    lv_obj_clear_flag(screen, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_bg_color(screen, lv_color_hex(0x262626), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(screen, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_disp_load_scr(screen);

    return screen;
}

void lemlib::ui::loop() {
    lv_obj_t* screen = createScreen();

    std::string lastPage = "";

    while (true) {
        if (lemlib::ui::currentPage == "") {
            pros::delay(100);
            continue;
        }

        if (lastPage != lemlib::ui::currentPage) {
            if (lastPage != "") {
                lemlib::ui::getPage(lastPage)->destroy();

                screen = createScreen();
            }

            lemlib::ui::getPage(lemlib::ui::currentPage)->initialize(screen);
        }

        lemlib::ui::getPage(lemlib::ui::currentPage)->render();

        lastPage = lemlib::ui::currentPage;

        pros::delay(50);
    }
}

void lemlib::ui::initialize() {
    pros::Task task(lemlib::ui::loop);
}

std::vector<std::string> lemlib::ui::getRegisteredPageNames() {
    std::vector<std::string> names = {};

    for (auto const& [key, val] : lemlib::ui::registeredPages) {
        names.push_back(key);
    }

    return names;
}