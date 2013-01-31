// -*- C++ -*-
//$Id: txvars.h,v 2.134 2012/06/20 17:15:58 grimm Exp $
// Copyright (c)  INRIA/apics (Jose' Grimm) 2002, 2004, 2007, 2008

// This software is governed by the CeCILL license under French law and
// abiding by the rules of distribution of free software.  You can  use, 
// modify and/ or redistribute the software under the terms of the CeCILL
// license as circulated by CEA, CNRS and INRIA at the following URL
// "http://www.cecill.info". 
// (See the file COPYING in the main directory for details)

// This file contains some forward declarations, some typedef,
// and most of all enums of tralics.
// symcodes and subtypes are in txcmd.h


// forward declarations 
class Istring;
class Xml;
class Macro;
class Math;

class Stack;
class Equivalent;
class SthInternal;
class Glue;
class LinePtr;
class Parser;
class TpiOneItem;
class XmlAction;
class AttList;
class AttPair;
class FpNum;
class Token;
class Stats;
class Buffer;
class StrHash;
class MainClass;



// Some typedef declarations
typedef const char*String;
typedef Xml* Xmlp;
typedef unsigned char uchar;
typedef unsigned int Digit;


// ------------------------------------------------
// Some enums now

enum system_type {
  st_windows,st_decalpha,st_solaris,st_sgi,st_linux,st_apple,st_hp,st_unknown,
};

// For registers
enum {
  last_register = nb_registers-1,  // last valid register
  setbox_offset = nb_registers,
  setbox_last = setbox_offset+nb_registers-1,
  move_location,  makebox_location,shipout_location,
  leaders_location,  cleaders_location,  xleaders_location,
};

// Tex channels
enum {
  nb_input_channels = 16, // number of input channels
  nb_real_output_channels = 16, // number of output channels
  tty_in_chan = 16, 
  main_in_chan = 17, 
  token_in_chan=18,
  max_openout = nb_real_output_channels-1,
  max_openin = max_openout,
  positive_out_slot = 16, // means log and tty
  negative_out_slot = 17, // means log
  write18_slot = 18,      // means shell
  nb_output_channels = 19
};

enum output_encoding_type {
  en_boot, en_utf8, en_ascii7,en_ascii8,en_latin,
};


enum math_style {
  ms_D,ms_T,ms_S,ms_SS
};

// symbolic code for the unit in a case like: \vskip 3cm 
enum { unit_pt, unit_in, unit_pc, unit_cm, unit_mm,unit_bp, unit_dd,
    unit_cc, unit_sp};


// A command defined by \newcommand\foo[...][...]{...}, i.e. LaTeX style
// with optional argument has type dt_optional. Otherwise,
// a definition like \def\foo{...} is dt_normal in the case the argument list
// is empty, #1, #1#2, #1#2#3, etc; it is dt_brace if there is # before
// the opening brace, like \def\foo#1#{...}, it is dt_delim otherwise
enum def_type {
  dt_normal, dt_optional, dt_delim, dt_brace, dt_empty,dt_spec_opt,
  dt_long=8, dt_outer=16,
};

enum tpa_line {
  tl_normal,tl_end,tl_empty
};


// Character type for the bibtex parser
// in fact, since only the test with lex_numeric is used,
// this is now useless.
enum lex_type {
  lex_illegal, lex_white_space, lex_alpha, lex_numeric,
  lex_sep_char, lex_open_bra, lex_close_bra, lex_other
};

// is char valid for a bibtex entry name ?
enum id_type {illegal_id_char, legal_id_char};

// is this citation from foot_bib, refer_bib or normal bib ?
// Is this bibentry for foot, refer, year or all? 
enum bib_from { from_foot, from_refer, from_year, from_any };

// the type of something like @ARTICLE
enum entry_type {
  type_article, type_book,type_booklet, type_inbook,type_incollection,
  type_inproceedings,type_conference,type_manual,
  type_masterthesis,type_misc,type_phdthesis, type_coursenotes,
  type_proceedings,type_techreport,type_unpublished, type_unknown,
  type_comment,type_preamble,type_string,  type_extension,
};

