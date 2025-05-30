#pragma once
#include <string>
#include <vector>

class User
{
   private:
    std::string username;
    std::string password;
    std::vector<int> scoruri;

   public:
    User() = default;
    User(const std::string& user, const std::string& pass)
        : username(user), password(pass)
    {
    }

    const std::string& getUsername() const { return username; }
    const std::string& getPassword() const { return password; }

    bool checkPassword(const std::string& pass) const
    {
        return pass == password;
    }

    void adaugaScor(int scor) { scoruri.push_back(scor); }

    const std::vector<int>& getScoruri() const { return scoruri; }
};
