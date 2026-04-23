#include <cstddef>
#include <iostream>
#include <string>
#include <vector>



void show_string(std::string const &sentence) {
    for (size_t i = 0; i < sentence.size(); i++) {
        std::cout << sentence[i];
    }
    std::cout << std::endl;
}

void update_string(std::string &sentence, std::string const &word) {
    std::vector<size_t> positions;

    size_t pos = sentence.find(word);
    while(pos != std::string::npos) {
        positions.push_back(pos);
        pos = sentence.find(word, pos+word.size());
    }

    for (size_t p : positions) {
        std::cout << "P: " << p << "\n";
        for (size_t i = p; i < word.size() + p; i++) {
            sentence[i] = '*';
        }
    }
    show_string(sentence);
}

int main() {
    std::string sentence = "I'm broccoli rolling up my broccoli";
    std::string word = "broccoli";

    update_string(sentence, word);

    show_string(sentence);

    return 0;
}


/*
#include <iostream>
#include <string>

void show_s(std::string const &text) {
  for (size_t i = 0; i < text.size(); i++) {
    std::cout << text[i];
  }
  std::cout << std::endl;
}

void bleep(std::string &text, std::string const &word) {
  size_t pos = text.find(word);
  for (size_t i = pos; i < word.size() + pos; i++) {
    text[i] = '*';
  }
}


int main() {
  std::string text = "I'm rolling up my broccoli";
  std::string word = "broccoli";

  update_s(text, word);

  show_s(text);

  return 0;
}
  */