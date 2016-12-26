//
// Created by regoeco on 23/12/16.
//

#ifndef STRING_H
#define STRING_H

#ifdef  __cplusplus
extern "C" {
#endif
extern const void* String;
struct String{
    const void* class;
    char *text;
};

#ifdef  __cplusplus
}

#endif
#endif //STRING_H
