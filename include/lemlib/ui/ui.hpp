#pragma once

#include <initializer_list>
#include <string>
#include <map>

#include "lemlib/ui/pages/odometry/odometryPage.hpp"
#include "pros/rtos.hpp"

namespace lemlib {
namespace ui {
static std::map<std::string, lemlib::ui::Page*> registeredPages = {};

void registerPage(lemlib::ui::Page* page);
lemlib::ui::Page* getPage(std::string name);

static std::string currentPage = "";

std::string getCurrentPage();
void setCurrentPage(std::string name);
void loop();

void initialize();

std::vector<std::string> getRegisteredPageNames();
} // namespace ui
} // namespace lemlib
