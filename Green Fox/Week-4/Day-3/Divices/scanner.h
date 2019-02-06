//
// Created by Tamas Nemeth on 2019-02-06.
//

#ifndef DIVICES_SCANNER_H
#define DIVICES_SCANNER_H

class Scanner {
public:
    Scanner(int speed);
    void scan();
private:
    int _speed;
};

#endif //DIVICES_SCANNER_H
