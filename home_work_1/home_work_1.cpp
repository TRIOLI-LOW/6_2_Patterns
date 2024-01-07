#include <string>
#include <iostream>

class Text {
public:
    virtual void render(const std::string& data) const {
        std::cout << data;
    }
};


class DecoratedText : public Text {
public:
    explicit DecoratedText(Text* text) : text_(text) {}
    Text* text_;
};

class ItalicText : public DecoratedText {
public:
    explicit ItalicText(Text* text) : DecoratedText(text) {}
    void render(const std::string& data)  const {
        std::cout << "<i>";
        text_->render(data);
        std::cout << "</i>";
    }
};

class BoldText : public DecoratedText {
public:
    explicit BoldText(Text* text) : DecoratedText(text) {}
    void render(const std::string& data) const {
        std::cout << "<b>";
        text_->render(data);
        std::cout << "</b>";
    }
};
class Paragraph : public DecoratedText {
public:
    explicit Paragraph(Text* text) : DecoratedText(text) {}
    void render(const std::string& data) const {
            std::cout << "<p>";
            text_->render(data);
            std::cout << "</p>";
    }
};

class Reversed : public DecoratedText {
public:
    explicit Reversed(Text* text) : DecoratedText(text){}
    void render(const std::string& data) const {
        std::string data2 = data;
        std::reverse(data2.begin(), data2.end()) ;
        text_->render(data2);
    }
};

class Link : public DecoratedText {
public:
    explicit Link(Text* text) : DecoratedText(text) {}
    void render(const std::string href,const std::string& data) const {
        std::cout << "<a href=" + href + ">";
        text_->render(data);
        std::cout << "</a>";
    }
};

int main() {
    //auto text_block = new ItalicText(new BoldText(new Text()));
   // text_block->render("Hello world");
    std::cout << std::endl;
    auto text_block2 = new Reversed(new Paragraph (new Text()));
    text_block2->render("hellow world");
    std::cout << std::endl;
    auto text_2 = new Link(new Text);
    text_2->render("netology.ru", "Helow World");
}