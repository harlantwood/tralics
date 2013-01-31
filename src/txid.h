// -*- C++ -*-
// $Id: txid.h,v 2.4 2008/02/21 17:45:58 grimm Exp $
// TRALICS, copyright (C) INRIA/apics (Jose' Grimm) 2006,2008

// This software is governed by the CeCILL license under French law and
// abiding by the rules of distribution of free software.  You can  use, 
// modify and/ or redistribute the software under the terms of the CeCILL
// license as circulated by CEA, CNRS and INRIA at the following URL
// "http://www.cecill.info". 
// (See the file COPYING in the main directory for details)



// Adress of attribute list of an xml object
// is a wrapper around an int
class Xid {
 public: 
  int value; // value of the id
  Xid(int v) :  value(v) {}
  Xid() : value(0) {}
  AttList& get_att() const;
  void add_attribute(Istring A,Istring B);
  void add_attribute(Istring A,Istring B,bool f);
  void add_attribute(name_positions A, name_positions B);
  void add_attribute(name_positions n, name_positions v,bool);
  void add_attribute(name_positions n, Istring v);
  void add_attribute(const AttList& L);
  void add_attribute(Xid b);
  void add_ref(string);
  bool operator==(Xid X)const { return value==X.value; }
  Istring has_attribute(Istring n);
  bool is_font_change() const;
  void add_special_att(string S);
};
