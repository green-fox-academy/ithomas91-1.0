//
// Created by Tamas Nemeth on 2019-01-29.
//

#include "BlogPost.h"
#include <string>

BlogPost::BlogPost(std::string authorName_, std::string title_, std::string text_, std::string publicationDate_){

        authorName = authorName_;
        title = title_;
        text = text_;
        publicationDate = publicationDate_;
}
void BlogPost::print() {}