enum c_primaire {
   cp_art, cp_aut, cp_bre, cp_col, cp_cov, cp_ouv, cp_rap, cp_tru,
   cp_last
};
enum c_secondaire {
  cs_acl,cs_scl,cs_arp,cs_aud, cs_aut, cs_bdd, cs_car, cs_cat,
  cs_cou, cs_dtr, cs_log,cs_man,cs_pho,cs_son,cs_act,cs_com,cs_inv,
  cs_pos,cs_cor,cs_rch,cs_ann, cs_ctr,cs_rec, cs_mem,cs_tha,cs_the, cs_thn,
  cs_none_cov, cs_none_bre,cs_last
};

// We keep an entry because we have seen \nocite{*}, or \cite{foo}, or
// crossref=foo. We assume that min_crossref=infinity
enum bib_creator { because_all, because_cite, because_crossref};

// If an entry contains note="foo", then the type of the assignment will be
// fp_note. NOTE: fp_key must be 1,fp_crossref must be 0...
enum field_pos {  
  fp_crossref=0, fp_key, fp_address, fp_author, fp_booktitle,   fp_chapter,
  fp_edition, fp_editor, fp_howpublished, fp_institution,
  fp_journal, fp_month, fp_note, fp_number, fp_organization,
  fp_pages, fp_publisher, fp_school, fp_series, fp_title, fp_type,
  fp_url, fp_volume, fp_year, fp_doi, fp_langue,fp_isbn, fp_issn, fp_isrn,
  fp_unknown
};

// For author={J.Grimm} to work, some hacks are needed.
// In the case of \'e, the first character is of type bct_cmd, 
// the two others are bct_continuation. In case {\foo bar}, the first char
// is bct_brace, others are bct_continuation. 
// bct_space, bct_tilde,bct_dash, bct_comma: obvious
// bct_dot is for the dot in J.Grimm, bct_bad is an error, bct_end is EOD
enum bchar_type {
  bct_normal, bct_space, bct_tilde,bct_dash, bct_comma, bct_cmd,bct_brace,
  bct_dot,bct_continuation, bct_extended,bct_end,bct_bad
};

// level_zero is undefined, level_one is the bottom level
// used for knowing whether to restore a variable when we leave a group
enum tex_level {level_zero, level_one};

// for push_level .. pop_level
enum boundary_type {
  bt_brace, bt_cell, bt_local, bt_semisimple, bt_esemisimple, bt_env,
  bt_tpa, bt_math, bt_impossible
}; 

// Handles behaviour of \par in a command
enum l_state {
  ls_normal, ls_long, ls_bad,
};

enum scan_stat{
  ss_normal, ss_skipping, ss_defining,ss_matching,ss_aligning,ss_absorbing,
};

// the state says how to interpret white space.
// see texbook end of chapter 8.
enum states { state_N,state_S,state_M};

// to make a decision between \def, \newcommand, \renewcommand, \providecommand
enum rd_flag {
  rd_always,rd_if_defined,rd_if_undef,rd_skip,rd_never};

// Is this a Error Warning Info 
enum msg_type {
  mt_error, mt_warning,mt_info,mt_none
};

// suffix for:  2pt, 3fil,  4fill, 5filll, and 6
enum glue_spec{
  glue_spec_pt, glue_spec_fil, glue_spec_fill, glue_spec_filll,glue_spec_empty,
  glue_spec_mu,
};

// for titlepage
enum tpi_vals{
  tpi_zero,tpi_noval,tpi_elt,tpi_cmd,tpi_str,tpi_alias,tpi_execute,tpi_err,
  tpi_CESS, tpi_ACSS, tpi_CES, tpi_CEES, tpi_E, tpi_CE, tpi_CEE,tpi_CCS,tpi_AC,
  tpi_S, tpi_EC,
  tpi_rt_tp=100,tpi_rt_normal,tpi_rt_list, tpi_rt_ur,
  tpi_rt_normal_def, tpi_rt_list_def,tpi_rt_constant, tpi_rt_exec,
  tpi_rt_urlist,tpi_rt_alias
};

// enum for: finish cell, start cell, or finish plus start
enum {push_only, pop_only, push_and_pop};

// this is the type of what \the can produce.
enum internal_type  {
  it_int =0,  it_dimen, it_glue,it_mu, it_ident, it_tok
};

enum scan_expr_t {se_none,se_add,se_sub,se_mult,se_div,se_scale};

// type of what is on the save stack, to be restored when we see a }.
enum save_type 
  {st_boundary,st_cmd,st_int,st_dim,st_glue,st_token,st_save,st_env,
   st_font,st_box,st_box_end,st_string};

