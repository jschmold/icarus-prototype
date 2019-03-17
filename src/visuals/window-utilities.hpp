#pragma once

#include <curses.h>
#include <string>

using std::string;

namespace Icarus::Visuals {
  string readString(WINDOW* win);
}
