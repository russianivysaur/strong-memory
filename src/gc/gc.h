#pragma once
#include "../object/strong_object.h"

void ref_count_inc(strong_object* object);
void ref_count_dec(strong_object* object);