// math delimiters. used for \left[\right] or <mrow open=a close=b>
enum del_pos
{
  del_Vert =0, del_vert, del_rangle, del_langle, del_rbrace, del_lbrace,
  del_lceil, del_rceil, del_lfloor, del_rfloor, del_open_par, del_close_par,
  del_open_bra, del_close_bra, del_open_brace, del_close_brace,
  del_open_ket, del_close_ket, del_bar, del_dot,
  del_slash, del_backslash,del_lmoustache, del_rmoustache,
  del_arrowvert,del_Arrowvert, del_uparrow,del_downarrow,  del_updownarrow,
  del_Uparrow,del_Downarrow,  del_Updownarrow, del_lgroup,del_rgroup,
  del_bracevert,
  del_invalid,del_tablesize
};


//  for fonts (\`a la Tralics)
static const int fi_shape_mul=16;
static const int fi_family_mul=64;
static const int fi_series_mul=256;
static const int fi_size_mul=2048;
enum font_info {
  fi_normal_size=0,
  fi_small_size=1, fi_small_size1=3, fi_small_size2=5, fi_small_size3=7,
  fi_small_size4=9,fi_small_size5=11,fi_small_size6=13,
  fi_big_size=2, fi_big_size1=4, fi_big_size2=6,fi_big_size3=8,
  fi_big_size4=10,fi_big_size5=12,fi_big_size6=14,
  fi_tsize_mask = 15,
  fi_up_shape=0,fi_it_shape=fi_shape_mul,fi_sl_shape=fi_shape_mul*2,
  fi_sc_shape=fi_shape_mul*3,
  fi_shape_mask = fi_shape_mul*3,
  fi_rm_family=0, fi_sf_family =fi_family_mul,fi_tt_family=fi_family_mul*2,
  fi_family_mask=fi_family_mul*3,
  fi_md_series = 0,fi_bf_series =fi_series_mul,fi_bx_series =fi_series_mul*2,
  fi_sb_series =fi_series_mul*3,fi_c_series =fi_series_mul*4,
  fi_series_mask = fi_series_mul*7,
  fi_data_mask = 2047,
  fi_size_mask = 15*fi_size_mul,
};

// Current execution mode
enum mode {
  mode_argument, mode_h, mode_v, mode_none, mode_bib, mode_array, mode_math
};


enum math_types {
  mt_flag_zero=0, // not XML
  mt_flag_space,  // This is space
  mt_flag_small,  // normal XML
  mt_flag_small_l,mt_flag_small_r,mt_flag_small_m, // small + info
  mt_flag_bin,mt_flag_rel,
  mt_flag_big,   // big object
  mt_flag_opL, mt_flag_opN,mt_flag_opD,// large p that allows limits
  mt_flag_large_l,mt_flag_large_r,mt_flag_large_m,
  mt_flag_dummy
};


enum math_list_type {
  invalid_cd=mt_flag_large_m+1, 
  math_open_cd, math_dollar_cd, math_ddollar_cd,math_env_cd, math_LR_cd,
  math_hbox_cd,math_argument_cd,
  fml_offset
};

// for extern calls
enum extern_call{
  ecall_xml_fo,ecall_xml_html, ecall_xml_lint,ecall_xml_tex,
  ecall_xml_tex1, ecall_xml_tex2,ecall_latex,ecall_dvips};

