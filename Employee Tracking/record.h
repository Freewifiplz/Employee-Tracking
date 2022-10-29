//record.h
#ifndef RECORD_H
#define RECORD_H

#include "employee.h"
#include "address.h"

class record : public employee, public address {};
#endif