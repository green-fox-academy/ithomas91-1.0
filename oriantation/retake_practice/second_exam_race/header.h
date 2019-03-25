//
// Created by Tamas Nemeth on 2019-03-25.
//

#ifndef SECOND_EXAM_RACE_HEADER_H
#define SECOND_EXAM_RACE_HEADER_H

#include <limits.h>
typedef enum category
{

  HANDICAPPED,
  AMATEUR,
  PROFESSIONAL

} category_t;

typedef struct competitor
{

  unsigned int start_number;
  category_t category;
  unsigned int finish_time;

} competitor_t;


competitor_t get_fastest(competitor_t* racer, int size_array, category_t category)
{

    competitor_t fastest;
    unsigned int max_finish_time = UINT_MAX;

    for (int i = 0; i < size_array; ++i) {
        if(racer[i].finish_time < max_finish_time && racer[i].category == category){
            fastest = racer[i];
        }
    }
    return fastest;
}


#endif //SECOND_EXAM_RACE_HEADER_H