// if you want \footnote to translate to <FootNote>, you have to
// modify an entry of the_names at position np_footnote
enum name_positions {
  cst_empty, cst_invalid,
  cst_flaghi,
  cst_accent, cst_accentunder, cst_argument, cst_biblio, cst_displaystyle, 
  cst_div0,cst_div1,cst_div2,cst_div3,cst_div4,cst_div5,cst_div6,
  cst_document, cst_composition, cst_elt, cst_hbox, cst_fonts, cst_foot,
  cst_hanl,
  cst_hi, cst_math, cst_mathml, cst_mathvariant,cst_mphantom,
  cst_mfenced, cst_mfrac, cst_mpadded, cst_mode,cst_display,
  // note: use same order as mathmi_code etc 
  cst_mi, cst_mn, cst_mo, cst_ci, cst_cn,cst_csymbol,cst_nothing,
  cst_multiscripts,
  cst_mover, cst_mrow, cst_mroot, cst_mrow_cst,cst_munderover,
  cst_msqrt, cst_msub, cst_mstyle, cst_msubsup, cst_msup, cst_mspace,
  cst_mtable, cst_mtd, cst_mtr, cst_mtext, cst_munder, cst_mref,
  cst_nl,cst_p,  cst_particip, cst_rasection,cst_refer, cst_scriptlevel, 
  cst_separators,cst_temporary, cst_theorem,cst_xmlns,
  // keep these in order  
  cst_dig0, cst_dig1, cst_dig2, cst_dig3, cst_dig4,
  cst_dig5, cst_dig6, cst_dig7, cst_dig8, cst_dig9,
  // For the biblio
  cstb_article, cstb_book, cstb_booklet, cstb_conference,
  cstb_coursenotes, cstb_comment, cstb_inbook, cstb_incollection,
  cstb_inproceedings, cstb_manual, cstb_mastersthesis, cstb_masterthesis,
  cstb_misc, cstb_phdthesis, cstb_proceedings, cstb_preamble,
  cstb_techreport, cstb_string, cstb_unpublished,cstb_extension,
  cstb_address, cstb_author, cstb_booktitle, cstb_chapter, cstb_crossref,
  cstb_doi, cstb_edition, cstb_editor, cstb_howpublished, cstb_institution,
  cstb_isbn, cstb_issn, cstb_isrn, cstb_journal, cstb_key, cstb_month,
  cstb_language, cstb_langue, cstb_note, cstb_number, cstb_organization,
  cstb_pages, cstb_publisher, cstb_school, cstb_series, cstb_title,
  cstb_type, cstb_url, cstb_volume, cstb_year, cstb_unknown,
  cstb_equipe, cstb_subtype, cstb_unite, cstb_statut, cstb_section,
  cst_numalign,cst_denalign,
  // keep these in order
  cstf_normal, cstf_upright,cstf_bold,cstf_italic, cstf_bold_italic,
  cstf_script,cstf_bold_script,cstf_fraktur, cstf_doublestruck,
  cstf_bold_fraktur,
  cstf_sansserif,cstf_bold_sansserif,cstf_sansserif_italic,
  cstf_sansserif_bold_italic,cstf_monospace,
  // other values
  np_a1, np_a2, np_accueil, np_alt_head, np_angle, np_arc, np_array, 
  np_alt_caption, np_alt_section, np_alternatives,
  np_arg1, np_arg2, np_arg3, np_b1, np_b2, np_b_rend, np_bauteurs, 
  np_bediteurs, np_bezier, np_biblio, np_bigcircle, np_bottomborder, 
  np_box, np_box_pos, np_boxed, np_bpers, np_c1, np_c2, np_c_left, 
  np_c_right, np_c_center, np_caption,np_captions, np_catperso, np_cell, 
  np_center, np_center_etc, np_center_etc1, np_center_etc2, np_center_etc3, 
  np_center_etc4, np_center_etc5, np_center_etc6,np_centered, np_chapters, np_circle, 
  np_cite_type,np_natcit,
  np_cit, np_citation, np_clip, np_close, np_closecurve, np_columnalign, 
  np_columnspan, np_cols, np_curve, np_curve_nbpts, np_dashline, np_dashdim, 
  np_depth, np_description, np_display, np_div0, np_div1, np_div2, np_div3, 
  np_div4, np_div5, np_div6, np_dottedline, np_drawline, np_dx, 
  np_dy, np_english, np_eqnpos,np_error, np_false, np_fbox, np_figure, np_float,
  np_float_figure, np_float_table, np_file,np_fileextension,np_full_first, 
  np_font_small,np_font_small1,np_font_small2,np_font_small3,np_font_small4,
  np_font_large,np_font_large1,np_font_large2,np_font_large3,np_font_small5,
  np_font_large4,np_font_large5,np_font_normalsize,
  np_font_large6,np_font_small6,
  np_font_it,np_font_slanted,np_font_sc,np_font_upright,np_font_medium,
  np_font_sansserif,np_font_tt,np_font_bold,np_font_roman,np_font_boldextended,
  np_font_semibold,np_font_condensed, 
  np_footnote, np_formula, np_form, np_foot, np_french, np_framed, 
  np_from, np_full, np_german, np_glo_name,np_gloss,  np_graphics, np_halfem, 
  np_halign, np_head, np_header, np_height, np_hfil, np_hfill, 
  np_hfilneg,np_hss, np_html, 
  np_id, np_inline, np_isproject, np_item, np_junior, np_key, np_keywords, 
  np_idtext,
  np_language,  np_left, np_leftborder, np_leg, np_linethickness, 
  np_label_item, np_label_glo, np_line,  np_lineC, np_line_thickness, 
  np_list, np_mbox, np_minipage, np_module, np_moreinfo, np_movablelimits, 
  np_multiput, np_noindent, np_nonumber,np_nom,  np_open, np_llap,
  np_rlap,np_warning,
  np_ordered, np_oval, np_overline, np_page,
  np_part, np_part0, np_part1, np_part2, np_part3, np_particle, 
  np_pers, np_place, np_picture, np_point, np_pre,np_prefix, np_prenom, 
  np_pos, np_posi,np_prenote,
  np_projet,  np_projetdeveloppe, np_put, np_quoted, np_r_angle, 
  np_ref, np_rend, np_repeat, np_right, np_rightborder, np_rotatebox, 
  np_row, np_rule,np_scale, np_scaleput,np_frame,np_dashbox,
  np_sc,np_s_scale, np_sbox, np_separator,np_size, 
  np_stylesheet, np_stylesheet_type,
  np_simple, np_simplemath, np_spaceafter, np_spacebefore, np_specs, np_starred,
  np_style, np_subfigure, np_table, np_Table, np_totalwidth,
  np_tabular, np_tabular_star, np_tagcurve, np_target, np_term, np_texmath,
  np_texte, np_theme, np_theorem, np_thick_lines, np_thin_lines, np_toc,
  np_toc1,np_toc2,np_topborder, np_true, np_type, np_underline, np_unknown, 
  np_unit_length,  np_url, np_userid, np_user_list, np_vfil, np_vfill,
  np_vfilneg,np_vss,
  np_xscale, np_xscaley, np_xdir, np_glossary,np_theglossary,
  np_xpos, np_xref, np_vector, np_yscale, np_yscalex, np_ydir, np_ypos, 
  np_val, np_vpos, np_width,np_cst_width, np_tab_width, np_minipage_width, 
  np_box_width, np_zerodim, np_3pt, np_6pt, np_12pt,
  np_affiliation,np_profession,np_hdr, np_raisebox, np_research_centre,
  np_node, np_name, np_nodeconnect, np_anodeconnect,np_nodecurve, 
  np_nodebox, np_nodeoval,np_nodetriangle, np_barnodeconnect, 
  np_abarnodeconnect, np_nodecircle,
  np_anodecurve,np_nameA, np_nameB,np_posA,np_posB,np_depthA,np_depthB,
  np_mainmatter,np_frontmatter,np_backmatter, np_index,np_encap,np_level,
  np_anchor,np_leaders,np_cleaders,np_xleaders,np_theindex,np_allowbreak,
  np_mml_normal, np_mml_upright,np_mml_bold,np_mml_italic, np_mml_bold_italic,
  np_mml_script,np_mml_bold_script,np_mml_fraktur, np_mml_doublestruck,
  np_mml_bold_fraktur, np_mml_sansserif,np_mml_bold_sansserif,
  np_mml_sansserif_italic,np_mml_sansserif_bold_italic,np_mml_monospace,
  np_marginpar, np_Error,np_Warning,np_Info,np_bibkey,np_bibitem,
  np_rclist,np_rcval,np_rasection,np_pagecolor, np_color,np_color2,
  np_textype,
  // keep these in order
  np_letter_a, np_letter_b, np_letter_c, np_letter_d, np_letter_e, 
  np_letter_f, np_letter_g, np_letter_h, np_letter_i, np_letter_j, 
  np_letter_k, np_letter_l, np_letter_m, np_letter_n, np_letter_o,
  np_letter_p, np_letter_q, np_letter_r, np_letter_s, np_letter_t, 
  np_letter_u, np_letter_v, np_letter_w, np_letter_x, np_letter_y, 
  np_letter_z, 
  np_letter_A, np_letter_B, np_letter_C, np_letter_D, np_letter_E, 
  np_letter_F, np_letter_G, np_letter_H, np_letter_I, np_letter_J, 
  np_letter_K, np_letter_L, np_letter_M, np_letter_N, np_letter_O,
  np_letter_P, np_letter_Q, np_letter_R, np_letter_S, np_letter_T, 
  np_letter_U, np_letter_V, np_letter_W, np_letter_X, np_letter_Y, 
  np_letter_Z, 
  np_letters_tl,np_letters_tr,  np_letters_bl,np_letters_br,
  // keep these in order
  np_s_sup, np_s_sub, np_s_old,np_s_caps,np_s_hl,np_s_so,np_s_st,np_s_ul,

