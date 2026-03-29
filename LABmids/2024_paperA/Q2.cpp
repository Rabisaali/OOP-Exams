#include<iostream>
using namespace std;
class User;
class Post;
class Comment {
    int commentID;
    string content;
    User* author;
    public:
        Comment() {}
        Comment (int id, string c, User* u) : commentID(id), content(c), author(u) {}
        Comment createnewcomment(Comment c) {
            commentID = c.commentID;
            content = c.content;
            author = c.author;
            return *this;
        }
        int getid() {
            return commentID;
        }
        void displayContent() {
            cout << content <<endl;
        }
};
class Post {
    public:
    int postID;
    string content;
    User* author;
    Comment comment[15];
    int current = 0;
    public:
        Post () {}
        Post (int id, string c, User* a) : postID(id), content(c), author(a) {}
        Post (const Post &p) {
            postID = p.postID;
            content = p.content;
            author = p.author;
        }
        Post createNewPost(int id, string c, User* u, Comment co) {
            postID = id;
            content = c;
            author = u;
            addComment(co);
            cout << "post created\n";
            return *this;
        }
        void addComment (Comment& c) {
            //Comment p;
            comment[current++] = c;
        }
        void displaypost() {
            cout << "Post ID: " << postID;
            cout << endl << "Content: " << content << endl;
            cout << "comment: " << endl;
            for (int i=0; i<current; i++) {
                cout << i+1;
                cout << "comment id: " << comment[i].getid() << endl;
                comment[i].displayContent();
            }
        }
};
class User {
    int userID;
    string userName;
    Post posts[15];
    const int MAX_POSTS=15;
    int current_post=0;
    public:
        User (int id, string n) : userID (id), userName (n) {}
        User () {}
        User (const User& u) : MAX_POSTS(u.MAX_POSTS) {
            userID = u.userID;
            userName = u.userName;
            current_post = u.current_post;
            for (int i=0; i<current_post; i++) {
                posts[i] = u.posts[i];
            }  
        }
        User& operator= (const User& u) {
            userID = u.userID;
            userName = u.userName;
            current_post = u.current_post;
            for (int i=0; i<current_post; i++) {
                posts[i] = u.posts[i];
            }
            return *this;  
        }
        void addPost(int id, string c, User* u, Comment co) {
            if (MAX_POSTS>current_post) {
                Post p; 
                posts[current_post] = p.createNewPost(id, c, u, co);
                current_post++;
            }
            else cout << "Max limit reached\n";
        }
        void display() {
            for (int i=0; i<current_post; i++) {
                cout << "post " << i+1 << "\n";
                cout << "Post ID: " << posts[i].postID; 
                posts[i].displaypost();
            }
        }
        void addCommentToPost(int index, Comment c) {
    if (index < current_post) {
        posts[index].addComment(c);
    }
}
};

class SocialMediaPlatform {
    User users[15];
    int MAX_USERS=15;
    int current_user=0;
    public:
        SocialMediaPlatform() {}
        void addUser (User u) {
            if (current_user<MAX_USERS) {
                users[current_user] = u;
                current_user++;
            }
            else cout << "Max limit reached\n";
        }
        

};

int main () {
    User u(45, "Ali");
    SocialMediaPlatform s;
    
    Comment c(9, "so cuteeee", &u);
    u.addPost(45, "hiking", &u, c);
    u.addCommentToPost(0, c);
    Comment c2(10, "enjoyable", &u);
    u.addCommentToPost(0, c2);
    s.addUser(u);
    u.display();
    
}
