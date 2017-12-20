
#ifndef _ID_CPP
#define _ID_CPP

#include <id.h>
#include <cstring>


ID::ID(): name_(0), age_(0)
{
  SetName(DEFAULT_NAME);
  SetAge(DEFAULT_AGE);
}


ID::ID(const char* name, int age): name_(0), age_(0)
{
  SetName(name);
  SetAge(age);
}


ID::ID(const ID& rhs): name_(0), age_(0)
{
  SetName(rhs.GetName());
  SetAge(rhs.GetAge());
}


const ID& ID::operator=(const ID& rhs)
{
  if(this != &rhs)
  {
    SetName(rhs.GetName());
    SetAge(rhs.GetAge());
  }
  return *this;
}



ID::~ID()
{
  delete[] name_;
}


void ID::SetName(const char* name)
{
 if(name_ != NULL)
    delete [] name_;
  name_ = new char[strlen(name) + 1];
  strcpy(name_, name);
  name_[ strlen(name) ] = '\0';
}


void ID::SetAge(int age)
{
  age_ = age;
}


const char* ID::GetName() const
{
  return name_;
}


int ID::GetAge() const
{
 return age_;
}



std::ostream& operator << (std::ostream& stream, const ID& rhs)
{
  stream << rhs.GetName() << "\t" << rhs.GetAge();
  return stream;
}



#endif