  np_last,
};

enum recur_type {
  rc_contains,rc_delete_first,rc_return_first,
  rc_return_first_and_kill,
  rc_delete,rc_delete_empty,rc_empty_par,rc_how_many,
  rc_subst,rc_move,rc_composition,rc_rename,
};

// next include defines some constants, in particular last_math_code
#include "txcmd.h" 

// A code for each math object
enum math_loc {
  math_dig_loc=last_math_code,
  math_char_normal_loc = math_dig_loc +10,
  math_char_upright_loc = math_char_normal_loc+nb_mathchars,
  math_c_loc  = math_char_upright_loc+nb_mathchars,
  xml_e_loc = math_c_loc + nb_mathchars,
  xml_o_loc,
  xml_zero_space_loc,xml_thinmu_space_loc,xml_thickmu_space_loc,
  xml_medmu_space_loc,xml_thinmuneg_space_loc,xml_quad_space_loc,
  first_inline_bhack,
  alpha_bcode,beta_bcode,gamma_bcode,delta_bcode,epsilon_bcode,varepsilon_bcode,
  zeta_bcode,eta_bcode,theta_bcode,iota_bcode,kappa_bcode,lambda_bcode,mu_bcode,
  nu_bcode,xi_bcode,pi_bcode,rho_bcode,sigma_bcode,tau_bcode,upsilon_bcode,phi_bcode,
  chi_bcode,psi_bcode,omega_bcode,varpi_bcode,varrho_bcode,varsigma_bcode,
  varphi_bcode, varkappa_bcode,vartheta_bcode,
  Gamma_bcode,Delta_bcode,Theta_bcode,Lambda_bcode,Xi_bcode,
  Sigma_bcode,Upsilon_bcode,Phi_bcode,Pi_bcode,Psi_bcode,Omega_bcode,
  first_inline_hack,
  alpha_code,beta_code,gamma_code,delta_code,epsilon_code,varepsilon_code,
  zeta_code,eta_code,theta_code,iota_code,kappa_code,lambda_code,mu_code,
  nu_code,xi_code,pi_code,rho_code,sigma_code,tau_code,upsilon_code,phi_code,
  chi_code,psi_code,omega_code,varpi_code,varrho_code,varsigma_code,
  varphi_code, varkappa_code,vartheta_code,
  Gamma_code,Delta_code,Theta_code,Lambda_code,Xi_code,
  Sigma_code,Upsilon_code,Phi_code,Pi_code,Psi_code,Omega_code,
  last_inline_bhack,
  hbar_code,ell_code,wp_code,Re_code,Im_code,partial_code,infty_code,
  emptyset_code,nabla_code,surd_code,top_code,bottom_code,bot_code,
  angle_code,triangle_code,
  forall_code,exists_code,coprod_code,bigvee_code,
  bigwedge_code,biguplus_code,bigcap_code,bigcup_code,int_code,sum_code,
  prod_code,bigotimes_code,bigodot_code,bigoplus_code,oint_code,bigsqcup_code,
  smallint_code, uplus_code,sqsubset_code,sqsupset_code, prec_code,
  doteq_code,mho_code,aleph_code, clubsuit_code, diamondsuit_code,
  heartsuit_code, spadesuit_code,leadsto_code,lhd_code,rhd_code,unlhd_code,
  unrhd_code, imaginaryi_code,exponentiale_code,differentiald_code,
  // mathbin
  triangleleft_code,triangleright_code,bigtriangleup_code,bigtriangledown_code,
  wedge_code,vee_code,cap_code,cup_code,multimap_code,
  dagger_code,ddagger_code,sqcap_code,triangleq_code,Cap_code,Cup_code,
  sqcup_code,almalg_code,diamand_code,Diamond_code,bullet_code,wr_code,
  div_code,odot_code,oslash_code,otimes_code,ominus_code,oplus_code,mp_code,
  pm_code,circ_code,bigcirc_code,setminus_code,cdot_code,ast_code,
  times_code,star_code,propto_code,sqsubseteq_code,sqsupseteq_code,
  parallel_code,mid_code,dashv_code,vdash_code,Vdash_code,models_code,
  nearrow_code,searrow_code,nwarrow_code,swarrow_code,Leftrightarrow_code,
  Leftarrow_code,Rightarrow_code,ne_code,le_code,ge_code,succ_code,
  approx_code,succeq_code,preceq_code,supset_code,subset_code,supseteq_code,
  subseteq_code,bindnasrepma_code,ni_code,gg_code,ll_code,gtrless_code,
  not_code,notin_code,colon_code,starchar_code,applyfct_code,
  invisiblecomma_code,
  leftrightarrow_code,leftarrow_code,rightarrow_code,mapsto_code,sim_code,
  simeq_code,perp_code,equiv_code,asymp_code,smile_code,frown_code,
  leftharpoonup_code,leftharpoondown_code,rightharpoonup_code,
  rightharpoondown_code,hookrightarrow_code,hookleftarrow_code,bowtie_code,
  Longrightarrow_code,longrightarrow_code,longleftarrow_code,
  Longleftarrow_code,longmapsto_code,longleftrightarrow_code,
  Longleftrightarrow_code,iff_code,cdots_code,hdots_code,vdots_code,
  ddots_code,imath_code,jmath_code,Vert_code,Vertx_code,vert_code,uparrow_code,
  downarrow_code,Uparrow_code,Downarrow_code,Updownarrow_code,
  updownarrow_code,backslash_code,Box_code, rmoustache_code,lmoustache_code,
  lgroup_code, rgroup_code,  varrangle_code,varlangle_code,
  rangle_code,langle_code,rbrace_code,lbrace_code,lceil_code,rceil_code,
  lfloor_code,rfloor_code,square_code,cong_code,in_code,
  geqslant_code,leqslant_code,ncong_code,
  open_brace_code,close_brace_code,prime_code, 
  last_inline_hack,
  // log like, with limits
  det_code, first_w_limit_code = det_code,
  gcd_code,inf_code, injlim_code,lim_code,liminf_code,limsup_code,
  max_code,min_code,sup_code,
  varliminf_code,varlimsup_code,varinjlim_code,varprojlim_code,
  projlim_code, last_w_limit_code=projlim_code,
  // log like, without limits
  log_code, lg_code,ln_code,sin_code, mod_code,
  arcsin_code,sinh_code,cos_code,arccos_code,cosh_code,tan_code,arctan_code,
  tanh_code,cot_code,coth_code,sec_code,csc_code,
  arg_code,ker_code,dim_code,hom_code,exp_code,Pr_code,
  deg_code,
  // mi 
  beth_code,circledS_code,complement_code,daleth_code,eth_code,Finv_code,
  Game_code,gimel_code,mathsection_code,mathparagraph_code,
  backprime_code,bigstar_code,blacktriangledown_code,blacktriangle_code,
  blacksquare_code,blacklozenge_code, diagup_code, diagdown_code,
  lightning_code, lozenge_code,measuredangle_code,nexists_code,
  sphericalangle_code,varnothing_code, baro_code,barwedge_code,
  curlyvee_code,curlywedge_code,divideontimes_code,dotplus_code, gtrdot_code,
  intercal_code,interleave_code, leftslice_code,rightslice_code,
  leftthreetimes_code,rightthreetimes_code,lessdot_code, ltimes_code,
  rtimes_code,merge_code,sslash_code,talloblong_code,boxast_code,
  boxbox_code,boxbslash_code,boxcircle_code,boxdot_code,boxminus_code,
  boxplus_code,boxslash_code,boxtimes_code, centerdot_code,circledast_code,
  circledcirc_code,circleddash_code,obar_code,ogreaterthan_code,
  varocircle_code,llparenthesis_code,rrparenthesis_code,//bindnasrepma_code,
  binampersand_code,llbracket_code,rrbracket_code,backepsilon_code,
  because_code,between_code,nmid_code,nparallel_code,nVDash_code,nvDash_code,
  nVdash_code,nvdash_code,pitchfork_code,therefore_code,vDash_code,VDash_code,
  nLeftarrow_code,nLeftrightarrow_code, nRightarrow_code,nleftarrow_code,
  nleftrightarrow_code,nrightarrow_code,olessthan_code,approxeq_code,
  Vvdash_code,digamma_code, lnapprox_code,  precapprox_code, Subset_code,
  Supset_code, blacktriangleleft_code, blacktriangleright_code, 
  triangledown_code, circlearrowleft_code,  circlearrowright_code,
  curvearrowleft_code, curvearrowright_code, dasharrow_code, 
  dashleftarrow_code, dashrightarrow_code, fatsemi_code, downdownarrows_code,
  downharpoonleft_code,
  downharpoonright_code, leftarrowtail_code, rightarrowtail_code, 
  leftarrowtriangle_code, rightarrowtriangle_code, leftrightarrowtriangle_code,
  leftleftarrows_code, upuparrows_code, rightrightarrows_code,
  leftrightarrows_code, leftrightharpoons_code, leftrightsquigarrow_code,
  Lleftarrow_code, Rrightarrow_code, Longmapsfrom_code,  Mapsfrom_code,
  Longmapsto_code, Mapsto_code,  longmapsfrom_code, mapsfrom_code, 
  looparrowleft_code, looparrowright_code, Lsh_code, Rsh_code, 
  rightleftarrows_code, rightleftharpoons_code, rightsquigarrow_code,
  twoheadleftarrow_code, twoheadrightarrow_code, upharpoonleft_code,
  upharpoonright_code, varprime_code, Prime_code, tprime_code, bprime_code,
  qprime_code, veebar_code, backsimeq_code,  backsim_code, Bumpeq_code,
  bumpeq_code, circeq_code, curlyeqprec_code,  curlyeqsucc_code,
  Doteq_code, doteqdot_code,  eqcirc_code,  eqsim_code,  eqslantgtr_code,
  eqslantless_code,  fallingdotseq_code,  risingdotseq_code,
  geqq_code,  leqq_code,   gggtr_code,  ggg_code, lll_code, llless_code,
  gtrapprox_code, lessapprox_code,  gtreqless_code,  gtreqqless_code,
  lesseqgtr_code, lesseqqgtr_code, lessgtr_code,  lesssim_code,
  gtrsim_code, succapprox_code,  succcurlyeq_code,   succsim_code,
  preccurlyeq_code, leftrightarroweq_code, gnapprox_code,
  gneqq_code, lneqq_code, gneq_code, lneq_code, gnsim_code,
  lnsim_code, ngeq_code, ngtr_code, nleq_code, nless_code,
  nprec_code, nsim_code, nsucc_code,  precnapprox_code,
  precneqq_code, precnsim_code, precsim_code, succnapprox_code, succneqq_code,
  succnsim_code, inplus_code, niplus_code,  ntrianglerighteqslant_code,
  ntrianglelefteqslant_code,  subseteqq_code,   supseteqq_code,
  vartriangleleft_code, vartriangleright_code,  trianglerighteq_code,
  trianglelefteq_code, nsubseteq_code, nsupseteq_code,
  ntrianglelefteq_code, ntrianglerighteq_code,  ntriangleleft_code,
  ntriangleright_code,  subsetneqq_code,  supsetneqq_code,
  subsetneq_code,   supsetneq_code, 
  strut_code, mathstrut_code, iint_code,iiint_code,iiiint_code,
  xiint_code,xiiint_code,xiiiint_code,idotsint_code,
  mml_none_code,mml_prescripts_code,
  last_math_loc
};

