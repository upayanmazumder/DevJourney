#include <iostream>
#include <vector>
using namespace std;

class User {
protected:
    string username, name;
public:
    User(const string& userUsername, const string& userName) : username(userUsername), name(userName) {}

    virtual void displayProfile() {
        cout << "User Profile:\n";
        cout << "Username: " << username << endl;
        cout << "Name: " << name << endl;
    }
};

class Blogger : public User {
protected:
    vector<string> posts;
public:
    Blogger(const string& userUsername, const string& userName) : User(userUsername, userName) {}

    void createPost(const string& post) {
        posts.push_back(post);
    }

    void displayProfile() override {
        User::displayProfile();
        cout << "Posts:\n";
        for (const auto& post : posts) {
            cout << post << endl;
        }
    }
};

class Influencer : public Blogger {
    int followerCount;
public:
    Influencer(const string& userUsername, const string& userName) : Blogger(userUsername, userName), followerCount(0) {}

    void manageFollowers(int count) {
        followerCount = count;
    }

    void displayProfile() override {
        Blogger::displayProfile();
        cout << "Follower Count: " << followerCount << endl;
    }
};

int main() {
    string username, name, post;
    int numPosts, followerCount;

    getline(cin, username);
    getline(cin, name);
    cin >> numPosts;
    cin.ignore();

    Influencer influencer(username, name);

    for (int i = 0; i < numPosts; i++) {
        getline(cin, post);
        influencer.createPost(post);
    }

    cin >> followerCount;
    influencer.manageFollowers(followerCount);

    influencer.displayProfile();

    return 0;
}