#pragma once

#include <filesystem>
#include <stdlib.h>

static const std::filesystem::path path_exec = []() {
    char resolved_path[1024];
    realpath("/proc/self/exe", resolved_path);
    return std::filesystem::path(std::string(resolved_path)).parent_path();
}();

static const std::filesystem::path path_hardware = path_exec / "hardware";

static const std::filesystem::path path_gpio = path_hardware / "gpio";

static const std::filesystem::path path_spi = path_hardware / "spi";

