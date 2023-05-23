/* ==============================================================================
 * describe£ºknob.h
 * author£ºSwordXC/Liangliang.Zhang
 * date£º2023.05.23
 * ==============================================================================*/

#ifndef _KNOB_H_
#define _KNOB_H_

#include "headfile.h"

typedef enum
{
    Knob_N,
    Knob_U,
    Knob_D,
}Knob_dir;

void Knob_init(void);
Knob_dir Knob_check(void);


#endif
