#ifndef CIRCBUF_H
#define CIRCBUF_H

#include<iostream>
using std::ostream;
#include<vector>
using std::vector;

class CircBuf{
 private:
  int sz_;
  int cnt_;
  vector<long> buf_;
  size_t front_;
  size_t back_;

 public:
  CircBuf(size_t s=10);
  long front() const;
  long back() const;  
  bool full() const;
  bool empty() const;
  void add(long);
  void remove();
  
  friend ostream& operator<<(ostream&, const CircBuf &cb);
  /*
  friend CircBuf operator+(CircBuf &buf, long val);
  friend CircBuf operator+(long val, CircBuf &buf);
  friend CircBuf operator+(CircBuf &buf2, CircBuf &buf1);
  */
};

ostream& operator<<(ostream&, const CircBuf &cb);
/*
CircBuf operator+(CircBuf &buf, long val);
CircBuf operator+(long val, CircBuf &buf);
CircBuf operator+(CircBuf &buf2, CircBuf &buf1);
*/

#endif
