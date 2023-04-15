#pragma once

#include <string>
#include <filesystem>

class DirectoryManager {
public:
    DirectoryManager(const std::string& path);
    const std::filesystem::path get_path() const;
    ~DirectoryManager();
    bool mkdir(const std::string& dir_name);
    bool rmdir(const std::string& dir_name);

private:
    std::filesystem::path path;
};
