#pragma once
#include <algorithm>
#include <fstream>
#include <iostream>
#include <mutex>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

struct UserData
{
    std::string password;
    std::vector<int> scoruri;
};

class UserManager
{
   private:
    std::unordered_map<std::string, UserData> users;
    static UserManager* instance;
    static std::mutex mtx;

    UserManager() = default;

   public:
    UserManager(const UserManager&) = delete;
    UserManager& operator=(const UserManager&) = delete;

    static UserManager& getInstance()
    {
        std::lock_guard<std::mutex> lock(mtx);
        if (!instance)
        {
            instance = new UserManager();
        }
        return *instance;
    }

    bool loadUsersFromFile(const std::string& filename)
    {
        std::ifstream file(filename);
        if (!file.is_open())
        {
            std::cerr << "Eroare la deschiderea fisierului userilor: "
                      << filename << std::endl;
            return false;
        }
        users.clear();
        std::string line;
        while (std::getline(file, line))
        {
            std::istringstream iss(line);
            std::string username, password;
            iss >> username >> password;
            UserData data;
            data.password = password;
            int scor;
            while (iss >> scor)
            {
                data.scoruri.push_back(scor);
            }
            users[username] = data;
        }
        file.close();
        return true;
    }

    bool saveUsersToFile(const std::string& filename)
    {
        std::ofstream file(filename);
        if (!file.is_open())
        {
            std::cerr << "Eroare la salvarea fisierului userilor: " << filename
                      << std::endl;
            return false;
        }
        for (const auto& [username, data] : users)
        {
            file << username << " " << data.password;
            for (int scor : data.scoruri) file << " " << scor;
            file << "\n";
        }
        file.close();
        return true;
    }

    bool validateUser(const std::string& username, const std::string& password)
    {
        auto it = users.find(username);
        return it != users.end() && it->second.password == password;
    }

    void addScore(const std::string& username, int scor)
    {
        users[username].scoruri.push_back(scor);
    }

    int getMaxScore(const std::string& username) const
    {
        auto it = users.find(username);
        if (it == users.end() || it->second.scoruri.empty()) return 0;
        return *std::max_element(it->second.scoruri.begin(),
                                 it->second.scoruri.end());
    }

    const std::vector<int>& getScores(const std::string& username) const
    {
        static const std::vector<int> empty;
        auto it = users.find(username);
        if (it == users.end()) return empty;
        return it->second.scoruri;
    }

    bool createUser(const std::string& username, const std::string& password)
    {
        if (users.count(username)) return false;
        users[username] = UserData{password, {}};
        return true;
    }
};

UserManager* UserManager::instance = nullptr;
std::mutex UserManager::mtx;
