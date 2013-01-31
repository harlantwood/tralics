// Tralics, a LaTeX to XML translator.
// Copyright INRIA/apics/marelle (Jose' Grimm) 2002, 2004, 2007-2011

// This software is governed by the CeCILL license under French law and
// abiding by the rules of distribution of free software.  You can  use, 
// modify and/ or redistribute the software under the terms of the CeCILL
// license as circulated by CEA, CNRS and INRIA at the following URL
// "http://www.cecill.info". 
// (See the file COPYING in the main directory for details)


// This file contains commands needed for the RA
#include "tralics.h"
const char* txra_rcsid =
  "$Id: txra.C,v 2.10 2011/06/28 08:15:25 grimm Exp $";

static Buffer Tbuf;
  vector<string> module_list;


namespace ra_ns {
  void fnhack(TokenList& c,TokenList&d, TokenList&aux);
  bool is_in_module_list(const string s);
}


inline string xml_to_string (Xmlp X)
{
  string s = X->convert_to_string();
  delete X;
  return s;
}



bool Parser::next_arg_is_project()
{
  TokenList L = mac_arg();
  if(L.empty()) return true;
  return L.front().is_one_token();
}





// --------------------------------------------------

// If c has no \footnote, copies it in aux;
// else copies only what is before, what is after is appended to d
void ra_ns::fnhack(TokenList& c,TokenList&d, TokenList&aux)
{
  Hashtab& H =the_parser.hash_table;
  int bl = 0;
  while(!c.empty()) {
    Token x = c.front(); c.pop_front();
    token_ns::check_brace(x,bl);
    if (x==H.footnote_token  && bl==0){
      if(!d.empty()) {
	d.push_front(H.space_token);
	d.push_front(H.comma_token);
      }
      d.splice(d.begin(), c);
    } else { aux.push_back(x); }
  }
}

// User function \fn@hack\foo\bar
void Parser::fnhack()
{
  get_r_token();
  Token A = cur_tok;
  get_r_token();
  Token B = cur_tok;
  TokenList La,Lb=get_mac_value(B),Li=get_mac_value(A);
  ra_ns::fnhack(Li,Lb,La);
  new_macro(La,A,false);
  new_macro(Lb,B,false);
}


// User function associated to \UR in the RA
void Parser::interpret_rc()
{
  TokenList L =mac_arg();
  Tbuf << bf_reset <<L;
  Xml*res =new Xml(np_rclist,0);
  the_stack.add_last(res);
  config_ns::check_RC(Tbuf,res);
}

// --------------------------------------------------
// \end{RAsection} or \tralics@pop@section
Xid compo_id=Xid(-1);
void Parser::T_rasection_end()
{
  Xmlp in = the_stack.top_stack();
  if(in->get_id()==compo_id)
    in->compo_special();
  the_stack.pop(cst_rasection);
}

// \begin{RAsection} or \tralics@push@section
void Parser::T_rasection()
{
  string name = sT_next_arg();
  Istring elt_name = the_names[np_rasection];
  Istring iname = Istring(name);
  leave_h_mode();
  the_stack.add_nl();
  Xml*cur =  new Xml( elt_name.empty() ? iname : elt_name,0);
  if(!elt_name.empty())
    cur->get_id().add_attribute(np_name,iname);
  if(iname==cst_composition) compo_id=cur->get_id();
  the_stack.push(the_names[cst_rasection],cur);
  string_define(0,name,false);
  the_stack.add_new_anchor();
  add_id("section:" + name);
}

void Parser::push_module()
{
  string aux = sT_next_arg();
  push_module(aux);
}

void Parser::push_module(const string&aux)
{
  the_stack.add_nl();
  the_stack.push1(np_module);
  //  refstepcounter("module",false); Assume done by the package
  start_paras(8,aux,false);
}

bool ra_ns::is_in_module_list(const string s)
{
  int n = module_list.size();
  for(int i=0;i<n;i++)
    if(module_list[i]==s) return true;
  return false;    
}
