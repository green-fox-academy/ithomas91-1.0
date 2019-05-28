//
// Created by Tamas Nemeth on 2019-01-29.
//
#include <string>
#ifndef BLOGPOST_BLOGPOST_H
#define BLOGPOST_BLOGPOST_H


class BlogPost {
    public:
        BlogPost(std::string authorName, std::string title, std::string text, std::string publicationDate);

        std::string authorName;
        std::string title;
        std::string text;
        std::string publicationDate;

};


#endif //BLOGPOST_BLOGPOST_H
