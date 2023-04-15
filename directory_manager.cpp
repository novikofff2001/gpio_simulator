#include "directory_manager.h"
#include <iostream>
#include <cstring>
#include <sys/stat.h>

DirectoryManager::DirectoryManager(const std::string& path) : path(path) {
    if (!std::filesystem::create_directory(path)) {
        std::cerr << "Не удалось создать директорию " << path << std::endl;
    }
}

DirectoryManager::~DirectoryManager() {
    if (!std::filesystem::remove_all(path)) {
        std::cerr << "Не удалось удалить директорию " << path << std::endl;
    }
}

bool DirectoryManager::mkdir(const std::string& dir_name) {
    std::filesystem::path full_path = path / dir_name;

    if (!std::filesystem::create_directory(full_path)) {
        std::cerr << "Не удалось создать директорию " << full_path << std::endl;
        return false;
    }

    return true;
}

bool DirectoryManager::rmdir(const std::string& dir_name) {
    std::filesystem::path full_path = path / dir_name;

    if (!std::filesystem::remove_all(full_path)) {
        std::cerr << "Не удалось удалить директорию " << full_path << std::endl;
        return false;
    }

    return true;
}

const std::filesystem::path DirectoryManager::get_path() const {
    return path;
};