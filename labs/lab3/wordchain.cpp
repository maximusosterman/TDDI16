#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <queue>
#include <unordered_set>


using std::vector;
using std::string;
using std::cout;
using std::endl;

// Typ som används för ordlistan. Den definieras med en typedef här så att du enkelt kan ändra
// representationen av en ordlista utefter vad din implementation behöver. Funktionen
// "read_questions" skickar ordlistan till "find_shortest" och "find_longest" med hjälp av denna
// typen.
typedef vector<string> Dictionary;

struct Node {
    string name;
    vector<Node*> neighbors {};
};

typedef vector<Node*> Graph;

const int LEN_WORD = 4;
const std::vector<char> alphabet{
    'a','b','c','d','e','f','g','h','i','j','k','l','m',
    'n','o','p','q','r','s','t','u','v','w','x','y','z'
};

vector<Node*> find_neighbors(string &word, const Dictionary &dict) {
    vector<Node*> neighbors; 
    
    for (int letter {}; letter < LEN_WORD; letter++) {

        string curr_word = word;

        for (auto character : alphabet) {
            curr_word[letter] = character;

            if(std::find(dict.begin(), dict.end(), curr_word) != dict.end())  // A neighboring word was found
                neighbors.push_back(new Node{curr_word});
            
        }
    }
    return neighbors;
    
}

/**
 * Hitta den kortaste ordkedjan från 'first' till 'second' givet de ord som finns i
 * 'dict'. Returvärdet är den ordkedja som hittats, första elementet ska vara 'from' och sista
 * 'to'. Om ingen ordkedja hittas kan en tom vector returneras.
 */
vector<string> find_shortest(const Dictionary &dict, const string &from, const string &to) {

    std::vector<string> path;

    if (std::find(dict.begin(), dict.end(), from) == dict.end())
        return {};
        
    Node* start {new Node { from }};
    Node* goal = nullptr;

    // Queue to help with the BFS traversal.
    std::queue<Node*> q {};
    std::unordered_map<Node*, Node*> parent {};
    std::unordered_set<string> visited {};

    visited.insert(from);
    parent[start] = nullptr;
    q.push(start);
    
    bool found = false;
    
    while (!q.empty()) {
        // point currentVertex at front vertex from the queue.
        Node* current_node = q.front(); q.pop();
        

        if (current_node->name == to) { // It is not our goal
            found = true;
            goal = current_node;
            break;
        }

        vector<Node*> neighbors = find_neighbors(current_node->name, dict);

        for (Node* neighbor : neighbors) {
            if (!visited.count(neighbor->name)) {   
                visited.insert(neighbor->name);;                
                parent[neighbor] = current_node;
                q.push(neighbor);
            } else
                delete neighbor;
        }
    }

    if (found){
        for(Node* n = goal; n != nullptr; n = parent[n])
            path.push_back(n->name);

        std::reverse(path.begin(), path.end());
        
    }

    for (auto &p : parent)
        delete p.first;

    return path;
}

/**
 * Hitta den längsta kortaste ordkedjan som slutar i 'word' i ordlistan 'dict'. Returvärdet är den
 * ordkedja som hittats. Det sista elementet ska vara 'word'.
 */
vector<string> find_longest(const Dictionary &dict, const string &word) {

    std::vector<string> path {};
    if (std::find(dict.begin(), dict.end(), word) == dict.end())
        return {};
        
    Node* start = new Node { word };
    
    std::queue<Node*> q {};
    std::unordered_map<Node*, Node*> parent {};
    std::unordered_map<Node*, int> distance {};
    std::unordered_set<string> visited;

    parent[start] = nullptr;
    distance[start] = 0;
    q.push(start);
    
    while (!q.empty()) {
        Node* current_node = q.front();
        q.pop();

        vector<Node*> neighbors = find_neighbors(current_node->name, dict);

        for (Node* neighbor: neighbors) {
            if (!visited.count(neighbor->name)) {   
                visited.insert(neighbor->name);;     
                parent[neighbor] = current_node;
                distance[neighbor] = distance[current_node] + 1;
                q.push(neighbor); 
            }else
                delete neighbor;
        }
    }
        
    Node* farthest = start;
    int max_dist = 0;
    for(auto& [node, dist] : distance) {
        if (dist > max_dist) {
            farthest = node;
            max_dist = dist;
        }
    }

    for(Node* n = farthest; n != nullptr; n = parent[n])
            path.push_back(n->name);


    // cleanup
    for (auto &p : parent)
        delete p.first;

    return path;
}


/**
 * Läs in ordlistan och returnera den som en vector av orden. Funktionen läser även bort raden med
 * #-tecknet så att resterande kod inte behöver hantera det.
 */
Dictionary read_dictionary() {
    string line;
    vector<string> result;
    while (std::getline(std::cin, line)) {
        if (line == "#")
            break;

        result.push_back(line);
    }

    return Dictionary(result.begin(), result.end());
}

/**
 * Skriv ut en ordkedja på en rad.
 */
void print_chain(const vector<string> &chain) {
    if (chain.empty())
        return;

    vector<string>::const_iterator i = chain.begin();
    cout << *i;

    for (++i; i != chain.end(); ++i)
        cout << " -> " << *i;

    cout << endl;
}

/**
 * Skriv ut ": X ord" och sedan en ordkedja om det behövs. Om ordkedjan är tom, skriv "ingen lösning".
 */
void print_answer(const vector<string> &chain) {
    if (chain.empty()) {
        cout << "ingen lösning" << endl;
    } else {
        cout << chain.size() << " ord" << endl;
        print_chain(chain);
    }
}

/**
 * Läs in alla frågor. Anropar funktionerna "find_shortest" eller "find_longest" ovan när en fråga hittas.
 */
void read_questions(const Dictionary &dict) {
    string line;
    while (std::getline(std::cin, line)) {
        size_t space = line.find(' ');
        if (space != string::npos) { // Question 1 if there is a space
            string first = line.substr(0, space);
            string second = line.substr(space + 1);
            vector<string> chain = find_shortest(dict, first, second);

            cout << first << " " << second << ": ";
            print_answer(chain);
        } else { // Question 2 if no space
            vector<string> chain = find_longest(dict, line);

            cout << line << ": ";
            print_answer(chain);
        }
    }
}

int main() {

    Dictionary dict = read_dictionary();
    read_questions(dict);

    return 0;
}
