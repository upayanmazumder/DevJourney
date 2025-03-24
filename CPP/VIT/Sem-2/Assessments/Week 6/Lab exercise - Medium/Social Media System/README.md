# Single File Programming Question

## Problem Statement

Design a social media system that allows users to create posts, manage followers, and display user profiles. Implement the system using multilevel inheritance with three classes: User, Blogger, and Influencer.

Define the classes User, Blogger, and Influencer to represent these user types and their functionalities.

The User class is the base class and represents a generic user. It stores the user's username (username) and name (name). The class provides a function displayProfile to display the user's profile information.

The Blogger class is derived from the User class and represents a blogger user. It inherits the username and name members from the User class. Additionally, it has an array of strings called posts to store the blogger's posts. The class provides functions createPost to add a new post to the posts array and displayProfile to display the blogger's profile information along with their posts.

The Influencer class is derived from the Blogger class and represents an influencer user. It inherits the username, name, and posts members from the Blogger class. It also has an additional member followerCount to store the number of followers the influencer has. The class provides a function manageFollowers to update the follower count and overrides the displayProfile function to display the influencer's profile information along with their follower count.

### Input format :

The first line contains the username (a string) of the influencer.

The second line contains the name (a string) of the influencer.

The third line contains an integer numPosts, representing the number of posts created by the influencer.

The next numPosts lines contain the post content (strings) created by the influencer.

The last line contains an integer followerCount, representing the number of followers of the influencer.

### Output format :

The output consists of the influencer's profile details.

The first line displays "User Profile:".

The subsequent lines display the influencer's username, name, posts (each post on a new line ), and followerCount.

### Code constraints :

3 ≤ length of username ≤ 20

2 ≤ length of name ≤ 50

0 ≤ numPosts ≤ 100

### Sample test cases :

#### Input 1 :

alice_smith
Alice Smith
3
Hello everyone
Excited to share my new blog post
Check out my latest travel adventure
5000

#### Output 1 :

User Profile:
Username: alice_smith
Name: Alice Smith
Posts:
Hello everyone
Excited to share my new blog post
Check out my latest travel adventure
Follower Count: 5000

#### Input 2 :

john_doe
John Doe
2
First post
Second post
1000

#### Output 2 :

User Profile:
Username: john_doe
Name: John Doe
Posts:
First post
Second post
Follower Count: 1000

Whitelist
Set 1:
User
Blogger
Influencer
Blogger(const string& userUsername, const string& userName)
