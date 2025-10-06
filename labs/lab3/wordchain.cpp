#include <iostream>
#include <string>
#include <vector>

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
    bool visited = false;
};

typedef vector<Node> Graph;

bool words_diff_with_one(const string &word1, const string &word2) {

    bool found_diff = false;

    for (int i {}; i < 4; i++) {
        if (word1[i] != word2[i]) {

            if(!found_diff)
                found_diff = true;

            else
                return false;
        }
    }

    return true;
}

Graph create_graph(const Dictionary &dict, Node* current, const string &to) {

    if (current->visited)
        return {};

    if (current->name == to)
        return {};

    Graph graph {};
    auto start = std::find(dict.begin(), dict.end(), current->name);

    for (const auto& word : dict) {
        if (*start == word) continue;

        if (words_diff_with_one(current->name, word)) {
            Node* neighbor = new Node{ word };
            current->neighbors.push_back(neighbor);
            create_graph(dict, neighbor, to);
        }
    }

    return {};

}

/**
 * Hitta den kortaste ordkedjan från 'first' till 'second' givet de ord som finns i
 * 'dict'. Returvärdet är den ordkedja som hittats, första elementet ska vara 'from' och sista
 * 'to'. Om ingen ordkedja hittas kan en tom vector returneras.
 */


vector<string> find_shortest(const Dictionary &dict, const string &from, const string &to) {
    vector<string> result;

    cout << "In find shortest" << endl;

    auto find_from = std::find(dict.begin(), dict.end(), from);

    if (find_from == dict.end())
        return result;

    Node* first_node = new Node {.name = from};

    Graph graph = create_graph(dict, first_node, to);

    for (const auto& g : graph) {
        cout << g.name << endl;
    }

    return result;
}

/**
 * Hitta den längsta kortaste ordkedjan som slutar i 'word' i ordlistan 'dict'. Returvärdet är den
 * ordkedja som hittats. Det sista elementet ska vara 'word'.
 */
vector<string> find_longest(const Dictionary &dict, const string &word) {
    vector<string> result(1, word);
    cout << "TODO: Implement me!" << endl;
    return result;
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