enum array_class_number { chn_c, chn_l,chn_r,chn_m,chn_p,chn_b };
enum array_class_type { chc_cell, chc_bar, chc_v, chc_u, chc_start, chc_inter,
       chc_pre_bar,chc_pre_inter,chc_pre_v,chc_pre_u,chc_pre_cell};

// Parameters to the program that have arguments
enum param_args {
  pa_none, pa_entnames, pa_tpastatus, pa_dir, pa_year, pa_type, pa_config, 
  pa_refer, pa_confdir, pa_external_prog, pa_trivialmath, pa_leftquote,
  pa_rightquote, pa_defaultclass, pa_infile, pa_outfile, pa_indir, pa_outdir,
  pa_logfile, pa_dtd, pa_param, pa_indata
};

extern Parser the_parser;
extern MainClass* the_main;
extern Istring the_names [np_last];

inline bool is_space (char c) { return c==' ' || c=='\t' || c=='\n';}
inline bool is_lower_case(char c) { return  'a' <= c && c <= 'z';}
inline bool is_upper_case(char c) { return  'A' <= c && c <= 'Z';}
inline bool is_digit (char c) { return ('0'<= c && c<= '9'); } 
inline uchar to_lower(uchar c) { 
  if('A' <= c && c <= 'Z') return c + ('a'-'A');  else return c;
}
