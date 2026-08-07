class BrowserHistory {
public:

    class Node {
    public:
        Node *next, *back;
        string data;

        Node(string s) {
            data = s;
            back = next = nullptr;
        }
    };

    Node* curr;

    BrowserHistory(string homepage) {
        curr = new Node(homepage);
    }

    void visit(string url) {
        Node* newNode = new Node(url);

        curr->next = newNode;
        newNode->back = curr;

        curr = newNode;
    }

    string back(int steps) {
        while(steps--) {
            if(curr->back) {
                curr = curr->back;
            }
            else {
                break;
            }
        }

        return curr->data;
    }

    string forward(int steps) {
        while(steps--) {
            if(curr->next) {
                curr = curr->next;
            }
            else {
                break;
            }
        }

        return curr->data;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna