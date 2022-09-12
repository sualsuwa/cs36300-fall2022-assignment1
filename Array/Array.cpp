// $Id: Array.cpp 820 2011-01-17 15:30:41Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Array.h"

Array::Array (void)
{
   data_ = new char[]; 
cur_size_ = 0;
max_size_ = 0;
}

Array::Array (size_t length)
{
 data_ = new char[length];
  cur_size_ = 0;
  max_size_ = length;
}

Array::Array (size_t length, char fill)
{
  data_ = new char[length];
  for( int i = 0; i < length;i++)
  {
      data_[i] = fill;

 }
}


Array::Array (const Array & array)
{
 data_ = array.data_;
  cur_size_ = array.cur_size_;
  max_size_= array.max_size_;
  for(int i = 0; i < cur_size_;i++)
  {
      data_[i]= array.data_[i];
  }
}

Array::~Array (void)
{
     delete[] data_;
  max_size_ = 0;
  cur_size_ = 0;
}

const Array & Array::operator = (const Array & rhs)
{
  data_ = rhs.data_;
  cur_size_ = rhs.cur_size_;
  max_size_ = rhs.max_size_;
  for(int i = 0; i < cur_size_;i++)
  {
      data_[i] = rhs.data_[i];
  }
  return rhs;
}

char & Array::operator [] (size_t index)
{
   if( index > max_size_)
   {
        return data_[0];
   }
}

const char & Array::operator [] (size_t index) const
{
 return data_[index];
}

char Array::get (size_t index) const
{
  
 return data_[index];
}

void Array::set (size_t index, char value)
{
    if(index > 0) 
    data_[index] = value;
}

void Array::resize (size_t new_size)
{
    char* newArr = data_;
    data_ = new char[new_size];
    for(int i = 0; i < new_size;i++)
    {
        data_[i] = newArr[i];
    }
    max_size_ =  new_size;
    delete[] data_;
    data_ = newArr;
}

int Array::find (char ch) const
{
    for(int i = 0; i < max_size_;i++)
    {
        if(data_[i] == ch)
        return 1;
    }
    return 0
}

int Array::find (char ch, size_t start) const
{
 for(int i = start; i < cur_size_; i++)
 {
     if(data_[i] == ch)
    }
    return i;
}

bool Array::operator == (const Array & rhs) const
{
  if(rhs.daa_ == data_ && rhs.cur_size_ == cur_size_ && rhs.max_size_ == max_size_)
  {
      return true;
  }
  return false;
}

bool Array::operator != (const Array & rhs) const
{
if(rhs.daa_ != data_ && rhs.cur_size_ != cur_size_ && rhs.max_size_ != max_size_)
{
    return true;

}
return false;
}

void Array::fill (char ch)
{
for(int i =0; i < max_size_; i++)
{
    data_[i] = ch;
}
cur_size_ = max_size_;
}

void Array::shrink (void)
{
  char* newArr = data_;
  size_t newsize = cur_size_ * 2;
  data_ = new char[newsize];
  for(int i = 0; i < newsize; i++)
  {
      data_[i]= newArr[i];
  }
}

void Array::reverse (void)
{
  size_t intial = 0;
  while ( intial < max_size_)
  {
      int temp = data_[intial];
      data_[intial] = data_[max_size_];
      intial++;
      data_[max_size_]= temp;
      max_size_--;
        }
}

Array Array::slice (size_t begin) const
{
   Array temp(cur_size_ - begin);
   for(int i = 0;i <temp.max_size_();i++ )
   {
       temp.set(i,data_[begin +i ]);
   }
   return temp;
}

Array Array::slice (size_t begin, size_t end) const
{
  Array temp(end - begin);
  if(end < cur_size_)
  {
      for(int i = 0; i < temp.max_size_();i++)
      temp.set(i,data_[begin + i]);
  }
  return temp;
}

